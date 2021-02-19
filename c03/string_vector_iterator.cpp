//
// Created by austin stone on 2019-04-21.
//

#ifndef PRIMER5_C03
#define PRIMER5_C03

using std::cout; //仅引用 std 的命名空间中的 cout
using std::endl;
//using namespace::std; //引用 整个 std
//using namespace std; //引用 整个 std
void testUsingNamespace() {
    cout << 1 << endl;
    cerr << 2 << endl;
    /*
     * using 可用来引用 标准库中的 定义好的 命名空间
     * 通常头文件中，由于没有实现，不需要使用 using 引用命名空间，以免包含该头文件的地方，都引用了这个命名空间
     *
     * 可以自定义命名空间, 暂不提
     */
}

#include <string> //可变长字符序列
using std::string;
void testString() {
    cout << "------3.2标准库类型 <string> ------" << endl;
    string s1; //默认初始化，为一个空字符串
    string s2 = s1;
    string s3 = "stone12341234中";//拷贝初始化。
    string s3a("stone12341234中");//utf8，一个汉字占3个字节。  直接初始化
    string s4(3, 'c'); //3个连续字符 c 。  直接初始化
    string s5 = s4;
    string s6 = string(3, 'c'); //右边先直接初始化， 再 拷贝给左边
    cout << s1 << "," << s2 << "," << s3 << "," << s4 << endl;
//    cout << (s5 == s6) << endl; // 1

    /*
     * string 的 输入输出操作
     *      os << s   输出操作
     *      is >> s   输入操作
     *      getline(is, s);  输入一行
     */
//    getline(cin, s2);
//    cout << "out:" << s1 << endl;

    cout << (s1.empty()==true) << endl;//是否为空
    /*
     * 返回多少个字符，即多少个 char； char 是8bit，一个字节，  也可以说返回多少个字节。
     * utf8的汉字占3个字节，所以 5个字母+8个数字+1个汉字=16
     */
    cout << s3.size() << "," << s3a.size() << endl;
    /*
     * s[n] 返回从0开始的 第 n个位置上的字符。
     * 对于非 ASCII，而是 unicode 字符集，则由于字符中的文字会占用多个字节，所以返回的 无法输出成期待的明文
     */
    cout << s3[3] << "," << s3a[16] << endl;
    /*
     * s1+s2; //连接字符串
     * s1=s2;
     * s1==s2;
     * s1!=s2;
     * <, <=, >, >=  利用字符的字典序进行比较，且对字母的大小写敏感
     */
}

#include <cctype> //c++中，兼容了c 中的标准库。以 c+name 的形式命名。 而在 c 中是 name.h 的命名。
void testStringAndCcType() {
    cout << "------3.2 处理 string 中的字符 ------" << endl;
    /*
     * cctype:  处理字符的特性
     */
    char c = 'A';
    isalnum(c);//字母或数字时为真
    isalpha(c); //字母时为真
    iscntrl(c);//控制符时为真
    isdigit(c);//数字时为真
    isxdigit(c);//十六进制时为真
    islower(c);//小写字母
    isupper(c);//大写字母
    char cl = tolower(c);//转小写
    char cu = toupper(c);//转大写
    isprint(c);//可打印字符
    ispunct(c);//是标点符号
    isspace(c);//c 是空白为真：空格、横向/纵向制表符、回车符、换行符中的一种
    int tab = isgraph(c);//非空格可打印的字符
    cout << "tab=" << tab << endl;


    string s1 = "stone";//拷贝初始化。
    string s2 = "stone12341234中";//拷贝初始化。
    for (auto str : s2) {//cpp11 for 循环
//        cout << str << ' '; //输出汉字 字符，还是有问题的
        if (islower(str)) {
            //默认打印时会当成 int
            cout << (char)toupper(str) << " ";
        }
    }
    cout << endl;

    /*
     * 操作 使用下标索引从头开始 [0]，改变 或 获取 string 中的某位上的字符
     */
    s1[0] = 'S';
    if (!s1.empty() && s1.size() > 4) {
        unsigned index = 4;
        s1[index] = 'E';

//        signed index2 = -1; //有符号类型，作下标时会自动转成无符号类型，所以不会触发异常；但结果可能不是期望的
//        s1[index2] = 'K';
    }
    cout << s1 << ", " << s1[4] << endl;

    s1 += " ADMIN";
    //遍历，且当非空白字符时， 转小写
    for (decltype(s1.size()) i = 0; i < s1.size() && !isspace(s1[i]); ++i) {
        s1[i] = tolower(s1[i]);
    }
    cout << s1 << endl;
}

