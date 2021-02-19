//
// Created by austin stone on 2019-04-20.
//

#include <iostream>
#include <string>
void types()
{
    /*2.1.1 算术类型*/
    bool flag = true; //or false. 可用于计算，结果就是 1或0 参与计算
    char c = 'c'; //8bit
    wchar_t w = 'c'; //宽字符型 16bit
    char16_t c16 = 'c'; //unicode 字符 16bit
    char32_t c32 = 'c'; //unicode 字符 32bit
    std::cout << "\u5b97\u94f6" << std::endl; //unicode-utf16  ，而utf8是  &#x5b97; &#x94f6;
    short s = 77; //16bit
    int i = 12222; //16bit
    long l = 33333333; //32bit
    long long ll = 888888888888; //64bit   //cpp11 add
    float f = 88.012345678901; //单精度浮点型 6位有效数字
    double d = 88.012345678901; //双精度  10位有效数字
    long double ld = 88.012345678901; //扩展精度  10位有效数字

    /*
     * c++规定，类型所占字节 longlong >= long >= int >= short
     * 除 bool 和 unicode 的字符型外，其它非浮点类型都可以成无符号的 unsigned ...
     * 而 字符型则可以分三种：char 、signed char 、 unsigned char
     *  但，表现形式，也只有两种，即有符号，或无符号
     *
     *  直接 unsigned vvv = 100;  是 int 型的，赋其它值可能有警告
     */
    char cc = 'f';
    signed char cc1 = 'f';
    unsigned char cc2 = 'f';
    wchar_t ccx = 'f';
//    unsigned char16_t xxcds = 'f'; //err
//    unsigned char32_t fsxxc = 'f'; //err
    /*
     * 注意：char 和 bool 最好不要用做 加减。
     * 浮点运算用 double
     */

    /*
     * 以上也叫基本内置类型，体现了大多数计算机硬件本身就具备的能力。
     */

    unsigned short sh = 0;
    std::cout << sh << std::endl;
}

