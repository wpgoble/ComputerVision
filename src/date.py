import cv2 as cv
import datetime as dt

cap = cv.VideoCapture(0)

while(cap.isOpened()):
	ret, frame = cap.read()
	frame = cv.flip(frame, 1)		# This will flip the video
	# gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

	if ret == True:
		temp = dt.datetime.now()
		date = 'Date: ' + str(temp.month) + '/' + str(temp.day) + '/' + str(temp.year)
		font = cv.FONT_HERSHEY_SIMPLEX

		frame = cv.putText(frame, date, (10, 50), font, 1, 
			(255, 255, 0), 2, cv.LINE_AA)
		cv.imshow('Frame', frame)

		k = cv.waitKey(1) & 0xFF

		if k == ord('q'):
			break
	else:
		break

cap.release()
cv.destroyAllWindows()