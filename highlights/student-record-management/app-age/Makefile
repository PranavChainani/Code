CC=gcc
CFLAGS=-O2 -Wall -Wextra
TARGET=app_age
SRC=college.c dataset.c
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)
run: all
	./$(TARGET)
clean: ; rm -f $(TARGET)
