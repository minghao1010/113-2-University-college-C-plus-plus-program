#include <iostream>
#include <string>
#include"dog.h"
using namespace std;

Dog::Dog(){
    dogName = "james";
    dogAge = 11;
    cout << "\n預設狗的資訊:" << endl;
    printInfo();
    setDogInfo();
}

void Dog::setDogInfo() {
    cout << "\n請輸入狗的名字: ";
    getline(cin, dogName);

    cout << "請輸入狗的年齡: ";
    cin >> dogAge;

    // 驗證年齡是否合理（<20）
    if (dogAge <= 0 || dogAge >= 20) {
        cout << "無效的年齡！年齡必須介於 1 到 19 之間，預設為 0。" << endl;
        dogAge = 0;
    }
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