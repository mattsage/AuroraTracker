#!/bin/sh

while [ 1 ] ; do
  /home/pi/blink1/commandline/blink1-tool -l 2 --rgb 20,232,30
  /home/pi/blink1/commandline/blink1-tool -l 1 --rgb 0,234,141
  sleep 0.5
  /home/pi/blink1/commandline/blink1-tool -l 2 --rgb 0,234,141
  /home/pi/blink1/commandline/blink1-tool -l 1 --rgb 1,126,213
  sleep 0.5
  /home/pi/blink1/commandline/blink1-tool -l 2 --rgb 1,126,213
  /home/pi/blink1/commandline/blink1-tool -l 1 --rgb 181,61,255
  sleep 0.5
  /home/pi/blink1/commandline/blink1-tool -l 2 --rgb 181,61,255
  /home/pi/blink1/commandline/blink1-tool -l 1 --rgb 141,0,196
  sleep 0.5
  /home/pi/blink1/commandline/blink1-tool -l 2 --rgb 141,0,196
  /home/pi/blink1/commandline/blink1-tool -l 1 --rgb 20,232,30
  sleep 0.5
done
