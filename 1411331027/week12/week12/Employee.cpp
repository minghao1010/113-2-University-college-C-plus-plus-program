#include <iostream>
#include "Employee.h"
using namespace std;

// �غc�l
Employee::Employee(const string& first, const string& last, const Date& dob, const Date& hire)
    : firstName(first), lastName(last), birthDate(dob), hireDate(hire) {
    cout << "�إ߭��u����G" << firstName << " " << lastName << endl;
}

// �]�w�W�r
Employee& Employee::setFirstName(const string& first) {
    this->firstName = first;
    return *this;  // �^�ǥثe����]�䴩�妡�I�s�^
}

// �]�w�m��
Employee& Employee::setLastName(const string& last) {
    this->lastName = last;
    return *this;
}

// �]�w�X�ͤ��
Employee& Employee::setBirthDate(const Date& date) {
    this->birthDate = date;
    return *this;
}

// �]�w��¾���
Employee& Employee::setHireDate(const Date& date) {
    this->hireDate = date;
    return *this;
}

// ��J��ơ]�z�L this ���妡�]�w�^
Employee& Employee::inputDetails() {
    string first, last;
    int bm, bd, by, hm, hd, hy;

    cout << "�п�J�W�r�G";
    cin >> first;
    cout << "�п�J�m��G";
    cin >> last;

    cout << "�п�J�X�ͤ���]�� �� �~�^�G";
    cin >> bm >> bd >> by;

    cout << "�п�J��¾����]�� �� �~�^�G";
    cin >> hm >> hd >> hy;

    return this->setFirstName(first)
        .setLastName(last)
        .setBirthDate(Date(bm, bd, by))
        .setHireDate(Date(hm, hd, hy));
}

// ��X���
Employee& Employee::print() {
    cout << "���u�m�W�G" << firstName << " " << lastName << endl;
    cout << "��¾����G";
    hireDate.print();
    cout << "  �X�ͤ���G";
    birthDate.print();
    cout << endl;
    return *this;
}

// �Ѻc�l
Employee::~Employee() {
    cout << "�P�����u����G" << firstName << " " << lastName << endl;
}
