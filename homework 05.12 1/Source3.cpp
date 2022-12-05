#include <iostream>
#include <stdint.h>

using namespace std;
template <typename T>
void countingSort(T arr[], T size) {// размер должен быть не менее max+1,но нельзя назначить его как int count[max+1] в с++Б потому что он не поддерживает динамическое выделение памяти, поэтому размер указываем статически 
    int output[10];// выходной массив содержит мак.10 элементов
    int count[10];
    int maximum = arr[0];

    
    for (int i = 1; i < size; i++) {// найти самый большой элемент массива
        if (arr[i] > maximum)
            maximum = arr[i];
    }

  
    for (int i = 0; i <= maximum; ++i) {// инизиализировать весь массив нулями.
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {// запомнить значение каждого элемента
        count[arr[i]]++;
    }
    for (int i = 1; i <= maximum; i++) {// запомнить совокупное количество каждого массива
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {// найти индекс каждого элемента исходного массива в массиве счета  
        output[count[arr[i]] - 1] = arr[i];// поместить элементы в массив выхода
        count[arr[i]]--;
    }

   
    for (int i = 0; i < size; i++) {//скопировать отсортированные элементы в исходный массив
        arr[i] = output[i];
    }
}


void printArr(int arr[], int size) {// функция для вывода массива
    for (int i = 0; i < size; i++)// после отсортировки массива
        cout << arr[i] << " ";// вывод массива по возрастанию
    cout << endl;
}


int main() {// наглядный пример отсортированного массива
    int arr[] = { 9, 7, 7, 8, 2, 3, 1 };// вводим любой массив
    int n = sizeof(arr) / sizeof(arr[0]);// возвращает количество байтов, которое занимает массив
    countingSort(arr, n);
    cout << "Sorted array :\n";// вывод отсортированного массива с новой строки
    printArr(arr, n);
    return 0;// возврат 0
}