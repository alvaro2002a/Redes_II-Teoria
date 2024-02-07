from socket import *


def main():


    nombreServidor = ''

    puertoServidor = 12000

   
    while True:

        socketCliente = socket(AF_INET,SOCK_STREAM)

        socketCliente.connect((nombreServidor,puertoServidor))

        sentence = input('Mensaje a enviar: ')

        socketCliente.send(sentence.encode())

        recibido = socketCliente.recv(1024)

        print('Respuesta del servidor:',recibido.decode())

        socketCliente.close()

    

main()
