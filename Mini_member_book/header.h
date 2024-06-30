#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 50
#define MAX_EMAIL_LEN 100


typedef struct {
	char name[MAX_NAME_LEN];
	char phone[MAX_PHONE_LEN];
	char email[MAX_EMAIL_LEN];
} Member;

void printMenu();
void addMemeber();


#endif