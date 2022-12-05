#include <iostream>
#include <stdint.h>

using namespace std;
template <typename T>
void countingSort(T arr[], T size) {// ������ ������ ���� �� ����� max+1,�� ������ ��������� ��� ��� int count[max+1] � �++� ������ ��� �� �� ������������ ������������ ��������� ������, ������� ������ ��������� ���������� 
    int output[10];// �������� ������ �������� ���.10 ���������
    int count[10];
    int maximum = arr[0];

    
    for (int i = 1; i < size; i++) {// ����� ����� ������� ������� �������
        if (arr[i] > maximum)
            maximum = arr[i];
    }

  
    for (int i = 0; i <= maximum; ++i) {// ���������������� ���� ������ ������.
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {// ��������� �������� ������� ��������
        count[arr[i]]++;
    }
    for (int i = 1; i <= maximum; i++) {// ��������� ���������� ���������� ������� �������
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {// ����� ������ ������� �������� ��������� ������� � ������� �����  
        output[count[arr[i]] - 1] = arr[i];// ��������� �������� � ������ ������
        count[arr[i]]--;
    }

   
    for (int i = 0; i < size; i++) {//����������� ��������������� �������� � �������� ������
        arr[i] = output[i];
    }
}


void printArr(int arr[], int size) {// ������� ��� ������ �������
    for (int i = 0; i < size; i++)// ����� ������������ �������
        cout << arr[i] << " ";// ����� ������� �� �����������
    cout << endl;
}


int main() {// ��������� ������ ���������������� �������
    int arr[] = { 9, 7, 7, 8, 2, 3, 1 };// ������ ����� ������
    int n = sizeof(arr) / sizeof(arr[0]);// ���������� ���������� ������, ������� �������� ������
    countingSort(arr, n);
    cout << "Sorted array :\n";// ����� ���������������� ������� � ����� ������
    printArr(arr, n);
    return 0;// ������� 0
}