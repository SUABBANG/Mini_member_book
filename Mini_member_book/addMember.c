#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_FILE "member.csv"

int isPhoneDuplicate(const char* phone) {
	FILE* file = fopen(CSV_FILE, "r"); //�б� ����
	if (file == NULL) { 
		// ������ �������� ����
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
		printf("�̸��� �Է� : ");
		scanf("%s", newMember.name);

		printf("��ȭ��ȣ �Է� : ");
		scanf("%s", newMember.phone);
		
		if (isPhoneDuplicate(newMember.phone)) {
			printf("�ߺ��� ��ȭ��ȣ�Դϴ�. �ٽ� �Է��Ͻðڽ��ϱ�? (Y/N): ");
			scanf_s("%1s", choice, (unsigned)_countof(choice)); // %1s to read a single character
			if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
				continue; // Re-enter details
			}
			else {
				return; // Go back to menu
			}
		}

		//if (isPhoneDuplicate(newMember.phone)) {
		//	printf("�ߺ��� ��ȭ��ȣ �Դϴ�. �ٽ� �Է��Ͻðڽ��ϱ�? (Y/N) : ");
		//	scanf_s("%s", &choice);
		//	if (choice == "Y" || choice == "y") {
		//		continue;
		//	}
		//	else {
		//		return; // Go Back to Menu
		//	}
		//}

		printf("�̸��� �Է� : ");
		scanf("%s", newMember.email);

		FILE* file = fopen(CSV_FILE, "a"); // �߰� ���� ����
		if (file == NULL) {
			printf("������ ã�� �� �����ϴ�.");
			return; // Go Back to Menu
		}
		fprintf(file, "%s,%s,%s\n", newMember.name, newMember.phone, newMember.email);
		fclose(file);

		printf("ȸ���� ���������� �߰��Ǿ����ϴ�.\n");
		return; // Go Back to Menu

	}

	return 0;
}