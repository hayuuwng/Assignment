#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetRandom(int minVal, int maxVal);

int main(void)
{
    srand((unsigned int)time(NULL));

    const int compVal = GetRandom(1, 3);
    int userVal = 0;

    printf("가위바위보 게임입니다. (1: 바위, 2: 가위, 3: 보)\n");
    printf("선택: ");
    scanf_s("%d", &userVal);

    if (userVal < 1 || userVal > 3)
    {
        printf("입력 값 오류. 패배 처리 및 게임을 종료합니다.\n");
        return 0;
    }

    printf("당신: %d, 컴퓨터: %d\n", userVal, compVal);

    const int result = (userVal - compVal + 3) % 3;

    if (result == 2)
    {
        printf("당신의 승리입니다.\n");
    }
    else if (result == 1)
    {
        printf("당신은 패배했습니다.\n");
    }
    else
    {
        printf("비겼습니다.\n");
    }

    return 0;
}

int GetRandom(int minVal, int maxVal)
{
    return (rand() % (maxVal - minVal + 1)) + minVal;
}