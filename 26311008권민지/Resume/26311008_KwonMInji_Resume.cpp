#include <stdio.h>

// 구조체 정의
struct Resume {
    char name[20];
    int age;
    char address[50];
    char phone[20];
    char education[100];
    char license[50];
    char military[20];
    char experience[300];
};

int main(void)
{
    // --- [과제 1: 이력서 작성] ---
    struct Resume myResume = {
        "권민지",
        20,
        "경기도 김포시",
        "010-5102-2578",
        "한국it직업전문학교 재학",
        "없음(JLPT N1 준비중)",
        "해당사항 없음",
        "애니메이션 원화/작화감독 경험, Blender 사용 가능, 오버워치 탑랭 플래티넘, 모데카이저 원챔으로 롤 탑랭 마스터"
    };

    printf("\n============================================================\n");
    printf("                  [ 이    력    서 ]                    \n");
    printf("============================================================\n");
    printf("■ 인적사항\n");
    printf("  %-10s : %s\n", "이    름", myResume.name);
    printf("  %-10s : %d 세\n", "나    이", myResume.age);
    printf("  %-10s : %s\n", "주    소", myResume.address);
    printf("  %-10s : %s\n", "연 락 처", myResume.phone);
    printf("------------------------------------------------------------\n");
    printf("■ 학력 및 병역\n");
    printf("  %-10s : %s\n", "학    력", myResume.education);
    printf("  %-10s : %s\n", "병    역", myResume.military);
    printf("------------------------------------------------------------\n");
    printf("■ 보유 역량 및 경험\n");
    printf("  %-10s : %s\n", "자 격 증", myResume.license);
    printf("  %-10s : %s\n", "경    력", myResume.experience);
    printf("============================================================\n\n");

    return 0;
}
