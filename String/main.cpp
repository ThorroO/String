#include "String.h"

using namespace std;

int main() {
    // Демонстрація конструктора за замовчуванням
    String s1;
    cout << "Enter a string for s1:" << endl;
    s1.input();
    cout << "You entered: ";
    s1.output();

    // Демонстрація конструктора з параметром (C-style string)
    String s2("Hello, world!");
    cout << "String s2 initialized with \"Hello, world!\": ";
    s2.output();

    // Демонстрація конструктора копіювання
    String s3(s2);
    cout << "String s3 (copied from s2): ";
    s3.output();

    // Демонстрація конструктора переміщення
    String s4 = std::move(s1);
    cout << "String s4 (moved from s1): ";
    s4.output();

    // Демонстрація оператора присвоєння (копіювання)
    s1 = s3;
    cout << "String s1 after assigning s3: ";
    s1.output();

    // Демонстрація оператора присвоєння (переміщення)
    s1 = String("Temporary string!");
    cout << "String s1 after assigning a temporary string: ";
    s1.output();

    // Демонстрація оператора доступу до символів
    try {
        cout << "First character of s1: " << s1[0] << endl;
        cout << "Changing first character of s1 to 'X'." << endl;
        s1[0] = 'X';
        cout << "Modified s1: ";
        s1.output();
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    // Демонстрація пошуку символа
    char ch = 'o';
    int position = s2(ch);
    if (position != -1) {
        cout << "Character '" << ch << "' found in s2 at position " << position << "." << endl;
    } else {
        cout << "Character '" << ch << "' not found in s2." << endl;
    }

    // Демонстрація перетворення до int
    cout << "Length of s2 (as int): " << static_cast<int>(s2) << endl;

    // Виведення кількості об'єктів String
    cout << "Number of String objects: " << String::getObjectCount() << endl;

    return 0;
}