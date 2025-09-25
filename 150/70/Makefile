CXX := g++
CXXFLAGS := -std=c++20 -g -O0 -fno-omit-frame-pointer -fsanitize=address

TARGET := main
SRC := main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
