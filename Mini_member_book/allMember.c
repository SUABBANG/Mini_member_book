#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "header.h"

void allMember(void) {
    Member members[MAX_MEMBERS];
    int count = 0;

    FILE* file = fopen(CSV_FILE, "r");
    if (!file) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    while (fgets(members[count].name, MAX_LINE_LEN, file)) {
        sscanf(members[count].name, "%49[^,],%49[^,],%99[^\n]", members[count].name, members[count].phone, members[count].email);
        count++;
    }
    fclose(file);

    // Sort members by name
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(members[i].name, members[j].name) > 0) {
                Member temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }

    // Print sorted members
    for (int i = 0; i < count; i++) {
        printf("이름: %s, 전화번호: %s, 이메일: %s\n", members[i].name, members[i].phone, members[i].email);
    }
}
