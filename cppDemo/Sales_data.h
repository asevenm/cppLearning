//
//  Sales_data.h
//  cppDemo
//
//  Created by 罗林峰 on 2018/6/21.
//  Copyright © 2018年 罗林峰. All rights reserved.
//

#ifndef Sales_data_h
#define Sales_data_h
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif /* Sales_data_h */
