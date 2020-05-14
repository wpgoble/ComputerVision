import cv2 as cv

cap = cv.VideoCapture(0)
# print(width, height)

cap.set(3, 700)		# Width
cap.set(4, 700)		# Height

while(cap.isOpened()):
	ret, frame = cap.read()
	frame = cv.flip(frame, 1)
	if ret == True:
		gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
		cv.imshow('Frame', gray)

		k = cv.waitKey(1) & 0xFF 
		if k == ord('q'):
			break
	else:
		break

cap.release()
cap.destroyAllWindows()