#include <iostream>
#include <stdexcept>
#include "Pet.h"
using namespace std;

// �غc�l�G��l�Ƹ�ƨ����Ҧ~�֦X�z��
Pet::Pet(const string& petSpecies, const string& petName,
    const Date& birth, const Date& adoption)
    : species(petSpecies), name(petName),
    birthDate(birth), adoptionDate(adoption) {
    validateAge(); // �ˬd�~�ֻP�������
    cout << "�إ��d������: " << name << " (" << species << ")" << endl;
}

// �L�X�d�����
void Pet::print() const {
    cout << "�d���W��: " << name << ", ����: " << species
        << "\n  �ͤ�: ";
    birthDate.print();
    cout << "\n  ��i��: ";
    adoptionDate.print();
    cout << endl;
}

// ���Ҧ~�֡]0~20���^�B�ͤ饲������ε����i��
void Pet::validateAge() const {
    if (!birthDate.isBefore(adoptionDate)) {
        throw invalid_argument("�ͤ饲������ε����i��I");
    }

    int age = adoptionDate.getYear() - birthDate.getYear();
    if (age < 0 || age > 20) {
        throw invalid_argument("�d���~�֥������� 0 �� 20 �������I");
    }
}

// �Ѻc�l�G�L�X�d��������
Pet::~Pet() {
    cout << "\n�R���d��: " << name << endl;
    print();
}