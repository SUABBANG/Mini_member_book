#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "header.h"

void allMember() {
    Member members[MAX_MEMBERS];
    int count = 0;

    FILE* file = fopen(CSV_FILE, "r");
    if (!file) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), file)) {
        // 개행 문자 제거
        line[strcspn(line, "\n")] = '\0';

        // 데이터를 파싱하여 members 배열에 저장
        sscanf(line, "%49[^,],%49[^,],%99[^\n]", members[count].name, members[count].phone, members[count].email);
        count++;
    }
    fclose(file);

    // 이름 기준으로 멤버들을 정렬
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(members[i].name, members[j].name) > 0) {
                Member temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }

    // 정렬된 멤버들을 출력
    for (int i = 0; i < count; i++) {
        printf("이름: %s, 전화번호: %s, 이메일: %s\n", members[i].name, members[i].phone, members[i].email);
    }
}