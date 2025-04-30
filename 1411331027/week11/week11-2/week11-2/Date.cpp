#include <iostream>
#include <array>
#include <stdexcept>
#include "Date.h"
using namespace std;

// 建構子：驗證月份與日期是否正確
Date::Date(int mn, int dy, int yr) {
    if (mn > 0 && mn <= monthsPerYear)
        month = mn;
    else
        throw invalid_argument("月份必須介於 1 到 12");

    year = yr;
    day = checkDay(dy); // 檢查日期是否合法

    cout << "建立日期物件: ";
    print();
    cout << endl;
}

// 檢查輸入日期是否合法
unsigned int Date::checkDay(int testDay) const {
    static const array<int, monthsPerYear + 1> daysPerMonth =
    { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    // 一般情況
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // 閏年判斷（2月29日）
    if (month == 2 && testDay == 29 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("日期不合法");
}

// 印出日期
void Date::print() const {
    cout << month << '/' << day << '/' << year;
}

// 解構子
Date::~Date() {
    cout << "刪除日期物件: ";
    print();
    cout << endl;
}

// getter 成員函數
int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

// 判斷是否早於另一日期（或相等）
bool Date::isBefore(const Date& other) const {
    if (year < other.year) return true;
    if (year == other.year && month < other.month) return true;
    if (year == other.year && month == other.month && day <= other.day) return true;
    return false;
}