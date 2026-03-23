#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int GetRandom(int min, int max) {
	return rand() % (max - min + 1) + min;
}

const char* GetCharacterName() {
	int index = GetRandom(1, 5);
	const char* names[] = { "", "Arthru", "Luna", "Kai", "Iris", "Dante" };
	return names[index];
}

const char* GetJob() {
	int index = GetRandom(1, 5);
	const char* jobs[] = { "", "전사", "궁수", "마법사", "도적" };
	return jobs[index];
}

const char* GetRarity() {
	int index = GetRandom(0, 100);
	if (index <= 4) return "영웅";
	if (index <= 29) return "희귀";
	return "일반";
}

const char* GetWeapon() {
	int index = GetRandom(0, 100);
	if (index == 0) return "전설 무기";
	if (index <= 9) return "영웅 무기";
	if (index <= 29) return "희귀 무기";
	return "일반 무기";
}

const char* GetArmor() {
	int index = GetRandom(0, 100);
	if (index <= 4) return "전설 갑옷";
	if (index <= 19) return "영웅 갑옷";
	return "일반 갑옷";
}


const char* GetMonster() {
	int index = GetRandom(0, 100);
	if (index <= 29) return "키에엑";
	if (index <= 59) return "키야악";
	if (index <= 89) return "끼요옷";
	return "아무도 날 막을수 없으셈ㅋㅋ";
}

int main(void) {
	srand((unsigned int)time(NULL));

	const char* name = GetCharacterName();
	const char* job = GetJob();
	const char* rarity = GetRarity();

	int atk = GetRandom(10, 30);
	int def = GetRandom(5, 20);
	int hp = GetRandom(80, 150);

	const char* weapon = GetWeapon();
	const char* armor = GetArmor();

	int power = atk + def + (hp / 2);

	char title[50];
	if (power >= 100) {
		sprintf(title, "강력한 %s", job);
	}
	else {
		sprintf(title, "풋내기 %s", job);
	}

	printf("===== 캐릭터 =====\n\n");
	printf("이름 : %s\n", name);
	printf("직업 : %s\n", job);
	printf("등급 : %s\n\n", rarity);

	printf("능력치\n");
	printf("    공격력 : %d\n", atk);
	printf("    방어력 : %d\n", def);
	printf("    체력   : %d\n\n", hp);

	printf("장비\n");
	printf("    무기 : %s\n", weapon);
	printf("    방어구 : %s\n\n", armor);

	printf("전투력 : %d\n", power);
	printf("칭호 : %s\n\n", title);

	printf("===== 몬스터 =====\n");
	printf("출현 : %s\n", GetMonster());


}