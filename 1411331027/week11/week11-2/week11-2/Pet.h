#ifndef PET_H
#define PET_H

#include <string>
#include "Date.h"

class Pet {
public:
    // �غc�l�G�ǤJ�����B�W�r�B�ͤ�B��i��
    Pet(const std::string&, const std::string&, const Date&, const Date&);
    void print() const; // �L�X�d����T
    ~Pet(); // �Ѻc�l�A�L�X�ԲӸ�T

private:
    std::string species; // �d������
    std::string name;    // �W�r
    Date birthDate;      // �X�ͤ��
    Date adoptionDate;   // ��i���

    void validateAge() const; // �����d���~�ֻP�������
};

#endif
