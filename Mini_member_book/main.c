#include <stdio.h>
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
			addMember();
			break;
		case 2:
			// 회원 수정
			editMember();
			break;
		case 3:
			// 회원 삭제
			deleteMember();
			break;
		case 4:
			// 회원 검색
			searchMember();
			break;
		case 5:
			// 전체 회원 출력
			allMemeber();
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