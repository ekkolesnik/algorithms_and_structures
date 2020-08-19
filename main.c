#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


int task14(){
	printf("\n�������� ���������, ������� ������ ����������� ����� N � \n������� �� ����� ��� ����������� �����, �� ������������� N.\n\n");
	
	int N;
	printf("������� ����������� �����: ");
	scanf("%d", &N);
	//�������� ��������� �����
	if(N < 1){
		printf("������� �� ����������� �����");
		return 0;
	}
	
	int i;
	printf("�������� �����:\n");
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
	printf("\n�������� �������, ������������ ��������� ����� �� 1 �� 100.\n\n");
	printf ( "a) C �������������� ����������� ������� rand()\n %d\n" , rand() % 100 + 1 );
	printf ( "a) ��� ������������� ����������� ������� rand()\n %d\n" , (39 * time(NULL) + 12)% 100 + 1 );
	
}

void task12(){
	printf("\n�������� ������� ���������� ������������� �� ���� �����\n\n");
	printf("������� 3 ����� ����� Enter\n");
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if(a<b) a = b;
	if(a<c) printf("������������ ����� %d\n", c);
	else printf("������������ ����� %d\n", a);
}

void printSelection(){
	printf("\n-------------------�������� ���������� ����� ������---------------------");
	printf("\n    1 -- ������ 14\n    2 -- ������ 13\n    3 -- ������ 12\n    0 -- ��������� ���������\n\n ��� �����: ");
}


int main(){
	setlocale(LC_ALL, "Rus");
	printf("�������� ������� ��������������.\n\n");
	
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
				printf("����-����\n");
				return 0;
				break;
			default:
				userTry++;
				if(userTry == 2){
					printf("!!!��������� �������!!!\n  ��� �����: ");
				}
				else if(userTry == 3) {
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
