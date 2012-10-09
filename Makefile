.PHONY: all server client clean

all: server client

server: parisrv-dyn

parisrv-dyn:
	make -C ./server
	mv ./server/parisrv-dyn ./parisrv

client: pari_client

pari_client:
	make -C ./client
	mv ./client/pari_client ./pari_client

clean:
	make -C ./server clean
	rm -f ./parisrv
	rm -f ./pari_client
	rm -f ./pari_socket