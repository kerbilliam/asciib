CC=gcc
OPTIMIZATION=-O2
INSTALL-PATH=${HOME}/.local/bin


all: atob.c btoa.c
	$(CC) $(OPTIMIZATION) -o atob atob.c
	$(CC) $(OPTIMIZATION) -o btoa btoa.c

local-install: atob btoa
	mv atob btoa $(INSTALL-PATH)

clean:
	rm -f atob btoa
