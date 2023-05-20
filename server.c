#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
 #define REQUEST_FIFO "myfifo"
#define RESPONSE_FIFO "myfifo2"

 // Function to delete FIFOs
void cleanup() {
    remove(REQUEST_FIFO);
    remove(RESPONSE_FIFO);
}

 // Function to handle SIGINT signal
void handle_sigint(int sig) {
    cleanup();
    exit(0);
}

 int main(){

    int req_fd, resp_fd;
    char buf[1024];

     // Create FIFOs
    mkfifo(REQUEST_FIFO, 0777);
    mkfifo(RESPONSE_FIFO, 0777);

     // Set up signal handler for SIGINT
    signal(SIGINT, handle_sigint);

     while(1){
        // Open request FIFO for reading
        req_fd = open(REQUEST_FIFO, O_RDONLY);

        // Read from request FIFO
        read(req_fd, buf, sizeof(buf));

        // Print received message
        printf("Received: %s\n", buf);

        // Close request FIFO
        close(req_fd);

         // Open response FIFO for writing
        resp_fd = open(RESPONSE_FIFO, O_WRONLY);

        // Check message and send response
        if(strcmp(buf, "hi") == 0){
            write(resp_fd, "hello!", strlen("hello!"));
        }
        else if (strcmp(buf, "hola") == 0){
            write(resp_fd, "hola mi amigo!", sizeof("hola mi amigo!"));
        }
        else{
            write(resp_fd, "error", sizeof("error"));
        }

        // Close response FIFO
        close(resp_fd);
    }
    return 0;  
}