CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lgtest -lgtest_main -pthread

TARGET = kraskal_app
TEST_TARGET = test_runner

all: $(TARGET)

$(TARGET): main.c kraskal.c
	$(CC) $(CFLAGS) main.c kraskal.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

test: test_kraskal.cpp kraskal.c
	gcc -c kraskal.c -o kraskal.o
	$(CXX) $(CXXFLAGS) test_kraskal.cpp kraskal.o $(LDFLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)


bench: benchmark.c kraskal.c
	$(CC) $(CFLAGS) benchmark.c kraskal.c -o benchmark_runner
	./benchmark_runner

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)