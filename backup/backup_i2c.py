#!/usr/bin/python3
# -*- coding: utf-8 -*-

import smbus as sm

address = 0x50  #ssss
bus_num = 1
bus = sm.SMBus(bus_num)

def writeNumber(value):
    bus.write_byte(address, value)
    return

def readNumber():
    number = bus.read_byte(address)
    return number

def readDouble():
    str_num = ""
    str_num_list = bus.read_i2c_block_data(address,0)
    for i in str_num_list:
        if(i == 255):
            break
        else:
            str_num += chr(i)
    actual_num = float(str_num) 
    return actual_num
    
     

def readString():
    sentence = ""
    asc = bus.read_i2c_block_data(address,0)
    for i in asc:
        if(i == 255):
            break
        else:
            sentence += chr(i)
    return sentence
    
while True:
    data = 12
    writeNumber(data)
    num = readDouble()
    #sen = readString()

    print("read data:", num)