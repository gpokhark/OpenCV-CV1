import cv2
import math

# List store points
TopLeft = []
BottomRight = []


# crop and save the image
def cropSave(src):
    # reference global variables
    global TopLeft, BottomRight
    
    # y, x
    dst = src[TopLeft[0][1]:BottomRight[0][1], TopLeft[0][0]:BottomRight[0][0]]
    
    # save the image
    cv2.imwrite("face.png",dst)


# function to draw rectangle
def drawRectangle(action, x, y, flags, userdata):
    # reference glovbal variables
    global TopLeft, BottomRight
    # action to be taken when left mouse button is pressed
    if action == cv2.EVENT_LBUTTONDOWN:
        TopLeft = [(x, y)]
        # Mark the point
        cv2.circle(source, TopLeft[0], 1, (255, 255, 0), 2, cv2.LINE_AA)
    
    # action to be taken when left mouse button is realeased
    elif action == cv2.EVENT_LBUTTONUP:
        BottomRight = [(x, y)]
        # draw the rectangle
        cv2.rectangle(source, TopLeft[0], BottomRight[0], (255, 255, 0), 2, cv2.LINE_AA)
        
        cv2.imshow("Window", source)   
    
    
source = cv2.imread("./sample.jpg", 1)
# Make a dummy image, will help to clear the drawing
dummy = source.copy()
cv2.namedWindow("Window")
# highgui function called when mouse event occurs
cv2.setMouseCallback("Window", drawRectangle)
k = 0
# loop while ESC character is not pressed
while k != 27:
    cv2.imshow("Window", source)
    cv2.putText(source, '''Choose the top left point, and drag''', 
                (10,30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
    
    cv2.putText(source, '''Press c to clear''', 
                (10,60), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
    
    cv2.putText(source, '''Press ESC to save and exit''', 
                (10,90), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
    
    k = cv2.waitKey(20) & 0xff
    
    # if c is pressed
    if k == 99:
        source = dummy.copy()

if TopLeft != [] and BottomRight != []:
    # crop and save the image
    cropSave(dummy)         

cv2.destroyAllWindows()