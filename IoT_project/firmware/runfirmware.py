import requestwebservice as rq
import controlhardware as gp
import time
def executa():
    time.sleep(60)
    response = rq.getNotes()
    msg = 'Finalizado'
    try:
    	if(1 == int(response['valor'])):
    		gp.enableGPIO()
    	if(0 == int(response['valor'])):
    		gp.desableGPIO()
    except:
    	msg = 'Sem notas de corte'
