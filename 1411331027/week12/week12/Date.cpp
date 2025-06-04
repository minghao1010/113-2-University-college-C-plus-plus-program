#include <iostream>
#include <stdexcept>
#include "Date.h"
using namespace std;

// �غc�l�A��l�Ƥ�������ҦX�k��
Date::Date(int mn, int dy, int yr) {
    if (mn > 0 && mn <= monthsPerYear)
        month = mn;
    else
        throw invalid_argument("����������� 1 �� 12");

    year = yr;
    day = checkDay(dy);

    cout << "�إߤ������G";
    print();
    cout << endl;
}

// ��X����]�榡�G��/��/�~�^
void Date::print() const {
    cout << month << "/" << day << "/" << year;
}

// �Ѻc�l
Date::~Date() {
    cout << "�P���������G";
    print();
    cout << endl;
}

// ���Ҥ���O�_�X�z
unsigned int Date::checkDay(int testDay) const {
    static const int daysPerMonth[13] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // �|�~�B�z
    if (month == 2 && testDay == 29 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("�o�Ӥ�P�~�����A����L�ġI");
}
