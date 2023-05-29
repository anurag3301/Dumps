#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int val;
    struct treenode *left;
    struct treenode *right;
    
}treenode;

void insert(treenode **tree, int val){
    treenode *trav;
    treenode *temp_node = malloc(sizeof(treenode));
    temp_node->val = val;
    temp_node->left = temp_node->right = NULL;
    if(*tree == NULL){
        *tree = temp_node;
        return;
    }

    trav = *tree;
    while(1){
        if(trav->val == val) return;
        if(val < trav->val){
            if(trav->left == NULL){
                trav->left = temp_node;
                break;
            }
            else trav = trav->left;
        }
        else{
            if(trav->right == NULL){
                trav->right = temp_node;
                break;
            }
            else trav = trav->right;
        }
    }
}

void display(treenode *node, unsigned int depth){
    if(node == NULL){
        return;
    }

    display(node->right, depth+1);

    for(int i=0; i<depth; i++)
        printf("++");
    printf("%d\n", node->val);

    display(node->left, depth+1);
}

int main(){
    treenode *tree = NULL;
    int arr[] = {3, 3, 3, 2};

    for(int i=0; i<4; i++){
        insert(&tree, arr[i]);
    }

    display(tree, 0);
}
