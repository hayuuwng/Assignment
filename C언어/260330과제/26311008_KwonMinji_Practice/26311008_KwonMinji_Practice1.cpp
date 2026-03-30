#include <stdio.h>
int main(void)
{
	/**/int oddSum = 0; //홀수 합
	int evenSum = 0; //짝수의 합
	int sevenSum = 0; //7의 배수의 합

	//단일 루프로 리소스 소모 줄이기
	for (int i = 1; i <= 10000; ++i) {
		if (i & 1){
			oddSum += i;
		}
		else {
			evenSum += i;
		}

		if (i % 7 == 0) {
			sevenSum += i;
		}
	}

	printf("1부터 10000까지의 홀수의 합: %d\n", oddSum);
	printf("1부터 10000까지의 짝수의 합: %d\n", evenSum);
	printf("1부터 10000까지의 7의 배수의 합: %d\n", sevenSum);


	//4.3.2 구구단
	printf("=== 구구단 출력 ===\n\n");

	for (int i = 1; i <= 9; ++i) {
		printf("[%d단]\n", i);

		for (int j = 1; j <= 9; ++j) {
			printf("%d x %d = %d\n", i, j, i * j);
		}

		printf("\n");
	}


	return 0;
}