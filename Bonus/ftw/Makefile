TARGET=ftw

$(TARGET): ftw.o functions.o error.o
	$(CC) -g -o $@ $^ 

ftw.o: ftw.c
	$(CC) -g -c ftw.c

functions.o: functions.c
	$(CC) -g -c functions.c

error.o: error.c
	$(CC) -g -c error.c

clean:
	rm -f ftw.o  functions.o  error.o $(TARGET)

