SRC_FILES := $(wildcard src/*.c)
OBJ_FILES := $(addprefix obj/,$(notdir $(SRC_FILES:.c=.o)))
BASE_DIR=`pwd`
BIN_DIR=$(BASE_DIR)/bin
SRC_DIR=$(BASE_DIR)/src
MKDIRS := $(shell mkdir -p obj bin)


all: citysum

citysum: obj/city.o obj/citysum.o
		$(MKDIRS)
		gcc -o bin/$@ $^

obj/%.o: src/%.c
	gcc -fPIC -Wall -Wextra -O2 -g -MMD -c -o $@ $<

-include $(OBJ_FILES:.o=.d)

clean:
	@rm -rf bin obj

.PHONY: all clean test
