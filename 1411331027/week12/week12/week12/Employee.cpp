#include <iostream>
#include "Employee.h"
using namespace std;

// 建構子
Employee::Employee(const string& first, const string& last, const Date& dob, const Date& hire)
    : firstName(first), lastName(last), birthDate(dob), hireDate(hire) {
    cout << "建立員工物件：" << firstName << " " << lastName << endl;
}

// 設定名字
Employee& Employee::setFirstName(const string& first) {
    this->firstName = first;
    return *this;  // 回傳目前物件（支援鍊式呼叫）
}

// 設定姓氏
Employee& Employee::setLastName(const string& last) {
    this->lastName = last;
    return *this;
}

// 設定出生日期
Employee& Employee::setBirthDate(const Date& date) {
    this->birthDate = date;
    return *this;
}

// 設定到職日期
Employee& Employee::setHireDate(const Date& date) {
    this->hireDate = date;
    return *this;
}

// 輸入資料（透過 this 做鍊式設定）
Employee& Employee::inputDetails() {
    string first, last;
    int bm, bd, by, hm, hd, hy;

    cout << "請輸入名字：";
    cin >> first;
    cout << "請輸入姓氏：";
    cin >> last;

    cout << "請輸入出生日期（月 日 年）：";
    cin >> bm >> bd >> by;

    cout << "請輸入到職日期（月 日 年）：";
    cin >> hm >> hd >> hy;

    return this->setFirstName(first)
        .setLastName(last)
        .setBirthDate(Date(bm, bd, by))
        .setHireDate(Date(hm, hd, hy));
}

// 輸出資料
Employee& Employee::print() {
    cout << "員工姓名：" << firstName << " " << lastName << endl;
    cout << "到職日期：";
    hireDate.print();
    cout << "  出生日期：";
    birthDate.print();
    cout << endl;
    return *this;
}

// 解構子
Employee::~Employee() {
    cout << "銷毀員工物件：" << firstName << " " << lastName << endl;
}
