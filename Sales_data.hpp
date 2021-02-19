//
// Created by austin stone on 2019-04-21.
//

#ifndef PRIMER5_SALES_DATA_HPP
#define PRIMER5_SALES_DATA_HPP

#include <string>
/*
 * cpp11， 会对结构体的数据成员，自动初始化，若没有赋初值时。
 */
struct Sales_data {
    std::string bookNo;//书号   默认初值为空字符串
    unsigned units_sold = 0;//销量
    double revenue = 0;//收益
};

void printData(Sales_data data) {
    std::cout << "bookNo:" << data.bookNo << ",销量=" << data.units_sold
        << ",收入=" << data.revenue << endl;
}


#endif //PRIMER5_SALES_DATA_HPP
