CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Isrc
GTEST_FLAGS = -I/usr/local/include -I/opt/homebrew/include -L/usr/local/lib -L/opt/homebrew/lib -lgtest -lgtest_main -pthread

.PHONY: all clean test bench run


all:
	$(CC) $(CFLAGS) src/kraskal.c src/main.c -o kraskal_prog


run: all
	./kraskal_prog


test:
	$(CXX) $(CFLAGS) -std=c++17 src/kraskal.c tests/test_kraskal.cpp $(GTEST_FLAGS) -o test_runner
	./test_runner

bench:
	$(CC) $(CFLAGS) src/kraskal.c bench/benchmark.c -o bench_runner
	./bench_runner

clean:
	rm -f kraskal_prog test_runner bench_runner