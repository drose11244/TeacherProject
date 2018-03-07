import RPi.GPIO as GPIO
import time
 
# GPIO.setmode(GPIO.BOARD)
GPIO.setmode(GPIO.BCM)

ECHO = 14
TRIG = 16
 
GPIO.setup(TRIG, GPIO.OUT)
GPIO.setup(ECHO, GPIO.IN)
 
try:
  while True:
    GPIO.output(TRIG, 0)
    time.sleep(0.00001)
 
    GPIO.output(TRIG, 1)
    time.sleep(0.00001)
    GPIO.output(TRIG, 0)
    start = time.time()
    # print("1")
    while GPIO.input(ECHO) == 0:
      start = time.time()
      # print("2")
    while GPIO.input(ECHO) == 1:
      stop = time.time()
      # print("3")

    distance = (stop - start) * 34000 / 2
    print distance

except KeyboardInterrupt:
  GPIO.cleanup()




import time
import RPi.GPIO as GPIO

# Use BCM GPIO references
# instead of physical pin numbers
GPIO.setmode(GPIO.BCM)

# Define GPIO to use on Pi
GPIO_TRIGGER = 16
GPIO_ECHO = 14

print "Ultrasonic Measurement"

# Set pins as output and input
GPIO.setup(GPIO_TRIGGER,GPIO.OUT)  # Trigger
GPIO.setup(GPIO_ECHO,GPIO.IN)      # Echo

# Set trigger to False (Low)
GPIO.output(GPIO_TRIGGER, False)

# Allow module to settle
time.sleep(0.5)

# Send 10us pulse to trigger
GPIO.output(GPIO_TRIGGER, True)
time.sleep(0.00001)
GPIO.output(GPIO_TRIGGER, False)
start = time.time()
while GPIO.input(GPIO_ECHO)==0:
  start = time.time()

while GPIO.input(GPIO_ECHO)==1:
  stop = time.time()

# Calculate pulse length
elapsed = stop-start

# Distance pulse travelled in that time is time
# multiplied by the speed of sound (cm/s)
distance = elapsed * 34000

# That was the distance there and back so halve the value
distance = distance / 2

print "Distance : %.1f" % distance

# Reset GPIO settings
GPIO.cleanup()
