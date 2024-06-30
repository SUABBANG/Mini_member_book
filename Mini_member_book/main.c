#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //for exit()
#include "header.h"


int main(void) {
	
	int choice;

	do {
		printMenu();
		
		printf("메뉴를 선택 하세요 : ");
		scanf_s("%d", &choice);

		switch (choice) {
			case 1:
				//회원 추가
				addMemeber();
				break;
			case 2: {
				char searchPhone[MAX_PHONE_LEN];
				char newName[MAX_NAME_LEN];
				char newEmail[MAX_EMAIL_LEN];

				printf("수정할 회원의 전화번호를 입력하세요: ");
				scanf("%s", searchPhone);

				printf("새로운 이름을 입력하세요: ");
				scanf("%s", newName);

				printf("새로운 이메일을 입력하세요: ");
				scanf("%s", newEmail);

				editMember(searchPhone, newName, newEmail);
				break;
			}
			case 3: {
				// 회원 삭제
				char searchPhone[MAX_PHONE_LEN];

				printf("삭제할 회원의 전화번호를 입력하세요: ");
				scanf("%s", searchPhone);
				deleteMember(searchPhone);
				break;
			}
			case 4:
				// 회원 검색
				//searchMember();
				break;
			case 5:
				// 전체 회원 출력
				//allMember();
				break;
			case 6:
				printf("프로그램을 종료합니다.");
				exit(0);
			default:
				printf("잘못된 입력입니다.");
			}

	} while (choice != 0);

	return 0;
}