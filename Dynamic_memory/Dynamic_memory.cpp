// Динамическая память
// Утечка памяти - это явление, в ходе которого значания, используемые в программе, отаются в оперативной памяти.

#include <iostream>
#include <ctime>
#include <cstdlib>

// Задача 1. Изменение длины динамического массива
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void add_el(T*& arr, const int length, int num);

// Задача 2. Уменьшение динамического массива
template <typename T>
void substract_el(T*& arr, const int length, int num);


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	// Динамические переменные.
	/*
	int* point = new int; // Выделение участка динамической памяти размером в 4 байта с помощью оператора new.

	*point = 10;

	std::cout << " point = " << point << '\n';
	std::cout << " *point = " << *point << '\n';

	delete point; // Очищение области памяти, на котору направлен указатель.
	point = nullptr;

	if (point != nullptr)
		std::cout << *point << '\n';
	else
		std::cout << " Указатель нейтрален." << '\n';

	point = new int; // Выделение нового участка памяти.
	*point = 15;

	std::cout << " point = " << point << '\n';
	std::cout << " *point = " << *point << '\n';

	delete point;
	point = nullptr;
	*/

	// Динамические массивы
	/*
	std::cout << " Введите длину массива --> ";
	std::cin >> n;
	if (n < 0)
		std::cout << " Ошибка! Длина не может быть отрицательной.\n";
	else {
		int* mass = new int[n]; // Выделение динамической памяти для хранения массива.
		std::cout << " Динамический массив --> ";
		std::cout << "[";
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			std::cout << mass[i] << ", ";
		}
		std::cout << "\b\b]\n";
		delete[] mass;
	}
	*/

	// Задача 1. Увеличение длины динамического массива
	/*
	int size1;
	std::cout << "\t\tЗадача 1.\n Введите длину массива --> ";
	std::cin >> size1;
	int* arr1 = new int[size1];
	std::cout << " Изначальный массив --> ";
	fill_arr(arr1, size1, 1, 11);
	show_arr(arr1, size1);

	std::cout << " Введите кол-во новых элементов --> ";
	std::cin >> n;
	add_el(arr1, size1, n);
	size1 += n;
	std::cout << " Измененный массив --> ";
	show_arr(arr1, size1);
	*/

	// Задача 2. Уменьшение динамического массива
	/*
	std::cout << "\t\tЗадача 2.\n Введите длину массива --> ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 1, 11);
	std::cout << " Изначальный массив --> ";
	show_arr(arr2, size2);
	std::cout << " Введите кол-во элементов на которое нужно уменьшить массив --> ";
	std::cin >> n;
	substract_el(arr2, size2, n);
	size2 -= n;
	std::cout << " Окончательный массив --> ";
	show_arr(arr2, size2);
	*/

	// Двумерный динамический массив

	// int* mx = new int[4][6]; Так динамический двумерный массив не создать.
	int** mx = new int*[4];
	for (int i = 0; i < 4; i++)
		mx[i] = new int[6]; // Таким образом создается двумерный динамический массив.

	// Очищение двумерного динамического массива.
	// delete[][] mx; - Ошибка!
	for (int i = 0; i < 4; i++)
		delete mx[i];
	delete[]mx;

	return 0;
}


// Задача 1. Изменение длины динамического массива
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename T>
void add_el(T*& arr, const int length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{}; // {} - это значит, что массив заполняется нулями.
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	delete[]arr;
	arr = tmp; // Перенаправили указатель на область tmp.
}

// Задача 2. Уменьшение динамического массива
template <typename T>
void substract_el(T*& arr, const int length, int num) {
	if (num <= 0)
		return;
	if (num > length) {
		delete[] arr;
		arr = new int[0];
		return;
	}
	T* tmp = new T[length - num];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	delete[]arr;
	arr = tmp;
}
