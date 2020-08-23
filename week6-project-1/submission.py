import numpy as np
import cv2

def getVar(patch):
    x = cv2.Scharr(patch, -1, 1, 0)
    y = cv2.Scharr(patch, -1, 0, 1)
    variance = np.abs(x) + np.abs(y)
    return variance

def getPatch(pt, image):
    # Patch of dimension
    size = 13
    patch = image[pt[1] - size : pt[1] + size, pt[0] - size : pt[0] + size]
    return patch

def BestNeighbor(pt, gray, image):
    bestVar = 0
    bestPt = None
    
    # Check a neighbor patch at distance of dim
    dim = 30
    neighbor = np.array([(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]) * dim
    
    for move in neighbor:
        movePt = pt + move
        
        # If the move pixel is outside of the image
        if movePt[movePt < 0].sum() < 0:
            continue
        
        # Get Patch surrounding the selected move point
        patch = getPatch(movePt, gray)
        
        # Get the variance for the patch
        var = 1/getVar(patch).sum()
        
        if var > bestVar:
            bestVar = var
            bestPt = movePt
            
    return getPatch(bestPt, image)
    

def on_mouse(event, x, y, flags, image):
    if event == cv2.EVENT_LBUTTONDOWN or event == cv2.EVENT_RBUTTONDOWN:
        
        imageGray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        
        # using the selected x, y find the best patch
        colorPatch = BestNeighbor((x, y), imageGray, image)
        
        # create a mask
        srcMask = np.ones_like(colorPatch) * 255
        
        # seanmless cloning
        cv2.seamlessClone(colorPatch, image, srcMask, (x, y), cv2.NORMAL_CLONE, blend = image)
        

image = cv2.imread("blemish.png")

cv2.namedWindow("Blemish Removal")

cv2.setMouseCallback("Blemish Removal", on_mouse, image)

k = 0
while k != 27:
    cv2.imshow("Blemish Removal", image)
    k = cv2.waitKey(20)

cv2.destroyAllWindows()