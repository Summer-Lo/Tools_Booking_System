"""
@ Author    : Lo King Hin
@ Date      : 10/02/2023
@ About     : This script is used to interact the MTR Next train information and telegram
@ Remark    : The chat id and bot id have been ignored since the personal issue
"""

# Library
import asyncio
from datetime import datetime
import json
import requests
import telegram
from telegram.ext import Updater, CommandHandler
import telepot
from telepot.loop import MessageLoop
import time
# function file
import client_config as hc
import station_info as info
import telegram_token as tt


# variables
allowable_order = []
allowable_data = []
telepot_bot = telepot.Bot(tt.tg_bot_id)

def timedelta_formatter(td):                             # defining the function
    td_sec = td.seconds                                  # getting the seconds field of the timedelta
    hour_count, rem = divmod(td_sec, 3600)               # calculating the total hours
    minute_count, second_count = divmod(rem, 60)         # distributing the remainders
    msg = "{} minutes, {} seconds".format(minute_count,second_count)
    return msg 

def Light_Rail(chat_msg):
    pass

def MTR(chat_msg):
    global telepot_bot, allowable_order, allowable_data
    # ---------------------------- Data from Station on the Line ----------------------------
    msg = requests.get("https://rt.data.gov.hk/v1/transport/mtr/getSchedule.php?line="+str(hc.user_line)+"&sta="+str(hc.user_sta))
    msg_dict = json.loads(msg.text)
    msg_data = msg_dict['data']
    msg_dir = msg_data[hc.station]
    msg_dir_up = msg_dir['UP']      # UP : e.g. TUM == Tuen Mun
    msg_dir_down = msg_dir['DOWN']  # DOWN : e.g. WKS == Wu Kai Sha
    now = datetime.now()
    
    # ---------------------------- Telegram Bot infotmation ----------------------------
    #print(chat_msg['chat'])
    try:
        chat_id = chat_msg['chat']['id']
        text = chat_msg['text']
        print("Sender: ",chat_id)
    except:
        text = str(chat_msg)
    print("Received text: ",text)
    if(info.list_sta_key[info.list_line_key.index(hc.user_line)].index(hc.user_sta) <= info.list_sta_key[info.list_line_key.index(hc.user_line)].index(hc.user_dest)):
        hc.DIR = 'Up'
    else:
        hc.DIR = 'Down'

    # Information Function from user input
    if(str(text) == "Information" or str(text) == "information" or str(text) == "Info"or str(text) == "info"):
        print("Information Message Received!")
        response = "[INFO]  The Next Train time information \nLine:                   " + info.line[hc.user_line] + " \nStation:             " + info.sta[hc.user_sta] + " \nDestination:    " + info.sta[hc.user_dest]
        telepot_bot.sendMessage(tt.chat_id, response)
        time_diff = []
    # ---------------- Down Case ----------------
        if(hc.DIR == 'Down'):
            if(len(msg_dir_down) == 0):
                response = "[INFO] ---------- Out of working hour ----------"
                telepot_bot.sendMessage(tt.chat_id, response)
            elif(msg_dir_down[1]['dest'] != hc.dest):
                response = "[INFO] ---------- Invalid Input ----------"
                telepot_bot.sendMessage(tt.chat_id, response)
            else:
                for i in range(len(msg_dir_down)):
                    if (msg_dir_down[i]['valid'] == 'Y' and datetime.strptime(msg_dir_up[i]['time'],"%Y-%m-%d %H:%M:%S") >= datetime.now()):
                        allowable_order.append(i)
                        allowable_data.append(msg_dir_down[i])
                        time_diff.append(timedelta_formatter(datetime.strptime(msg_dir_up[i]['time'],"%Y-%m-%d %H:%M:%S")-datetime.now()))
                #response = "[INFO] The Next Train time information in \nLine:            " + info.line[hc.user_line] + " \nStation:      " + info.sta[hc.user_sta]
                #telepot_bot.sendMessage(tt.chat_id, response)
                for i in range(len(allowable_data)):
                    response = "Order :                  " + allowable_data[i]['seq'] + "\n"
                    response = response + "Destination :      " + allowable_data[i]['dest'] + "\n"
                    response = response + "Arrive Time :      " + allowable_data[i]['time'] + "\n"
                    response = response + "Next Train:         " + str(time_diff[i])
                    telepot_bot.sendMessage(tt.chat_id, response)

        # ---------------- Up Case----------------
        elif (hc.DIR == 'Up'):
            if(len(msg_dir_up) == 0):
                response = "[INFO] ---------- Out of working hour ----------"
                telepot_bot.sendMessage(tt.chat_id, response)
            elif(msg_dir_up[1]['dest'] != hc.dest):
                response = "[INFO] ---------- Invalid Input ----------"
                #print(response)
                #telepot_bot.sendMessage(tt.chat_id, response)
            else:
                for i in range(len(msg_dir_up)):
                    if (msg_dir_up[i]['valid'] == 'Y' and datetime.strptime(msg_dir_up[i]['time'],"%Y-%m-%d %H:%M:%S") >= datetime.now()):
                        allowable_order.append(i)
                        allowable_data.append(msg_dir_up[i])
                        time_diff.append(timedelta_formatter(datetime.strptime(msg_dir_up[i]['time'],"%Y-%m-%d %H:%M:%S")-datetime.now()))
                #response = "[INFO] The Next Train time information in \nLine:            " + info.line[hc.user_line] + " \nStation:      " + info.sta[hc.user_sta]
                #telepot_bot.sendMessage(tt.chat_id, response)
                for i in range(len(allowable_data)):
                    response = "Order :                 " + allowable_data[i]['seq'] + "\n"
                    response = response + "Destination :      " + allowable_data[i]['dest'] + "\n"
                    response = response + "Arrive Time :      " + allowable_data[i]['time']
                    response = response + "Next Train:         " + str(time_diff[i])
                    telepot_bot.sendMessage(tt.chat_id, response)

        # ---------------- No Data Case ----------------
        elif(len(allowable_data) == 0):
            response = "[INFO] ------------------- No Data -------------------"
            telepot_bot.sendMessage(tt.chat_id, response)
        # ---------------- Reset ----------------
        allowable_order = []            # Reset
        allowable_data = []             # Reset
    
    # Configuration function for user input
    # ---------------- Config stage  = 1 ---------------- 
    # Received Config command and start config process
    elif(str(text) == "Config" or str(text) == "config"):         
        print("Config Message Received!")
        hc.config_stage = 1
        response = "[Config] Please input the Line for Configuration!"
        telepot_bot.sendMessage(tt.chat_id, response)

    # ---------------- Config stage  = 1 ---------------- 
    # Check user input for the MTR line selection
    elif(hc.config_stage == 1):
        if str(text) in info.line:              # check user input line vaild or not
            hc.config_stage = 2
            hc.user_line_temp = str(text)
            response = "[Config] Please input the Station for Configuration!"
            telepot_bot.sendMessage(tt.chat_id, response)
        elif (str(text) not in info.line and str(text) != "Config" and str(text) != "config"):
            response = "[Config] --------- Invalid Input ---------\n[Config] ------- Please try again -------"
            telepot_bot.sendMessage(tt.chat_id, response)

    # ---------------- Config stage  = 2 ---------------- 
    # Check user input for the MTR station selection
    elif(hc.config_stage == 2):
        if str(text) in info.sta:              # check user input line vaild or not
            hc.config_stage = 3
            hc.user_sta_temp = str(text)
            response = "[Config] Please input the Destination for Configuration!"
            telepot_bot.sendMessage(tt.chat_id, response)
        elif (str(text) not in info.line and str(text) not in info.sta and str(text) != "Config" and str(text) != "config"):
            response = "[Config] --------- Invalid Input ---------\n[Config] ------- Please try again -------"
            telepot_bot.sendMessage(tt.chat_id, response)

    # ---------------- Config stage  = 3 ---------------- 
    # Check user input for the MTR Destination selection
    elif(hc.config_stage == 3):
        if str(text) in info.sta:           # check user input station valid or not
            hc.config_stage = 4
            hc.user_dest_temp = str(text)
            response = "[Config] Please type OK for confirm: \n"
            response = response + "Inputed Line:                        " + info.line[hc.user_line_temp] + "\n"
            response = response + "Inputed Station:                 " + info.sta[hc.user_sta_temp] + "\n"
            response = response + "Inputed Destination:         " + info.sta[hc.user_dest_temp] + "\n"
            telepot_bot.sendMessage(tt.chat_id, response)
        elif (str(text) not in info.line and str(text) not in info.sta and str(text) != "Config" and str(text) != "config"):
            response = "[Config] --------- Invalid Input ---------\n[Config] -------- Please try again --------"
            telepot_bot.sendMessage(tt.chat_id, response)
    
    # ---------------- Config stage  = 4 ---------------- 
    elif(hc.config_stage == 4):
        if(str(text) == "OK" or str(text) == "Ok" or str(text) == "ok"):
            hc.config_stage = 0
            hc.user_line = str(hc.user_line_temp)
            hc.user_sta = str(hc.user_sta_temp)
            hc.user_dest = str(hc.user_dest_temp)
            hc.station = hc.user_line+"-"+hc.user_sta
            hc.user_line_temp = ""
            hc.user_sta_temp = ""
            hc.user_dest_temp = ""
            response = "[Config] Configuration have been done!"
            telepot_bot.sendMessage(tt.chat_id, response)
            response = "[INFO] ---------- Information ----------\n"
            response = response + "Line:                    " + hc.user_line + "\n"
            response = response + "Station:             " + hc.user_sta + "\n"
            response = response + "Destination:     " + hc.user_dest + "\n"
            telepot_bot.sendMessage(tt.chat_id, response)
            MTR("Information")
    
    # Help function for user input
    elif(str(text) == "Help" or str(text) == "help"):
        response = "[Help] ---------- Information for Line and Description ----------"
        telepot_bot.sendMessage(tt.chat_id, response)
        response = "Line:           Description:\n"
        for x in range(len(info.list_line_key)):
            response = response + info.list_line_key[x] + " ----------  " + info.list_line_val[x] + "\n"
        telepot_bot.sendMessage(tt.chat_id, response)
        response = "[Help] --------- Information for Station and Description ---------"
        telepot_bot.sendMessage(tt.chat_id, response)
        response = "Station:        Description:\n"
        for x in range(5):
            if(x == 0):                         # Airport Express
                response = response +  "\n-------- Airport Express --------\n"
            elif(x == 1):                       # Tung Chung Line
                response = response +  "\n-------- Tung Chung Line --------\n"
            elif(x == 2):                      # Tuen Ma Line 
                response = response +  "\n--------- Tuen Ma Line ----------\n"
            elif(x == 3):                      # Tseung Kwan O Line
                response = response +  "\n------- Tseung Kwan O Line ------\n"
            elif(x == 4):                      # East Rail Line
                response = response +  "\n--------- East Rail Line --------\n"
            for i in range(len(info.list_sta_key[x])):
                response = response + info.list_sta_key[x][i] + "  ----------  " + info.list_sta_val[x][i] + "\n"
        telepot_bot.sendMessage(tt.chat_id, response)
    
    # reset
    text = ''
            

async def main():
    global telepot_bot
    bot = telegram.Bot(tt.tg_bot_id)

    #async with bot:
        #pass
        #print(await bot.get_me())
        #await bot.send_message(text="Hello", chat_id=tt.chat_id)

if __name__ == '__main__':
    try:
        MessageLoop(telepot_bot, MTR).run_as_thread()
        while(True):
            #asyncio.run(main())
            time.sleep(1)
    except:
        print("Error and Exit")