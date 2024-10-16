CC = gcc
CFLAGS = -Wall
TARGET = text_analyzer
OBJECTS = main.o word_count.o line_count.o frequency.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

word_count.o: word_count.c word_count.h
	$(CC) $(CFLAGS) -c word_count.c

line_count.o: line_count.c line_count.h
	$(CC) $(CFLAGS) -c line_count.c

frequency.o: frequency.c frequency.h
	$(CC) $(CFLAGS) -c frequency.c

clean:
	rm -f $(OBJECTS) $(TARGET)
