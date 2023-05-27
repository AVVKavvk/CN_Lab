import socket
import os

obj = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print ("Socket created successfully.")

port = 5500
host = 'localhost'

obj.bind((host, port))

obj.listen(10)
print('Server is listening...')
# print(" efjgrghdj")
while True:
    client, addr = obj.accept()
    print('Connected with ', addr)

    # data = client.recv(1024)
    # print(data.decode())
    file = open('serverfile.txt', 'rb')

    count =1 

    line = file.read(1024)
    while(line):
        client.send(line)
        line = file.read(1024)
        count+=1
    
    file.close()
    print('File has been transferred successfully.')
    print("number of lines ",count)

    client.close()
    print("connection ended")