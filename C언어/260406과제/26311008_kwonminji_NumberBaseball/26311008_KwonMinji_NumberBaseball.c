#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAY_MAX_TRY 10
#define TARGET_WINS 3
#define GAME_QUIT -1

void SetupComputerNumbers(int answerArray[]);
int PlaySingleRound(int roundNumber, int cheatMode);
void CheckStrikeBall(int answerArray[], int inputArray[], int* strikeCount, int* ballCount);

int main(void)
{
    int winCount = 0;
    int loseCount = 0;
    int roundCount = 1;
    int cheatMode = 0;

    srand((unsigned int)time(NULL));

    printf("====== 숫자 야구 (5판 3선승) ======\n");
    printf("치트 활성화 (1: ON, 0: OFF): ");
    scanf("%d", &cheatMode);
    printf("\n");

    while (winCount < TARGET_WINS && loseCount < TARGET_WINS)
    {
        int roundResult = PlaySingleRound(roundCount, cheatMode);

        if (roundResult == GAME_QUIT)
        {
            printf("\n게임을 종료합니다.\n");
            return 0;
        }
        else if (roundResult == 1)
        {
            winCount++;
        }
        else
        {
            loseCount++;
        }

        printf("현재 스코어 -> 승: %d / 패: %d\n\n", winCount, loseCount);
        roundCount++;
    }

    if (winCount == TARGET_WINS)
    {
        printf("최종 승리!!!\n");
    }
    else
    {
        printf("최종 패배...\n");
    }

    return 0;
}

void SetupComputerNumbers(int answerArray[])
{
    for (int i = 0; i < 3; ++i)
    {
        answerArray[i] = (rand() % 9) + 1;
        for (int j = 0; j < i; ++j)
        {
            if (answerArray[i] == answerArray[j])
            {
                i--;
                break;
            }
        }
    }
}

void CheckStrikeBall(int answerArray[], int inputArray[], int* strikeCount, int* ballCount)
{
    *strikeCount = 0;
    *ballCount = 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (answerArray[i] == inputArray[j])
            {
                if (i == j) (*strikeCount)++;
                else (*ballCount)++;
            }
        }
    }
}

int PlaySingleRound(int roundNumber, int cheatMode)
{
    int answerNumbers[3];
    int userNumbers[3];
    int userInput;
    int tryCount = 1;

    SetupComputerNumbers(answerNumbers);

    printf("===== Round %d =====\n", roundNumber);
    if (cheatMode == 1)
    {
        printf("치트: %d %d %d\n\n", answerNumbers[0], answerNumbers[1], answerNumbers[2]);
    }

    while (tryCount <= PLAY_MAX_TRY)
    {
        printf("[시도 %d / %d]\n", tryCount, PLAY_MAX_TRY);
        printf("세 자리 숫자 입력 (0: 게임 종료, 1~9 중복 없음): ");
        scanf("%d", &userInput);

        if (userInput == 0) return GAME_QUIT;

        userNumbers[0] = userInput / 100;
        userNumbers[1] = (userInput / 10) % 10;
        userNumbers[2] = userInput % 10;

        int strike = 0, ball = 0;
        CheckStrikeBall(answerNumbers, userNumbers, &strike, &ball);

        if (strike == 3)
        {
            printf("3 스트라이크\n승리!!!\n");
            return 1;
        }

        if (strike == 0 && ball == 0)
        {
            printf("아웃\n\n");
        }
        else
        {
            if (strike > 0) printf("%d 스트라이크 ", strike);
            if (ball > 0) printf("%d 볼 ", ball);
            printf("\n\n");
        }

        tryCount++;
    }

    printf("패배...\n정답은 %d %d %d 였습니다.\n", answerNumbers[0], answerNumbers[1], answerNumbers[2]);
    return 0;
}