#include "String.h"
#include <cstring>

using namespace std;

size_t String::objectCount = 0;

String::String() : String(80) {}

String::String(size_t size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    ++objectCount;
}

String::String(const char* inputStr) {
    length = strlen(inputStr);
    str = new char[length + 1];
    strcpy_s(str, length + 1, inputStr);
    ++objectCount;
}

String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str);
    ++objectCount;
}

String::String(String&& other) noexcept : str(other.str), length(other.length) {
    other.str = nullptr;
    other.length = 0;
    ++objectCount;
}

String::~String() {
    delete[] str;
    --objectCount;
}

void String::input() {
    char buffer[256];
    cout << "Enter a string\n\n--> ";
    cin.getline(buffer, 256);
    delete[] str;
    length = strlen(buffer);
    str = new char[length + 1];
    strcpy_s(str, length + 1, buffer);
}

void String::output() const {
    cout << str << endl;
}

size_t String::getObjectCount() {
    return objectCount;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] str;
        str = other.str;
        length = other.length;
        other.str = nullptr;
        other.length = 0;
    }
    return *this;
}