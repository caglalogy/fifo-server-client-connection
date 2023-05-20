#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Define the names of the two named pipes
#define REQUEST_FIFO "myfifo"
#define RESPONSE_FIFO "myfifo2"

int main(){
    int req_fd, resp_fd;
    char buf[1024];
    char input[1024];

     while(1){
         // Prompt the user for a message
        printf("Enter message: ");

         // Read in the user's message
        fgets(input, sizeof(input), stdin);

         // Strip the trailing newline character from the input
        input[strlen(input) - 1] = '\0';

         // Open the request FIFO for writing
        req_fd = open(REQUEST_FIFO, O_WRONLY);

         // Write the user's message to the request FIFO
        write(req_fd, input, sizeof(input));

         // Close the request FIFO
        close(req_fd);

         // Open the response FIFO for reading
        resp_fd = open(RESPONSE_FIFO, O_RDONLY);

         // Read the response from the response FIFO
        read(resp_fd, buf, sizeof(buf));

         // Print the response to the terminal
        printf("%s\n", buf);
        
         // Close the response FIFO
        close(resp_fd);
    }
     // Exit with success
    return 0;
}