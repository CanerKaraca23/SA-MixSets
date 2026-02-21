CXX = g++
CXXFLAGS = -std=c++17 -I. -I../MixSets/IniReader

all: test

test: test_string_helpers
	./test_string_helpers

test_string_helpers: test_string_helpers.cpp ../MixSets/IniReader/IniReader.h Windows.h plugin.h
	$(CXX) $(CXXFLAGS) test_string_helpers.cpp -o test_string_helpers

clean:
	rm -f test_string_helpers

.PHONY: all test clean
