#include<iostream>
using namespace std;

void pryam(int i, int* a, size_t n)
{
	for (size_t j = 0; j<n; j++)
		if (a[j] == i)
		{
		cout << j << " ";
		pryam(j, a, n);
		}
}


void obrat(int i, int* a, size_t n)
{
	for (size_t j = 0; j<n; j++)
		if (a[j] == i)
		{
		obrat(j, a, n);
		}
	if (i != -1) cout << i << " ";
}

void simmetr(int i, int* a, size_t n)
{
	int x = 0;
	for (size_t j = 0; j<n; j++)
		if (a[j] == i)
		{
		simmetr(j, a, n);
		if ((!x) && (i != -1)) cout << i << " ";
		x++;
		}
	if (x == 0)
	{
		cout << i << " ";
	}
}


int main()
{
	size_t n;
	cin >> n;
	int* tree = new int[n];
	for (size_t i = 0; i<n; i++)
		cin >> tree[i];

	pryam(-1, tree, n);
	cout << endl;

	obrat(-1, tree, n);
	cout << endl;

	simmetr(-1, tree, n);
	cout << endl;

	delete[] tree;
	system("pause");
	return 0;
}
