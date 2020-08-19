#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


void printSelection(){
	printf("\n-------------------Выберите порядковый номер задачи---------------------");
	printf("\n    1 -- Задача 1\n    2 -- Задача 2\n    3 -- Задача 4\n    0 -- Завершить программу\n\n Ваш выбор: ");
}

void arrCopy(int arr[], int arrNew[], int arrSize){
	int i;
	for(i=0; i<arrSize; i++) arrNew[i] = arr[i];
}

void arrInsert(int arr[], int arrSize){
	int i;
	srand(clock());
	for(i=0; i<arrSize; i++) arr[i] = (rand()%997 + rand()%378);
}


void bubbleSort(int arr[], int arrSize, int* steps, int* count){
	
	*count = 0;
	*steps = 0;
	int i, j, temp;
	for(j=0; j<arrSize-1; j++)
		for(i=0; i<arrSize-1; i++){
			*count+=1;
			if(arr[i] > arr[i+1]){
				*count+=1;
				*steps+=1;
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
}

void shakeSort(int arr[], int arrSize, int* steps, int* count){
	*count = 0;
	*steps = 0;
	int i, temp;
	int min = 0, max = arrSize - 1;
	while(min<max){
		for(i=min; i<max; i++){
			*count+=1;
			if(arr[i] > arr[i+1]){
				*count+=1;
				*steps+=1;
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
		max--;
		for(i=max; i>min; i--){
			*count+=1;
			if(arr[i] < arr[i-1]){
				*count+=1;
				*steps+=1;
				temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;
			}
		}
		min++;
	}
}

void selectionSort(int arr[], int arrSize, int* steps, int* count){
	*count = 0;
	*steps = 0;
	int i, j, temp;
	int min, min_i;
	for(j=0; j<arrSize-1; j++){
		min = arr[j];
		for(i=j+1; i<arrSize; i++){
			*count+=1;
			if(min > arr[i]){
				min = arr[i];
				min_i = i;
			}
		}
		if(min != arr[j]){
			*count+=1;
			*steps+=1;
			temp = arr[min_i];
			arr[min_i] = arr[j];
			arr[j] = temp;
		}
	}
}

void insertSort(int arr[], int arrSize, int* steps, int* count){
	*count = 0;
	*steps = 0;
	int i, j, temp;
	for(j=1; j<arrSize; j++){
		i = j;
		while(i>0 && arr[i-1]>arr[i]){
			*count+=1;
			*steps+=1;
			temp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = temp;
			i--;
		}
	}
}

void arrPrint(int arr[], int arrSize){
	int i;
	for(i=0; i<arrSize; i++){
		printf("%d, ", arr[i]);
	}
}



void comparison(int const arrSize){
	int i;
	int arr_main[arrSize];
	int arr_copy[arrSize];
	int steps, count;
	printf("\n================ Размер массива %d ==============", arrSize);
	for(i=0; i<3; i++){
		printf("\n--------- запуск №%d -------------",i+1);
		arrInsert(arr_main, arrSize);
		
		
		printf("\n\nсортировка пузырьком: ");
		arrCopy(arr_main, arr_copy, arrSize);
		bubbleSort(arr_copy, arrSize, &steps, &count); 
		printf(" операций: %d перемещений:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
		
		printf("\nшейкерная сортировка: ");
		arrCopy(arr_main, arr_copy, arrSize);
		shakeSort(arr_copy, arrSize, &steps, &count); 
		printf(" операций: %d перемещений:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
		
		printf("\nсортировка методом выбора: ");
		arrCopy(arr_main, arr_copy, arrSize);
		selectionSort(arr_copy, arrSize, &steps, &count); 
		printf(" операций: %d перемещений:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
		
		printf("\nсортировка вставками: ");
		arrCopy(arr_main, arr_copy, arrSize);
		insertSort(arr_copy, arrSize, &steps, &count); 
		printf(" операций: %d перемещений:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
	}
}


int main(){
	setlocale(LC_ALL, "Rus");
	printf("Колесник Евгений Константинович.\n\n");
	int const arrSize = 10;
	int arr_main[arrSize];
	int arr_copy[arrSize];
	int task, userTry = 0;
	printSelection();
	int steps, count; // steps -- количество перемещений, count -- количество элементарных операций.
	while(1){
		scanf("%d", &task);
		steps = 0;
		switch(task){
			case 1:
				printf("Попробовать оптимизировать пузырьковую сортировку.\nСравнить количество операций сравнения оптимизированной и не оптимизированной программы.\nНаписать функции сортировки, которые возвращают количество операций.\n\n");
				arrInsert(arr_main, arrSize);
				printf("неотсортированный массив:  ");
				arrPrint(arr_main, arrSize);
				//сортировка пузырьком
				printf("\n\nсортировка пузырьком: ");
				arrCopy(arr_main, arr_copy, arrSize);
				bubbleSort(arr_copy, arrSize, &steps, &count); 
				arrPrint(arr_copy, arrSize);
				printf("\n    количество операций: %d\n    количество перемещений:%d", count, steps);
				//шейкерная сортировка
				printf("\n\nулучшенная сортировка пузырьком (шейкерная сортировка): ");
				arrCopy(arr_main, arr_copy, arrSize);
				shakeSort(arr_copy, arrSize, &steps, &count);
				arrPrint(arr_copy, arrSize);
				printf("\n    количество операций: %d\n    количество перемещений:%d", count, steps);
				userTry = 0;
				printSelection();
				break;
			case 2:
				printf("Реализовать шейкерную сортировку\n\n");
				arrInsert(arr_main, arrSize);
				printf("неотсортированный массив:  ");
				arrPrint(arr_main, arrSize);
				printf("\n\nулучшенная сортировка пузырьком (шейкерная сортировка): ");
				shakeSort(arr_main, arrSize, &steps, &count);
				arrPrint(arr_main, arrSize);
				printf("\n    количество операций: %d\n    количество перемещений:%d", count, steps);
				userTry = 0;
				printSelection();
				break;
			case 3:
				printf("Подсчитать количество операций для каждой из сортировок и сравнить их\n\n");
				int const a = 100, b = 1000, c = 10000;
				
				comparison(a);
				comparison(b);
				comparison(c);
				userTry = 0;
				printSelection();
				break;
			case 0:
				printf("Пока-Пока\n");
				return 0;
				break;
			default:
				userTry++;
				if(userTry == 2){
					printf("!!!Последняя попытка!!!\n  Ваш выбор: ");
				}
				else if(userTry == 3) {
					printf("Пока-Пока\n");
					return 0;
				}
				else {
					printf("Такого значения нет. Повторите попытку: ");
				}
		}
	}
	return 0;
}
