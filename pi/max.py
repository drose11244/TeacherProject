#!/usr/bin/env python
# encoding: utf-8

import RPi.GPIO
import time

R,G,B=25,8,7

RPi.GPIO.setmode(RPi.GPIO.BCM)

RPi.GPIO.setup(R, RPi.GPIO.OUT)
RPi.GPIO.setup(G, RPi.GPIO.OUT)
RPi.GPIO.setup(B, RPi.GPIO.OUT)

pwmR = RPi.GPIO.PWM(R, 70)
pwmG = RPi.GPIO.PWM(G, 70)
pwmB = RPi.GPIO.PWM(B, 70)

pwmR.start(0)
pwmG.start(0)
pwmB.start(0)


SERVO = 4
# GPIO.setmode(GPIO.BCM)
RPi.GPIO.setup(SERVO, RPi.GPIO.OUT)
p = RPi.GPIO.PWM(SERVO, 50)
p.start(2.5)

 
TRIG = 17
ECHO = 27
 
RPi.GPIO.setup(TRIG, RPi.GPIO.OUT)
RPi.GPIO.setup(ECHO, RPi.GPIO.IN)


RPi.GPIO.setwarnings(False)
RPi.GPIO.setup(17,RPi.GPIO.OUT)
RPi.GPIO.setup(27,RPi.GPIO.OUT)


t = 0.4
def pwm():
    
    pwmR.ChangeDutyCycle(0)
    pwmG.ChangeDutyCycle(100)
    pwmB.ChangeDutyCycle(100)
    time.sleep(t)
    
    pwmR.ChangeDutyCycle(100)
    pwmG.ChangeDutyCycle(0)
    pwmB.ChangeDutyCycle(100)
    time.sleep(t)
    
    pwmR.ChangeDutyCycle(100)
    pwmG.ChangeDutyCycle(100)
    pwmB.ChangeDutyCycle(0)
    time.sleep(t)

def sg90():
    p.ChangeDutyCycle(7.5)
    time.sleep(1)
    p.ChangeDutyCycle(12.5)
    time.sleep(1)
    p.ChangeDutyCycle(2.5)
    time.sleep(1)
    print "Done loop"

def ping():
    RPi.GPIO.output(TRIG, 0)
    time.sleep(0.1)
 
    RPi.GPIO.output(TRIG, 1)
    time.sleep(0.00001)
    RPi.GPIO.output(TRIG, 0)
    start = time.time()
    while RPi.GPIO.input(ECHO) == 0:
      start = time.time()
    while RPi.GPIO.input(ECHO) == 1:
      stop = time.time()
    distance = (stop - start) * 34000 / 2
    print distance
def motor():
    # Makes the motor spin one way for 3 seconds
    RPi.GPIO.output(14, True)
    RPi.GPIO.output(16, False)
    time.sleep(3)
    # Spins the other way for a further 3 seconds
    # GPIO.output(17, False)
    # GPIO.output(27, True)
    # time.sleep(3)

try:
    while True:
        # pwm(); 
        # sg90(); 
        # ping(); 
        motor(); 
        
except KeyboardInterrupt:
    pass

pwmR.stop()
pwmG.stop()
pwmB.stop()

RPi.GPIO.output(14, False)
RPi.GPIO.output(16, False)


RPi.GPIO.cleanup()