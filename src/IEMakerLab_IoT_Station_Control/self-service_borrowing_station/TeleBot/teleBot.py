import asyncio
import telegram
import telepot
from telepot.loop import MessageLoop
import time
from datetime import datetime
import json
import requests
from telegram.ext import Updater, CommandHandler
import client_config as hc
#from gmqtt import Client as mqtt


async def main():
    global tg_alert, connect_mqtt, data, tg_alert, alert_msg, tg_alert_status, threshold_data, threshold_status
    bot = telegram.Bot(hc.tg_bot_id)
    #print(data)
    #print("Threshold is: ",threshold_data)
    #print("Threshold Status is: ",threshold_status)     # threshold reset or not
    #print("Alert Status is: ",tg_alert_status)
    #await client.connect(hc.server, 1883, keepalive=60)
    async with bot:
        print(await bot.get_me())
        #print((await bot.get_updates())[0])			# Getting the chat ID 999181758
        #print((await bot.get_updates()))
        await bot.send_message(text="Hello", chat_id=hc.chat_id)

                
    #await aclient.disconnect()
        
if __name__ == '__main__':
    #client = mqtt(hc.server)
    #client.set_auth_credentials(hc.username, hc.password)

    while(True):
        asyncio.run(main())
