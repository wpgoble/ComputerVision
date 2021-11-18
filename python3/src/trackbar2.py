import numpy as np
import cv2 as cv

def nothing(x):
	print(x)

# img = np.zeros((300, 512, 3), np.uint8)
cv.namedWindow('image')

cv.createTrackbar('curPos', 'image', 10, 400, nothing)

switch = 'color/gray'
cv.createTrackbar(switch, 'image', 0, 1, nothing)

while(1):
	img = cv.imread('../data/lena.jpg')

	pos = cv.getTrackbarPos('curPos', 'image')
	font = cv.FONT_HERSHEY_SIMPLEX
	cv.putText(img, str(pos), (50, 150), font, 
		4, (255, 255, 0), 2)

	k = cv.waitKey(1) & 0xFF
	if k == ord('q'):
		break
	
	s = cv.getTrackbarPos(switch, 'image')

	if s == 0:
		pass
	else:
		img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

	cv.imshow('image', img)
	# img = cv.imread('../data/lena.jpg')

cv.destroyAllWindows()