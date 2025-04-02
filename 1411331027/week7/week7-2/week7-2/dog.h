#include <iostream>
#include <string>
using namespace std;

// 定義 Dog 類別
class Dog {
public:
    // 預設建構子，建立一隻預設狗
    Dog();

    // 設定狗的名字與年齡
    void setDogInfo();

    // 取得狗的名字
    string getName() const;

    // 取得狗的年齡
    int getAge() const;

    // 列印狗的資訊
    void printInfo() const;
        

private:
    string dogName; // 狗的名字
    int dogAge; // 狗的年齡
};
