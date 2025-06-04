// shape.cpp
#include <iostream>
#include "shape.h"
using namespace std;

// square_2D 類別成員的實作
square_2D::square_2D(double l, double w) {
    length = l;
    width = w;
    cout << "square_2D 建構子被呼叫" << endl;
}

square_2D::~square_2D() {
    cout << "square_2D 解構子被呼叫" << endl;
}

void square_2D::print_2D() const {
    cout << "二維長方形：" << endl;
    cout << "長度 = " << length << endl;
    cout << "寬度 = " << width << endl;
    cout << "面積 = " << length * width << endl;
}

// rect_3D 類別成員的實作
rect_3D::rect_3D(double l, double w, double h) : square_2D(l, w) {
    height = h;
    cout << "rect_3D 建構子被呼叫" << endl;
}

rect_3D::~rect_3D() {
    cout << "rect_3D 解構子被呼叫" << endl;
}

void rect_3D::print_3D() const {
    cout << "三維長方體：" << endl;
    cout << "長度 = " << length << endl;
    cout << "寬度 = " << width << endl;
    cout << "高度 = " << height << endl;
    cout << "體積 = " << length * width * height << endl;
}
