#include <iostream>
#include <stdexcept>
#include "Date.h"
using namespace std;

// 建構子，初始化日期並驗證合法性
Date::Date(int mn, int dy, int yr) {
    if (mn > 0 && mn <= monthsPerYear)
        month = mn;
    else
        throw invalid_argument("月份必須介於 1 到 12");

    year = yr;
    day = checkDay(dy);

    cout << "建立日期物件：";
    print();
    cout << endl;
}

// 輸出日期（格式：月/日/年）
void Date::print() const {
    cout << month << "/" << day << "/" << year;
}

// 解構子
Date::~Date() {
    cout << "銷毀日期物件：";
    print();
    cout << endl;
}

// 驗證日期是否合理
unsigned int Date::checkDay(int testDay) const {
    static const int daysPerMonth[13] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // 閏年處理
    if (month == 2 && testDay == 29 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("這個月與年份中，日期無效！");
}
