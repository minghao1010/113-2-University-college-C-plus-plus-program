#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Date.h"
using namespace std;

// �غc�l
Date::Date(int y, int m, int d) {
    setDate(y, m, d); // �I�s setDate �ˬd�ó]�w
}

// �]�w���������
void Date::setDate(int y, int m, int d) {
    if (!isValidDate(y, m, d)) {
        throw invalid_argument("Invalid date entered.");
    }
    year = y;
    month = m;
    day = d;
}

// �P�_�O�_���|�~
bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// ���Ҥ���X�k��
bool Date::isValidDate(int y, int m, int d) const {
    if (y < 1900 || y > 2099 || m < 1 || m > 12) return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int maxDay = (m == 2 && isLeapYear(y)) ? 29 : daysInMonth[m - 1];

    return d >= 1 && d <= maxDay;
}

// ��X�褸�榡
void Date::printGregorian() const {
    cout << "Gregorian Date: "
        << setfill('0') << setw(4) << year << "-"
        << setw(2) << month << "-"
        << setw(2) << day << endl;
}

// ��X����榡
void Date::printROC() const {
    int rocYear = year - 1911;
    cout << "Minguo Date: ����"
        << rocYear << "�~"
        << month << "��"
        << day << "��" << endl;
}
