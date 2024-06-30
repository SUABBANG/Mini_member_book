#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

void deleteMember(const char* phoneToDelete) {
    FILE* fp;
    FILE* tempFp;
    Member member;
    int found = 0;

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
            continue; 
        }


        fprintf(tempFp, "%s,%s,%s\n", member.name, member.phone, member.email);
    }


    fclose(fp);
    fclose(tempFp);

    // Remove the original file and rename the temporary file
    remove(CSV_FILE);
    rename("temp.csv", CSV_FILE);

    if (found) {
        printf("회원 정보가 성공적으로 삭제되었습니다.\n");
    }
    else {
        printf("해당 전화번호를 가진 회원을 찾을 수 없습니다.\n");
    }
}
