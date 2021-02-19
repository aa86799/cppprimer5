#include <iostream>

#include "c02/c02.cpp"

//测试 extern 声明变量
#include "c02/aa.cpp"
#include "c02/bb.cpp"

#include "c03/string_vector_iterator.cpp"

//int xst = 88; //不能多次定义

//#include "practice/Circle.h"
#include "practice/Circle.cpp"
#include "c03/sruct_test.cpp"
#include <string>
int main() {
    std::cout << "Hello,11 World!" << std::endl;

    /*c02*/
//    types();
//    typesConvert();
//    variable();
//    typeOpt();
//    customStruct();

    //测试 extern 声明变量
//    cout << "------测试 extern 声明变量-------" << endl;
//    p1();
//    p2();

    /*c03*/
//    testUsingNamespace();
//    testString();
//    testStringAndCcType();
//    testVector();
//    testIterator();

//    const char32_t ccxx = U'\u4e2d';
//    cout << (U'中' == ccxx) << endl;
//    wstring  ws;
//    ws+=ccxx;
//    cout << (ws[0]==U'中') << endl;

//    Circle cir1;
//    cir1.setR(10);
//    cout << cir1.calculateZC() << endl;
//    auto *cir2 = new Circle();
////    Circle *cir2;// = new Circle();
//    cir2->setR(8);
//    std::cout << cir2->calculateZC() << endl;
//    cir2->func2(18);
//    cir2->func2(18, 17);
//    delete cir2;
//    Circle cir3 = 88; //相当于调用了 Circle cir3 = Circle(100) ，隐式类型转换
//    cout << cir3.calculateZC() << endl;
//
////#define SQUARE(X) X*X
////    auto d = 2;
////    auto c = SQUARE(d++); //d++ * d++
////    cout << c << endl;
//
//    cout << sizeof(string("abc")) << endl;
//
////   const int acf = 97;
////    char cf = static_cast<char>(acf);
//////    char cf = const_cast<char>(acf);
////    cout <<cf <<endl;
//
//    int aryc = 2345879;
//    int *ip = &aryc;
//    char *pc = reinterpret_cast<char*>(ip);
//    cout << string(pc) << endl;
//
//    const int acf = 97;
//    int cf = (acf); //正确
//
//    try {
//
//    } catch (exception p) {
//        const char *xvd = p.what();
//
//    }

    int xxAry[10] = {3, 7, 9};
//    cout << xxAry[0] << endl;
    testFX(xxAry);

    int *xxi = xxAry;
//    cout << endl;
//    cout << xxi[2];
//    cout << *(xxi+2);

    cout <<  ( sizeof(xxAry)/sizeof(xxAry[0]) ) << endl;
    cout <<  ( sizeof(xxAry)/sizeof(int) ) << endl;
    cout <<  ( sizeof(xxAry)/sizeof(*xxAry) ) << endl;

    char ch[] = {'a', 'b', 'c', '\0'};

    return 0;
}