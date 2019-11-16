#Autor:Diego Silva
#Data:03/11/2019
#Descrição: Webservice Temperatura

from flask import Flask, request, jsonify

app = Flask(__name__)

temperatura=[]


@app.route('/')
def index():
    return "Bem Vindo UBB - plataforma d eintegração IoT\n Vesão:1.0.0.0\n"


@app.route('/temperatura', methods=['POST'])
def postTemperatua():
    dadostemp={
        'device': request.json['device'],
        'value': request.json['value']
        }
    temperatura.append(dadostemp)
    return jsonify({'temperatura' : dadostemp})


@app.route('/temperatura', methods=['GET'])
def getTemperatua():
    return jsonify({'temperatura' : temperatura})


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5001)
