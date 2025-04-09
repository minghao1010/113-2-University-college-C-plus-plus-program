#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Date.h"
using namespace std;

// 建構子
Date::Date(int y, int m, int d) {
    setDate(y, m, d); // 呼叫 setDate 檢查並設定
}

// 設定日期並驗證
void Date::setDate(int y, int m, int d) {
    if (!isValidDate(y, m, d)) {
        throw invalid_argument("Invalid date entered.");
    }
    year = y;
    month = m;
    day = d;
}

// 判斷是否為閏年
bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 驗證日期合法性
bool Date::isValidDate(int y, int m, int d) const {
    if (y < 1900 || y > 2099 || m < 1 || m > 12) return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int maxDay = (m == 2 && isLeapYear(y)) ? 29 : daysInMonth[m - 1];

    return d >= 1 && d <= maxDay;
}

// 輸出西元格式
void Date::printGregorian() const {
    cout << "Gregorian Date: "
        << setfill('0') << setw(4) << year << "-"
        << setw(2) << month << "-"
        << setw(2) << day << endl;
}

// 輸出民國格式
void Date::printROC() const {
    int rocYear = year - 1911;
    cout << "Minguo Date: 民國"
        << rocYear << "年"
        << month << "月"
        << day << "日" << endl;
}
