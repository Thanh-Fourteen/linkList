#include <string.h>
#include "color.cpp"

void loadTestCases(Node** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf(RED "Khong the mo file.\n" RESET);
        return;
    }

    int choice, val, pos, key;
    char taskDescription[255]; // Buffer d? ch?a mô t? tác v?

    while (fscanf(file, "%d", &choice) != EOF) {
        switch (choice) {
            case 1:
                fscanf(file, "%d", &val);
                sprintf(taskDescription, GREEN "Them %d vao dau danh sach" RESET, val);
                insertAtHead(head, val);
                break;
            case 2:
                fscanf(file, "%d", &val);
                sprintf(taskDescription, GREEN "Them %d vao cuoi danh sach" RESET, val);
                insertAtTail(head, val);
                break;
            case 3:
                fscanf(file, "%d %d", &pos, &val);
                sprintf(taskDescription, GREEN "Them %d vao vi tri %d" RESET, val, pos);
                insertAtPosition(head, val, pos);
                break;
            case 4:
                fscanf(file, "%d %d", &key, &val);
                sprintf(taskDescription, GREEN "Them %d sau phan tu %d" RESET, val, key);
                insertAfterKeys(head, val, key);
                break;
            case 5:
                fscanf(file, "%d %d", &key, &val);
                sprintf(taskDescription, GREEN "Them %d truoc phan tu %d" RESET, val, key);
                insertBeforeKeys(head, val, key);
                break;
            case 6:
                strcpy(taskDescription, RED "Xoa phan tu dau danh sach" RESET);
                deleteHead(head);
                break;
            case 7:
                strcpy(taskDescription, RED "Xoa phan tu cuoi danh sach" RESET);
                deleteTail(head);
                break;
            case 8:
                fscanf(file, "%d", &pos);
                sprintf(taskDescription, RED "Xoa phan tu tai vi tri %d" RESET, pos);
                deleteAtPosition(head, pos);
                break;
            case 9:
                fscanf(file, "%d", &key);
                sprintf(taskDescription, RED "Xoa cac phan tu %d" RESET, key);
                deleteAllOccurrences(head, key);
                break;
            case 10:
                fscanf(file, "%d", &key);
                sprintf(taskDescription, RED "Xoa phan tu sau phan tu %d" RESET, key);
                deleteAfterKeys(head, key);
                break;
            case 11:
                fscanf(file, "%d", &key);
                sprintf(taskDescription, RED "Xoa phan tu truoc phan tu %d" RESET, key);
                deleteBeforeKeys(head, key);
                break;
            case 0:
                printf(YELLOW "Ket thuc test cases.\n" RESET);
                fclose(file);
                return;
            default:
                printf(RED "Lua chon khong hop le.\n" RESET);
                break;
        }

        printf(CYAN "Task: %s\n" RESET, taskDescription);
        printList(*head);
    }

    fclose(file);
}