#include <vector> //向量，对象集合. 是类模板； c++还有函数模板.
using std::vector;
void testVector() {
    cout << "------3.3标准库类型 <vector> ------" << endl;
    /*
     * vector<T> v1; 空 T 类型的vector，默认初始化
     * vector<T> v2(v1); v2含有 v1所有元素的副本
     * vector<T> v2 = v1; 与上句等价
     * vector<T> v3(n, val); 与 string 中的使用类似； 含有 n 个 val 值的集合
     * vector<T> v4(n); n 个元素的集合，默认初始化; 如果 T 是内置类型，会默认初始化。如果是类 类型，如 string，由 string 提供默认初始化；
     *      如果，T 不支持默认初始化，就必须用 v(n, initValue) 指定初值；否则无法完成初始化工作
     */
     vector<int> v5 {1,2,3,4,5}; //含有{}内元素的集合   cpp11
     vector<int> v6 = {1,2,3,4,5}; //与上句等价        cpp11
    for (int i = 0; i < v6.size(); ++i) {
        cout << v5[i] << " ";
    }
    cout << endl;
    for(int i : v6) {
        cout << i << " ";
    }
    cout << endl;

//    vector<int> v7 = 10; //error。 未指定向量大小

    /*
     * 注意 () 和 {}
     *
     * vector<T> v3(n, val);  n 个 val
     * vector<T> v4(n);   n 个 默认初始值
     *
     * vector<int> v5 {1,2,3,4,5};     初始值列表
     * vector<int> v6 = {1,2,3,4,5};   列表初始化
     */
    vector<string> v7(5, "abc");
    vector<string> v8{"hi"}; //列表初始化
//    vector<string> v9("hi"); //error
    vector<string> v9{10}; //类型不一样，无法列表初始化。编译器会尝试 默认初始化。 10个默认值
    vector<string> v10{5, "hi"}; //类型不一样，...   5个 "hi"

    vector<int> nums;
    for (int j = 0; j < 20; ++j) {
        nums.push_back(j);//压入尾
    }
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;

    for (int &i : nums) {//int 引用，别名。
        cout << i*10 << " ";
    }
    cout << endl;

//    vector<int> ivec(10);
    vector<int> ivec;
    for (int k = 0; k < 10; ++k) {
//        ivec[k] = k;//error. 空集合。无法使用下标.  要么使用 push_back(); 要么在定义时指定数量及初始化
        ivec.push_back(k);
    }
    for (int k : ivec) {
        cout << "k=" << k << " ";
    }
    cout << endl;
    ivec.data();

    /*
     * 与 string 相似的一些操作
     * v.empty();
     * v.size();
     * v[n]
     * v1 == v2  仅当 元素数量相同，且相同索引上的元素同
     * v1 != v2
     * < <= > >=  字典顺序比较
     */
}

void testIterator() {
    cout << "------3.4 迭代器 ------" << endl;
    vector<int> vec(10);
    int index = 0;
    for(auto v : vec) {
        vec[index++] = v;
    }
    for(int v : vec) {
        cout << v << "\t";
    }
    cout << endl;

//    while (vec.begin() != vec.end()) {//error. 无限循环
//    for(auto it = vec.begin(); it != vec.end(); it++) {
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        *it += 2; //迭代器，必须以 指针运算符 来处理指向的值。  所以可以改变集合中的值
    }

    //不改变集合中的值
    for(int v : vec) {
        cout << v << "\t";
    }
    cout << endl;

    //使用引用&； 也会改变集合中的值
    for(int &it : vec) {
        it += 5;
    }
    for(int &it : vec) {
        cout << it << "\t";
    }
    cout << endl;

    /*
     * string 和 vector 等一些标准库类型才有下标运算符。
     * 更多的标准库容器类型，都实现了迭代器。
     */

    /*
     * 迭代器的类型
     * 非常量迭代器：  vector<type>::iterator.md
     * 常量迭代器： vector<type>::const_iterator
     *
     * 在各种标准库的容器类中， 都定义了 相应的  ::iterator.md 迭代器
     * auto it = vec.begin() 移动指针到第一个元素，
     * vec.end()  最后一个元素外
     * it++;  指针位置向后移
     * *it; 取得指向的值
     *
     * 通常不需要考虑迭代器的类型，使用 auto 自动推断即可。
     *
     * cpp11 新增：cbegin() 、 cend();
     * 它们会返回 const_iterator, 不论 容器是否是 const 定义的
     *
     */
    const vector<int> vec2 = vec;
    for (vector<int>::const_iterator it = vec2.cbegin(); it != vec2.cend(); ++it) {
        //...
    }

    const vector<string> vec3{"aaa", "bbb", "ccc"};
    for (auto it = vec3.begin(); it != vec3.end(); ++it) {
//    for (const auto & it : vec3) {  cout << it
        cout << *it << ",";
        /*
         * 如果 *it 是一个类， 那么访问类成员： (*it).xx();
         * 或用 箭头运算符： it->xx();
         */
    }
    cout << endl;

    /*
     * 迭代器运算。 用于运算时，运算的是一个迭代器中指示的位置值
     * it+n; it-n; it+=n; it-=n; it1-it2; > >= < <=
     */

    //迭代器用于 二分搜索
    vector<int> svec(100);
    for (int i = 0; i < 100; ++i) {
//        svec.push_back(rand()%10);
//        svec[i] = random()%100;
        svec[i] = i;
    }
    int searchValue = 53;
    //用迭代器表示位置；需要三个位置，开始，中间，结束，所以需要三个迭代器
    auto itStart = svec.begin();
    auto itEnd = svec.end();
    auto itMid = svec.begin() + (itEnd - itStart) / 2; //l+(r-l)/2
    int searchCount = 0;
    while (itMid != itEnd && *itMid != searchValue) {
        searchCount++;
        if (searchValue > *itMid) {
            itStart = itMid + 1;
        } else {
            itEnd = itMid - 1;
        }
        itMid = itStart + (itEnd - itStart) / 2;
    }
   /* while (itStart <= itEnd && searchValue != *itMid) {
        searchCount++;
        itMid = itStart + (itEnd - itStart) / 2;
        if (searchValue > *itMid) {
            itStart = itMid + 1;
        } else {
            itEnd = itMid - 1;
        }
    }*/
    cout << ((*itMid==searchValue)?"搜索到了":"没搜索到") << ", searchCount=" << searchCount << endl;
}


#endif