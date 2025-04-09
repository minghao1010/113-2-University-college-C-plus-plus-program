#ifndef DATE_H
#define DATE_H

class Date {
public:
    // 建構子：可指定日期，提供預設值為 1990/1/1
    Date(int year = 1990, int month = 1, int day = 1);

    // 設定日期，包含合法性檢查
    void setDate(int year, int month, int day);

    // 輸出西元日期格式 YYYY-MM-DD
    void printGregorian() const;

    // 輸出民國日期格式 民國XXX年X月X日
    void printROC() const;

private:
    int year;
    int month;
    int day;

    // 判斷是否為閏年
    bool isLeapYear(int y) const;

    // 檢查日期是否有效
    bool isValidDate(int y, int m, int d) const;
};

#endif