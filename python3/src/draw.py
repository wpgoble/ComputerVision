import numpy as np
import cv2 as cv

img = cv.imread('lena.jpg', 1)
# img = np.zeros([512, 512, 3], np.uint8)		# Draws a black square
# The color is given in BGR not RGB
img = cv.line(img, (0, 0), (255, 255), (0, 255, 0), 2)

img = cv.rectangle(img, (235, 235), (362, 382), (255, 255, 0), 2)
cv.imshow('Image', img)

k = cv.waitKey(0) & 0xFF

if k == ord('q'):
	cv.destroyAllWindows()