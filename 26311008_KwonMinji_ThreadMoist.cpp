/*과제: 이력서 작성 출력
이력서용 프로젝트를 만들고, printf 함수를 사용해서 이력서 작성
이름/나이/주소(시군구까지만)/연락처는 반드시 포함
학력/자격증/군필/취업 또는 아르바이트 등 이력이 될만한 모든 내용을 적어보자.
포멧 옵션을 사용해서 줄을 맞춰 출력해보자.

과제: 자기소개서 작성 출력
자기 소개서용 프로젝트를 만들고, printf 함수를 사용해서 자기 소개서 작성
이름/잘하는 것/장단점 을 반드시 포함
포멧 옵션을 사용해서 줄을 맞춰 출력.

과제: 게임 캐릭터의 상태 출력하기
기사(Knight), 마법사(Mage), 성직자(Priest) 세 캐릭터를 준비하고 각 캐릭터의 HP, MP, EXP를 변수로 선언한 뒤
다음과 같은 형식으로 출력 각 수치는 float 형을 사용
*/

#include <stdio.h>
{
struct Resume{
char name[20];
int age;
char address[50];
char phone[20];
char education[50];
char license[50];
char military[20];
char experience[100];
};
int main(void){
struct Resume myResume = {
  "권민지",                 // 이름
  20,                       // 나이
  "경기도 김포시",          // 주소(시군구)
  "010-5102-2578",          // 연락처
  "운양 고등학교 졸업, 한국it직업전문학교 게임 프로그래밍과 재학중",         //최종학력
  "없음",    //자격증
  "해당사항 없음", //군필 여부
  "애니메이션 원화, 동화, 작화감독 경험 다수 보유, 일본어 가능, blender 사용 가능"
};

printf("\n");
  printf("============================================================\n");
  printf("                  [ 이     력     서 ]                    \n");
  printf("============================================================\n");

  printf("■ 인적사항\n");
    printf("  %-15s : %s\n", "이    름", myResume.name);
    printf("  %-15s : %d 세\n", "나    이", myResume.age);
    printf("  %-15s : %s\n", "주    소", myResume.address);
    printf("  %-15s : %s\n", "연 락 처", myResume.phone);
  
return 0;
}
