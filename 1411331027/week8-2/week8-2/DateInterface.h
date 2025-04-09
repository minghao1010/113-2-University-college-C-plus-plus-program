#ifndef DATE_INTERFACE_H
#define DATE_INTERFACE_H

// ��H�����A�Ψөw�q�@�q��k�A��@���O�ݹ�@�o�Ǥ�k
class DateInterface {
public:
    // �]�w����]�µ����禡�^
    virtual void setDate(int year, int month, int day) = 0;

    // �L�X�褸���
    virtual void printGregorian() const = 0;

    // �L�X������
    virtual void printROC() const = 0;

    // �����Ѻc�l�A�������i���T����O����
    virtual ~DateInterface() {}
};

#endif