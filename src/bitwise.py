import cv2 as cv
import numpy as np

img1 = np.zeros((250, 500, 3), np.uint8)
img1 = cv.rectangle(img1, (200, 0), (300, 100), 
	(255, 255, 255), -1)
img2 = cv.imread('../data/image_1.png')

img2 = cv.resize(img2, (500, 250))

bitAnd = cv.bitwise_and(img2, img1)
bitOr = cv.bitwise_or(img2, img1)

cv.imshow('img1', img1)
cv.imshow('img2', img2)
cv.imshow('BitAnd', bitAnd)
cv.imshow('BitOr', bitOr)

k = cv.waitKey(0)

if k == ord('q'):
	cv.destroyAllWindows()