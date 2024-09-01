// Console_Minesweeper.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <locale.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    setlocale(0, "");
    int k, c;
    size_t x, y, m, n;
    cin >> m >> n >> k;
    vector<vector<int>> field(m, vector<int>(n, 0));
    vector<array<size_t, 2>> cells1;
    vector<array<size_t, 2>> cells2;
    for (int i = 0; i != k; ++i) {
        cin >> x >> y;
        field[x - 1][y - 1] = -1;
    }
    x = 0, y = 0;
    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (field[i][j] != -1) {
                cells2.clear();
                cells1 = {
                    {i - 1, j - 1},
                    {i - 1, j},
                    {i - 1, j + 1},
                    {i, j - 1},
                    {i, j + 1},
                    {i + 1, j - 1},
                    {i + 1, j},
                    {i + 1, j + 1}
                };
                for (size_t k = 0; k != 8; ++k) {
                    if (cells1[k][0] < m and cells1[k][1] < n) {
                        cells2.push_back(cells1[k]);
                    }
                }
                c = 0;
                for (size_t h = 0; h != cells2.size(); ++h) {
                    x = cells2[h][0], y = cells2[h][1];
                    if (field[x][y] == -1) { ++c; }
                }
                field[i][j] = c;
            }
        }
    }
    for (vector<int> line : field) {
        for (int value : line) {
            switch (value) {
            case -1:
                cout << "* ";
                break;
            default:
                cout << value << ' ';
            }

        }
        cout << '\n';
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
