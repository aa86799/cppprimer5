//
// Created by austin stone on 2020/2/10.
//

#include "Circle.h"
#include <iostream>
#include <cstdio>
extern "C" {
    void Circle_Test_C() {
//        puts("");
//        gets("");
//        putchar('a');
//        getchar();

//        char s[10] = "admin";
//        char *qs = s;
//        *qs = 'A';

//        auto *qs = "admin";
//        *qs = 'A'; //error

        short ss[3] = {18};
        short *p = ss;
        *p = 19;

    }
}

Circle::Circle() {

}

Circle::Circle(int r): m_R(r) {
    cout << (r) << endl;
}

double Circle::calculateZC() {
    return 2 * pi * this->m_R;
}

void Circle::setR(int r) {
    this->m_R = r;
}

void Circle::func2(int a , int = 1)
{

}

int Circle::getMR() const {
    return m_R;
}
