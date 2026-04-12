#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void RunCalculator(void);
void PrintMenu(void);
void ExecuteOperation(char menuChoice);

int main(void)
{
    RunCalculator();
    return 0;
}

void RunCalculator(void)
{
    char userChoice;

    while (1)
    {
        PrintMenu();
        printf("메뉴 선택:");
        scanf(" %c", &userChoice);

        if (userChoice == 'Q' || userChoice == 'q')
        {
            printf("종료\n");
            break;
        }

        ExecuteOperation(userChoice);
    }
}

void PrintMenu(void)
{
    printf("\n=== 계산기 메뉴 ===\n");
    printf("[+] 덧셈\n");
    printf("[-] 뺄셈\n");
    printf("[*] 곱셈\n");
    printf("[/] 나눗셈\n");
    printf("[Q] 종료\n\n");
}

void ExecuteOperation(char menuChoice)
{
    int operandOne, operandTwo;

    if (menuChoice != '+' && menuChoice != '-' && menuChoice != '*' && menuChoice != '/')
    {
        printf("Err\n");
        return;
    }

    if (menuChoice == '+') printf("[덧셈] ");
    else if (menuChoice == '-') printf("[뺄셈] ");
    else if (menuChoice == '*') printf("[곱셈] ");
    else if (menuChoice == '/') printf("[나눗셈] ");

    printf("두 수를 입력: ");
    scanf("%d %d", &operandOne, &operandTwo);

    if (menuChoice == '+')
    {
        printf("덧셈 결과: %d + %d = %d\n", operandOne, operandTwo, operandOne + operandTwo);
    }
    else if (menuChoice == '-')
    {
        printf("뺄셈 결과: %d - %d = %d\n", operandOne, operandTwo, operandOne - operandTwo);
    }
    else if (menuChoice == '*')
    {
        printf("곱셈 결과: %d * %d = %d\n", operandOne, operandTwo, operandOne * operandTwo);
    }
    else if (menuChoice == '/')
    {
        if (operandTwo == 0)
        {
            printf("나눗셈 결과: 0으로 나눌 수 없음\n");
        }
        else
        {
            printf("나눗셈 결과 : %d / %d = 몫: %d, 나머지: %d\n", operandOne, operandTwo, operandOne / operandTwo, operandOne % operandTwo);
        }
    }
}