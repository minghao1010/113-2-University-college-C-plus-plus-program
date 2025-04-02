#include <iostream>
#include <string>
#include "dog.h"
using namespace std;

Dog::Dog() {
    dogName = "james";
    dogAge = 11;
    cout << "\n�w�]������T:" << endl;
    printInfo();
    setDogInfo();
}

void Dog::setDogInfo() {
    cout << "\n�п�J�����W�r: ";
    getline(cin, dogName);

    // ����W�r���׳̦h��10�r��
    if (dogName.size() > 10) {
        cout << "�W�r \"" << dogName << "\" �W�L�̤j���� (10)�A�N����e10�Ӧr���C" << endl;
        dogName = dogName.substr(0, 10);
    }

    cout << "�п�J�����~��: ";
    cin >> dogAge;
    cin.ignore(); // �M����J�w�İϡA�קK�v�T�����J

    // ���Ҧ~�֬O�_�X�z�]1~19�^
    if (dogAge <= 0 || dogAge >= 20) {
        cout << "�L�Ī��~�֡I�~�֥������� 1 �� 19 �����A�w�]�� 0�C" << endl;
        dogAge = 0;
    }

    // ��̲ܳת��d����T
    printInfo();
}

string Dog::getName() const {
    return dogName;
}

int Dog::getAge() const {
    return dogAge;
}

void Dog::printInfo() const {
    cout << "�����W�r: " << getName() << "\n�����~��: " << getAge() << " ��" << endl;
}
