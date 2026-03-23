#include "game.h"
#include <stdlib.h>

int GetRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

const char* GetCharacterName() {
    const char* names[] = { "Arthur", "Luna", "Kai", "Iris", "Dante" };
    int index = GetRandom(0, 4); // ¹è¿­ Å©±â ¸ÂÃß±â
    return names[index];
}

const char* GetJob() {
    const char* jobs[] = { "Àü»ç", "±Ã¼ö", "¸¶¹ı»ç", "µµÀû" };
    int index = GetRandom(0, 3); 
    return jobs[index];
}

const char* GetRarity() {
    int index = GetRandom(0, 100);
    if (index <= 4) return "¿µ¿õ";
    if (index <= 29) return "Èñ±Í";
    return "ÀÏ¹İ";
}

const char* GetWeapon() {
    int index = GetRandom(0, 100);
    if (index == 0) return "Àü¼³ ¹«±â";
    if (index <= 9) return "¿µ¿õ ¹«±â";
    if (index <= 29) return "Èñ±Í ¹«±â";
    return "ÀÏ¹İ ¹«±â";
}

const char* GetArmor() {
    int index = GetRandom(0, 100);
    if (index <= 4) return "Àü¼³ °©¿Ê";
    if (index <= 19) return "¿µ¿õ °©¿Ê";
    return "ÀÏ¹İ °©¿Ê";
}

const char* GetMonster() {
    int index = GetRandom(0, 100);
    if (index <= 29) return "Å°¿¡¿¢";
    if (index <= 59) return "Å°¾ß¾Ç";
    if (index <= 89) return "³¢¿ä¿Ê";
    return "¾Æ¹«µµ ³¯ ¸·À»¼ö ¾øÀ¸¼À¤»¤»";
}