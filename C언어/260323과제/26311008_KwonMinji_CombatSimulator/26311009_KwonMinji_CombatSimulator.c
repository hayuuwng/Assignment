#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerHp = 1000;
int playerMp = 500;

void ShowPlayerStat() {
	printf("---	플레이어 상태	---\n");
	printf("HP: %d\n", playerHp);
	printf("MP: %d\n", playerMp);
	printf("--------------------\n\n");
}

void TakeDamage(int damage) {
	printf("%d의 세기로 명치를 맞았다!!!\n", damage);
	playerHp -= damage;
	playerHp = (playerHp < 0) ? 0 : playerHp;
}

void UseMp(int amount) {
	printf("너한테는 %d 정도면 충분해..\n", amount);
	playerMp -= amount;
	playerMp = (playerMp < 0) ? 0 : playerMp;
}

int main() {
	srand((unsigned int)time(NULL));
	printf("[턴 시작]\n\n");

	ShowPlayerStat();

	int randomDamage = rand() % 401 + 100;
	TakeDamage(randomDamage);

	int randomMpAmount = rand() % 151 + 50;
	UseMp(randomMpAmount);

	printf("\n[이것으로 내 턴을 종료한다...]\n\n");
	ShowPlayerStat();

	return 0;
}