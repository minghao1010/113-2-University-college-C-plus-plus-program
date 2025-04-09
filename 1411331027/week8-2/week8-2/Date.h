#ifndef DATE_H
#define DATE_H

class Date {
public:
    // �غc�l�G�i���w����A���ѹw�]�Ȭ� 1990/1/1
    Date(int year = 1990, int month = 1, int day = 1);

    // �]�w����A�]�t�X�k���ˬd
    void setDate(int year, int month, int day);

    // ��X�褸����榡 YYYY-MM-DD
    void printGregorian() const;

    // ��X�������榡 ����XXX�~X��X��
    void printROC() const;

private:
    int year;
    int month;
    int day;

    // �P�_�O�_���|�~
    bool isLeapYear(int y) const;

    // �ˬd����O�_����
    bool isValidDate(int y, int m, int d) const;
};

#endif