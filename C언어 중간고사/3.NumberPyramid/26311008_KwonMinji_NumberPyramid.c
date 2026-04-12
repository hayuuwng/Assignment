#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_CAPACITY 30

int g_workBuffer[MAX_CAPACITY];
int g_resultBuffer[MAX_CAPACITY];

void RunPyramidGame(void);
int GetArraySize(void);
void InitializeArray(int size);
void PrintArrayBuffer(const char* title, int targetArray[], int size);
void SortAscending(int size);
void RearrangePyramid(int size);

int main(void) {
    system("chcp 65001");

    srand((unsigned int)time(NULL));
    RunPyramidGame();
    return 0;
}

void RunPyramidGame(void)
{
    int currentSize;

    while (1)
    {
        currentSize = GetArraySize();
        if (currentSize == 99)
        {
            break;
        }

        InitializeArray(currentSize);
        PrintArrayBuffer("Before Sort", g_workBuffer, currentSize);

        SortAscending(currentSize);
        PrintArrayBuffer("Ascending", g_workBuffer, currentSize);

        RearrangePyramid(currentSize);
        PrintArrayBuffer("Result", g_resultBuffer, currentSize);
        printf("\n");
    }
}

int GetArraySize(void) {
    int inputSize;

    while (1) {
        printf("숫자 피라미드 원소 개수 입력 (10~30, 종료:99): ");
        if (scanf("%d", &inputSize) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (inputSize == 99) {
            return inputSize;
        }

        if (inputSize >= 10 && inputSize <= 30) {
            return inputSize;
        }

        printf("10 이상 30 이하의 숫자를 입력하시오\n\n");
    }
}

void InitializeArray(int size) {
    int i;
    for (i = 0; i < size; ++i) {
        g_workBuffer[i] = (rand() % 90) + 10;
    }
}

void PrintArrayBuffer(const char* title, int targetArray[], int size) {
    int i;
    printf("\n%s:\n", title);
    for (i = 0; i < size; ++i) {
        printf("%d ", targetArray[i]);
    }
    printf("\n");
}

void SortAscending(int size) {
    int i, j, tempValue;
    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < size - 1 - i; ++j) {
            if (g_workBuffer[j] > g_workBuffer[j + 1]) {
                tempValue = g_workBuffer[j];
                g_workBuffer[j] = g_workBuffer[j + 1];
                g_workBuffer[j + 1] = tempValue;
            }
        }
    }
}

void RearrangePyramid(int size) {
    int frontIndex = 0;
    int backIndex = size - 1;
    int i;

    for (i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            g_resultBuffer[frontIndex] = g_workBuffer[i];
            frontIndex++;
        }
        else {
            g_resultBuffer[backIndex] = g_workBuffer[i];
            backIndex--;
        }
    }
}

