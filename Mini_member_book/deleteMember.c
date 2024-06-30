#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h> // for system("pause");

void deleteMember(const char* phoneToDelete) {
    FILE* fp;
    FILE* tempFp;
    Member member;
    int found = 0;
    char confirm;

    fp = fopen(CSV_FILE, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    tempFp = fopen("temp.csv", "w");
    if (tempFp == NULL) {
        perror("Error creating temporary file");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n", member.name, member.phone, member.email) == 3) {
        if (strcmp(member.phone, phoneToDelete) == 0) {
            found = 1;
            printf("���� ȸ���� �����Ͻðڽ��ϱ�?\n");
            printf("�̸�: %s\n", member.name);
            printf("��ȭ��ȣ: %s\n", member.phone);
            printf("�̸���: %s\n", member.email);
            printf("������ �����Ϸ��� 'y'�� �Է��ϼ��� (�������� �������� �ٸ� Ű�� �Է��ϼ���): ");
            scanf(" %c", &confirm);
            if (confirm != 'y' && confirm != 'Y') {
                fprintf(tempFp, "%s,%s,%s\n", member.name, member.phone, member.email);
            }
            continue; 
        }

        fprintf(tempFp, "%s,%s,%s\n", member.name, member.phone, member.email);
    }

    fclose(fp);
    fclose(tempFp);

   
    remove(CSV_FILE);
    rename("temp.csv", CSV_FILE);

    if (found) {
        printf("ȸ�� ������ ���������� �����Ǿ����ϴ�.\n");
    }
    else {
        printf("�ش� ��ȭ��ȣ�� ���� ȸ���� ã�� �� �����ϴ�.\n");
    }

    system("pause"); // �Ͻ�����
}
