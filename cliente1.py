from socket import *


def main():


    nombreServidor = ''

    puertoServidor = 80

    socketCliente = socket(AF_INET,SOCK_STREAM)

    socketCliente.connect((nombreServidor,puertoServidor))
   
    sentence = input('Mensaje a enviar: ')

    socketCliente.send(sentence.encode())

    print("Esperando Respuesta ...")

    recibido = socketCliente.recv(1024)

    print('Respuesta del servidor:',recibido.decode())

        

    

main()
