import runfirmware
import controlhardware as gp

def runtask():
	gp.activeStation()
	while(True):
		runfirmware.executa()
		