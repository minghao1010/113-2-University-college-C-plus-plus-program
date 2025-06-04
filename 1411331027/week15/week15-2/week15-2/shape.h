// shape.h
#include <iostream>
using namespace std;

// 基本類別：square_2D（長方形）
class square_2D {
protected:
    double length;
    double width;
public:
    square_2D(double l = 1.0, double w = 1.0); // 建構子
    virtual ~square_2D();                      // 解構子
    void print_2D() const;                     // 印出長、寬、面積
};

// 衍生類別：rect_3D（長方體）
class rect_3D : public square_2D {
private:
    double height;
public:
    rect_3D(double l = 1.0, double w = 1.0, double h = 1.0); // 建構子
    ~rect_3D();                                              // 解構子
    void print_3D() const;                                   // 印出長、寬、高、體積
};