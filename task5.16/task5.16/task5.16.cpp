// task5.16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void sort(int* &tree, int n)
{
	int k=1;
	int t=1;
	int i = n;
	int j = 0;
	while (i != 1)
	{
		i = i / 2;
		k++;
	}
	while (t != 0)
	{
		t = 0;
		for (i = n; i > 1; i--)
		{
			if (tree[i - 1] < tree[i / 2 - 1])
			{
				int temp;
				temp = tree[i - 1];
				tree[i - 1] = tree[i / 2 - 1];
				tree[i / 2 - 1] = temp;
				t++;
			}
		}
	}
}

void add(int* &tree, int n, int a)
{
	int *temp;
	temp = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		temp[i] = tree[i];
	}
	temp[n] = a;
	delete[] tree;
	tree = temp;
	sort(tree, n+1);
}

void del(int* &tree, int n)
{
	int *temp;
	temp = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		temp[i] = tree[i+1];
	}
	delete[] tree;
	tree = temp;
	sort(tree, n-1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string command;
	int ncommand;
	cin >> ncommand;
	int *tree;
	int n = 0;
	cin >> command;
	if (!command.compare(0, 3, "add")) {
		tree = new int[1];
		cin >> tree[0];
		n++;
		for (int i = 0; i < ncommand - 1; i++) {
			cin >> command;
			if (!command.compare(0, 3, "add")) {
				int  dat;
				cin >> dat;
				add(tree, n, dat);
				n++;
			}
			else if (!command.compare(0, 3, "del")) {
				del(tree, n);
				n--;
			}
			else if (!command.compare(0, 3, "get")) {
				cout << tree[0] << endl;
			}
		}
		delete[] tree;
	}
	else cout << "Начните с комманды add" << endl;
	system("pause");
	return 0;
}
