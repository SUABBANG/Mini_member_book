#include <stdio.h>
#include "header.h"

int main(void) {
	
	int choice;


	do {
		printMenu();
		
		printf("�޴��� ���� �ϼ��� : ");
		scanf_s("%d", &choice);

	} while (choice != 0);

	return 0;
}