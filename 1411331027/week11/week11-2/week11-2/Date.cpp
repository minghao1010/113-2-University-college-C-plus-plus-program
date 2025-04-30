#include <iostream>
#include <array>
#include <stdexcept>
#include "Date.h"
using namespace std;

// �غc�l�G���Ҥ���P����O�_���T
Date::Date(int mn, int dy, int yr) {
    if (mn > 0 && mn <= monthsPerYear)
        month = mn;
    else
        throw invalid_argument("����������� 1 �� 12");

    year = yr;
    day = checkDay(dy); // �ˬd����O�_�X�k

    cout << "�إߤ������: ";
    print();
    cout << endl;
}

// �ˬd��J����O�_�X�k
unsigned int Date::checkDay(int testDay) const {
    static const array<int, monthsPerYear + 1> daysPerMonth =
    { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    // �@�뱡�p
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // �|�~�P�_�]2��29��^
    if (month == 2 && testDay == 29 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("������X�k");
}

// �L�X���
void Date::print() const {
    cout << month << '/' << day << '/' << year;
}

// �Ѻc�l
Date::~Date() {
    cout << "�R���������: ";
    print();
    cout << endl;
}

// getter �������
int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

// �P�_�O�_����t�@����]�ά۵��^
bool Date::isBefore(const Date& other) const {
    if (year < other.year) return true;
    if (year == other.year && month < other.month) return true;
    if (year == other.year && month == other.month && day <= other.day) return true;
    return false;
}