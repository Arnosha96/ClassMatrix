#pragma once
#include <string>
#include <iostream>
#include "TVector.h"
#include <iomanip>

template <class T> 
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix(int s) : TVector<TVector<T>>(s)
	{
		for (int i(0); i < s; i++)
			pVector[i] = TVector<T>(s - i, i);
	}

	TMatrix (const TVector<T> &mt) : TVector<TVector<T>>(mt) {}
	TMatrix(const TVector<TVector<T>> &mt) : TVector<TVector<T>>(mt){}
	bool operator == (const TMatrix<T> &mt)
	{
		bool res = true;
		if (this != &mt)
		{
			if (Size != mt.Size) res = false;
			else

			{

				for (int i(0); i < Size; i++)
				{
					if (pVector[i] == mt.pVector[i]) res = true;
					else res = false;

				}
			}
		}
		return res;
	}

	TMatrix & operator = (const TMatrix<T> &mt)
	{
		if (this != &mt)
		{
			if (Size != mt.Size)
			{
				delete[]pVector;
				pVector = new TVector<T>[mt.Size];
			}
			for (int i(0); i < Size; i++) pVector[i] = mt.pVector[i];
		}
		return *this;
	}

	TMatrix  operator + (const TMatrix<T> &mt)
	{
		return TVector<TVector<T>>::operator+(mt); // вектор из векторов в котором хранятся данные шаблонного типа T
	}

	TMatrix  operator - (const TMatrix<T> &mt)
	{
		return TVector<TVector<T>>::operator-(mt);
	}

	TMatrix  operator * (const TMatrix<T> &mt)
	{
		
		TMatrix rez(Size);
		
		for (int i = 0; i < Size; i++)
		for (int j = i; j < Size; j++) rez.pVector[i][j] = 0;

		for (int i= 0; i < Size; i++)
		for (int j = i; j < Size; j++){
			
		for (int m = i; m <=j; m++)
			rez.pVector[i][j]+= pVector[i][m] * mt.pVector[m][j];
		}
		return rez;
	}


	friend istream & operator >> (istream &in, TMatrix &mt)
	{
		for (int i(0); i < mt.Size; i++) in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<(ostream &out, const TMatrix &mt)
	{
		
		string z = " ";
		for (int i(0); i < mt.Size; i++)
		
		{
			out << setw(4)<<mt.pVector[i] << endl;
			out << setw(4*i+4)<<z;
		}
		
		return out;
	}
};