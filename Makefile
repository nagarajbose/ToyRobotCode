# Compiler settings
CC = g++
CFLAGS = -Wall -Werror -std=c++11

# File and directory settings
SRCDIR = ./src
INCDIR = ./include
BUILDDIR = ./build

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Binary file
TARGET = $(BUILDDIR)/ToyRobotCode

# Rules
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)