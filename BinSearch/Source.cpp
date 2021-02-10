#include <fstream>

using namespace std;

int binsearch_last(int a[], int left, int right, int value)
{
	int middle, result = -1;
	while (left <= right)
	{
		middle = (right + left) / 2;
		if (a[middle] > value)
		{	
			right = middle - 1;
		}
		else
		{
			if (a[middle] == value)
			{
				result = middle + 1;
			}
			left = middle + 1;
		}
	}
	return result;
}
int binsearch_first(int a[], int left, int right, int value)
{
	int middle, result = -1;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (a[middle] < value)
		{
			
			left = middle + 1;
		}
		else
		{
			if (a[middle] == value)
			{
				result = middle + 1;
			}
			right = middle - 1;
		}
	}
	return result;
}
int main()
{
	int n, k, value;
	//ifstream fin("in.txt");
	//ofstream fout("out.txt");
	ifstream fin("binsearch.in");
	ofstream fout("binsearch.out");
	fin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
	fin >> k;
	int first, last;
	for (int i = 0; i < k; i++)
	{
		fin >> value;
		if (value < arr[0] || value > arr[n - 1])
		{
			fout << -1 << " " << -1 << endl;
		}
		else
		{
			first = binsearch_first(arr, 0, n - 1, value);
			last = binsearch_last(arr, 0, n - 1, value);
			fout << first << " " << last << endl;
		}
	}
	fin.close();
	fout.close();

	return 0;
}