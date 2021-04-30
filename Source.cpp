#include <iostream>
#include <cmath>
#include <list>
using namespace std;
int hash1(int data, list<int> *mass[])
{
	if (mass[data % 11]==NULL)
	{
		mass[data%11] = new list<int>();
		mass[data % 11]->push_back(data);
		return data % 11;
	}
	else
	{
	int i = 1;
	while (mass[(data  + i)%11] != NULL)
	{
		i++;
	}
	mass[(data  + i) % 11] = new list<int>();
	mass[(data  + i) % 11]->push_back(data);
	return (data  + i) % 11;
	}
}
int hash2(int data,list<int> *mass[])
{
	if (mass[data % 11] == NULL)
	{
		mass[data % 11] = new list<int>();
		mass[data % 11]->push_back(data);
		return data % 11;
	}
	else
	{
		int i = 1,q=3;
		while (mass[(data  + i*q) % 11] != NULL)
		{
			i++;
		}
		mass[(data + i * q) % 11] = new list<int>();
		mass[(data + i * q) % 11]->push_back(data);
		return (data + i * q) % 11;
	}
}
int hash3(int data, list<int> *mass[])
{
	if (mass[(int)pow(data,2) % 11] == NULL)
	{
		mass[(int)pow(data, 2) % 11] = new list<int>();
		mass[(int)pow(data, 2) % 11]->push_back(data);
		return (int)pow(data, 2) % 11;
	}
	else
	{
		int i = 0;
		while (mass[(long int)pow(2,data + i)% 11] != NULL)
		{
			i++;
		}
		mass[(long int)pow(2, data + i) % 11] = new list<int>();
		mass[(long int)pow(2, data + i) % 11]->push_back(data);
		return (long int)pow(2, data + i) % 11;
	}
}
int main()
{    list<int> *mass[11];
	 for (int i = 0; i < 11; i++) mass[i] = NULL;
	 cout << "funkciya posledovatel'nogo razmesheniya: " << endl;
	 cout << hash1(1, mass) << endl;
	 cout << hash1(5, mass)<<endl;
	 cout << hash1(12, mass) << endl;
	 cout << hash1(11, mass) << endl;
	 cout << hash1(4, mass) << endl;
	 cout << hash1(8, mass) << endl;
	 cout << hash1(15, mass) << endl;
	 cout << hash1(17, mass) << endl;
	 for (int i = 0; i < 11; i++) mass[i] = NULL;
	 cout << "funkciya lineynogo razmesheniya: " << endl;
	 cout << hash2(1, mass) << endl;
	 cout << hash2(5, mass) << endl;
	 cout << hash2(12, mass) << endl;
	 cout << hash2(11, mass) << endl;
	 cout << hash2(4, mass) << endl;
	 cout << hash2(8, mass) << endl;
	 cout << hash2(15, mass) << endl;
	 cout << hash2(17, mass) << endl;
	 for (int i = 0; i < 11; i++) mass[i] = NULL;
	 cout << "funkciya dvoynogo heshirovaniya: " << endl;
	 cout << hash3(1, mass) << endl;
	 cout << hash3(5, mass) << endl;
	 cout << hash3(12, mass) << endl;
	 cout << hash3(11, mass) << endl;
	 cout << hash3(4, mass) << endl;
	 cout << hash3(8, mass) << endl;
	 cout << hash3(15, mass) << endl;
	 cout << hash3(17, mass) << endl;
	 system("pause");
	 return 0;
}