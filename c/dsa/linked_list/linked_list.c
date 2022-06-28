#include "stdio.h"
#include "stdlib.h"
#include "linked_list.h"

void l_print(node *head){
    if(head == NULL){
        printf("Head not initialised!\n");
        return;
    }
    node *temp = head;
    printf("\nPrinting the ll\n");
    while(temp){
        printf("%p %d %p\n", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

void l_init(node **head, int data){
    if((*head)!=NULL){
        printf("Linked list already initialised!!\n");
        return;
    }
    (*head) = (node *)malloc(sizeof(node));
    (*head)->data = data;
    (*head)->next = NULL;
}

void l_push_back(node **head, int data){
    if((*head) == NULL){
        l_init(head, data);
        return;
    }

    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    node *temp = (*head);
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new;
}

void l_push_front(node **head, int data){
    if((*head) == NULL){
        l_init(head, data);
        return;
    }

    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void l_insert(node **head, int pos, int data){
    if((*head) == NULL){
        printf("The linked list not initialised!!\n");
        return;
    }

    if(pos == 1){
        l_push_front(head, data);
        return;
    }

    node *new = (node *)malloc(sizeof(node));
    new->data = data;

    node *temp = (*head);
    pos--;
    while(temp && --pos){
        temp = temp->next;
    }
    if(pos-1!=-1){
        printf("Pos out of bound!!\n");
        return;
    }

    new->next = temp->next;
    temp->next = new;
}

void l_delete_front(node **head){
    if((*head) == NULL){
        printf("The linked list not initialised!!\n");
        return;
    }
    node *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
}

void l_delete_back(node **head){
    if((*head) == NULL){
        printf("The linked list not initialised!!\n");
        return;
    }
    if((*head)->next == NULL){
        l_delete_front(head);
        return;
    }
    node *temp = (*head);
    printf("\n");
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void l_delete(node **head, int pos){
    if((*head) == NULL){
        printf("The linked list not initialised!!\n");
        return;
    }
    if(pos == 1){
        l_delete_front(head);
        return;
    }

    node *prev = (*head);
    pos--;
    while(prev->next->next && --pos){
        prev = prev->next;
    }
    if(pos!=0&&pos!=1){
        printf("Invalid position\n");
        return;
    }
    if(pos == 1){
        l_delete_back(head);
        return;
    }
    node *temp = prev->next;
    prev->next = temp->next;
    free(temp);

}

void l_clear(node **head){
    if((*head) == NULL)
        return;

    node *temp;
    while((*head)){
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
}

node *l_get(node *head, int pos){
    if(head == NULL){
        printf("The linked list not initialised!!\n");
        return NULL;
    }

    node *temp = head;
    while(temp->next&& --pos){
        temp = temp->next;
    }

    if(pos!=0&&pos!=1){
        printf("Invalid position\n");
        return NULL;
    }
    return temp;
}

void l_set(node **head, int pos, int data){
    if((*head) == NULL){
        printf("The linked list not initialised!!\n");
        return;
    }

    node *temp = (*head);
    while(temp->next&& --pos){
        temp = temp->next;
    }

    if(pos!=0&&pos!=1){
        printf("Invalid position\n");
        return;
    }
    temp->data=data;
}

int l_find(node *head, int data){
    if(head == NULL){
        printf("The linked list not initialised!!\n");
        return -1;
    }

    node *temp = head;
    while(temp){
        if(temp->data == data)return 1;
        temp = temp->next;
    }
    return 0;
}
