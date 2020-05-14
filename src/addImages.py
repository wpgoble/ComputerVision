import numpy as np
import cv2 as cv

img = cv.imread('../data/messi5.jpg')
img2 = cv.imread('../data/opencv-logo.png')

b,g,r = cv.split(img)

img = cv.merge((b,g,r))

ball = img[280:340, 330:390]
img[273:333, 100:160] = ball

img = cv.resize(img, (512, 512))
img2 = cv.resize(img2, (512, 512))

# This is regular add
dst = cv.add(img, img2)

cv.imshow('Regular Add', dst)
k = cv.waitKey(0)

if k == ord('q'):
	cv.destroyAllWindows()

# Now we will execute Add Weighted

dst2 = cv.addWeighted(img, 0.8, img2, 0.2, 0)
cv.imshow('Add Weighted', dst2)
k = cv.waitKey(0)

if k == ord('q'):
	cv.destroyAllWindows()