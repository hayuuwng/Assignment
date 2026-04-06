#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

void InitializeArray(int targetArray[], int size);
void PrintArrayStats(int targetArray[], int size);
void PrintArrayReverse(int targetArray[], int size);
void CopyArray(int sourceArray[], int destinationArray[], int size);

int main(void)
{
    int originalArray[ARRAY_SIZE];
    int copiedArray[ARRAY_SIZE];

    srand((unsigned int)time(NULL));

    InitializeArray(originalArray, ARRAY_SIZE);

    printf("=== 배열 통계 ===\n");
    PrintArrayStats(originalArray, ARRAY_SIZE);

    printf("\n=== 배열 역순 출력 (일부 10개만 출력) ===\n");
    PrintArrayReverse(originalArray, ARRAY_SIZE);

    printf("\n=== 배열 복사 테스트 ===\n");
    CopyArray(originalArray, copiedArray, ARRAY_SIZE);
    printf("복사 완료. 원본 첫 값: %d, 사본 첫 값: %d\n", originalArray[0], copiedArray[0]);

    return 0;
}

void InitializeArray(int targetArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        targetArray[i] = (rand() % 201) - 100; // -100 ~ 100
    }
}

void PrintArrayStats(int targetArray[], int size)
{
    int maxValue = targetArray[0];
    int minValue = targetArray[0];
    int positiveCount = 0;
    int negativeCount = 0;
    int oddCount = 0;
    int evenCount = 0;

    for (int i = 0; i < size; ++i)
    {
        if (targetArray[i] > maxValue) maxValue = targetArray[i];
        if (targetArray[i] < minValue) minValue = targetArray[i];

        if (targetArray[i] > 0) positiveCount++;
        else if (targetArray[i] < 0) negativeCount++;

        if (targetArray[i] % 2 == 0) evenCount++;
        else oddCount++;
    }

    printf("최대값: %d\n", maxValue);
    printf("최소값: %d\n", minValue);
    printf("양수 개수: %d\n", positiveCount);
    printf("음수 개수: %d\n", negativeCount);
    printf("홀수 개수: %d\n", oddCount);
    printf("짝수 개수: %d\n", evenCount);
}

void PrintArrayReverse(int targetArray[], int size)
{
    int printLimit = 10; // 1000개를 모두 출력하면 화면이 가려지므로 10개만 예시로 출력
    for (int i = size - 1; i >= size - printLimit; --i)
    {
        printf("%d ", targetArray[i]);
    }
    printf("...\n");
}

void CopyArray(int sourceArray[], int destinationArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        destinationArray[i] = sourceArray[i];
    }
}