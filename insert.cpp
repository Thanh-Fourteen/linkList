void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri %d khong phu hop", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterKeys(Node** head, int value, int key) {
    if (*head == NULL) {
        printf("Danh sach rong");
        return;
    }

    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == key) {
            Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode; 
        }
        temp = temp->next;
    }
}

void insertBeforeKeys(Node** head, int value, int key) {
    if (*head == NULL) {
        printf("Danh sach rong");
        return;
    }
	
	Node* temp = *head;
	
    if ((*head)->data == key) {
        Node* newNode = createNode(value);
        newNode->next = *head;
        *head = newNode;
    }

    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode; 
        }
        temp = temp->next;
    }
}

