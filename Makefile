CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic -std=c99 -g -D_DEFAULT_SOURCE
BIN = myfind
BIN_OBJS = myfind.o
VPATH = src

all: $(BIN)

$(BIN): $(BIN_OBJS)

clean:
	rm -f -d -r $(BIN) $(BIN_OBJS) myfind f.txt myfind.txt tests/test html latex

test:
	tests/test.sh

doc:
	doxygen
