#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void RunPatternProgram(void);
int GetValidSize(void);
void DrawDiamond(int size);

int main(void)
{
    RunPatternProgram();
    return 0;
}

void RunPatternProgram(void)
{
    int inputSize;

    while (1)
    {
        inputSize = GetValidSize();
        if (inputSize == 99)
        {
            break;
        }
        DrawDiamond(inputSize);
    }
}

int GetValidSize(void)
{
    int size;

    while (1)
    {
        printf("입력: ");
        scanf("%d", &size);

        if (size == 99)
        {
            return size;
        }

        if (size < 7)
        {
            printf("입력한 숫자가 너무 작다\n");
            continue;
        }

        if (size % 2 == 0)
        {
            size -= 1;
        }

        return size;
    }
}

void DrawDiamond(int size)
{
    int halfSize = size / 2;
    int i, j;

    for (i = 0; i <= halfSize; ++i)
    {
        for (j = 0; j < halfSize - i; ++j) printf(" ");
        for (j = 0; j < (2 * i + 1); ++j) printf("*");
        printf("\n");
    }

    for (i = halfSize - 1; i >= 0; --i)
    {
        for (j = 0; j < halfSize - i; ++j) printf(" ");
        for (j = 0; j < (2 * i + 1); ++j) printf("*");
        printf("\n");
    }
}