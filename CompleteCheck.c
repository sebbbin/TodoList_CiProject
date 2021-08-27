#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include "CompleteCheck.h"
#include "BasicInfo.h"

void CompleteCheck(int ListNum, int CompNum)
{
    if (ListNum == 0)
    {
        printf("완료처리할 일정이 없습니다.\n");
        return;
    }

    CompleteLoop(ListNum, CompNum);
}

// 의도 : 할 일을 완료처리하는 함수
void CompleteLoop(int ListNum, int CompNum)
{
    int choice;

    while (1)
    {
        ShowMyList(ListNum);

        printf("완료처리할 일정의 번호를 입력해주세요: ");
        scanf("%d", &choice);
        printf("\n");

        // 문자열 길이 함수로 title에 내용이 있는지 판단

        if (choice > ListNum)
        {
            printf("해당 번호에 완료할 일정이 없습니다.\n");
            printf("다시 선택하세요\n");
            continue;
        }
        else if (choice <= ListNum)
        {
            break;
        }
    }

    choice -= 1;

    myCompList[CompNum] = myList[choice]; // 완료 처리된 항목들을 저장하는 연산

    // 값 덮어씌우는 작업
    for (int i = choice; i < ListNum - choice; i++)
    {
        myList[i] = myList[i + 1];
    }
}

void ShowCompList(int idx)
{
    printf("\n");

    printf("항목 번호 : %d\n", idx + 1);
    printf("할 일 이름 : %s\n", myCompList[idx].Title);

    if (myCompList[idx].Date.DateChecker == 1)
        printf("날짜 : %d월 %d일\n", myCompList[idx].Date.date.month, myCompList[idx].Date.date.day);

    if (myCompList[idx].Importance.ImportanceChecker == 1)
        printf("중요도 : %d\n", myCompList[idx].Importance.importance);

    printf("\n");
}

void ShowMyCompList(int CompNum)
{
    for (int i = 0; i < CompNum; ++i)
    {
        ShowCompList(i);
    }
}