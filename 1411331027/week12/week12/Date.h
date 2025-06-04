#ifndef DATE_H
#define DATE_H

class Date {
public:
    static const unsigned int monthsPerYear = 12;  // 一年有12個月

    explicit Date(int = 1, int = 1, int = 1900);    // 建構子（預設為1900/1/1）
    void print() const;                            // 輸出日期
    ~Date();                                        // 解構子（顯示銷毀訊息）

private:
    unsigned int month;  // 月
    unsigned int day;    // 日
    unsigned int year;   // 年

    unsigned int checkDay(int) const;  // 檢查日期是否有效（含閏年）
};

#endif