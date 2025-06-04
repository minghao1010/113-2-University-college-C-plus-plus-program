#ifndef DATE_H
#define DATE_H

class Date {
public:
    static const unsigned int monthsPerYear = 12;  // �@�~��12�Ӥ�

    explicit Date(int = 1, int = 1, int = 1900);    // �غc�l�]�w�]��1900/1/1�^
    void print() const;                            // ��X���
    ~Date();                                        // �Ѻc�l�]��ܾP���T���^

private:
    unsigned int month;  // ��
    unsigned int day;    // ��
    unsigned int year;   // �~

    unsigned int checkDay(int) const;  // �ˬd����O�_���ġ]�t�|�~�^
};

#endif