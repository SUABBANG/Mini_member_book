#include <stdio.h>
#include "header.h"

int main(void) {
	
	int choice;


	do {
		printMenu();
		
		printf("메뉴를 선택 하세요 : ");
		scanf_s("%d", &choice);

	} while (choice != 0);

	return 0;
}