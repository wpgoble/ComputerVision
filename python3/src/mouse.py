import numpy as np
import cv2 as cv

# events = [i for i in dir(cv) if 'EVENT' in i]
# print(events)

def click_event(event, x, y, flags, param):
	if event == cv.EVENT_RBUTTONDOWN:
		font = cv.FONT_HERSHEY_SIMPLEX
		strXY = str(x) + ', ' + str(y)
		cv.putText(img, strXY, (x, y), font, 0.5, (255, 255, 0), 2)
		cv.imshow('Image', img)
	if event == cv.EVENT_LBUTTONDOWN:
		font = cv.FONT_HERSHEY_SIMPLEX
		blue = img[y, x, 0]
		green = img[y, x, 1]
		red = img[y, x, 2]
		strBGR = str(blue) + ', ' + str(green) + ', ' + str(red)
		cv.putText(img, strBGR, (x, y), font, 0.5, (0, 255, 0), 2)
		cv.imshow('Image', img)

# img = np.zeros((512, 512, 3), np.uint8)
img = cv.imread('lena.jpg')
cv.imshow('Image', img)

cv.setMouseCallback('Image', click_event)

k = cv.waitKey(0) & 0xFF

if k == ord('q'):
	cv.destroyAllWindows()