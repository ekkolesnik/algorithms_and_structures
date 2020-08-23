#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MaxN 1000

void clean_stream();



void trueBrackets() {
	char expression[MaxN];
	char stack[MaxN];
	int n = -1;
	printf("Введите выражение для проверки: ");
	clean_stream();
	gets(expression);
	int i = 0;
	while (i < MaxN && expression[i] != NULL) {
		if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
			stack[++n] = expression[i];
		}
		else {
			switch (expression[i]){
				case ')':
					if (stack[n] == '(') {
						n--;
					}
					else {
						printf("ошибка в скобочной последовательности");
						return 0;
					}
					break;
				case ']':
					if (stack[n] == '[') {
						n--;
					}
					else {
						printf("ошибка в скобочной последовательности");
						return 0;
					}
					break;
				case '}':
					if (stack[n] == '{') {
						n--;
					}
					else {
						printf("ошибка в скобочной последовательности");
						return 0;
					}
					break;
			}
		}
		i++;
	}
	if (n == -1) printf("скобочная последовательность верная");
	else printf("ошибка в скобочной последовательности");
}


void printSelection() {
	printf("\n-------------------Выберите порядковый номер задачи---------------------");
	printf("\n    1 -- Задача 1\n    2 -- Задача 2\n    0 -- Завершить программу\n\n Ваш выбор: ");
}


void clean_stream() {
	while (fgetc(stdin) != '\n');
}


int operationIndex(char x){
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
}

void infToPost() {
	char expression[MaxN];
	char stack[MaxN];
	char queue[MaxN];
	int stack_n = -1;
	int queue_n = -1;
	printf("\nВведите выражение для проверки: ");
	clean_stream();
	gets_s(expression, MaxN);
	int i = 0;
	while (expression[i] != NULL){
		if (isalnum(expression[i])){
			queue[++queue_n] = expression[i];
			while (isalnum(expression[i+1])) {
				i++;
				queue[++queue_n] = expression[i];
			}
			queue[++queue_n] = ' ';
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			if (stack_n == -1 || stack[stack_n] == '(' || operationIndex(expression[i]) > operationIndex(stack[stack_n])) {
				stack[++stack_n] = expression[i];
			}
			else{
				while (operationIndex(expression[i]) >= operationIndex(stack[stack_n])) {
					queue[++queue_n] = stack[stack_n];
					stack[stack_n] = NULL;
					stack_n--;
				}
				stack[++stack_n] = expression[i];
			}
		}
		else if (expression[i] == '(') {
			stack[++stack_n] = expression[i];
		}
		else if (expression[i] == ')') {
			while (stack[stack_n] != '(') {
				queue[++queue_n] = stack[stack_n];
				stack[stack_n] = NULL;
				stack_n--;
			}
			stack[stack_n] = NULL;
			stack_n--;
		}
		i++;
	}
	while (stack_n != -1) {
		queue[++queue_n] = stack[stack_n];
		stack[stack_n] = NULL;
		stack_n--;
	}
	printf("\nрезультат: ");
	i = 0;
	while (queue[i] != 'М') {
		printf("%c", queue[i]);
		if (queue[i] == '+' || queue[i] == '-' || queue[i] == '*' || queue[i] == '/') printf(" ");
		i++;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	printf("Колесник Евгений Константинович.\n\n");

	int task, userTry = 0;
	printSelection();
	while (1) {
		scanf("%d", &task);
		switch (task) {
		case 1:
			printf("\nНаписать программу, которая определяет, является ли введенная скобочная последовательность правильной.\n");
			trueBrackets();
			printSelection();
			break;
		case 2:
			printf("Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную");
			userTry = 0;
			infToPost();
			printSelection();
			break;
		case 0:
			printf("Пока-Пока\n");
			return 0;
			break;
		default:
			userTry++;
			if (userTry == 2) {
				printf("!!!Последняя попытка!!!\n  Ваш выбор: ");
			}
			else if (userTry == 3) {
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
