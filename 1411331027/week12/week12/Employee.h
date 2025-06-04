#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee {
public:
    // �غc�l�]�i�w�]���š^
    Employee(const std::string & = "", const std::string & = "", const Date & = Date(), const Date & = Date());

    // �ϥ� this ���Ф䴩�妡�]�w
    Employee& setFirstName(const std::string&);
    Employee& setLastName(const std::string&);
    Employee& setBirthDate(const Date&);
    Employee& setHireDate(const Date&);

    Employee& inputDetails();  // �q��L��J���
    Employee& print();         // �L�X���

    ~Employee();  // �Ѻc�l

private:
    std::string firstName;  // �W�r
    std::string lastName;   // �m��
    Date birthDate;         // �X�ͤ��
    Date hireDate;          // ��¾���
};

#endif
