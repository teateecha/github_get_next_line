AR = ar rcs
OUTPUT = output
OBJS = main.o get_next_line.o get_next_line_utils.o
LIB = get-next-line/get_next_line.h
CC = cc
CFLAG = -g -Wall -Wextra -Werror 

all: $(OUTPUT)

$(OUTPUT): $(OBJS) 
	$(CC) $(OBJS) -o $(OUTPUT)

#compile .c to objectfiles .o
main.o: main.c $(LIB)
	$(CC) $(CFLAG) -c main.c -o $@

get_next_line_utils.o: get-next-line/get_next_line_utils.c $(LIB)
	$(CC) $(CFLAG) -c get-next-line/get_next_line_utils.c -o get_next_line_utils.o
 
get_next_line.o: get-next-line/get_next_line.c $(LIB)
	$(CC) $(CFLAG) -c get-next-line/get_next_line.c -o get_next_line.o

#remove object files
clean:
	rm -f $(OBJS)

#remove object files and the library
fclean: clean
	rm -f $(OUTPUT)

#rebuild. firs remove  and then build again
re: fclean all

#rell which are commands and not files:
.PHONY: all clean fclean re
