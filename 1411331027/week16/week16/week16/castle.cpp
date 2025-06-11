#include <iostream>
#include "castle.h"
using namespace std;

// -------- Circ_1D ���O��@ --------
Circ_1D::Circ_1D() {
    cout << "[Circ_1D] �п�J�b�|: ";
    cin >> radius;
}

void Circ_1D::compute_circ() {
    double circ = 2 * pi * radius;
    cout << "��P��: " << circ << endl;
}

double Circ_1D::get_radius() const {
    return radius;
}

double Circ_1D::get_pi() const {
    return pi;
}

// -------- Cron_3D ���O��@ --------
Cron_3D::Cron_3D() {
    cout << "[Cron_3D] �п�J��������: ";
    cin >> height;
}

void Cron_3D::compute_volume() {
    volume = (1.0 / 3.0) * get_pi() * radius * radius * height;
    cout << "������n: " << volume << endl;
}

double Cron_3D::get_height() const {
    return height;
}

double Cron_3D::get_volume() const {
    return volume;
}

// -------- Pie_2D ���O��@ --------
Pie_2D::Pie_2D() {
    cout << "[Pie_2D] �ЦA����J�b�|�]�Ω󭱿n�p��^: ";
    cin >> radius;
}

void Pie_2D::compute_area() {
    area = get_pi() * radius * radius;
    cout << "�ꭱ�n: " << area << endl;
}

double Pie_2D::get_area() const {
    return area;
}

// -------- Cylinder_3D ���O��@ --------
Cylinder_3D::Cylinder_3D() {
    cout << "[Cylinder_3D] �п�J��W�鰪��: ";
    cin >> height;
}

void Cylinder_3D::compute_volume() {
    volume = get_pi() * radius * radius * height;
    cout << "��W����n: " << volume << endl;
}

void Cylinder_3D::compute_surface() {
    surface = 2 * get_pi() * radius * height + 2 * get_pi() * radius * radius;
    cout << "��W����n: " << surface << endl;
}

double Cylinder_3D::get_height() const {
    return height;
}

double Cylinder_3D::get_volume() const {
    return volume;
}

// -------- Castle ���O��@ --------
Castle::Castle() {
    cout << "[Castle] �غc����...\n";
}

void Castle::compute_volume() {
    // �N�����P��W�骺��n�ۥ[
    total_volume = Cron_3D::get_volume() + Cylinder_3D::get_volume();
    cout << "�����`��n (���� + ��W): " << total_volume << endl;
}

void Castle::compute_height() {
    // �N�ⳡ�����׬ۥ[
    total_height = Cron_3D::get_height() + Cylinder_3D::get_height();
    cout << "�����`����: " << total_height << endl;
}
