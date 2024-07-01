#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "header.h"

void allMember() {
    Member members[MAX_MEMBERS];
    int count = 0;

    FILE* file = fopen(CSV_FILE, "r");
    if (!file) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), file)) {
        // ���� ���� ����
        line[strcspn(line, "\n")] = '\0';

        // �����͸� �Ľ��Ͽ� members �迭�� ����
        sscanf(line, "%49[^,],%49[^,],%99[^\n]", members[count].name, members[count].phone, members[count].email);
        count++;
    }
    fclose(file);

    // �̸� �������� ������� ����
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(members[i].name, members[j].name) > 0) {
                Member temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }

    // ���ĵ� ������� ���
    for (int i = 0; i < count; i++) {
        printf("�̸�: %s, ��ȭ��ȣ: %s, �̸���: %s\n", members[i].name, members[i].phone, members[i].email);
    }
}