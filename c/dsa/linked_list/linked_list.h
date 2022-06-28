typedef struct node{
    int data;
    struct node *next;
}node;

void l_print(node *head);
void l_init(node **head, int data);
void l_push_back(node **head, int data);
void l_push_front(node **head, int data);
void l_insert(node **head, int pos, int data);
void l_delete_front(node **head);
void l_delete_back(node **head);
void l_delete(node **head, int pos);
void l_clear(node **head);
node *l_get(node *head, int pos);
void l_set(node **head, int pos, int data);
int l_find(node *head, int data);
