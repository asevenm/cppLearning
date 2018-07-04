//
//  main.cpp
//  cppDemo
//
//  Created by 罗林峰 on 2018/6/10.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#include <iostream>
#include "Sales_data.h"
using namespace std;
struct Foo {};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    //两数相加
/*    std::cout << " enter two numbers: " << std::endl;
      int v1 = 0, v2 = 0;
      std::cin >> v1 >> v2;
      std::cout << " the sum of " << v1 << " and " << v2
      << " is " << v1 + v2 << std::endl;
 */
    
    //输出hello，world
//    std::cout << " Hello, World. " << std::endl;
    
    //两数相乘
    /*
    std::cout << " enter two numbers: " << std::endl;
    int v3 = 0, v4 = 0;
    std::cin >> v3 >> v4;
    std::cout << " the product of " << v3 << " and " << v4
    << " is " << v3 * v4 << std::endl;
    */
    
    //while求和
    /*int sum = 0, val = 50;
    while(val <= 100) {
        sum = sum + val;
        ++val;
    }
    std::cout << " sum of 55 to 100 inclusive is " << sum << std::endl;*/
    
    //while 打印
    /*int val = 10;
    while(val >= 0) {
        std::cout << val << std::endl;
        --val;
    }*/
    
    //while 打印用户输入范围内的整数
    /*int v5 = 0, v6 = 0;
    std::cout << " enter two number, and I'll print digit betweent them: " << std::endl;
    std::cin >> v5 >> v6;
    if(v5 >= v6) {
        while(v5 >= v6) {
            std::cout << v5 << std::endl;
            --v5;
        }
    } else {
        while (v6 >= v5) {
            std::cout << v6 << std::endl;
            --v6;
        }
    }*/
    //打印用户输入整数的和
    /*int sum = 0, val = 0;
    while(std::cin >> val) {
        sum += val;
    }
    std::cout << " sum is :" << sum << std::endl;*/
    
    //统计每个输入值的个数
    /*int curValue = 0, value = 0;
    if(std::cin >> curValue) {
        int cnt = 1;
        while(std::cin >> value) {
            if(curValue == value) {
                ++cnt;
            } else {
                std::cout << curValue << " occurs " << cnt << " times " << std::endl;
                curValue = value;
                cnt = 1;
            }
        }
        std::cout << curValue << " occurs " << cnt << " times " << std::endl;
    }*/
    /*unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;*/
    
    {/*Sales_data data1, data2;
    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    if(data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if(totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
      }*/}
    
    Sales_data total;
    double totalPrice;
    if(std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.revenue = total.units_sold * totalPrice;
        Sales_data trans;
        double transPrice;
        while(std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.revenue = trans.units_sold * transPrice;
            if(trans.bookNo == total.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << total.bookNo << " " << total.units_sold << " ";
                if(total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << std::endl;
                else
                    std::cout << "no salse" << std::endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        std::cout << total.bookNo << " " << total.units_sold << " ";
        if(total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << std::endl;
        else
            std::cout << "no sales" << std::endl;
        return 0;
    } else {
        std::cerr << "no data" << std::endl;
        return -1;
    }
    return 0;
}
