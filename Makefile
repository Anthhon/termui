#!/bin/bash

CC = gcc
CFLAGS = -Wall -fPIC
LIBRARY_DIR = ./termui
OUTPUT_DIR = ./bin
LIBRARY_NAME = libtermui.a

# Get all .c files in LIBRARY_DIR
SOURCES := $(wildcard $(LIBRARY_DIR)/*.c)

# Generate corresponding object files in OUTPUT_DIR
OBJECTS := $(patsubst $(LIBRARY_DIR)/%.c, $(OUTPUT_DIR)/%.o, $(SOURCES))

all: $(OUTPUT_DIR)/$(LIBRARY_NAME)

$(OUTPUT_DIR)/$(LIBRARY_NAME): $(OBJECTS)
	ar rcs $@ $^

# Compile .c files into .o files in OUTPUT_DIR
$(OUTPUT_DIR)/%.o: $(LIBRARY_DIR)/%.c
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OUTPUT_DIR)/$(LIBRARY_NAME) $(OBJECTS)

install: $(OUTPUT_DIR)/$(LIBRARY_NAME)
	sudo cp $(OUTPUT_DIR)/$(LIBRARY_NAME) /usr/local/lib
	sudo cp $(LIBRARY_DIR)/*.h /usr/local/include/termui
	sudo ldconfig

