#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_FILE "member.csv"

int isPhoneDuplicate(const char* phone) {
	FILE* file = fopen(CSV_FILE, "r"); //읽기 전용
	if (file == NULL) { 
		// 파일이 존재하지 않음
		return 0;
	}

	char line[1024];
	while (fgets(line, sizeof(line), file)) {
		char* context = NULL;
		char* token = strtok_s(line, ",", &context); // Skip name
		token = strtok_s(NULL, ",", &context); // Get phone

		if (token != NULL && strcmp(token, phone) == 0) {
			fclose(file);
			return 1; // Duplicate found
		}
	}
	fclose(file);
	return 0; //No duplicate found
}

void addMemeber() {
	Member newMember;
	char choice[2];

	while (1) {
		printf("이름을 입력 : ");
		scanf("%s", newMember.name);

		printf("전화번호 입력 : ");
		scanf("%s", newMember.phone);
		
		if (isPhoneDuplicate(newMember.phone)) {
			printf("중복된 전화번호입니다. 다시 입력하시겠습니까? (Y/N): ");
			scanf_s("%1s", choice, (unsigned)_countof(choice)); // %1s to read a single character
			if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
				continue; // Re-enter details
			}
			else {
				return; // Go back to menu
			}
		}

		//if (isPhoneDuplicate(newMember.phone)) {
		//	printf("중복된 전화번호 입니다. 다시 입력하시겠습니까? (Y/N) : ");
		//	scanf_s("%s", &choice);
		//	if (choice == "Y" || choice == "y") {
		//		continue;
		//	}
		//	else {
		//		return; // Go Back to Menu
		//	}
		//}

		printf("이메일 입력 : ");
		scanf("%s", newMember.email);

		FILE* file = fopen(CSV_FILE, "a"); // 추가 쓰기 전용
		if (file == NULL) {
			printf("파일을 찾을 수 없습니다.");
			return; // Go Back to Menu
		}
		fprintf(file, "%s,%s,%s\n", newMember.name, newMember.phone, newMember.email);
		fclose(file);

		printf("회원이 성공적으로 추가되었습니다.\n");
		return; // Go Back to Menu

	}

	return 0;
}