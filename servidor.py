from socket import *

def main():

    recieved = 0
    serverPort = 80
    connect = False

    serverSocket = socket(AF_INET,SOCK_STREAM)
    serverSocket.bind(('',serverPort))
    serverSocket.listen()
    

    print("El servidor esta listo")

    while(True):
    
        
        print("Esperando Clientes ...")
        connectionSocket, addr = serverSocket.accept()
        print("Conectado a " ,addr[0],":",addr[1])
        connect = True
    
    

        while (connect == True):

            print("Esperando Mensaje ...")

            sentence = connectionSocket.recv(1024).decode()

            print("Mensaje de" , addr , ":" , sentence)

            sentence = input("Mensaje a enviar: ")

            connectionSocket.send(sentence.encode())

            connect = False



            

main()
