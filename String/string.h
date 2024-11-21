#pragma once
#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* str;
    size_t length;
    static size_t objectCount;

public:
    String();
    explicit String(size_t size);
    String(const char* inputStr);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    void input();
    void output() const;
    static size_t getObjectCount();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
};

#endif