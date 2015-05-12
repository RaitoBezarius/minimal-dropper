CC = gcc48
CFLAGS = -s -Os -Bdynamic -lc

TARGET = dropper

SRCS = dropper.c dynamic.c
INCLUDES = dynamic.h

all: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	$(RM) $(TARGET)
