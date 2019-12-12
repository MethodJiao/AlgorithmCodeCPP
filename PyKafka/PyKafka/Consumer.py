from kafka import KafkaConsumer
import time
consumer = KafkaConsumer('test',group_id='123', bootstrap_servers=['39.105.126.10:9092'])

while True:
    msg = consumer.poll(timeout_ms=5)   #从kafka拉取消息
    print(msg)
    time.sleep(1)
