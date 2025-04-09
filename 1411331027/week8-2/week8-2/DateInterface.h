#ifndef DATE_INTERFACE_H
#define DATE_INTERFACE_H

// 抽象介面，用來定義共通方法，實作類別需實作這些方法
class DateInterface {
public:
    // 設定日期（純虛擬函式）
    virtual void setDate(int year, int month, int day) = 0;

    // 印出西元日期
    virtual void printGregorian() const = 0;

    // 印出民國日期
    virtual void printROC() const = 0;

    // 虛擬解構子，讓介面可正確釋放記憶體
    virtual ~DateInterface() {}
};

#endif