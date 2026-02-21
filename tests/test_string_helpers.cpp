#include "Windows.h"
#include "plugin.h"
#include <cstdint>

// Mock MixSets for ini_parser.hpp
class MixSets {
public:
    static bool bParsePreserveComments;
};
bool MixSets::bParsePreserveComments = false;

#define MIXSETS_H
#define COMMON_H
enum languages { PT, EN };

#include "../MixSets/IniReader/IniReader.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void test_strcmp() {
    std::cout << "Testing strcmp..." << std::endl;
    assert(strcmp("abc", "abc", true) == 0);
    assert(strcmp("abc", "ABC", true) != 0);
    assert(strcmp("abc", "ABC", false) == 0);
    assert(strcmp("abc", "abd", true) < 0);

    // strncmp version
    assert(strcmp("abc", "abd", 2, true) == 0);
    assert(strcmp("abc", "ABC", 2, false) == 0);
}

void test_compare() {
    std::cout << "Testing compare..." << std::endl;

    // std::string version
    assert(compare(std::string("abc"), std::string("abc"), true) == 0);
    assert(compare(std::string("abc"), std::string("abd"), true) < 0);
    assert(compare(std::string("abc"), std::string("ABC"), false) == 0);

    // Desired behavior: lexicographical
    std::cout << "  Checking lexicographical behavior..." << std::endl;
    assert(compare(std::string("a"), std::string("aa"), true) < 0);
    assert(compare(std::string("aa"), std::string("a"), true) > 0);
    assert(compare(std::string("b"), std::string("aa"), true) > 0); // "b" > "aa" lexicographically

    // std::string version with num
    std::cout << "  Checking compare with num..." << std::endl;
    assert(compare(std::string("abc"), std::string("abd"), 2, true) == 0);
    assert(compare(std::string("abc"), std::string("ab"), 2, true) == 0);

    // const char* version
    std::cout << "  Checking const char* version..." << std::endl;
    assert(compare("abc", "abc", true) == 0);
    assert(compare("b", "aa", true) > 0);
}

void test_starts_with() {
    std::cout << "Testing starts_with..." << std::endl;
    assert(starts_with("abcdef", "abc", true) == true);
    assert(starts_with("abcdef", "ABC", false) == true);
    assert(starts_with("abcdef", "abd", true) == false);
    assert(starts_with("a", "abc", true) == false);
    assert(starts_with("", "abc", true) == false);
    assert(starts_with("abc", "", true) == true);
}

void test_ends_with() {
    std::cout << "Testing ends_with..." << std::endl;
    assert(ends_with("abcdef", "def", true) == true);
    assert(ends_with("abcdef", "DEF", false) == true);
    assert(ends_with("abcdef", "deg", true) == false);

    std::cout << "  Testing edge cases for ends_with..." << std::endl;
    assert(ends_with("a", "abc", true) == false);
    assert(ends_with("", "abc", true) == false);
    assert(ends_with("abc", "", true) == true);
}

int main() {
    test_strcmp();
    test_compare();
    test_starts_with();
    test_ends_with();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
