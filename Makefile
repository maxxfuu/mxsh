CC = clang
CFLAGS = -Wall -Wextra -Werror -Iheader
LDFLAGS = 

SRC_DIR = src
HEADER_DIR = header
OBJ_DIR = obj
BIN = shell

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

$(BIN): $(OBJS)  # Ensure objects are built before linking
	$(CC) $(LDFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(BIN)

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
