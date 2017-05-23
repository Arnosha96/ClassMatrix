#include <iostream>
#include <conio.h>
#include "TMatrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите размерность матриц: ";
	cin >> N;
	TMatrix<int> a(N), b(N), c(N);
	cout << "Введите матрицу 1:" << endl; 
	cin >> a;
	cout << "Введите матрицу 2:" << endl;
	cin >> b;
	cout << endl<< "Матрица 1:" << endl << a << endl;
	cout << "Матрица 2:" << endl << b << endl;
	c = a + b;
	cout << "Сумма:" << endl << c << endl;
	c = a - b;
	cout << "Разность:" << endl << c << endl;
	c = a*b;
	cout << "Произведение:" << endl << c << endl;
	cout << "Cравнение:" << endl;
	
	if (a == b)  {  cout << "Матрицы равны"; }
	else { cout << "Матрицы не равны"; }
	_getch();
	return 0;
}