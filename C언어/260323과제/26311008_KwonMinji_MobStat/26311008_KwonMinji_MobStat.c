#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetRandom(int min, int max) {
	return rand() % (max - min + 1)
		+ min;
}

//  몹1
void ShowMob1Stat() {
	int hp = GetRandom(10, 30); 
	int atk = GetRandom(5, 10);

	printf("몹1 : 키에엑\n");
	printf(" - HP : %d\n", hp);
	printf(" - 공격력(ATK): %d\n\n", atk);
}

void ShowMob2Stat() {
	int hp = GetRandom(20, 50);
	int atk = GetRandom(10, 20);

	printf("몹2 : 끼요옷\n");
	printf(" - HP : %d\n", hp);
	printf(" - 공격력(ATK): %d\n\n", atk);
}

void ShowMob3Stat() {
	int hp = GetRandom(40, 80);
	int atk = GetRandom(20, 30);

	printf("몹3 : 아무도 날 막을수 없으셈ㅋㅋ\n");
	printf(" - HP : %d\n", hp);
	printf(" - 공격력(ATK): %d\n\n", atk);
}

int main(void) {
	srand((unsigned int)time(NULL));

	printf("===몬스터 스폰 정보===\n\n");

	ShowMob1Stat();
	ShowMob2Stat();
	ShowMob3Stat();


	return 0;
}