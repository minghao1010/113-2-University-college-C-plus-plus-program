#include <iostream>
#include <string>
#include"dog.h"
using namespace std;

Dog::Dog(){
    dogName = "james";
    dogAge = 11;
    cout << "\n�w�]������T:" << endl;
    printInfo();
    setDogInfo();
}

void Dog::setDogInfo() {
    cout << "\n�п�J�����W�r: ";
    getline(cin, dogName);

    cout << "�п�J�����~��: ";
    cin >> dogAge;

    // ���Ҧ~�֬O�_�X�z�]<20�^
    if (dogAge <= 0 || dogAge >= 20) {
        cout << "�L�Ī��~�֡I�~�֥������� 1 �� 19 �����A�w�]�� 0�C" << endl;
        dogAge = 0;
    }
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