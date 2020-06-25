// Задача №98. Есть ли цикл.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    int M[60][60];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            in >> M[i][j];
            if (M[i][j] == 1)
                M[i][j] = -10;
            else
                M[i][j] = 1000000;
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j] > M[i][k] + M[k][j]||M[i][j]== 1000000)
                    M[i][j] = M[i][k] + M[k][j];

    bool F = false;
    for (int i = 0; i < n; i++) 
        if (M[i][i] < 0) {
            cout << "1";
            F = true;
            break;
        }
    
    if (!F)
        cout << "0";
    in.close();
}

