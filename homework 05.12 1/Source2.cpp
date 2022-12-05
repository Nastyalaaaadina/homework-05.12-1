#include <iostream>
#include <stdint.h>

using namespace std;
template <typename T>
void swap(T a, T b) {// �������, �������� ��� ������ ��������� a � 4b
	int temp = *a;// temp � ��������� ����������, �������� ������������ ������
	*a = *b;// ��������, �����������
	*b = temp;// �� ������ �������
}
template <typename T>
T divide(T arr[], T min, T max) {
	T pivot = arr[max]; // pivot ��� �������, ������� �������� ������� ������ �� ������� ������.
	T a = (min - 1);
	for (T b = min; b <= max - 1; b++) {// ���� ��� ��������� ���� ��������� � pivot 

		if (arr[b] < pivot) {// ��� ������ b, �������� ��� pivot 
			a++;//����� ������������� ���������� �� ������ ���� ����� ��� ���������, ��� � ������� �������� ���������� ������������� ����� ��������� �� 1
			swap(&arr[a], &arr[b]);// ����� ���������
		}
	}
	swap(&arr[a + 1], &arr[max]);
	return (a + 1);// ������� �������� �+1
}
template <typename T>
void quickSort(T arr[], T min, T max)// ������� ��� ����������
{
	if (min < max) {

		int array_divide = divide(arr, min, max);// ���� ������������� �������
		quickSort(arr, min, array_divide - 1);// ������� ���������� ��������� ��������� � ����� ������� �� �������� pivot
		quickSort(arr, array_divide + 1, max);// ������� ���������� ��������� ��������� � ������ ������� �� �������� pivot
	}
}// print array function 
template <typename T>
void printArr(T arr[], T size)//������� printArr
{
	int i;
	for (i = 0; i < size; i++) // ��� ���������� ������� �������...
		cout << arr[i] << " ";// ������� ����� ������� � ����� ��������
	cout << endl;
}
int main()// ��������� ������ ���������������� �������
{
	int arr[] = { 12, 3, 5, 7, 8, 15, 20, 32, 6 };// ��� ������

	int size = sizeof(arr) / sizeof(arr[0]);// ���������� ���������� ������, ������� �������� ������

	quickSort(arr, 0, size - 1);
	cout << "Sorted array: \n";// ����� ���������������� ������� � ����� ������
	printArr(arr, size); // �������, ��� �������� ������ �����
	
     return 0;// ������� 0
}
