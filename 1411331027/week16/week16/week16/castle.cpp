#include <iostream>
#include "castle.h"
using namespace std;

// -------- Circ_1D 類別實作 --------
Circ_1D::Circ_1D() {
    cout << "[Circ_1D] 請輸入半徑: ";
    cin >> radius;
}

void Circ_1D::compute_circ() {
    double circ = 2 * pi * radius;
    cout << "圓周長: " << circ << endl;
}

double Circ_1D::get_radius() const {
    return radius;
}

double Circ_1D::get_pi() const {
    return pi;
}

// -------- Cron_3D 類別實作 --------
Cron_3D::Cron_3D() {
    cout << "[Cron_3D] 請輸入甜筒高度: ";
    cin >> height;
}

void Cron_3D::compute_volume() {
    volume = (1.0 / 3.0) * get_pi() * radius * radius * height;
    cout << "甜筒體積: " << volume << endl;
}

double Cron_3D::get_height() const {
    return height;
}

double Cron_3D::get_volume() const {
    return volume;
}

// -------- Pie_2D 類別實作 --------
Pie_2D::Pie_2D() {
    cout << "[Pie_2D] 請再次輸入半徑（用於面積計算）: ";
    cin >> radius;
}

void Pie_2D::compute_area() {
    area = get_pi() * radius * radius;
    cout << "圓面積: " << area << endl;
}

double Pie_2D::get_area() const {
    return area;
}

// -------- Cylinder_3D 類別實作 --------
Cylinder_3D::Cylinder_3D() {
    cout << "[Cylinder_3D] 請輸入圓柱體高度: ";
    cin >> height;
}

void Cylinder_3D::compute_volume() {
    volume = get_pi() * radius * radius * height;
    cout << "圓柱體體積: " << volume << endl;
}

void Cylinder_3D::compute_surface() {
    surface = 2 * get_pi() * radius * height + 2 * get_pi() * radius * radius;
    cout << "圓柱體表面積: " << surface << endl;
}

double Cylinder_3D::get_height() const {
    return height;
}

double Cylinder_3D::get_volume() const {
    return volume;
}

// -------- Castle 類別實作 --------
Castle::Castle() {
    cout << "[Castle] 建構城樓...\n";
}

void Castle::compute_volume() {
    // 將甜筒與圓柱體的體積相加
    total_volume = Cron_3D::get_volume() + Cylinder_3D::get_volume();
    cout << "城樓總體積 (甜筒 + 圓柱): " << total_volume << endl;
}

void Castle::compute_height() {
    // 將兩部分高度相加
    total_height = Cron_3D::get_height() + Cylinder_3D::get_height();
    cout << "城樓總高度: " << total_height << endl;
}
