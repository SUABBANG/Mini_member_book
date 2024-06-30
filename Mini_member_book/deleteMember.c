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
            printf("다음 회원을 삭제하시겠습니까?\n");
            printf("이름: %s\n", member.name);
            printf("전화번호: %s\n", member.phone);
            printf("이메일: %s\n", member.email);
            printf("정말로 삭제하려면 'y'를 입력하세요 (삭제하지 않으려면 다른 키를 입력하세요): ");
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
        printf("회원 정보가 성공적으로 삭제되었습니다.\n");
    }
    else {
        printf("해당 전화번호를 가진 회원을 찾을 수 없습니다.\n");
    }

    system("pause"); // 일시정지
}
