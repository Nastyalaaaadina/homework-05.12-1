#include <iostream>
#include <stdint.h>

using namespace std;

template <typename T>// ввод шаблона
void bubbleSort(T arr[], T size) {// сортировка пузырьком


    for (int j = 0; j < size - 1; ++j) {
        for (int i = 0; i < size - j - 1; ++i) {// при выполнении данного условия...

            if (arr[i] > arr[i + 1]) {// меняем элементы местами

                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;//меняем местами
            }
        }
    }
}
template <typename T>// использование шаблона
void display(T arr[], T size) { // что будет показано на консоли
    for (T i = 0; i < size; ++i) {// после отсортировки массива
        cout << "  " << arr[i];// вывод массива по возрастанию
    }
    cout << "\n";//Вывод на экран символа новой строки.
}

int main() {// наглядный пример отсортированного массива
    int arr[] = { -9287, 182, 40, 1, 68, -987 };// вводим любой массив
    int size = sizeof(arr) / sizeof(arr[0]);// возвращает количество байтов, которое занимает массив
    bubbleSort(arr, size);
    cout << "Sorted array :\n";// вывод отсортированного массива с новой строки
    display(arr, size);// методом, код которого указан ранее
    return 0;// возврат 0
}
