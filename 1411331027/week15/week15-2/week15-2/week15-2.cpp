// main.cpp
#include <iostream>
#include "shape.h"
using namespace std;

int main() {
    double length, width, height;

    // 輸入長與寬
    cout << "請輸入長與寬（用於長方形與長方體）：" << endl;
    cout << "長：";
    cin >> length;
    cout << "寬：";
    cin >> width;

    // 建立並顯示二維長方形
    square_2D rect2D(length, width);
    cout << "\n=== 二維長方形資訊 ===" << endl;
    rect2D.print_2D();

    // 輸入高度
    cout << "\n請輸入高（用於三維長方體）：" << endl;
    cout << "高：";
    cin >> height;

    // 建立並顯示三維長方體
    rect_3D rect3D(length, width, height);
    cout << "\n=== 三維長方體資訊 ===" << endl;
    rect3D.print_3D();

    return 0;
}
