from kafka import KafkaProducer
import json
msg_dict = {
    "sleep_time": 10,
    "msg": "Hello World"
}
msg = json.dumps(msg_dict)

producer = KafkaProducer(bootstrap_servers=['39.105.126.10:9092'])  #此处ip可以是多个['0.0.0.1:9092','0.0.0.2:9092','0.0.0.3:9092' ]
for i in range(3):
    producer.send('test', msg.encode('utf-8'))
producer.close()
