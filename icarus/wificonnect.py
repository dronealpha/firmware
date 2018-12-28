#
#Autor:Diego Silva
#Data:18/12/2018
#Descrição: Firmware para comunicação em rede

import network
import time
from socket import *
from machine import Pin

#pilha de erros que regista ACK ou NACK para conexão coms ervidor
stackerro = []

#instanciando classes de controle do hardware/comunicação via rede
ap_if = network.WLAN(network.AP_IF)
sta_if = network.WLAN(network.STA_IF)
pin  = Pin(0, Pin.OUT)

#metodo para connectar no wifi
def ActiveStationConnection():
    ap_if.active(False)
    sta_if.active(True)
    sta_if.connect('Casa21','Dlink22a4')

##metodo para desconnectar do wifi
def ActiveStationDisconnect():
    sta_if.disconnect()

#desliga porta
def DownPortGPIO():
     pin.value(0)

def UpPortGPIO():
     pin.value(1)

#metodo para comunicação com server
def ConnectServer():
    soc = socket(AF_INET, SOCK_STREAM)
    soc.connect(("192.168.0.112",5004))
    soc.send(b'Ky75Ad;A002\n')
    ad = soc.recv(1024)
    soc.send(b'K000\n')
    time.sleep(10)
    soc.close()
    cut = ad.decode("utf-8")
    if(cut=="A000"):
         DownPortGPIO()
    elif(cut=="A001"):
         UpPortGPIO()
    else:
         stackerro.append("NACK")
    #return ad.decode("utf-8")


def CheckMessages():
     ActiveStationConnection()
     time.sleep(5)
     msg="ACK"
     try:
          ConnectServer()
     except:
          msg="NACK"
     finally:
          stackerro.append(msg)
          #print(stackerro[cont])
          time.sleep(5)
          ActiveStationDisconnect()
          time.sleep(120)


CheckMessages()