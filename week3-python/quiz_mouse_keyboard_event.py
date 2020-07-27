import cv2

maxScaleUp = 100
scaleFactor = 1
scaleType = 0
maxType = 1

windowName = "Resize Image"
trackbarValue = "Scale"
trackbarType = "Type: \n 0: Scale Up \n 1: Scale Down"

# load an image
im = cv2.imread("data/images/truth.png")

# Create a window to display results
cv2.namedWindow(windowName, cv2.WINDOW_AUTOSIZE)

def resizeImage(action, x, y, flag, userdata):
    # Referencing global variables 
    global scalingFactor, scalingType
    # Action to be taken when ctrl key + mouse wheel scrolled forward
    print("action = {}".format(action))
    print("flag = {}".format(flag))
    print("k = {}".format(k))
    if action == 10 + 8:
        if (flag > 0):
            # Resize image
            print("Ctrl + Mouse UP")
    # Action to be taken when ctrl key + mouse wheel scrolled backward
    elif action == cv2.EVENT_FLAG_CTRLKEY and cv2.EVENT_MOUSEWHEEL:
        if (flag < 0):
            # Resize image
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