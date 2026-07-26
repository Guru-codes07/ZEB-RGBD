CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = zeb-rgbd

SRC = src/main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)