#include <iostream>
#include <conio.h>
#include "TMatrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "������� ����������� ������: ";
	cin >> N;
	TMatrix<int> a(N), b(N), c(N);
	cout << "������� ������� 1:" << endl; 
	cin >> a;
	cout << "������� ������� 2:" << endl;
	cin >> b;
	cout << endl<< "������� 1:" << endl << a << endl;
	cout << "������� 2:" << endl << b << endl;
	c = a + b;
	cout << "�����:" << endl << c << endl;
	c = a - b;
	cout << "��������:" << endl << c << endl;
	c = a*b;
	cout << "������������:" << endl << c << endl;
	cout << "C��������:" << endl;
	
	if (a == b)  {  cout << "������� �����"; }
	else { cout << "������� �� �����"; }
	_getch();
	return 0;
}