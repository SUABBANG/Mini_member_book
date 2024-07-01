#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"

void searchMember() {
    int searchChoice;
    char searchTerm[MAX_NAME_LEN];

    printf("ȸ�� ���� �˻�\n");
    printf("1. �̸����� �˻�\n");
    printf("2. ��ȭ��ȣ�� �˻�\n");
    printf("3. �̸��Ϸ� �˻�\n");
    printf("�˻� ����� �����ϼ���: ");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
    case 1:
        printf("�̸��� �Է��ϼ���: ");
        scanf("%s", searchTerm);
        searchByName(searchTerm);
        break;
    case 2:
        printf("��ȭ��ȣ�� �Է��ϼ���: ");
        scanf("%s", searchTerm);
        searchByPhone(searchTerm);
        break;
    case 3:
        printf("�̸����� �Է��ϼ���: ");
        scanf("%s", searchTerm);
        searchByEmail(searchTerm);
        break;
    default:
        printf("�߸��� �Է��Դϴ�.\n");
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
            printf("ȸ�� ����: �̸�: %s, ��ȭ��ȣ: %s, �̸���: %s\n", member.name, member.phone, member.email);
            found = 1;
        }
    }
    fclose(file);
    if (!found) {
        printf("��ġ�ϴ� ȸ���� �����ϴ�.\n");
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
            printf("ȸ�� ����: �̸�: %s, ��ȭ��ȣ: %s, �̸���: %s\n", member.name, member.phone, member.email);
            found = 1;
        }
    }
    fclose(file);
    if (!found) {
        printf("��ġ�ϴ� ȸ���� �����ϴ�.\n");
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
            printf("ȸ�� ����: �̸�: %s, ��ȭ��ȣ: %s, �̸���: %s\n", member.name, member.phone, member.email);
            found = 1;
        }
    }
    fclose(file);
    if (!found) {
        printf("��ġ�ϴ� ȸ���� �����ϴ�.\n");
    }
}
