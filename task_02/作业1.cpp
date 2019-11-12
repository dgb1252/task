#include<iostream>
using namespace std;
void merge(int arr1[], int m, int arr2[], int n)
{
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
		arr1[k--] = arr1[i] >= arr2[j] ? arr1[i--] : arr2[j--];
	while (j >= 0)
		arr1[k--] = arr2[j--];
}
int main()
{
	int arr1[5] = { 1,3,5 };
	int arr2[2] = { 2,4 };
	merge(arr1, 3, arr2, 2);
	for (int i = 0; i < 5; i++)cout << arr1[i] << '\t';
}