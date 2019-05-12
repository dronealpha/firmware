import paho.mqtt.client as mqtt
import os, urlparse

# Define event callbacks
def on_connect(client, userdata, flags, rc):
    print("rc: " + str(rc))

def on_message(client, obj, msg):
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload))

def on_publish(client, obj, mid):
    print("mid: " + str(mid))

def on_subscribe(client, obj, mid, granted_qos):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))

def on_log(client, obj, level, string):
    print(string)

mqttc = mqtt.Client()
# Assign event callbacks
mqttc.on_message = on_message
mqttc.on_connect = on_connect
mqttc.on_publish = on_publish
mqttc.on_subscribe = on_subscribe

# Uncomment to enable debug messages
#mqttc.on_log = on_log

# Parse CLOUDMQTT_URL (or fallback to localhost)
url_str = os.environ.get('CLOUDMQTT_URL', 'mqtt://postman.cloudmqtt.com:18711')
url = urlparse.urlparse(url_str)
topic = url.path[1:] or '/topic/qos0'

# Connect
#mqttc.username_pw_set(url.username, url.password)
mqttc.username_pw_set('zoagkpqy','JVA47ugnhYuz')
mqttc.connect(url.hostname, url.port)


print("Connect with server: ")
print("mqtt://postman.cloudmqtt.com:18711")
ac = int(input("On -> 1 | Off -> 2:"))

#mqttc.connect("mqtt://postman.cloudmqtt.com", "18711")
# Start subscribe, with QoS level 0
mqttc.subscribe(topic, 0)

# Publish a message
if(ac==1):
	mqttc.publish(topic, "1")
elif(ac==2):
	mqttc.publish(topic, "22")
# Continue the network loop, exit when an error occurs
rc = 0
#while rc == 0:
rc = mqttc.loop()
#print("rc: " + str(rc))
#mqttc.close

