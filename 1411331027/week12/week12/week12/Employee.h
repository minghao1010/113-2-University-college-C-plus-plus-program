#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee {
public:
    // 建構子（可預設為空）
    Employee(const std::string & = "", const std::string & = "", const Date & = Date(), const Date & = Date());

    // 使用 this 指標支援鍊式設定
    Employee& setFirstName(const std::string&);
    Employee& setLastName(const std::string&);
    Employee& setBirthDate(const Date&);
    Employee& setHireDate(const Date&);

    Employee& inputDetails();  // 從鍵盤輸入資料
    Employee& print();         // 印出資料

    ~Employee();  // 解構子

private:
    std::string firstName;  // 名字
    std::string lastName;   // 姓氏
    Date birthDate;         // 出生日期
    Date hireDate;          // 到職日期
};

#endif
