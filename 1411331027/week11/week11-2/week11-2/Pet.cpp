#include <iostream>
#include <stdexcept>
#include "Pet.h"
using namespace std;

// 建構子：初始化資料並驗證年齡合理性
Pet::Pet(const string& petSpecies, const string& petName,
    const Date& birth, const Date& adoption)
    : species(petSpecies), name(petName),
    birthDate(birth), adoptionDate(adoption) {
    validateAge(); // 檢查年齡與日期順序
    cout << "建立寵物物件: " << name << " (" << species << ")" << endl;
}

// 印出寵物資料
void Pet::print() const {
    cout << "寵物名稱: " << name << ", 種類: " << species
        << "\n  生日: ";
    birthDate.print();
    cout << "\n  領養日: ";
    adoptionDate.print();
    cout << endl;
}

// 驗證年齡（0~20歲）且生日必須早於或等於領養日
void Pet::validateAge() const {
    if (!birthDate.isBefore(adoptionDate)) {
        throw invalid_argument("生日必須早於或等於領養日！");
    }

    int age = adoptionDate.getYear() - birthDate.getYear();
    if (age < 0 || age > 20) {
        throw invalid_argument("寵物年齡必須介於 0 到 20 歲之間！");
    }
}

// 解構子：印出寵物完整資料
Pet::~Pet() {
    cout << "\n刪除寵物: " << name << endl;
    print();
}