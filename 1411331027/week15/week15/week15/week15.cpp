// main.cpp
#include <iostream>
#include <string>
#include "air.h"
using namespace std;

int main() {
    airliner air1;
    air1.display();
    air1.display_airliner();

    cout << "\n=== 建立一架貨機 ===\n";
    cargo cargo1;
    cargo1.display();         
    cargo1.display_cargo();   

    return 0;
}
