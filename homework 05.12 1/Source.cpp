#include <iostream>
#include <stdint.h>

using namespace std;

template <typename T>// ���� �������
void bubbleSort(T arr[], T size) {// ���������� ���������


    for (int j = 0; j < size - 1; ++j) {
        for (int i = 0; i < size - j - 1; ++i) {// ��� ���������� ������� �������...

            if (arr[i] > arr[i + 1]) {// ������ �������� �������

                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;//������ �������
            }
        }
    }
}
template <typename T>// ������������� �������
void display(T arr[], T size) {
    for (T i = 0; i < size; ++i) {// ����� ������������ �������
        cout << "  " << arr[i];// ����� ������� �� �����������
    }
    cout << "\n";//����� �� ����� ������� ����� ������.
}

int main() {// ��������� ������ ���������������� �������
    int arr[] = { -9287, 182, 40, 1, 68, -987 };// ������ ����� ������
    int size = sizeof(arr) / sizeof(arr[0]);// ���������� ���������� ������, ������� �������� ������
    bubbleSort(arr, size);
    cout << "Sorted array :\n";// ����� ���������������� �������
    display(arr, size);// �������, ��� �������� ������ �����
    return 0;
}