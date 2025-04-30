#ifndef PET_H
#define PET_H

#include <string>
#include "Date.h"

class Pet {
public:
    // 建構子：傳入種類、名字、生日、領養日
    Pet(const std::string&, const std::string&, const Date&, const Date&);
    void print() const; // 印出寵物資訊
    ~Pet(); // 解構子，印出詳細資訊

private:
    std::string species; // 寵物種類
    std::string name;    // 名字
    Date birthDate;      // 出生日期
    Date adoptionDate;   // 領養日期

    void validateAge() const; // 驗證寵物年齡與日期順序
};

#endif
