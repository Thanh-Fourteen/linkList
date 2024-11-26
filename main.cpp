#include <stdio.h>
#include <stdlib.h>

#include "setup.cpp"
#include "insert.cpp"
#include "delete.cpp"
#include "color.cpp"
#include "loadTestCase.cpp"         

void menu(){
    printf(GREEN "+-------------------- Menu ---------------------+\n" RESET);
    printf(RED "| 0. Thoat					|\n" RESET);
    printf(CYAN "| 1. Them vao dau danh sach			|\n" RESET);
    printf(CYAN "| 2. Them vao cuoi danh sach			|\n" RESET);
    printf(CYAN "| 3. Them phan tu vao vi tri			|\n" RESET);
    printf(CYAN "| 4. Them phan tu sau mot phan tu cu the	|\n" RESET);
    printf(CYAN "| 5. Them phan tu truoc mot phan tu cu the	|\n" RESET);
    printf(CYAN "| 6. Xoa phan tu dau danh sach			|\n" RESET);
    printf(CYAN "| 7. Xoa phan tu cuoi danh sach			|\n" RESET);
    printf(CYAN "| 8. Xoa phan tu tai vi tri			|\n" RESET);
    printf(CYAN "| 9. Xoa phan tu cu the				|\n" RESET);
    printf(CYAN "|10. Xoa phan tu sau mot phan tu cu the		|\n" RESET);
    printf(CYAN "|11. Xoa phan tu truoc mot phan tu cu the	|\n" RESET);
    printf(YELLOW "|12. In link list				|\n" RESET);
    printf(YELLOW "|13. Load test cases from file			|\n" RESET);
    printf(GREEN "+-----------------------------------------------+\n" RESET);
}

int main() {
    int choice;
    Node* head = NULL;

    do {
    	system("cls");
        menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                //Them vao dau danh sach
                int val;
                printf("Nhap gia tri can them: ");
                scanf("%d", &val);
                insertAtHead(&head, val);
                break;
            case 2:
                //Them vao cuoi danh sach
                printf("Nhap gia tri can them: ");
                scanf("%d", &val);
                insertAtTail(&head, val);
                break;
            case 3:
                //Them phan tu vao vi tri
                int pos, value;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertAtPosition(&head, value, pos);
                break;
            case 4:
                //Them phan tu sau mot phan tu cu the
                int key, key_val;
                printf("Nhap gia tri phan tu can them sau: ");
                scanf("%d", &key);
                printf("Nhap gia tri can them: ");
                scanf("%d", &key_val);
                insertAfterKeys(&head, key_val, key);
                break;
            case 5:
                deleteHead(&head);
                printf("Danh sach sau khi xoa head: ");
                break;
            case 6:
                //Them phan tu truoc mot phan tu cu the
                printf("Nhap gia tri phan tu can them truoc: ");
                scanf("%d", &key);
                printf("Nhap gia tri can them: ");
                scanf("%d", &key_val);
                insertBeforeKeys(&head, key_val, key);
                break;
            case 7:
                deleteTail(&head);
                printf("Danh sach sau khi xoa phan tu cuoi: ");
                break;
            case 8:
                //Xoa phan tu tai vi tri
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 9:
            	// Xoa phan tu cu the
            	int num;
            	printf("Nhap vi tri can xoa: ");
                scanf("%d", &num);
            	deleteAllOccurrences(&head, num);
            case 10:
                //Xoa phan tu sau mot phan tu cu the
                printf("Nhap gia tri phan tu can xoa sau: ");
                scanf("%d", &key);
                deleteAfterKeys(&head, key);
                break;
            case 11:
                //Xoa phan tu truoc mot phan tu cu the
                printf("Nhap gia tri phan tu can xoa truoc: ");
                scanf("%d", &key);
                deleteBeforeKeys(&head, key);
                break;
            case 12:
            	printList(head);
            	system("pause");
            	break;
            case 13:
            	printf("Nhap ten test case: ");
            	char name[100];
            	scanf("%s", &name);
                loadTestCases(&head, name);
				system("pause");  
                break;
            case 0:
                printf(RED "Thoat chuong trinh\n" RESET);
                break;
            default:
                printf(RED "Lua chon khong hop le\n" RESET);
                system("pause");
        }
    } while (choice != 0);

    freeList(head); 
    return 0;
}


