// shape.h
#include <iostream>
using namespace std;

// �����O�Gsquare_2D�]����Ρ^
class square_2D {
protected:
    double length;
    double width;
public:
    square_2D(double l = 1.0, double w = 1.0); // �غc�l
    virtual ~square_2D();                      // �Ѻc�l
    void print_2D() const;                     // �L�X���B�e�B���n
};

// �l�����O�Grect_3D�]������^
class rect_3D : public square_2D {
private:
    double height;
public:
    rect_3D(double l = 1.0, double w = 1.0, double h = 1.0); // �غc�l
    ~rect_3D();                                              // �Ѻc�l
    void print_3D() const;                                   // �L�X���B�e�B���B��n
};