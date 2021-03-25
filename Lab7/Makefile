TARGET=Lab7

$(TARGET): Lab7.o error.o
	$(CC) -o $@ $^ 

Lab7.o:  Lab7.c
error.o: error.c

clean:
	rm -f lab7o error.o $(TARGET)
