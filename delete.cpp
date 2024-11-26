void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next; 
    free(temp);            
}

void deleteTail(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong");
        return;
    }
	
	// Danh sach chi co 1 phan tu
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


void deleteAfterKeys(Node** head, int key) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* temp = *head;

    while (temp != NULL) {
        if (temp->data == key && temp->next != NULL) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;  
            free(nodeToDelete); 
        }
        temp = temp->next;
    }
}


void deleteBeforeKeys(Node** head, int key) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* nodeToDelete = temp;
            temp = temp->next;  
            if (prev != NULL) {
                prev->next = temp;
            } else {
                *head = temp;  
            }
            free(nodeToDelete);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sach rong");
        return;
    }

    if (position == 1) {
        Node* temp = *head;
        *head = (*head)->next; 
        free(temp);           
        return;
    }

    Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri %d khong phu hop", position);
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; 
    free(nodeToDelete);            
}


void deleteAllOccurrences(Node** head, int key) {
    if (*head == NULL) {
        return;  
    }

    while (*head != NULL && (*head)->data == key) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node* temp = *head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;  
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}


