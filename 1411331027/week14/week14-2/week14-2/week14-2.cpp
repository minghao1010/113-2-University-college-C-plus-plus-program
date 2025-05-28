#include <iostream>
using namespace std;

class Matrix {
public:
    int row, column;
    int** element;

    // 建構子
    Matrix(int m, int n) {
        row = m;
        column = n;
        element = new int* [row];
        for (int i = 0; i < row; ++i)
            element[i] = new int[column];
    }

    // 建構子 + 輸入
    Matrix(char name, int m, int n) {
        row = m;
        column = n;
        element = new int* [row];
        for (int i = 0; i < row; ++i)
            element[i] = new int[column];

        cout << "請輸入矩陣 " << name << "（" << row << "x" << column << "）:\n";
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j) {
                cout << name << "[" << i << "][" << j << "] = ";
                cin >> element[i][j];
            }
    }

    // 複製建構子
    Matrix(const Matrix& src) {
        row = src.row;
        column = src.column;
        element = new int* [row];
        for (int i = 0; i < row; ++i) {
            element[i] = new int[column];
            for (int j = 0; j < column; ++j)
                element[i][j] = src.element[i][j];
        }
    }

    // 遞乘 *=
    Matrix& operator*=(const Matrix& other) {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j)
                element[i][j] *= other.element[i][j];
        return *this;
    }

    // 遞加 +=
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j)
                element[i][j] += other.element[i][j];
        return *this;
    }

    // 遞減 -=
    Matrix& operator-=(const Matrix& other) {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j)
                element[i][j] -= other.element[i][j];
        return *this;
    }

    // 印出矩陣
    void print(const string& title) const {
        cout << title << ":\n";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j)
                cout << element[i][j] << '\t';
            cout << '\n';
        }
        cout << endl;
    }
};

int main() {
    int row, column;
    cout << "請輸入矩陣的行數（row）: ";
    cin >> row;
    cout << "請輸入矩陣的列數（column）: ";
    cin >> column;

    Matrix a('A', row, column);
    Matrix b('B', row, column);
    Matrix a_orig = a;  // 儲存原始 A

    a.print("原始矩陣 A");
    b.print("原始矩陣 B");

    a *= b;
    a.print("A * B 結果");

    a = a_orig;
    a += b;
    a.print("A + B 結果");

    a = a_orig;
    a -= b;
    a.print("A - B 結果");

    return 0;
}
