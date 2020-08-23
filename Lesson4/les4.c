#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 6
#define M 6




// Доска для ферзей
// 0 - пустая клетка
// Число – номер ферзя
int board[N][M];

int SearchSolution(int n, int x, int y, int breakpoint);
int CheckBoard(int x, int y);
int CheckQueen(int x, int y);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);
void Pause(int key);

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Колесник Евгений Константинович.\n\n");
	printf("Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу\n");
	int breakpoint = (N*M)+1;
    Zero(N, M, board);
    SearchSolution(1, 0, 0, breakpoint);
    printf("Результат с размерами %d на %d\n\n", N, M);
    Print(N, M, board);
    getch();
    return 0;

	setlocale(LC_ALL, "Rus");
	printf("Колесник Евгений Константинович.\n\n");
	//start_task_3();
	return 0;
	printSelection();
	int task, userTry = 0;
	while(1){
		scanf("%d", &task);
		switch(task){
			case 1:
				printf("Подсчитать количество операций для каждой из сортировок и сравнить их\n\n");
				
				userTry = 0;
				printSelection();
				break;
			case 2:
				printf("Подсчитать количество операций для каждой из сортировок и сравнить их\n\n");
				
				userTry = 0;
				printSelection();
				break;
			case 3:
				printf("Подсчитать количество операций для каждой из сортировок и сравнить их\n\n");
				
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



int SearchSolution(int n, int x, int y, int breakpoint)
{
    if (n == breakpoint) return 1;
    // Если проверка доски возвращает 0, то эта расстановка не подходит
    if (CheckBoard(x, y)) return 0;
    int i, j;
    int countOfTry = 0;
    board[x][y] = n;
    if(SearchSolution(n+1, x+1, y+2, breakpoint)) return 1;
    if(SearchSolution(n+1, x-1, y+2, breakpoint)) return 1;
	if(SearchSolution(n+1, x-2, y+1, breakpoint)) return 1;
	if(SearchSolution(n+1, x-2, y-1, breakpoint)) return 1;
	if(SearchSolution(n+1, x-1, y-2, breakpoint)) return 1;
	if(SearchSolution(n+1, x+1, y-2, breakpoint)) return 1;
	if(SearchSolution(n+1, x+2, y-1, breakpoint)) return 1;
	if(SearchSolution(n+1, x+2, y+1, breakpoint)) return 1;
	board[x][y] = 0;
    return 0;
}
// Проверка всей доски
int CheckBoard(int x, int y)
{
    int i, j;
    if(x>=0 && x<N && y>=0 && y<M && !board[x][y]) return 0;
    return 1;
}


// Выводим доску на экран
void Print(int n, int m, int a[N][M])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
// Очищаем доску
void Zero(int n, int m, int a[N][M])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[i][j] = 0;
}

void Pause(int key)
{
	int i;
    if (key == 1)
        getch();
    else
        for (i = 0; i < 100000000; i++);
}

