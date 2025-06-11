#ifndef CASTLE_H
#define CASTLE_H

// 類別：Circ_1D（圓周長）
class Circ_1D {
protected:
    double radius;        // 半徑
    const double pi = 3.14;

public:
    Circ_1D();            // 建構元
    void compute_circ();  // 計算圓周長
    double get_radius() const;
    double get_pi() const;
};

// 類別：Cron_3D（甜筒）
class Cron_3D : public Circ_1D {
protected:
    double height;       // 高度
    double volume;       // 體積

public:
    Cron_3D();           // 建構元
    void compute_volume(); // 計算甜筒體積
    double get_height() const;
    double get_volume() const;
};

// 類別：Pie_2D（圓餅，面積用）
class Pie_2D : public Circ_1D {
protected:
    double area;         // 面積

public:
    Pie_2D();            // 建構元
    void compute_area(); // 計算圓面積
    double get_area() const;
};

// 類別：Cylinder_3D（圓柱體）
class Cylinder_3D : public Pie_2D {
protected:
    double height;       // 高度
    double volume;       // 體積
    double surface;      // 表面積

public:
    Cylinder_3D();           // 建構元
    void compute_volume();   // 計算體積
    void compute_surface();  // 計算表面積
    double get_height() const;
    double get_volume() const;
};

// 類別：Castle（城樓）
class Castle : public Cron_3D, public Cylinder_3D {
private:
    double total_volume; // 總體積
    double total_height; // 總高度

public:
    Castle();               // 建構元
    void compute_volume();  // 計算總體積
    void compute_height();  // 計算總高度
};

#endif // CASTLE_H
