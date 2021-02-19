//
// Created by austin stone on 2020/12/21.
//

struct TestType {
    int a;
    double b;
};

void test(int *p) {

}


#include <iterator>
using namespace std;
void test(const int &a) {
    struct TestType c = {1, 10.0};

    int ary[] = {1,2,3};
    begin(ary);
    test(ary);
}

#include <iostream>
void test(const int *begin, const int *end) {
    while (begin != end)
        cout << *begin++ << endl;
}

void testFF( int (&ary)[10]) {
    for (auto a: ary) {
        cout << a << endl;
    }
}

template<typename T,int N>
void testFX(T (&ary)[N]) {
    for (auto a: ary) {
        cout << a << endl;
    }
}
