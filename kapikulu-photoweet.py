import tweepy
import os
import sys
import config
import cv2
import serial

while True:

    arduinoTTY = serial.Serial("/dev/ttyUSB0")
    retStr = arduinoTTY.readline()
    print(retStr)
    arduinoTTY.close()

    if "knock-knock" in retStr:
        print("ok")

        ## cam stuff, thx to codeplasma.com

        # Camera 0 is the integrated web cam on my netbook
        camera_port = 0

        #Number of frames to throw away while the camera adjusts to light levels
        ramp_frames = 30

        # Now we can initialize the camera capture object with the cv2.VideoCapture class.
        # All it needs is the index to a camera port.
        camera = cv2.VideoCapture(camera_port)

        # by mboyar
        #camera.set(4, 320) #CV_CAP_PROP_FRAME_HEIGHT
        #camera.set(3, 240) #CV_CAP_PROP_FRAME_WIDTH
        #

        # Captures a single image from the camera and returns it in PIL format
        def get_image():
         # read is the easiest way to get a full image out of a VideoCapture object.
         retval, im = camera.read()
         return im

        # Ramp the camera - these frames will be discarded and are only used to allow v4l2
        # to adjust light levels, if necessary
        for i in xrange(ramp_frames):
         temp = get_image()
        print("Taking image...")
        # Take the actual image we want to keep
        camera_capture = get_image()
        # A nice feature of the imwrite method is that it will automatically choose the
        # correct format based on the file extension you provide. Convenient!
        cv2.imwrite(config.mediafile_path, camera_capture, [cv2.IMWRITE_JPEG_QUALITY, 100])

        # You'll want to release the camera, otherwise you won't be able to create a new
        # capture object until your script exits
        del(camera)


        ## tweet stuffs

        auth = tweepy.OAuthHandler(config.consumer_key, config.consumer_secret)
        auth.secure = True
        auth.set_access_token(config.access_token, config.access_token_secret)

        api = tweepy.API(auth)
        api.update_with_media(config.mediafile_path)

        #


#TODO logger syslog logrotate
#TODO watermark blending
#TODO lcd energy saving
#TODO web config page
#TODO todolari githuba ayri dosyaya yaz
