CXX := g++
CXXFLAGS := -std=c++20 -g -O0 -fno-omit-frame-pointer -fsanitize=address

TARGET := temp
SRC := template.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
