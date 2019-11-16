#Autor:Diego Silva
#Data:05/11/2019
#Descrição:Script para subir serviço rest

#importando bibliotecas para criação de rotas, trativa com json e captura de requests
from flask import Flask, jsonify, request

#criando instancia do objeto para o uso dos recursos do falsk
app = Flask(__name__)


#metodo para apagar nota
def deletanota(nota):
    for x in range(len(notascorte)):
        if notascorte[x]['dispositivo']==nota:
            retornoinfo = notascorte[x]
            del notascorte[x]
            break
    return retornoinfo


#lista para armazenar json
notascorte = []

#letreiro para exibir versão do softare
@app.route('/index')
def index():
    return 'IoT Connector - Versão 1.0.0.0\n '

#rota para post de dados
@app.route('/cadastranotas', methods=['POST'])
def cadastraNota():

    #pega o json enviadoe faz um append para lista
    request_dados = request.get_json()
    nova_nota = {
        'dispositivo': request_dados['dispositivo'],
        'valor': request_dados['valor']
        }
    notascorte.append(nova_nota)
    return jsonify(nova_nota)

#retorna o json com a nota de corte do dispositivo e remove da lista
@app.route('/peganota/<string:dipositivo>', methods=['GET'])
def pegaNota(dipositivo):

    tamanho=len(notascorte)
    if (tamanho==0 and notascorte[tamanho] ==''):
        return jsonify({"dispositivo":"nulo","valor":"nulo"})
    else:
        return jsonify(deletanota(dipositivo))

@app.route('/notaslista', methods=['GET'])
def retornaNotas():
    return jsonify(notascorte)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
    

