#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define ARR_SIZE 20



void printSelection(){
	printf("\n-------------------Выберите порядковый номер задачи---------------------");
	printf("\n    1 -- Задача 1\n    2 -- Задача 2\n    3 -- Задача 3\n    0 -- Завершить программу\n\n Ваш выбор: ");
}



void task1(int dec){
	int mod = dec%2;
	int integer = dec/2;
	if(integer>1){
		task1(integer);
	}
	else if(integer==1){
		printf("%d",integer);
	}
	printf("%d",mod);
}

float recurse_task2(float base, int exp){
	 if(exp<0){
	 	if(exp==(-1)) {
			return base= 1/base;
	 	}else{
	 		exp*=-1;
	 		return base=1/recurse_task2(base, exp);
	 	}
	}else if(exp==0){
		base = 1;
	}else{
		if(exp>1){
			exp--;
			return base*=recurse_task2(base, exp);
		}else{
			return base;
		}
	}
}

float task2(float base, int exp){
	printf("а) Без рекурсии\n");
	float newbase = 1;
	int i;
	if(exp<0){
		exp*=-1;
		for(i=0; i<exp; i++){
			newbase*=base;
		}
		newbase = 1/newbase;
	}else if(exp==0){
		newbase = 1;
	}else{
		for(i=0; i<exp; i++){
			newbase*=base;
		}
	}
	printf("Результат: %f", newbase);
	printf("б) С рекурсией\nРезультат: %f", recurse_task2(base, exp));
	
}



int recurse_task3(int n){
	if (n==0) return 0;
	if (n==1) return 0;
	if (n==2) return 0;
	if (n==3) return 1;
	if (n==4) return 1;
	return recurse_task3(n-1) + recurse_task3(n/2);
}

void task3(){
	int n = 3;
	printf("Исполнитель «Калькулятор» преобразует целое число, записанное на экране.\n У исполнителя две команды, каждой присвоен номер:\n    1. Прибавь 1.\n    2. Умножь на 2.\n");
	printf("Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20:\n");
	printf("а) С использованием массива.\n");
	int f[ARR_SIZE+3];
	f[0] = 0;
	f[1] = 0;
	f[2] = 0;
	f[3] = 1;
	f[4] = 1;
	int i;
	for (i=n+2; i<=ARR_SIZE; i++){
		f[i] = f[i-1] + f[i/2];
		printf ("f(%d) = f(%d) + f(%d) = %d\n" ,i, i-1, i/2, f[i]);
	}
	printf ("Результат: %d\n" , f[ARR_SIZE]);
	int answer = 0;
	printf("b) С использованием рекурсии.\nРезультат: %d", recurse_task3(ARR_SIZE));
}

int main(){
	setlocale(LC_ALL, "Rus");
	printf("Колесник Евгений Константинович.\n\n");
	
	int task, userTry = 0;
	printSelection();
	//Для первого задания
	int digit;
	//для второго задания
	float base; int exp;
	while(1){
		scanf("%d", &task);
		switch(task){
			case 1:
				printf("Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию\n");
				printf("Введите десятичное число: ");
				scanf("%d", &digit);
				task1(digit);
				userTry = 0;
				printSelection();
				break;
			case 2:
				printf("Реализовать функцию возведения числа a в степень b.\nВведите a: ");
				scanf("%f", &base);
				printf("Введите b: ");
				scanf("%d", &exp);
				task2(base, exp);
				userTry = 0;
				printSelection();
				break;
			case 3:
				userTry = 0;
				task3();
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
