#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"

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

    return 0;
}