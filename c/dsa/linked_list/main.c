#include "linked_list.h"
#include "stdio.h"

int main(){
    int choice, data, position;

    node *head = NULL;
    node *temp;

    while(1){
        printf("**Linked List Menu**\n");
        printf("0: Exit\n");
        printf("1: Display the linked list\n");
        printf("2: Initiate the linked list\n");
        printf("3: Push Element at the end\n");
        printf("4: Push Element at the start\n");
        printf("5: Push Element at a location\n");
        printf("6: Delete the first element\n");
        printf("7: Delete the last element\n");
        printf("8: Delete at a location\n");
        printf("9: Find an element\n");
        printf("10: Get the element at a position\n"); 
        printf("11: Set value at a position\n");
        printf("-- Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                return 0;

            case 1:
                l_print(head);
                break;

            case 2:
                printf("Enter data to initiaise the linked list: ");
                scanf("%d", &data);
                l_init(&head, data);
                break;

            case 3:
                printf("Enter data to push at back of the linked list: ");
                scanf("%d", &data);
                l_push_back(&head, data);
                break;

            case 4:
                printf("Enter data to push at front of the linked list: ");
                scanf("%d", &data);
                l_push_front(&head, data);
                break;

            case 5:
                printf("Enter data and the position to insert in the linked list: ");
                scanf("%d %d", &data, &position);
                l_insert(&head, position, data);
                break;

            case 6:
                l_delete_front(&head);
                printf("First element deleted\n");
                break;

            case 7:
                l_delete_back(&head);
                printf("Last element deleted\n");
                break;

            case 8:
                printf("Enter position to delete element from the linked list: ");
                scanf("%d", &position);
                l_delete(&head, position);
                break;

            case 9:
                printf("Enter the element you wanna search: ");
                scanf("%d", &data);
                int stat = l_find(head, data);
                if(stat == 1) printf("The element was found in the list\n");
                else if(stat == 0) printf("The element was not found in the list\n");
                else printf("The list is not initiaised\n");
                break;

            case 10:
                printf("Enter the position to access data: ");
                scanf("%d", &position);
                temp = l_get(head, position);
                if(temp)printf("data: %d\n", temp->data);
                break;

            case 11:
                printf("Enter the position and value to set in the linked list: ");
                scanf("%d %d", &position, &data);
                l_set(&head, position, data);
                break;
            
            default:
                printf("Invalid input\n");
        }
    }
}
