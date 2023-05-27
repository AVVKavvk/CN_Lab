import socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('socket created')
server.bind(('localhost', 5555)) 
server.listen(5) 
print('waiting for connections')
o=True
while o: 
 client_socket, addr = server.accept()
 sentence = client_socket.recv(1024).decode('utf-8')
 capital_sentence = sentence.upper()
 print('Connected to', addr)
 print('Message from client is:', capital_sentence)
 client_socket.send('Got your message, Thank you'.encode('utf-8'))
 client_socket.close()
 print('Connection is ended from',addr)
 o=False