import tweepy
import os
import sys
import config

auth = tweepy.OAuthHandler(config.consumer_key, config.consumer_secret)
auth.secure = True
auth.set_access_token(config.access_token, config.access_token_secret)

api = tweepy.API(auth)

#api.update_with_media("/home/murat/Pictures/20160418_220038.jpg")

api.send_direct_message(screen_name="mboyar_ei", text="selam murat, ben ev")


