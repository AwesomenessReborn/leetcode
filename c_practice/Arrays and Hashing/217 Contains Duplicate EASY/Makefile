
# Define the source files
SRCS = main.c

# Define the header files (not strictly necessary in this case, but useful for dependencies)
HEADERS = uthash.h

# Define the output executable
TARGET = exec

# Rule to build the target executable
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Rule to clean the build files
clean:
	rm -f $(TARGET)