#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
int GetRandom(int minVal, int maxVal);

int main(void)
{
    srand((unsigned int)time(NULL));

    const int compVal = GetRandom(10, 90);
    const int compOdd = compVal & 1;

    char userChoice = '\0';
    printf("홀짝을 선택하세요 (E: 짝수, O: 홀수, Q: 종료): ");
    scanf_s(" %c", &userChoice, 1);

    if (userChoice == 'Q' || userChoice == 'q')
    {
        return 0;
    }

    int userOdd = -1;
    if (userChoice == 'O' || userChoice == 'o')
    {
        userOdd = 1;
    }
    else if (userChoice == 'E' || userChoice == 'e')
    {
        userOdd = 0;
    }

    if (userOdd != -1)
    {
        printf("컴퓨터의 값: %d\n", compVal);
        if (userOdd == compOdd)
        {
            printf("승리!\n");
        }
        else
        {
            printf("패배!\n");
        }
    }
    else
    {
        printf("잘못된 입력입니다.\n");
    }

    return 0;
}

// 함수 정의
int GetRandom(int minVal, int maxVal)
{
    return (rand() % (maxVal - minVal + 1)) + minVal;
}