#include <iostream>
#include <string>
using namespace std;

int main() {
    string phone;

    cout << "請輸入10碼手機號碼（例如: 0912345678）: ";
    cin >> phone;

    // 確認輸入長度正確
    if (phone.length() == 10 && phone.substr(0, 2) == "09") {
        string formatted = phone.substr(0, 4) + "-" + phone.substr(4, 3) + "-" + phone.substr(7, 3);
        cout << "格式化後的手機號碼: " << formatted << endl;
    }
    else {
        cout << "輸入錯誤，請輸入正確的10碼手機號碼（開頭需為09）" << endl;
    }

    return 0;
}