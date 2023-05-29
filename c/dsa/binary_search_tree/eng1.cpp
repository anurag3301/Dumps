#include <iostream>
using namespace std;

class TreeNode{
private:
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode();
    TreeNode(int v, TreeNode* l, TreeNode*r);

    int get_val();
    TreeNode* get_left();
    TreeNode* get_right();

    void set_val(int v);
    void set_left(TreeNode *l);
    void set_right(TreeNode *r);

    void insert(int v);
    void node_print(TreeNode *node, unsigned int depth);
};




class BinarySearchTree{
private:
    TreeNode *root;
public:
    BinarySearchTree(){
        root = nullptr;
    }
    TreeNode* get_root();
    void insert(int v);
    void display();
};

TreeNode* BinarySearchTree::get_root(){
    return root;
}

void BinarySearchTree::display(){
    if(root == nullptr)return;
    root->node_print(root, 0);
}

void BinarySearchTree::insert(int v){
    if(root == nullptr){
        root = new TreeNode;
        root->set_val(v);
    }
    else{
        root->insert(v);
    }
}



TreeNode::TreeNode(){
    val = 0;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int v, TreeNode* l, TreeNode*r){
    val = v;
    left = l;
    right = r;
}

int TreeNode::get_val(){
    return val;
}
TreeNode* TreeNode::get_left(){
    return left;
}

TreeNode* TreeNode::get_right(){
    return right;
}

void TreeNode::set_val(int v){
    val = v;
}
void TreeNode::set_left(TreeNode *l){
    left = l;
}

void TreeNode::set_right(TreeNode *r){
    right = r;
}

void TreeNode::insert(int v){
    TreeNode* trav = this;
    TreeNode* temp_node = new TreeNode;
    temp_node->set_val(v);

    while(1){
        if(trav->val == v) return;
        if(v < trav->val){
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

void TreeNode::node_print(TreeNode *node, unsigned int depth){
    if(node == NULL){
        return;
    }

    node_print(node->right, depth+1);

    for(unsigned int i=0; i<depth; i++)
        std::cout << "++";
    std::cout << node->val << endl;

    node_print(node->left, depth+1);
}



int main(){
    BinarySearchTree test;
    int arr[] = {10, 4, 6, 15, 13, 12, 15, 20, 11, 15};
    for(int i=0; i<10; i++){
        test.insert(arr[i]);
    }
    test.display();
}
