#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //for exit()
#include "header.h"


int main(void) {
	
	int choice;

	do {
		printMenu();
		
		printf("�޴��� ���� �ϼ��� : ");
		scanf_s("%d", &choice);

		switch (choice) {
			case 1:
				//ȸ�� �߰�
				addMemeber();
				break;
			case 2: {
				char searchPhone[MAX_PHONE_LEN];
				char newName[MAX_NAME_LEN];
				char newEmail[MAX_EMAIL_LEN];

				printf("������ ȸ���� ��ȭ��ȣ�� �Է��ϼ���: ");
				scanf("%s", searchPhone);

				printf("���ο� �̸��� �Է��ϼ���: ");
				scanf("%s", newName);

				printf("���ο� �̸����� �Է��ϼ���: ");
				scanf("%s", newEmail);

				editMember(searchPhone, newName, newEmail);
				break;
			}
			case 3: {
				// ȸ�� ����
				char searchPhone[MAX_PHONE_LEN];

				printf("������ ȸ���� ��ȭ��ȣ�� �Է��ϼ���: ");
				scanf("%s", searchPhone);
				deleteMember(searchPhone);
				break;
			}
			case 4:
				// ȸ�� �˻�
				//searchMember();
				break;
			case 5:
				// ��ü ȸ�� ���
				//allMember();
				break;
			case 6:
				printf("���α׷��� �����մϴ�.");
				exit(0);
			default:
				printf("�߸��� �Է��Դϴ�.");
			}

	} while (choice != 0);

	return 0;
}