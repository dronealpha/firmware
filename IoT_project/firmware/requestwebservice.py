#Autor:Diego Silva
#Data:07/11/2019
#Descrição: Script para fazer request no webservice
import urequests
import json

#retorna dados do servidor
def getNotes():
    #faz requests, se a response for 200 ele retorna o json obtido
    response = urequests.get('http://192.168.15.15:5000/peganota/teste8266')
    if(response.status_code == 200):
        dados = str(response.text)
        dados = dados.replace("\n","")
        dados = dados.replace("[","")
        dados = dados.replace("]","")
        return json.loads(dados)
    else:#senão retorna json
        return '3'
