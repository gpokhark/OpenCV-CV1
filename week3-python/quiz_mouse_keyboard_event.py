import cv2

windowName = "Resize Image"

# load an image
im = cv2.imread("data/images/truth.png")

# Create a window to display results
cv2.namedWindow(windowName, cv2.WINDOW_AUTOSIZE)

def resizeImage(action, x, y, flag, userdata):
    # Referencing global variables 
    global scalingFactor, scalingType

    print("action = {}".format(action))
    print("flag = {}".format(flag))
    print("k = {}".format(k))
    
    # Action to be taken when ctrl key + mouse wheel scrolled forward
    if flag == 7864320 + 8:
        # Enlarge image
        print("Ctrl + Mouse UP")
    # Action to be taken when ctrl key + mouse wheel scrolled backward
    elif flag == -7864320 + 8:
        # Shrink image
        print("Ctrl + Mouse Down")


cv2.imshow(windowName, im)
cv2.setMouseCallback(windowName, resizeImage)
print(cv2.EVENT_FLAG_CTRLKEY)
k = 1
while(1):
    k = cv2.waitKey(0)
    if k==27:    # Esc key to stop
        break
    elif k==-1:  # normally -1 returned,so don't print it
        continue
    else:
        print(k) 

cv2.destroyAllWindows()