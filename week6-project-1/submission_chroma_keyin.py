import cv2
import numpy as np
import matplotlib.pyplot as plt

color = np.zeros((1, 1, 3))

lowH = 0
upH = 179
lowS = 0
upS = 255
lowV = 0
upV = 255

clicked = False

def onMouse(event, x, y, flag, srcHsv):
    global lowH, upH, lowS, upS, clicked
    
    if event == cv2.EVENT_LBUTTONDOWN or event == cv2.EVENT_RBUTTONDOWN:
        clicked = True
        
        lowH = srcHsv[y, x, 0]
        upH = srcHsv[y, x, 0] + 25
        
        lowS = srcHsv[y, x, 1]
        
        cv2.setTrackbarPos("lowH", "Panel", lowH)
        cv2.setTrackbarPos("upH", "Panel", upH)
        cv2.setTrackbarPos("lowS", "Panel", lowS)
        

def createTrackerBars():
    cv2.namedWindow("Panel")

    cv2.createTrackbar("lowH", "Panel", 0, 179, nothing)
    cv2.createTrackbar("upH", "Panel", 179, 179, nothing)

    cv2.createTrackbar("lowS", "Panel", 0, 255, nothing)
#     cv2.createTrackbar("upS", "Panel", 255, 255, nothing)

#     cv2.createTrackbar("lowV", "Panel", 0, 255, nothing)
#     cv2.createTrackbar("upV", "Panel", 255, 255, nothing)

#     cv2.createTrackbar("Gauss Kernel", "Panel", 1, 5, nothing)

def getTrackBarPositions():
    
    global lowH, upH, lowS, upS
    
    lowH = cv2.getTrackbarPos("lowH", "Panel")
    upH = cv2.getTrackbarPos("upH", "Panel")
        
    lowS = cv2.getTrackbarPos("lowS", "Panel")
#     upS = cv2.getTrackbarPos("upS", "Panel")
        
#     lowV = cv2.getTrackbarPos("lowV", "Panel")
#     upV = cv2.getTrackbarPos("upV", "Panel")
        
#     kGauss = cv2.getTrackbarPos("Gauss Kernel", "Panel")

def nothing(*args):
    pass

# Video capture object
cap = cv2.VideoCapture('./greenscreen-asteroid.mp4')
if(cap.isOpened() == False):
    print("Error opening video stream or file")

# Background replacement Image
bgImage = cv2.imread('./avengers.jpg')

# read in the first frame
ret, frame = cap.read()

# save the first frame as png image for trial
# cv2.imwrite('greenscreen.png', frame)

panel = np.zeros([100, 800], np.uint8)

cv2.namedWindow("Input Video")

createTrackerBars()

# Read until video is completed
k = 0
# start from 1 instead of 0 so that last frame is not empty
frameCounter = 0

while(True):
    # Capture frame-by-frame
    ret, frame = cap.read()
    
    # To play the video in loop
    if (ret == False):
        cap.set(cv2.CAP_PROP_POS_AVI_RATIO, 0);
        continue;
    
    if ret == True and k != 27:
        
        hsvFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        
        cv2.setMouseCallback("Input Video", onMouse, hsvFrame)
        
        if clicked == False:
            cv2.imshow("Input Video", frame)
            k = cv2.waitKey(25)
        
        else:
            getTrackBarPositions()
        
            lowGreen = np.array([lowH, lowS, lowV])
            upGreen = np.array([upH, upS, upV])
        
            mask = cv2.inRange(hsvFrame, lowGreen, upGreen) # Background highlights so Foreground masks
        
            kSize = (3, 3)
            kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, kSize)
            mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
            mask = cv2.morphologyEx(mask, cv2.MORPH_DILATE, kernel)
        
#             if kGauss != 0:
#                 if kGauss % 2 == 0: # If even
#                     kGauss = 2 * kGauss + 1 # Make it odd
#                     # Gaussian blur on Foreground mask
#                     mask = cv2.GaussianBlur(mask, (kGauss, kGauss), 0, 0)
#                 else:
#                     # Gaussian blur on Foreground mask
#                     mask = cv2.GaussianBlur(mask, (kGauss, kGauss), 0, 0)
        
            maskInv = cv2.bitwise_not(mask) # Foreground highlights so Background masks

            background = cv2.bitwise_and(frame, frame, mask = mask)
            foreground = cv2.bitwise_and(frame, frame, mask = maskInv)

            bgImageMod = cv2.bitwise_and(bgImage, bgImage, mask = mask)
            # bgImage + foreground
#             outputFrame = cv2.bitwise_or(bgImageMod, foreground)
            outputFrame = cv2.addWeighted(bgImageMod, 1, foreground, 1, 0)
        
            cv2.imshow("Input Video", outputFrame)
            
            cv2.putText(panel, "Best Values - 47, 58, 109", (30, 30), cv2.FONT_HERSHEY_SIMPLEX, \
                        1, (255, 255, 255), 2)
            
            cv2.imshow("Panel", panel)
        
#             cv2.imshow("Background", mask)
#             cv2.imshow("Foreground", maskInv)
            # Wait for 25 ms before moving on to the next frame
            # This will slow down the video
            k = cv2.waitKey(25)

    # Break the loop
    if k == 27:
        cv2.destroyAllWindows()
        cap.release()
        break