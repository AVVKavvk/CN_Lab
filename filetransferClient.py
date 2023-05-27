import socket
import os
obj = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print ("Socket created successfully.")

port = 5500
host = 'localhost'

obj.connect((host, port))
print('requesting connection')

# msg = input("message from client : ")
# obj.send(msg.encode())

file = open("clientfile.txt", "wb")
try:
    line = obj.recv(1024)
    print(line)

    while(line):
        file.write(line)
        line = obj.recv(1024)
    print('File has been received successfully.')
    file.close()
except:
    print("some error occured")


obj.close()
print('Connection Closed.')