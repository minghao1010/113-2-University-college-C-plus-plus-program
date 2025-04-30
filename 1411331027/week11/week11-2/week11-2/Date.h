#ifndef DATE_H
#define DATE_H

class Date {
public:
    static const unsigned int monthsPerYear = 12; // 一年有12個月
    Date(int = 1, int = 1, int = 2000); // 預設建構子
    void print() const; // 印出日期
    ~Date(); // 解構子，顯示解構順序
    int getYear() const; // 取得年份
    int getMonth() const; // 取得月份
    int getDay() const; // 取得日期

    bool isBefore(const Date& other) const; // 比較是否早於另一日期（含等於）

private:
    unsigned int month; // 月份（1~12）
    unsigned int day; // 日期
    unsigned int year; // 年份

    unsigned int checkDay(int) const; // 檢查日期是否合法
};

#endif
