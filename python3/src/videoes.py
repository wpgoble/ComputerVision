import cv2 as cv

cap = cv.VideoCapture(0)

while(True):
	ret, frame = cap.read()
	frame2 = cv.flip(frame, 1)		# This will flip the video
	# gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

	# print(cap.get(cv.CAP_PROP_FRAME_WIDTH), cap.get(cv.CAP_PROP_FRAME_HEIGHT))

	# cv.imshow('Frame', gray)
	cv.imshow('Frame', frame2)
	k = cv.waitKey(1) & 0xFF

	if k == ord('q'):
		break

cap.release()
cv.destoryAllWindows()