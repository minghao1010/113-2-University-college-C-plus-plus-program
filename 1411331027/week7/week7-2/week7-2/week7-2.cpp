#include <iostream>
#include <string>
#include"dog.h"
using namespace std;

// 主程式
int main() {
    // 直接透過建構子建立狗的物件，並讓使用者輸入屬性
    Dog myDog;

    cout << "\n新的狗的資訊:" << endl;
    myDog.printInfo();

    return 0;
}