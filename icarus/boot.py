# This file is executed on every boot (including wake-boot from deepsleep)
#import esp
#esp.osdebug(None)
import gc
import webrepl
from wificonnect import *

cont = 0
while(cont < 100):
    CheckMessages()
    cont = cont+1
webrepl.start()
gc.collect()
