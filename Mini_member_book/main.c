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
			case 2:
				// ȸ�� ����
				//editMember();
				break;
			case 3:
				// ȸ�� ����
				//deleteMember();
				break;
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