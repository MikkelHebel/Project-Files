from djitellopy import Tello

# Establish connection to the drone
#tello = Tello()
tello = Tello('192.168.43.243', 8889)

tello.connect()
tello.connect_to_wifi("WeeFee", "JustConnect")