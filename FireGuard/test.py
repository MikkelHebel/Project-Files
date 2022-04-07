import time, cv2
from threading import Thread
from playsound import playsound
from djitellopy import Tello
fire_cascade = cv2.CascadeClassifier('fire_detection.xml')
from twilio.rest import Client
client = Client('ACd43dda35d113528b41f348cbc3235ef4', '3ad17f3b9dbdae1d0a2c317081c0de69')

# Establish connection to the drone
#tello = Tello()
tello = Tello('192.168.10.1',8889)
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

            # The drone operator gets alerted with a sound from the computer and a phone message
            print("[INFO] Fire is detected!")
            time.sleep(1)
            message = client.messages \
                .create(
                     body="Fire Detected!",
                     from_='+19062562866',
                     to='+4531365107'
                 )
            print(message.sid)
            print("[INFO] Alerted the operator!")

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