#include <stdio.h>
int main(void) 
{
    // 과제 3  캐릭터 스탯
    float k_hp = 500.5f, k_mp = 50.0f, k_exp = 12.45f;
    float m_hp = 250.2f, m_mp = 450.8f, m_exp = 85.12f;
    float p_hp = 320.0f, p_mp = 300.5f, p_exp = 42.77f;

    printf("==================================================\n");
    printf("    직업(Job)      HP          MP        EXP(%%)   \n");
    printf("--------------------------------------------------\n");
    printf("  %-12s %-10.1f %-10.1f %-10.2f\n", "Knight", k_hp, k_mp, k_exp);
    printf("  %-12s %-10.1f %-10.1f %-10.2f\n", "Mage", m_hp, m_mp, m_exp);
    printf("  %-12s %-10.1f %-10.1f %-10.2f\n", "Priest", p_hp, p_mp, p_exp);
    printf("==================================================\n\n");

	return 0;
}