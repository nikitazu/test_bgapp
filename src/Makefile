all: app
app: bin app.c
	cc app.c -o ../bin/app
bin: app.c
	mkdir -p ../bin
clean:
	rm -rf ../bin

