#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    Employee e;  // 建立員工物件

    e.inputDetails().print();  // 鍊式呼叫：輸入完馬上印出

    return 0;
}
