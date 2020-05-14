import cv2 as cv

img = cv.imread('lena.jpg', 1)
# We can test if img == None to see if it is a valid file
print(img)	# This will print out a matrix of the img

cv.imshow('Sample Image', img)
# cv.waitKey(10000) 	#This will show the image for 10 seconds
k = cv.waitKey(0) & 0xFF

if k == 27:						# The esacpe Key
	cv.destroyAllWindows()
elif k == ord('s'):
	cv.imwrite('lena_copy.png', img)
	cv.destroyAllWindows()