#include <iostream>
#include "castle.h"
using namespace std;

int main() {
    cout << "=== 建立城樓模型 ===" << endl;

    // 建立 Castle 物件
    Castle castle;

    // 計算甜筒體積
    castle.Cron_3D::compute_volume();

    // 計算圓柱體體積與表面積
    castle.Cylinder_3D::compute_volume();
    castle.Cylinder_3D::compute_surface();

    // 計算整體城樓的體積與總高度
    castle.compute_volume();
    castle.compute_height();

    return 0;
}
