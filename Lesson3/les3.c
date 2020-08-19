#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


void printSelection(){
	printf("\n-------------------�������� ���������� ����� ������---------------------");
	printf("\n    1 -- ������ 1\n    2 -- ������ 2\n    3 -- ������ 4\n    0 -- ��������� ���������\n\n ��� �����: ");
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
	printf("\n================ ������ ������� %d ==============", arrSize);
	for(i=0; i<3; i++){
		printf("\n--------- ������ �%d -------------",i+1);
		arrInsert(arr_main, arrSize);
		
		
		printf("\n\n���������� ���������: ");
		arrCopy(arr_main, arr_copy, arrSize);
		bubbleSort(arr_copy, arrSize, &steps, &count); 
		printf(" ��������: %d �����������:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
		
		printf("\n��������� ����������: ");
		arrCopy(arr_main, arr_copy, arrSize);
		shakeSort(arr_copy, arrSize, &steps, &count); 
		printf(" ��������: %d �����������:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
		
		printf("\n���������� ������� ������: ");
		arrCopy(arr_main, arr_copy, arrSize);
		selectionSort(arr_copy, arrSize, &steps, &count); 
		printf(" ��������: %d �����������:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
		
		printf("\n���������� ���������: ");
		arrCopy(arr_main, arr_copy, arrSize);
		insertSort(arr_copy, arrSize, &steps, &count); 
		printf(" ��������: %d �����������:%d", count, steps);
		arrCopy(arr_main, arr_copy, arrSize);
		
	}
}


int main(){
	setlocale(LC_ALL, "Rus");
	printf("�������� ������� ��������������.\n\n");
	int const arrSize = 10;
	int arr_main[arrSize];
	int arr_copy[arrSize];
	int task, userTry = 0;
	printSelection();
	int steps, count; // steps -- ���������� �����������, count -- ���������� ������������ ��������.
	while(1){
		scanf("%d", &task);
		steps = 0;
		switch(task){
			case 1:
				printf("����������� �������������� ����������� ����������.\n�������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.\n�������� ������� ����������, ������� ���������� ���������� ��������.\n\n");
				arrInsert(arr_main, arrSize);
				printf("����������������� ������:  ");
				arrPrint(arr_main, arrSize);
				//���������� ���������
				printf("\n\n���������� ���������: ");
				arrCopy(arr_main, arr_copy, arrSize);
				bubbleSort(arr_copy, arrSize, &steps, &count); 
				arrPrint(arr_copy, arrSize);
				printf("\n    ���������� ��������: %d\n    ���������� �����������:%d", count, steps);
				//��������� ����������
				printf("\n\n���������� ���������� ��������� (��������� ����������): ");
				arrCopy(arr_main, arr_copy, arrSize);
				shakeSort(arr_copy, arrSize, &steps, &count);
				arrPrint(arr_copy, arrSize);
				printf("\n    ���������� ��������: %d\n    ���������� �����������:%d", count, steps);
				userTry = 0;
				printSelection();
				break;
			case 2:
				printf("����������� ��������� ����������\n\n");
				arrInsert(arr_main, arrSize);
				printf("����������������� ������:  ");
				arrPrint(arr_main, arrSize);
				printf("\n\n���������� ���������� ��������� (��������� ����������): ");
				shakeSort(arr_main, arrSize, &steps, &count);
				arrPrint(arr_main, arrSize);
				printf("\n    ���������� ��������: %d\n    ���������� �����������:%d", count, steps);
				userTry = 0;
				printSelection();
				break;
			case 3:
				printf("���������� ���������� �������� ��� ������ �� ���������� � �������� ��\n\n");
				int const a = 100, b = 1000, c = 10000;
				
				comparison(a);
				comparison(b);
				comparison(c);
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
