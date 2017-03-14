CC=cc
CFLAGS=-Wall

all: app
app: bin app.c
	$(CC) $(CFLAGS) app.c -o ../bin/app
bin: app.c
	mkdir -p ../bin
clean:
	rm -rf ../bin

