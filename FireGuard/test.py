import time, cv2
from threading import Thread
from djitellopy import Tello
fire_cascade = cv2.CascadeClassifier('fire_detection.xml')

# Establish connection to the drone
tello = Tello()
tello.connect()

# Begin the video streamer
keepRecording = True
tello.streamon()
frame_read = tello.get_frame_read()

# Create a VideoWrite object, recording to ./video.avi
def videoRecorder():
    height, width, _ = frame_read.frame.shape
    video = cv2.VideoWriter('video.avi', cv2.VideoWriter_fourcc(*'XVID'), 30, (width, height))

    # While the recorder is active it scans for fire
    while keepRecording:
        frame = frame_read.frame
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        fire = fire_cascade.detectMultiScale(frame, 1.2, 5)

        # Create a blue rectangle around the fire
        for (x,y,w,h) in fire:
            cv2.rectangle(frame,(x-20,y-20),(x+w+20,y+h+20),(255,0,0),2)
            roi_gray = gray[y:y+h, x:x+w]
            roi_color = frame[y:y+h, x:x+w]
            print("[INFO] Fire is detected!")

        # Show the Drone Video Stream, if Q is pressed stop the program
        cv2.imshow('Drone Camera', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

        video.write(frame_read.frame)
        time.sleep(1 / 30)

    video.release()

# For performance we run the recorder in a seperate thread
recorder = Thread(target=videoRecorder)
recorder.start()