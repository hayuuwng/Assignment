#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 상수 정의
static const int GAME_EXIT = 0;
static const int GAME_CONTINUE = 1;
static const int PLAYER_HP_MAX = 100;

// 전역 변수
char playerName[32] = { 0 };
int playerHP = 100;
int mobHP = 100;

// 함수 선언
int GetRandom(int minVal, int maxVal);
int PlayMiniBattle(int playCount);

int main(void)
{
    srand((unsigned int)time(NULL));

    playerHP = PLAYER_HP_MAX;
    mobHP = 100;

    printf("플레이어 이름 입력: ");
    scanf_s("%31s", playerName, (unsigned int)sizeof(playerName));

    printf("\n--- 게임 시작 ---\n\n");

    // 1회차
    if (GAME_EXIT == PlayMiniBattle(1))
    {
        printf("1 회차 종료\n");
        return 0;
    }

    // 2회차
    if (GAME_EXIT == PlayMiniBattle(2))
    {
        printf("2 회차 종료\n");
        return 0;
    }

    // 3회차
    if (GAME_EXIT == PlayMiniBattle(3))
    {
        printf("3 회차 종료\n");
        return 0;
    }

    printf("--- 전투 종료 ---\n");

    return 0;
}

int PlayMiniBattle(int playCount)
{
    int playerAction = 0;

    printf("%s [%d회차] 행동 선택 (1: 공격, 2: 방어): ", playerName, playCount);
    // 보안 함수 적용
    scanf_s("%d", &playerAction);

    if (playerAction == 1)
    {
        const int mobDmg = GetRandom(10, 20);
        const int playerDmg = GetRandom(40, 50);

        mobHP -= mobDmg;
        playerHP -= playerDmg;

        printf("[공격] 몬스터에게 %d의 데미지를 입혔습니다.\n", mobDmg);
        printf("[반격] 몬스터로부터 %d의 데미지를 입었습니다.\n", playerDmg);
    }
    else if (playerAction == 2)
    {
        const int healAmount = GetRandom(20, 50);
        playerHP += healAmount;

        printf("[방어] 체력을 %d만큼 회복했습니다.\n", healAmount);
    }
    else
    {
        printf("잘못된 입력입니다. 턴을 날렸습니다.\n");
    }

    if (playerHP < 0)
    {
        playerHP = 0;
    }
    else if (playerHP > PLAYER_HP_MAX)
    {
        playerHP = PLAYER_HP_MAX;
    }

    if (mobHP < 0)
    {
        mobHP = 0;
    }

    printf("[현재 체력] %s: %d / 몬스터: %d\n\n", playerName, playerHP, mobHP);

    if (playerHP == 0 || mobHP == 0)
    {
        return GAME_EXIT;
    }

    return GAME_CONTINUE;
}

int GetRandom(int minVal, int maxVal)
{
    return (rand() % (maxVal - minVal + 1)) + minVal;
}