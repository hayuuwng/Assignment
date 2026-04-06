#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define PROC_EXIT        0
#define PROC_CONTINUE    1
#define SORT_ASCENDING   0
#define SORT_DESCENDING  1

#define ARRAY_SIZE       100

void InitializeRandomArray(int targetArray[], int size);
void PrintArray(int targetArray[], int size);
void BubbleSort(int targetArray[], int size, int sortOrder);
int ProcessMenu(int targetArray[], int size);

int main(void)
{
    int sortArray[ARRAY_SIZE];
    int programState = PROC_CONTINUE;

    srand((unsigned int)time(NULL));
    InitializeRandomArray(sortArray, ARRAY_SIZE);

    while (programState == PROC_CONTINUE)
    {
        programState = ProcessMenu(sortArray, ARRAY_SIZE);
    }

    return 0;
}

void InitializeRandomArray(int targetArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        targetArray[i] = (rand() % 90) + 10; // 10 ~ 99
    }
}

void PrintArray(int targetArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", targetArray[i]);
    }
    printf("\n\n");
}

void BubbleSort(int targetArray[], int size, int sortOrder)
{
    int tempValue;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            int condition = (sortOrder == SORT_ASCENDING) ?
                (targetArray[j] > targetArray[j + 1]) :
                (targetArray[j] < targetArray[j + 1]);

            if (condition)
            {
                tempValue = targetArray[j];
                targetArray[j] = targetArray[j + 1];
                targetArray[j + 1] = tempValue;
            }
        }
    }
}

int ProcessMenu(int targetArray[], int size)
{
    char userInput;

    printf("버블 정렬\n");
    printf("(A: 오름차순, D: 내림차순, R: 랜덤 생성, Q: 종료)\n");
    printf("입력: ");

    // 버퍼 비우기 및 입력 처리
    scanf(" %c", &userInput);

    switch (userInput)
    {
    case 'A': case 'a':
        printf("\n정렬 전:\n");
        PrintArray(targetArray, size);
        BubbleSort(targetArray, size, SORT_ASCENDING);
        printf("정렬 후:\n");
        PrintArray(targetArray, size);
        break;
    case 'D': case 'd':
        printf("\n정렬 전:\n");
        PrintArray(targetArray, size);
        BubbleSort(targetArray, size, SORT_DESCENDING);
        printf("정렬 후:\n");
        PrintArray(targetArray, size);
        break;
    case 'R': case 'r':
        InitializeRandomArray(targetArray, size);
        printf("\n랜덤 생성 결과:\n");
        PrintArray(targetArray, size);
        break;
    case 'Q': case 'q':
        return PROC_EXIT;
    default:
        printf("\n잘못된 입력입니다. 다시 입력해주세요.\n\n");
        break;
    }

    return PROC_CONTINUE;
}