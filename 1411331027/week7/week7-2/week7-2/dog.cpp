#include <iostream>
#include <string>
#include "dog.h"
using namespace std;

Dog::Dog() {
    dogName = "james";
    dogAge = 11;
    cout << "\n預設狗的資訊:" << endl;
    printInfo();
    setDogInfo();
}

void Dog::setDogInfo() {
    cout << "\n請輸入狗的名字: ";
    getline(cin, dogName);

    // 限制名字長度最多為10字元
    if (dogName.size() > 10) {
        cout << "名字 \"" << dogName << "\" 超過最大長度 (10)，將限制為前10個字元。" << endl;
        dogName = dogName.substr(0, 10);
    }

    cout << "請輸入狗的年齡: ";
    cin >> dogAge;
    cin.ignore(); // 清除輸入緩衝區，避免影響後續輸入

    // 驗證年齡是否合理（1~19）
    if (dogAge <= 0 || dogAge >= 20) {
        cout << "無效的年齡！年齡必須介於 1 到 19 之間，預設為 0。" << endl;
        dogAge = 0;
    }

    // 顯示最終的寵物資訊
    printInfo();
}

string Dog::getName() const {
    return dogName;
}

int Dog::getAge() const {
    return dogAge;
}

void Dog::printInfo() const {
    cout << "狗的名字: " << getName() << "\n狗的年齡: " << getAge() << " 歲" << endl;
}
