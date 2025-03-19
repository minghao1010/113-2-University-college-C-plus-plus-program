#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    struct Student* nextPtr;
};

typedef struct Student Student;
typedef Student* StudentPtr;

void insert(StudentPtr* sPtr, int id, char name[]);
void printList(StudentPtr currentPtr);
int isEmpty(StudentPtr sPtr);
void deleteStudent(StudentPtr* sPtr, int id);

int main(void)
{
    StudentPtr startPtr = NULL;
    int id;
    char name[50];

    // 輸入學生資料
    for (int i = 0; i < 4; i++) {
        printf("輸入第 %d 筆學生資料：\n", i + 1);
        printf("輸入學生學號: ");
        scanf_s("%d", &id);
        printf("輸入學生姓名: ");
        scanf_s("%s", name, sizeof(name));
        insert(&startPtr, id, name);
    }

    // 顯示鏈結串列內容
    printList(startPtr);

    // 輸入要刪除的學生 ID
    printf("輸入要刪除的學生學號: ");
    scanf_s("%d", &id);

    // 刪除對應的學生資料
    deleteStudent(&startPtr, id);

    // 顯示刪除後的鏈結串列內容
    printList(startPtr);

    puts("程式結束。");
}

// 插入新的學生資料
void insert(StudentPtr* sPtr, int id, char name[])
{
    StudentPtr newPtr = (StudentPtr)malloc(sizeof(Student));
    if (newPtr != NULL) {
        newPtr->id = id;
        strcpy_s(newPtr->name, sizeof(newPtr->name), name);
        newPtr->nextPtr = NULL;

        StudentPtr previousPtr = NULL;
        StudentPtr currentPtr = *sPtr;

        // 找到正確的位置插入新學生資料
        while (currentPtr != NULL && id > currentPtr->id) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // 插入新節點
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf("學生資料未插入，無法分配記憶體。\n");
    }
}

// 顯示所有學生資料
void printList(StudentPtr currentPtr)
{
    if (isEmpty(currentPtr)) {
        puts("串列為空。\n");
    }
    else {
        puts("學生資料如下:");
        while (currentPtr != NULL) {
            printf("學號: %d, 姓名: %s --> ", currentPtr->id, currentPtr->name);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

// 檢查串列是否為空
int isEmpty(StudentPtr sPtr)
{
    return sPtr == NULL;
}

// 根據學號刪除學生資料
void deleteStudent(StudentPtr* sPtr, int id)
{
    if (*sPtr == NULL) {
        printf("串列為空，無法刪除。\n");
        return;
    }

    StudentPtr previousPtr = NULL;
    StudentPtr currentPtr = *sPtr;

    // 查找要刪除的節點
    while (currentPtr != NULL && currentPtr->id != id) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    // 如果找到了對應的學生 ID
    if (currentPtr != NULL) {
        if (previousPtr == NULL) { // 刪除的是第一個節點
            *sPtr = currentPtr->nextPtr;
        }
        else { // 刪除的是中間或最後一個節點
            previousPtr->nextPtr = currentPtr->nextPtr;
        }
        free(currentPtr);
        printf("學號 %d 的學生已被刪除。\n", id);
    }
    else {
        printf("未找到學號 %d 的學生。\n", id);
    }
}