import time, cv2
from flask import Flask, render_template, Response
from time import gmtime, strftime
from threading import Thread
from djitellopy import Tello
fire_cascade = cv2.CascadeClassifier('fire_detection.xml')
app = Flask(__name__)

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
    video = cv2.VideoWriter('video.avi', cv2.VideoWriter_fourcc(*'XVID'), 24, (width, height))

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

        # Show the Drone Video Stream on the pc, if Q is pressed stop the program
        cv2.imshow('Drone Camera', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

        video.write(frame_read.frame)
        time.sleep(1 / 24)

        # Show the Drone Video Stream on a website.
        ret, buffer = cv2.imencode('.jpg', frame)
        frame = buffer.tobytes()
        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')  # concat frame one by one and show result

    video.release()

# For performance we run the recorder in a seperate thread
recorder = Thread(target=videoRecorder)
recorder.start()

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/video')
def video():
    return Response(videoRecorder(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == "__main__":
    app.run(debug=False)

# Flight path
#exec(open('flight path/forestPath.py').read())