#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char operator;
    double num1, num2;

    printf("수식을 입력하시오");

    scanf("%lf %c %lf", &num1, &operator, &num2);

    switch (operator) {
    case '+':
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
        break;
    case '/':
        if (num2 != 0.0) {
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
        }
        else {
            printf("0으로 나눌 수 없음\n");
        }
        break;
    default:
        printf("키에엑\n");
    }

    return 0;
}