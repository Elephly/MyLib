.PHONY: all
.PHONY: clean
.PHONY: install

.PHONY: nnl
.PHONY: experimental
.PHONY: test

# Assert build target except in case of clean. If clean is a goal, proceed with
# cleaning entire bin/ directory.
ifeq ($(filter clean,$(MAKECMDGOALS)),)
  ifndef TARGET
    $(error TARGET is not set)
  endif
endif

include $(TARGET)

NNL_ROOT = nnl
EXPERIMENTAL_ROOT = experimental
TEST_ROOT = test

NNL_SRC_DIR = $(NNL_ROOT)/$(SRC_LANG)/src
EXPERIMENTAL_SRC_DIR = $(EXPERIMENTAL_ROOT)
TEST_SRC_DIR = $(TEST_ROOT)/$(SRC_LANG)/src

NNL_SRC_FILES = $(shell find $(NNL_SRC_DIR) -name *$(SRC_EXT))
EXPERIMENTAL_SRC_FILES = $(shell find $(EXPERIMENTAL_SRC_DIR) -name *$(SRC_EXT))
TEST_SRC_FILES = $(shell find $(TEST_SRC_DIR) -name *$(SRC_EXT))

NNL_BIN_DIR = bin/$(NNL_ROOT)/$(SRC_LANG)
EXPERIMENTAL_BIN_DIR = bin/$(EXPERIMENTAL_ROOT)/$(SRC_LANG)
TEST_BIN_DIR = bin/$(TEST_ROOT)/$(SRC_LANG)

BIN_DIRS += $(NNL_BIN_DIR)
BIN_DIRS += $(EXPERIMENTAL_BIN_DIR)
BIN_DIRS += $(TEST_BIN_DIR)
ifndef TARGET
  BIN_DIRS += bin/
endif

all: nnl

nnl: $(NNL_BIN_DIR) $(NNL_SRC_FILES)
	$(CC) -d $(NNL_BIN_DIR) $(NNL_SRC_FILES)

experimental: $(EXPERIMENTAL_BIN_DIR) $(EXPERIMENTAL_SRC_FILES)
	$(CC) -d $(EXPERIMENTAL_BIN_DIR) $(EXPERIMENTAL_SRC_FILES)

test: $(TEST_BIN_DIR) $(TEST_SRC_FILES)
	$(CC) -d $(TEST_BIN_DIR) $(TEST_SRC_FILES)

clean:
	rm -rf $(BIN_DIRS)

$(NNL_BIN_DIR):
	mkdir -p $(NNL_BIN_DIR)

$(EXPERIMENTAL_BIN_DIR):
	mkdir -p $(EXPERIMENTAL_BIN_DIR)

$(TEST_BIN_DIR):
	mkdir -p $(TEST_BIN_DIR)
