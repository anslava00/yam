// Задача №7. Заправки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include<stack>
#include<vector>
#include<set>

#define INF 1000000000

using namespace std;

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    int* bens = new int[n];
    for (int i = 0; i < n; i++)
        in >> bens[i];

    int** M = new int* [n];
    for (int i = 0; i < n; i++)
        M[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                M[i][j] = 0;
            else
                M[i][j] = INF;

    int m;
    in >> m;
    for (int i = 0; i < m; i++) {
        int tmpi, tmpj;
        in >> tmpi >> tmpj;
        tmpi--; tmpj--;
        M[tmpi][tmpj] = bens[tmpi];
        M[tmpj][tmpi] = bens[tmpj];
    }

    int s = 0, f = n-1;
    set<pair<int, int>>c;
    int* d = new int[n];
    bool* b = new bool[n];
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        b[i] = true;
    }
    d[s] = 0;
    c.insert(make_pair(0, s));

    while (!c.empty()) {
        int i = c.begin()->second;
        b[i] = false;
        c.erase(c.begin());
        for (int j = 0; j < n; ++j)
            if (b[j] && d[j] > d[i] + M[i][j]) {
                c.erase(make_pair(d[j], j));
                d[j] = d[i] + M[i][j];
                c.insert(make_pair(d[j], j));
            }
    }
    if (d[f] < INF) {
        cout << d[f];
    }
    else cout << -1;
    in.close();
}

