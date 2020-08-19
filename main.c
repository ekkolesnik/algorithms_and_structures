#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


int task14(){
	printf("\nНапишите программу, которая вводит натуральное число N и \nвыводит на экран все автоморфные числа, не превосходящие N.\n\n");
	
	int N;
	printf("Введите натуральное число: ");
	scanf("%d", &N);
	//проверка введённого числа
	if(N < 1){
		printf("введено не натуральное число");
		return 0;
	}
	
	int i;
	printf("Аморфные числа:\n");
	for(i=1; i<N; i++){
		int iSqr = i*i;
		int delimetr = 10;
		while(i/delimetr){
			delimetr *= 10;
		}
		if(i == (iSqr%delimetr)) printf("%d\n", i);
	}
	return 0;
}


void task13(){
	printf("\nНаписать функцию, генерирующую случайное число от 1 до 100.\n\n");
	printf ( "a) C использованием стандартной функции rand()\n %d\n" , rand() % 100 + 1 );
	printf ( "a) Без использования стандартной функции rand()\n %d\n" , (39 * time(NULL) + 12)% 100 + 1 );
	
}

void task12(){
	printf("\nНаписать функцию нахождения максимального из трех чисел\n\n");
	printf("Введите 3 числа через Enter\n");
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if(a<b) a = b;
	if(a<c) printf("Максимальное число %d\n", c);
	else printf("Максимальное число %d\n", a);
}

void printSelection(){
	printf("\n-------------------Выберите порядковый номер задачи---------------------");
	printf("\n    1 -- Задача 14\n    2 -- Задача 13\n    3 -- Задача 12\n    0 -- Завершить программу\n\n Ваш выбор: ");
}


int main(){
	setlocale(LC_ALL, "Rus");
	printf("Колесник Евгений Константинович.\n\n");
	
	int task, userTry = 0;
	printSelection();
	while(1){
		scanf("%d", &task);
		switch(task){
			case 1:
				task14();
				userTry = 0;
				printSelection();
				break;
			case 2:
				task13();
				userTry = 0;
				printSelection();
				break;
			case 3:
				task12();
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
