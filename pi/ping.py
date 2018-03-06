import RPi.GPIO as GPIO
import time
 
GPIO.setmode(GPIO.BOARD)
 
TRIG = 18
ECHO = 16
 
GPIO.setup(TRIG, GPIO.OUT)
GPIO.setup(ECHO, GPIO.IN)
 
try:
  while True:
    GPIO.output(TRIG, 0)
    time.sleep(1)
 
    GPIO.output(TRIG, 1)
    time.sleep(0.00001)
    GPIO.output(TRIG, 0)
    start = time.time()
 
    while GPIO.input(ECHO) == 0:
      start = time.time()
 
    while GPIO.input(ECHO) == 1:
      stop = time.time()
 
    distance = (stop - start) * 34000 / 2
    print distance
except KeyboardInterrupt:
  GPIO.cleanup()
