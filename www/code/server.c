#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#include "utils.h"
#include <asm-generic/socket.h>

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1, bytesReceived = 0;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    FILE *file;

    /* Crear descriptor de fichero de socket */
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Adjuntar socket al puerto 80 */
    if ((setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))))
    {
        perror("setsockport");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    /* Vincular socket al puerto 80 */
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    /* Abrir un archivo para los datos recibidos */
    file = fopen("archivo_recibido", "wb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return -1;
    }

    while ((bytesReceived = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytesReceived, file);
    }

    if (bytesReceived < 0) {
        perror("recv");
    }

    printf("Archivo recibido y guardado como 'archivo_recibido'\n");

    fclose(file);
    close(new_socket);
    close(server_fd);
    return 0;
}
