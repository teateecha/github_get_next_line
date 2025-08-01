CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c get-next-line/get_next_line.c get-next-line/get_next_line_utils.c
NAME = output

BUFFER_SIZES = 0 1 10 10000
FILES = empty.txt txt.txt lorem.txt

all: $(foreach bs,$(BUFFER_SIZES),$(foreach f,$(FILES),test_bs$(bs)_$(f)))

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

define TEST_template
test_bs$(1)_$(2): $(NAME)
	@echo "=============================="
	@echo "Testing BUFFER_SIZE=$(1) on file $(2)"
	@echo "=============================="
	@$(CC) $(CFLAGS) -DBUFFER_SIZE=$(1) -o $(NAME) $(SRCS)
	@valgrind --leak-check=full --error-exitcode=42 ./$(NAME) $(2)
	@echo "======== END TEST ============"
	@echo ""
endef

$(foreach bs,$(BUFFER_SIZES),$(foreach f,$(FILES),$(eval $(call TEST_template,$(bs),$(f)))))

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all