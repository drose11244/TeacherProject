import time
import RPi.GPIO as GPIO

# Next we setup the pins for use!
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

motorA = 17
motorB = 27

GPIO.setup(motorA,GPIO.OUT)
GPIO.setup(motorB,GPIO.OUT)

print('Starting motor sequence!')

while True:
  try:
    # Makes the motor spin one way for 3 seconds
    GPIO.output(motorA, True)
    GPIO.output(motorB, False)
    time.sleep(3)
    # Spins the other way for a further 3 seconds
    GPIO.output(motorA, False)
    GPIO.output(motorB, True)
    time.sleep(3)
  except(KeyboardInterrupt):
    # If a keyboard interrupt is detected then it exits cleanly!
    print('Finishing up!')
    GPIO.output(motorA, False)
    GPIO.output(motorB, False)
    quit()
