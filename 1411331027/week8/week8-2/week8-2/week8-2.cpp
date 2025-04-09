#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    int y, m, d;

    cout << "請輸入西元年、月、日（例如 2025 4 9）: ";
    cin >> y >> m >> d;

    try {
        Date date(y, m, d);         // 建構時自動驗證
        date.printGregorian();      // 顯示西元
        date.printROC();            // 顯示民國
    }
    catch (invalid_argument& e) {
        cerr << "錯誤: " << e.what() << endl;
    }

    return 0;
}