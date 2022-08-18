CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
DEPS = include/my_printf.h
OBJFILES = src/main.o src/my_printf.o 

TARGET = my_printf
all: $(TARGET)
$(TARGET): $(OBJFILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)
	
.PHONY: clean
clean:
	rm -f src/*.o $(TARGET)
