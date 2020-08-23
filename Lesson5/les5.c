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
	printf("������� ��������� ��� ��������: ");
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
						printf("������ � ��������� ������������������");
						return 0;
					}
					break;
				case ']':
					if (stack[n] == '[') {
						n--;
					}
					else {
						printf("������ � ��������� ������������������");
						return 0;
					}
					break;
				case '}':
					if (stack[n] == '{') {
						n--;
					}
					else {
						printf("������ � ��������� ������������������");
						return 0;
					}
					break;
			}
		}
		i++;
	}
	if (n == -1) printf("��������� ������������������ ������");
	else printf("������ � ��������� ������������������");
}


void printSelection() {
	printf("\n-------------------�������� ���������� ����� ������---------------------");
	printf("\n    1 -- ������ 1\n    2 -- ������ 2\n    0 -- ��������� ���������\n\n ��� �����: ");
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
	printf("\n������� ��������� ��� ��������: ");
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
	printf("\n���������: ");
	i = 0;
	while (queue[i] != '�') {
		printf("%c", queue[i]);
		if (queue[i] == '+' || queue[i] == '-' || queue[i] == '*' || queue[i] == '/') printf(" ");
		i++;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	printf("�������� ������� ��������������.\n\n");

	int task, userTry = 0;
	printSelection();
	while (1) {
		scanf("%d", &task);
		switch (task) {
		case 1:
			printf("\n�������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������.\n");
			trueBrackets();
			printSelection();
			break;
		case 2:
			printf("����������� �������� �������� �� ��������� ������ ��������������� ��������� � �����������");
			userTry = 0;
			infToPost();
			printSelection();
			break;
		case 0:
			printf("����-����\n");
			return 0;
			break;
		default:
			userTry++;
			if (userTry == 2) {
				printf("!!!��������� �������!!!\n  ��� �����: ");
			}
			else if (userTry == 3) {
				printf("����-����\n");
				return 0;
			}
			else {
				printf("������ �������� ���. ��������� �������: ");
			}
		}
	}
	return 0;
}
