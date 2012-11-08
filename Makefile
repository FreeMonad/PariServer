.PHONY: all server server_clean client client_clean clean uberclean

CWD = $(shell pwd)

CLIENT = $(CWD)/client

SERVER = $(CWD)/server

all: server client

server:
	make -C $(SERVER)
	mv ./server/parisrv-dyn ./parisrv

client:
	make -C $(CLIENT)
	mv ./client/pari_client ./pari_client

server_clean:
	make -C $(SERVER) clean

client_clean:
	make -C $(CLIENT) clean

clean: server_clean client_clean

uberclean: clean
	rm -f ./parisrv
	rm -f ./pari_client
	rm -f ./pari_socket
