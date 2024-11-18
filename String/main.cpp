#include "String.h"

using namespace std;

int main() {
    String s1;
    s1.input();
    s1.output();

    String s2("Hello, world!");
    s2.output();

    String s3(s2);
    s3.output();

    String s4 = s1;
    s4.output();

    cout << "Number of String objects: " << String::getObjectCount() << endl;

    return 0;
}