//using namespace std;
using namespace::std;
//using std::cout;
void typesConvert()
{
    /*2.1.2*/
    bool b = 42; //true
    int i = b; //1
    i = 3.14; //3
    double pi = i; //3.0
    unsigned char c = -1; //if char 8bit,  => 255
    float fc = 3.14;
    signed char cc = 256; //if char 8bit,  => undefined
    cout << (int)c << ", " << (cc!=0) << endl;

    /*
     * 无符号类型，总是 >=0的，若在运算时，将其赋值为负数，那么
     * 会自动转换成合法的一个无符号数；如 若int 是32位，那么-1，等于2^32-1
     *
     * 尽量不要混用 有符号与无符号；
     */
    unsigned int ui = -100;
    cout << ui << endl;

    /*2.1.3 字面值常量*/
    int aa = 076;
    cout << "八进制：" << aa << endl;
    //0x or 0X 十六进制

    //科学计算法  e/E
    int ee = 1.32e5;
    cout << "科学计数1.32*10的5次方" << ee << endl;

    //char c = 'a';  字符字面值
    /*
     * "hello world" 字符串字面值，实际是由字符构成的数组；编译器会在结尾添加一个空字符 '\0'表示结尾；
     * 因此，字符串字面值的长度，比实际内容多1个。
     */

    // 转义符 \

    //添加前缀或后缀，改变整型、浮点型和字符型字面值的默认类型；
    cout << "1: " << sizeof('a') << endl; //char
    cout << "2: " << sizeof(L'a') << endl; //L:wchar_t; u:char16_t; U:char32_t;
    cout << "3: " << sizeof(u"中国") << endl;
    cout << "4: " << sizeof(u8"中国") << endl; //utf8, 与 sizeof("中国")一样，是char[]
    cout << "5: " << sizeof(100) << endl; //int
    cout << "6: " << sizeof(100ULL) << endl; //ll/LL: unsigned long long;  u/U: unsigned; l/L: long
    cout << "7: " << sizeof(1E-3) << endl; //double
    cout << "8: " << sizeof(1E-3F) << endl; //f/F: float
    cout << "9: " << sizeof(3.14) << endl; //double
    cout << "10: " << sizeof(3.14L) << endl; //l/L: long double
//    char xyz='&#x4E2D;';
//    char32_t zyx = '\uaa80';


    //bool 字面值 true/false

    //指针字面值 nullptr

    //<string>中的 string， 表示一个可变长度的字符序列
    std::string xxx("stone");
    std::cout << xxx << endl;

}
constexpr int rvrv() {
    return 100;
}
void variable() {
    /*2.2 变量*/
    cout << "------2.2------" << endl;

    //小括号赋值、花括号赋值 都可以
    int a = 0;
    int aa = {0};
    int aaa{0};
    int aaaa(0);
    cout << (a == aa == aaa == aaaa) << endl;

    long double ld = 3.14;
//    int l1{ld}; //error。 说明花括号对丢失数据处理，更严格了
    int l1(ld); //正确转换了类型
    cout << l1 << endl;

    /*
     * 定义在函数之外的变量，默认初始化值为0；
     * 函数体内的，默认是 undefined的，即没被默认初始化
     */

    /*
     * 变量的声明与定义
     * extern int v1;  //声明, 如在 a.cpp 文件中
     * int v1; // 声明，并定义。 如果引用了 a.cpp，那本文件中的 v1 与 a.cpp 中的 v1就关联起来了。
     * extern int v1 =1; //定义并初始化，且由 extern 修饰，表明会被外部使用；外部只需要 extern int v1，就可关联起来
     *
     * 可以多次声明，用 extern；定义只能是一次；
     * 如， 在 main.cpp 中定义 int 变量 xst； 在 a.cpp 和 b.cpp 中 extern 声明 xst，且使用。
     */

    cout << "------2.3 复合变量：引用和指针------" << endl;

    /*
     * 引用 &，即别名，  左值引用；     cpp11:右值引用，主要用于内置类。一般说引用，就是指别名
     * 改变引用的值，会改变原有的值。
     */

    int iv = 1024;
    int &iva = iv;
//    int &ivb; //error. 必须初始化
//    int &ivb = &iva; //error. 引用本身不是一个对象，不能定义引用的引用
    cout << "iva: " << iva << endl;

    /*
     * 指针
     * 变量声明：  int *p;
     * int v = 99;   p = &v;  int*q = &v;
     */
    int *q = &iva; //引用的指针，书上说这个不可以，测试发现，是可以的。。。
    cout << "*q=" << *q << endl;  //这里的*，叫解引用符
    int *&r = q; //指针的引用
    cout << "*r" << ++*r << endl;
    cout << "*q=" << *q << endl;  //这里的*，叫解引用符

    /*
     * 空指针
     * int *p1 = nullptr; <==> int *p1 = 0;    nullptr: cpp11
     * int *p2 = NULL; 需要先引用 <cstdlib>  ，即引用了 c 标准函数库的头文件
     */

    cout << "------2.4 const 限定符------" << endl;

    /*
     * const 常量限定符
     * const int bufSize = func();  延迟到 func()中初始化
     * extern int bufSize = func(); 可由外部使用，即多文件共享
     *
     * const 声明连续变量时，都有效
     */
    const int con1 = 1024;
//    int &con2 = con1; //错误
    const int &con2 = con1; //正确。 对常量的引用，简称常量引用，也必须是一个常量
//    con2 = 100; //错误。 常量不能被赋值
//    int &ccon  = 1024; //错误，非常量引用，不能被赋值上一个字面值。
    int cVal = 1;
    const int &con3 = cVal; //正确，常量引用是一个 非常量
    cVal = 2;
    cout << con3 << endl; //非常量改变后，常量引用的值也被改变
//    con3 = 4; //错误， 常量引用本身不能改变值

    /*
     * 指向常量的指针，也是与引用一样, 该指针也要定义成 const，该常量指针，也不能通过 解引用符*  来赋值。
     */
    /*
    const int con1 = 1024;
    const int *con2 = &con1;
    int cVal1 = 188;
    const int *con3 = &cVal1;
    cout << * con3<<endl;

    int cVal2 = 197;
    con2 = con3 = &cVal2;
    cout << *con2 << endl;
    cout << *con3 << endl;
     形如 `const type * ` 定义的变量，无论指向的是一个常量，还是非常量。都可以重新指定指向的地址。
     */

    /*
     * const 指针，即常量指针。
     * 定义时，必须初始化。
     * 该指针，就无法被重新赋值，会一直指向初始值地址。
     */
    int cv = 88;
    int *const cp = &cv;
//    cp = &cVal; //错误，const 指针无法被重新赋值
    cv = 99; //正确

    /*
     * 术语
     * 顶层 const (top-level const)  表示指针本身是一个常量   *const
     * 底层 const (low-level const) 表示指针指向的是一个常量
     *
     * 通俗的讲 顶层 const，即(指针或引用或其它类型)变量本身不可变；
     *          底层 const，即(指针或引用或其它类型)变量所指向的对象值不可变
     *
     * 如果传递顶层 const 参数，那就表示，通过该指针是不能改变指针的地址的，指向指向的对象变量还是可变的；
     *      内存地址不变；指向的值可变
     * 如果传递底层 const 参数，该指针还是可变的
     *      内存地址可变；指向的值不变
     */
    const int *pc = &cv; //low const.  const type*，指针地址可变，指向值不(可直接改)变
//    pc = &cVal; //正确
//    *pc = 88989; //错误
    const int *const ccp = &cv;//左边是 low const，右边是 top const； 既是顶层也是底层 const
//    ccp = &cVal; //错误
//    *ccp = 88989; //错误

    /*
     * constexpr 与常量表达式、常量函数
     *      cpp11 新增该关键字，可用于声明常量，和常量函数
     * 让编译器，在编译期间来验证，常量定义是否正确
     *
     * 由于在编译期间要确定常量值，所以非基本类型不可用于 常量表达式;
     * 像是指针类型 就是不行的
     */
    constexpr int xd = 88;
//    xd = 87; //error
    constexpr int xxd = rvrv(); //constexpr int rvrv() {return 1};

    /*
     * 一条语句定义多个变量， *、& 只对紧跟的一个变量名起作用；
     * int aa =88;
     * int *pp = &aa, qq = &aa; //err， qq 是 int
     */
}

