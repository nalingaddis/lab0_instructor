# The compiler for C programs
CC = gcc

# Compiler Flags
#  -g     adds debugging information to the executable
#  -Wall  turns on most, but not all compiler warnings
CFLAGS = -g -Wall

# Remove Command
RM = rm -rf

TARGET = MatrixMultiplier
TESTFILE = tests

all: $(TARGET)

$(TARGET): $(TARGET).c $(TESTFILE).c $(TARGET).h
	$(CC) $(CFLAGS) -o $(TESTFILE) $(TARGET).c $(TESTFILE).c

clean:
	$(RM) $(TESTFILE) *.dSYM