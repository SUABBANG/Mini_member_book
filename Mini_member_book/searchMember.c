#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"

void searchMember() {
    int searchChoice;
    char searchTerm[MAX_NAME_LEN];

    printf("회원 정보 검색\n");
    printf("1. 이름으로 검색\n");
    printf("2. 전화번호로 검색\n");
    printf("3. 이메일로 검색\n");
    printf("검색 방법을 선택하세요: ");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
    case 1:
        printf("이름을 입력하세요: ");
        scanf("%s", searchTerm);
        searchByName(searchTerm);
        break;
    case 2:
        printf("전화번호를 입력하세요: ");
        scanf("%s", searchTerm);
        searchByPhone(searchTerm);
        break;
    case 3:
        printf("이메일을 입력하세요: ");
        scanf("%s", searchTerm);
        searchByEmail(searchTerm);
        break;
    default:
        printf("잘못된 입력입니다.\n");
        break;
    }
}

void searchByName(char* name) {
    FILE* file = fopen(CSV_FILE, "r");
    char line[MAX_LINE_LEN];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        Member member;
        sscanf(line, "%[^,],%[^,],%s", member.name, member.phone, member.email);
        if (strcmp(member.name, name) == 0) {
            printf("회원 정보: 이름: %s, 전화번호: %s, 이메일: %s\n", member.name, member.phone, member.email);
            found = 1;
        }
    }
    fclose(file);
    if (!found) {
        printf("일치하는 회원이 없습니다.\n");
    }
}

void searchByPhone(char* phone) {
    FILE* file = fopen(CSV_FILE, "r");
    char line[MAX_LINE_LEN];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        Member member;
        sscanf(line, "%[^,],%[^,],%s", member.name, member.phone, member.email);
        if (strcmp(member.phone, phone) == 0) {
            printf("회원 정보: 이름: %s, 전화번호: %s, 이메일: %s\n", member.name, member.phone, member.email);
            found = 1;
        }
    }
    fclose(file);
    if (!found) {
        printf("일치하는 회원이 없습니다.\n");
    }
}

void searchByEmail(char* email) {
    FILE* file = fopen(CSV_FILE, "r");
    char line[MAX_LINE_LEN];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        Member member;
        sscanf(line, "%[^,],%[^,],%s", member.name, member.phone, member.email);
        if (strcmp(member.email, email) == 0) {
            printf("회원 정보: 이름: %s, 전화번호: %s, 이메일: %s\n", member.name, member.phone, member.email);
            found = 1;
        }
    }
    fclose(file);
    if (!found) {
        printf("일치하는 회원이 없습니다.\n");
    }
}
