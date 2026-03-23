#include <stdio.h>

int main() {
    //산술 연산자 실습
    int a = 150, b = 120;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b (정수 나눗셈): %d\n", a / b);
    printf("a %% b (나머지): %d\n", a % b);
    printf("a / b (실수 나눗셈): %f\n\n", (double)a / b);

    //증감 연산자 실습
    int a1 = 5, b1 = ++a1; 
    printf("전위 (++a): a=%d, b=%d\n", a1, b1);

    int a2 = 5, b2 = a2++;
    printf("후위 (a++): a=%d, b=%d\n", a2, b2);

    

    //복합 대입 연산자 실습
    int ca = 10;
    ca += 5;  printf("+= 5: %d\n", ca);
    ca -= 3;  printf("-= 3: %d\n", ca);
    ca *= 2;  printf("*= 2: %d\n", ca);
    ca /= 4;  printf("/= 4: %d\n", ca);
    ca %= 3;  printf("%%= 3: %d\n", ca);
    

    //단항 연산자 실습
    int x = 10;
    printf("-x: %d\n", -x);
    printf("+x: %d\n", +x);
    printf("!x (논리 부정): %d\n", !x);
    printf("~x (비트 반전): %d\n", ~x);

    //형 변환 실습
    double r1 = 5 / 2;           // 정수/정수 = 정수(2) -> double 저장(2.0)
    double r2 = (double)5 / 2;   // 실수/정수 = 실수(2.5)
    printf("r1 (5 / 2): %f\n", r1);
    printf("r2 ((double)5 / 2): %f\n", r2);


    //sizeof 실습
    printf("char: %zu, short: %zu, int: %zu\n", sizeof(char), sizeof(short), sizeof(int));
    printf("long: %zu, long long: %zu\n", sizeof(long), sizeof(long long));
    printf("float: %zu, double: %zu\n", sizeof(float), sizeof(double));
    printf("sizeof('A'): %zu\n", sizeof('A'));
    printf("포인터 크기: %zu, %zu, %zu, %zu\n", sizeof(char*), sizeof(short*), sizeof(int*), sizeof(long long*));
    printf("sizeof(0x34 + 128): %zu\n", sizeof(0x34 + 128));
    printf("sizeof(3 + 2.5): %zu\n\n", sizeof(3 + 2.5));

    //삼항 조건 연산자
    int num = 7;
    int isEven = (num % 2 == 0) ? 1 : 0;
    printf("%d는 %s\n", num, isEven ? "짝수" : "홀수");

    int n1 = 10, n2 = 20;
    int maxVal = (n1 > n2) ? n1 : n2;
    printf("더 큰 값: %d\n", maxVal);

    double x_val = 5.5;
    double result = (x_val > 0) ? 100.0 : -100.0;
    printf("실수 판별 결과: %f\n", result);

    return 0;
}