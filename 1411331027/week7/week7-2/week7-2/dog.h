#include <iostream>
#include <string>
using namespace std;

// �w�q Dog ���O
class Dog {
public:
    // �w�]�غc�l�A�إߤ@���w�]��
    Dog();

    // �]�w�����W�r�P�~��
    void setDogInfo();

    // ���o�����W�r
    string getName() const;

    // ���o�����~��
    int getAge() const;

    // �C�L������T
    void printInfo() const;
        

private:
    string dogName; // �����W�r
    int dogAge; // �����~��
};
