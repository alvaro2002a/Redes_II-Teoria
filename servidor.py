from socket import *

def main():

    recieved = 0
    serverPort = 12000
    serverSocket = socket(AF_INET,SOCK_STREAM)
    serverSocket.bind(('',serverPort))
    serverSocket.listen(2)

    print("El servidor esta listo")

    while True:

        connectionSocket, addr = serverSocket.accept()

        sentence = connectionSocket.recv(1024).decode()

        connectionSocket, addr = serverSocket.accept()


        

main()
