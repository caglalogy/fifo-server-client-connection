# fifo-server-client-connection
Simple server-client connection with request and response fifos. 

The above code implements a simple server using named pipes (FIFOs) in C language. 
It creates two FIFOs with names "myfifo" and "myfifo2". The server waits for requests on the "myfifo" named pipe. When a request is received, it prints the request message and sends a response back through the "myfifo2" pipe, based on the received message. If the message is "hi", it sends "hello!", if the message is "hola", it sends "hola mi amigo!", otherwise it sends "error". If the user sends a SIGINT signal (usually by pressing Ctrl+C), the program cleans up by removing the two named pipes and exits.


In this program, the FIFOs work unidirectionally. The client program writes messages to the REQUEST_FIFO and reads responses from the RESPONSE_FIFO, while the server program writes responses to the RESPONSE_FIFO and reads requests from the REQUEST_FIFO. This creates a unidirectional flow of information between the client and the server.
This ensures that the server and client are not trying to read and write the same FIFO at the same time, which provides a basic level of synchronization.

## To run

After downloading code on your computer, unzip it and specify the folder. In the folder which contains the files above, open terminal.

`make`

This will make your program compiled. To run it, you should open one more terminal. On each terminal, you should input these seperate commands: 

`./server`

`./client`

On client side, enter trying 'hi', 'hola' and any other strings.
Server will respond it and you will see responses on client side again.
