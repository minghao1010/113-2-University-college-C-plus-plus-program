#ifndef DATE_H
#define DATE_H

class Date {
public:
    static const unsigned int monthsPerYear = 12; // �@�~��12�Ӥ�
    Date(int = 1, int = 1, int = 2000); // �w�]�غc�l
    void print() const; // �L�X���
    ~Date(); // �Ѻc�l�A��ܸѺc����
    int getYear() const; // ���o�~��
    int getMonth() const; // ���o���
    int getDay() const; // ���o���

    bool isBefore(const Date& other) const; // ����O�_����t�@����]�t����^

private:
    unsigned int month; // ����]1~12�^
    unsigned int day; // ���
    unsigned int year; // �~��

    unsigned int checkDay(int) const; // �ˬd����O�_�X�k
};

#endif
