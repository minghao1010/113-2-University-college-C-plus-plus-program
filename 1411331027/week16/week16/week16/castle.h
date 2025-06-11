#ifndef CASTLE_H
#define CASTLE_H

// ���O�GCirc_1D�]��P���^
class Circ_1D {
protected:
    double radius;        // �b�|
    const double pi = 3.14;

public:
    Circ_1D();            // �غc��
    void compute_circ();  // �p���P��
    double get_radius() const;
    double get_pi() const;
};

// ���O�GCron_3D�]�����^
class Cron_3D : public Circ_1D {
protected:
    double height;       // ����
    double volume;       // ��n

public:
    Cron_3D();           // �غc��
    void compute_volume(); // �p�Ⲣ����n
    double get_height() const;
    double get_volume() const;
};

// ���O�GPie_2D�]���A���n�Ρ^
class Pie_2D : public Circ_1D {
protected:
    double area;         // ���n

public:
    Pie_2D();            // �غc��
    void compute_area(); // �p��ꭱ�n
    double get_area() const;
};

// ���O�GCylinder_3D�]��W��^
class Cylinder_3D : public Pie_2D {
protected:
    double height;       // ����
    double volume;       // ��n
    double surface;      // ���n

public:
    Cylinder_3D();           // �غc��
    void compute_volume();   // �p����n
    void compute_surface();  // �p����n
    double get_height() const;
    double get_volume() const;
};

// ���O�GCastle�]���ӡ^
class Castle : public Cron_3D, public Cylinder_3D {
private:
    double total_volume; // �`��n
    double total_height; // �`����

public:
    Castle();               // �غc��
    void compute_volume();  // �p���`��n
    void compute_height();  // �p���`����
};

#endif // CASTLE_H
