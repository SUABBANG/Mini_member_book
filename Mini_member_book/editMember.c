#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

void editMember(const char* beforePhone, const char* newName, const char* newEmail) {
    FILE* fp;
    FILE* tempFp;
    Member member;
    int found = 0;

    // CSV ������ �б� ���� ����
    fp = fopen(CSV_FILE, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // ������ ������ ����� �ӽ� ���� ����
    tempFp = fopen("temp.csv", "w");
    if (tempFp == NULL) {
        perror("Error creating temporary file");
        fclose(fp);
        return;
    }

    // CSV ������ �� ���� �о��
    // "%[^,]"�� ��ǥ�� �ƴ� ���ڵ��� ���� -> member.name, member.phone, member.email ������ ��ǥ�� �ƴ� ���ڵ��� ���ʴ�� ����
    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n", member.name, member.phone, member.email) == 3) {
        // Check if this is the member to edit
        if (strcmp(member.phone, beforePhone) == 0) {
            // Update the member's information
            strcpy(member.name, newName);
            strcpy(member.email, newEmail);
            found = 1;
        }

        // Write the member (either updated or unchanged) to the temporary file
        fprintf(tempFp, "%s,%s,%s\n", member.name, member.phone, member.email);
    }

    // Close both files
    fclose(fp);
    fclose(tempFp);

    // Remove the original file and rename the temporary file
    remove(CSV_FILE);
    rename("temp.csv", CSV_FILE);

    if (found) {
        printf("ȸ�� ������ ���������� �����Ǿ����ϴ�.\n");
    }
    else {
        printf("�ش� ��ȭ��ȣ�� ���� ȸ���� ã�� �� �����ϴ�.\n");
    }
}