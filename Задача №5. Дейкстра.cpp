// Задача №5. Дейкстра.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include<set>

#define INF 1000000000
using namespace std;

int main() {
	ifstream in("input.txt");
	int n, f, s; 
	set<pair<int, int>>c;
	in >> n >> s >> f; 
	s--; f--;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
		
	int* d = new int[n]; 
	bool* b = new bool[n];

	for (int i = 0; i < n; i++) {
		d[i] = INF; 
		b[i] = true;
		for (int j = 0; j < n; j++) {
			in >> a[i][j];
			if (a[i][j] < 0)a[i][j] = INF;
		}
	}

	d[s] = 0; 
 	c.insert(make_pair(0, s));

	while (!c.empty()) {
		int i = c.begin()->second; 
		b[i] = false;
		 c.erase(c.begin());
		for (int j = 0; j < n; ++j)
			if (b[j] && d[j] > d[i] + a[i][j]) {
				c.erase(make_pair(d[j], j));
				d[j] = d[i] + a[i][j]; 			
				c.insert(make_pair(d[j], j));
			}
	}
	if (d[f] < INF) {
		cout << d[f];
	}
	else cout << -1;
	in.close();
}
