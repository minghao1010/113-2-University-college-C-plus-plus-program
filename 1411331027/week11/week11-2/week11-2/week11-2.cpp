#include <iostream>
#include <vector>
#include <memory>
#include "Pet.h"
using namespace std;

int main() {
    vector<unique_ptr<Pet>> pets; // 儲存多隻寵物
    int n;

    cout << "請輸入寵物數量: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string species, name;
        int bMonth, bDay, bYear;
        int aMonth, aDay, aYear;

        cout << "\n輸入第 " << i + 1 << " 隻寵物資料：" << endl;
        cout << "種類: ";
        cin >> species;
        cout << "名字: ";
        cin >> name;
        cout << "生日 (月 日 年): ";
        cin >> bMonth >> bDay >> bYear;

        cout << "領養日 (月 日 年): ";
        cin >> aMonth >> aDay >> aYear;

        try {
            Date birth(bMonth, bDay, bYear);
            Date adoption(aMonth, aDay, aYear);
            pets.push_back(make_unique<Pet>(species, name, birth, adoption));
        }
        catch (const exception& e) {
            cerr << "建立寵物時發生錯誤: " << e.what() << "\n略過此筆資料。\n";
        }
    }

    cout << "\n所有寵物資料輸入完畢，程式結束。\n";
    return 0;
}
