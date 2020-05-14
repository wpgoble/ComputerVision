import numpy as np
import cv2 as cv

img = cv.imread('../data/messi5.jpg')

print(img.shape)	# returns a tuple of number of rows, columns, and channels
print(img.size)		# returns the total number of pixels
print(img.dtype)	# returns Image datatype

b,g,r = cv.split(img)

img = cv.merge((b,g,r))

# Get the coordinates of the ball
# These were given, but we would need to calculate 
# where the roi exists
ball = img[280:340, 330:390]

# Now we are going to move the ball around in the image
img[273:333, 100:160] = ball

cv.imshow('image', img)
k = cv.waitKey(0)

if k == ord('q'):
	cv.destroyAllWindows()