int returnValue();
void typeOpt() {
    cout << "------2.5 处理类型------" << endl;

    /*
     * 类型别名。传统方式，使用 typedef， cpp11，可使用 using
     * 例，指针类型别名
     *      typedef char* ps; 指向 char 的指针； char* 的别名 ps;
     *      const ps str = 0; 指向 char 的常量指针
     *      const ps *p; 指向char 常量的指针 的指针
     */
    typedef char* ps;
    char xx = 'X';
    const ps str = &xx;//虽然将char*，代入后是 const char*，但实际是常量指针，即符合顶层const -> type*const 特性
    *str = 'F'; //地址指向值可变
//    str = &zz; //常量指针的地址不可变
    cout << *str << endl;

    const ps *p;
    p = &str;
    cout << **p << endl;
    char zz = 'Z';
    char * q = &zz;
    p = &q;
    cout << **p << endl;
    //    cout << p << endl;

    typedef int mi;
    mi xa = 88;
    using mii = mi;
    mii xb = 88;
    cout << (xa == xb) << endl;

    //常量指针，先常量后指针，本质是一个指针
    const int * axxx = &xa;
    int xc = 'A';
    axxx = &xc;
    cout << *axxx << endl;

    /*
     * auto 类型说明符   cpp11
     * 主要就是 进行类型自动推断。
     * 在与常量、复合类型(引用、指针)一起使用时要注意
     */
    int i = 0, &r = i;
    auto a = r; // a: int
    //忽略顶层 const 特性，保留底层 const 特性
    const int ci = i, &cr = ci; //ci、cr 是 顶层 const，即本身不可变
    auto b = ci; //忽略顶层
    auto bbb = cr; //int
    b = 99; //正确
    auto c = cr; //忽略顶层
    c = 100;
    cout << "b=" << b << ", c=" << c << endl;
    auto d = &i;
    *d = 99;
    auto e = &ci; //保留底层 const
//    *e = 100; //error. 指向常量的指针， 指向的值不可变
    cout << "d=" << *d << ", e=" << *e << endl;
//    const auto f = &ci; //加上顶层特性
    auto const f = &ci; //加上顶层特性
    auto &g = ci; //& 类型 推断
//    auto &h = 33; //err. 非常量& ，必须是另一个变量的别名
    auto const &h = 42; //常量&，可以绑定 字面值

    /*
     * decltype 类型指示符   cpp11
     * decltype(dvalue) variable = value;
     *  变量的类型就是 dvalue 的类型
     */
    decltype('a') dc = 'b';
//    decltype("aa") dc1 = "a"; //err.  期望是3位字符串，即加上空字符是3位； 而赋值成2位
//    decltype("aa") dc1 = "aaa";//err. 期望是3位，而赋值成4位
    decltype("aa") dc1 = "aa";

    decltype(returnValue()) dc2 = 999999;
    decltype(11) dc3 = 999999;

    int di = 11, *pdi = &di, &dr = di;
    decltype(dr + 0) dc4;
//    decltype(*pdi) dc5;//err.   解引用操作后，得到的是 int&，必须初始化
    decltype((18)) dc6;
//    decltype((di)) dc7;//err.  变量加了括号后，就成了 &，必须初始化
    decltype(dr) dc8 = di;

    const int cci = 0, &ccj = ci;
    decltype(cci) dc9 = 1; //const int dc9 = 1
    decltype(ccj) dc10 = 2; //const int &dc10 = 2

    /*
     * auto和 decltype，一般情况是相同的
     * 不同点：
     *  将 & 类型赋值给变量后， auto 是原类型，如上面的 bbb，还是 int 类型；
     *      而 decltype 是 & 类型，如上面的 dc8
     *  auto 会忽略顶层 const，保留底层 const；
     *  decltype 不能与 const 混用; 只可以将原是 const 类型的变量用于 decltype()表达式中，从而达到定义 const 常量的目的
     *
     */
}

int returnValue() {
    return 1888;
}

#include "../Sales_data.hpp"
void customStruct() {
    cout << "------2.6 自定义数据结构------" << endl;

//    struct Sales_data A, B;
    Sales_data A, B; //不写 struct 也是可以的
//    A = {"aaa", 10, 100};
//    B = {"bbb", 20, 250};
//    printData(A);
//    printData(B);

    double price;
    //标准输入三个值，回车时读入到相应变量： 书号，销量，单价
    cin >> A.bookNo >> A.units_sold >> price;
    A.revenue = A.units_sold * price; //收入
    printData(A);

    cin >> B.bookNo >> B.units_sold >> price;
    B.revenue = B.units_sold * price;
    printData(B);

    if (A.bookNo == B.bookNo) {
        unsigned totalUnitsSold = A.units_sold + B.units_sold;
        double totalRevenue = A.revenue + B.revenue;
        double avg = totalRevenue / totalUnitsSold;
        cout << "总销量=" << totalUnitsSold << ",总收入=" << totalRevenue << ",均价=" << avg << endl;
    } else {
        cerr << "book no is not same." << endl;
    }
}