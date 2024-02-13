from socket import *

def main():

    recieved = 0
    serverPort = 12004
    serverSocket = socket(AF_INET,SOCK_STREAM)
    serverSocket.bind(('192.168.137.209',serverPort))
    serverSocket.listen(1)

    print("El servidor esta listo")

    connectionSocket, addr = serverSocket.accept()
    
    print(f"Conexión establecida con: {addr[0]}:{addr[1]}")


    while True:

        envio = input("Mensaje a enviar: ")

        connectionSocket.send(envio.encode())


        sentence = connectionSocket.recv(1024).decode()

        print("Respuesta: " , sentence)
        
        


        

main()
