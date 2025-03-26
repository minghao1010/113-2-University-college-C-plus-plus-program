#include <iostream>
#include <string>
using namespace std;

// 定義 Dog 類別
class Dog {
public:
    // 預設建構子，建立一隻預設狗
    Dog() {
        dogName = "james";
        dogAge = 11;
        cout << "\n預設狗的資訊:" << endl;
        printInfo();
        setDogInfo();
    }

    // 設定狗的名字與年齡
    void setDogInfo() {
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

    // 取得狗的名字
    string getName() const {
        return dogName;
    }

    // 取得狗的年齡
    int getAge() const {
        return dogAge;
    }

    // 列印狗的資訊
    void printInfo() const {
        cout << "狗的名字: " << getName() << "\n狗的年齡: " << getAge() << " 歲" << endl;
    }

private:
    string dogName; // 狗的名字
    int dogAge; // 狗的年齡
};

// 主程式
int main() {
    // 直接透過建構子建立狗的物件，並讓使用者輸入屬性
    Dog myDog;

    cout << "\n新的狗的資訊:" << endl;
    myDog.printInfo();

    return 0;
}