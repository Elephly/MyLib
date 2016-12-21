.PHONY: all
.PHONY: clean
.PHONY: install

BIN_DIR = bin

SRC_FILES = $(shell find nnl/java/src -name *.java)

all: $(BIN_DIR)
	javac -d $(BIN_DIR) $(SRC_FILES)

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
