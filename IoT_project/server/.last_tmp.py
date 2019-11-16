#Autor:Diego Silva
#Data:05/11/2019
#Descrição:Script para subir serviço rest

#importando bibliotecas para criação de rotas, trativa com json e captura de requests
from flask import Flask, jsonify, request

#criando instancia do objeto para o uso dos recursos do falsk
app = Flask(__name__)


#lista para armazenar json
notascorte = []

@app.route('/index')
def index():
    return 'IoT Connector - Versão 1.0.0.0\n '

@app.route('/cadastranotas', methods=['POST'])
def cadastraNota():
    request_dados = request.get_json()
    nova_nota = {
        'dispositivo': request_dados['dispositivo'],
        'valor': request_dados['valor']
        }
    notascorte.append(nova_nota)
    return jsonify(nova_nota)


@app.route('/peganota', methods=['GET'])
def pegaNota():
    return jsonify(notascorte)


if __name__ == '__main__':
    app.run(host='0.0.0.0')