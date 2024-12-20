CC = gcc
CFLAGS = -Wall
SRC = main.c src\cartas.c src\io.c src\utils.c
INCLUDE = -Iinclude
OUTPUT = supertrunfo.exe

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(OUTPUT)

clean:
	@if exist $(OUTPUT) del $(OUTPUT)

run: $(OUTPUT)
	.\$(OUTPUT)