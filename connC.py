import socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 5555))
sentence = input('Enter lowercase sentences')
client.send(sentence.encode('utf-8'))
print('From receiver:')
print(client.recv(1024).decode('utf-8'))