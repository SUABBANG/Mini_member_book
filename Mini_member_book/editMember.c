#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

void editMember(const char* beforePhone, const char* newName, const char* newEmail) {
    FILE* fp;
    FILE* tempFp;
    Member member;
    int found = 0;

    // CSV 파일을 읽기 모드로 열기
    fp = fopen(CSV_FILE, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // 수정된 내용을 기록할 임시 파일 열기
    tempFp = fopen("temp.csv", "w");
    if (tempFp == NULL) {
        perror("Error creating temporary file");
        fclose(fp);
        return;
    }

    // CSV 파일의 각 줄을 읽어옴
    // "%[^,]"는 쉼표가 아닌 문자들을 읽음 -> member.name, member.phone, member.email 변수에 쉼표가 아닌 문자들을 차례대로 저장
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
        printf("회원 정보가 성공적으로 수정되었습니다.\n");
    }
    else {
        printf("해당 전화번호를 가진 회원을 찾을 수 없습니다.\n");
    }
}