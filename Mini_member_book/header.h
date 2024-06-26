#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

#define MAX_NAME 10
#define MAX_PHONE 20
#define MAX_EMAIL 50

typedef struct {
	char name[MAX_NAME];
	char phone[MAX_PHONE];
	char email[MAX_EMAIL];
} Member;

void printMenu();
void addMember();
void editMember();
void deleteMember();
void searchMember();
void allMemeber();


#endif