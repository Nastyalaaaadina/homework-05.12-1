#include <iostream>
#include <stdint.h>

using namespace std;
template <typename T>
void swap(T a, T b) {// функция, служащая для обмена элементов a и b
	int temp = *a;// temp – локальная переменная, алгоритм циклического обмена
	*a = *b;// значения, находящиеся
	*b = temp;// по данным адресам
}
template <typename T>
T divide(T arr[], T min, T max) {
	T pivot = arr[max]; // pivot как элемент, который разделит большую задачу на меньшую задачу.
	T a = (min - 1);
	for (T b = min; b <= max - 1; b++) {// цикл для сравнения всех элементов с pivot 

		if (arr[b] < pivot) {// для эмента b, меньшего чем pivot 
			a++;//после использования переменной на данном шаге цикла или алгоритма, или в формуле значение переменной автоматически будет увеличено на 1
			swap(&arr[a], &arr[b]);// обмен элементов
		}
	}
	swap(&arr[a + 1], &arr[max]);
	return (a + 1);// возврат значения а+1
}
template <typename T>
void quickSort(T arr[], T min, T max)// функция для сортировки
{
	if (min < max) {

		int array_divide = divide(arr, min, max);// ввод разграничения массива
		quickSort(arr, min, array_divide - 1);// быстрая сортировка рекурсией элементов с левой стороны от элемента pivot
		quickSort(arr, array_divide + 1, max);// быстрая сортировка рекурсией элементов с правой стороны от элемента pivot
	}
}// print array function 
template <typename T>
void printArr(T arr[], T size)//функция printArr
{
	int i;
	for (i = 0; i < size; i++) // при выполнении данного условия...
		cout << arr[i] << " ";// перебор всего массива и вывод элемента
	cout << endl;
}
int main()// наглядный пример отсортированного массива
{
	int arr[] = { 12, 3, 5, 7, 8, 15, 20, 32, 6 };// мой массив

	int size = sizeof(arr) / sizeof(arr[0]);// возвращает количество байтов, которое занимает массив

	quickSort(arr, 0, size - 1);
	cout << "Sorted array: \n";// вывод отсортированного массива с новой строки
	printArr(arr, size); // методом, код которого указан ранее
	
     return 0;// возврат 0
}
