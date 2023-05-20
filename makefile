CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS =

# list of source files
SERVER_SRC = server.c 
CLIENT_SRC = client.c

# list of object files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: server client

server: $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) -o server $(LDFLAGS)

client: $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) -o client $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f server client $(SERVER_OBJ) $(CLIENT_OBJ) 
	

