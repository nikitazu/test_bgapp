CC=cc
CFLAGS=-Wall
SOURCES=app.c
EXECUTABLE=app

all: $(EXECUTABLE)

app: bin $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o ../bin/$(EXECUTABLE)

bin: app.c
	mkdir -p ../bin

clean:
	rm -rf ../bin

