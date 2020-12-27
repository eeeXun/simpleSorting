#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

enum Color {RED,BLACK};
struct TreeNode{
    int data;
    bool color;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int num){
        this->data=num;
        this->right=nullptr;
        this->left=nullptr;
        this->parent=nullptr;
        this->color=RED;
    }
};
class RBTree{
    public:
        RBTree();
        void createTree(vector<int>&);
        void printTree();
    private:
        TreeNode* root;
        void insert(int);
        void TreeInsert(TreeNode*&,TreeNode*);
        void fixViolation(TreeNode*&,TreeNode*&);
        void leftRotate(TreeNode*&,TreeNode*&);
        void rightRotate(TreeNode*&,TreeNode*&);
        void printTreeHelper(TreeNode*);
};

void generate_arr(vector<int>&);

int main(){
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr);
    RBTree node;
    node.createTree(arr);
    node.printTree();

    return 0;
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<20;i++){
        arr.push_back(rand()%100);
    }
}

RBTree::RBTree(){
    this->root=nullptr;
}

void RBTree::createTree(vector<int>& arr){
    for(int num:arr){
        this->insert(num);
    }
}

void RBTree::insert(int num){
    TreeNode* newNode=new TreeNode(num);
    TreeInsert(root,newNode);
    fixViolation(root,newNode);
}

void RBTree::TreeInsert(TreeNode*& root,TreeNode* newNode){
    if(root==nullptr){
        root=newNode;
        return;
    }
    else if(newNode->data<root->data){
        TreeInsert(root->left,newNode);
        root->left->parent=root;
    }
    else{
        TreeInsert(root->right,newNode);
        root->right->parent=root;
    }
}

void RBTree::fixViolation(TreeNode*& root,TreeNode*& node){
    TreeNode* parent_node=nullptr;
    TreeNode* grand_parent_node=nullptr;
    while((node!=root) && (node->color!=BLACK) && (node->parent->color==RED)){
        parent_node=node->parent;
        grand_parent_node=node->parent->parent;
        // parent is on the left hand side of grand parent
        if(parent_node==grand_parent_node->left){
            TreeNode* uncle_node=grand_parent_node->right;
            // uncle is red;recoloring
            if((uncle_node!=nullptr) && (uncle_node->color==RED)){
                parent_node->color=BLACK;
                uncle_node->color=BLACK;
                grand_parent_node->color=RED;
            }
            else{
                if(node==parent_node->right){
                    leftRotate(root,parent_node);
                    node=parent_node;
                    parent_node=node->parent;
                }
                rightRotate(root,grand_parent_node);
                swap(parent_node->color,grand_parent_node->color);
                node=parent_node;
            }
        }
        // parent is on the right hand side of grand parent
        else{
            TreeNode* uncle_node=grand_parent_node->left;
            // uncle is red;recoloring
            if((uncle_node!=nullptr) && (uncle_node->color==RED)){
                parent_node->color=BLACK;
                uncle_node->color=BLACK;
                grand_parent_node->color=RED;
            }
            else{
                if(node==parent_node->left){
                    rightRotate(root,parent_node);
                    node=parent_node;
                    parent_node=node->parent;
                }
                leftRotate(root,grand_parent_node);
                swap(parent_node->color,grand_parent_node->color);
                node=parent_node;
            }
        }
    }
    root->color=BLACK;
}

void RBTree::leftRotate(TreeNode*& root,TreeNode*& node){
    TreeNode* node_right=node->right;
    node->right=node_right->left;
    if(node->right!=nullptr)
        node->right->parent=node;
    node_right->parent=node->parent;
    if(node->parent==nullptr)
        root=node_right;
    else if(node==node->parent->left)
        node->parent->left=node_right;
    else
        node->parent->right=node_right;
    node_right->left=node;
    node->parent=node_right;
}

void RBTree::rightRotate(TreeNode*& root,TreeNode*& node){
    TreeNode* node_left=node->left;
    node->left=node_left->right;
    if(node->left!=nullptr)
        node->left->parent=node;
    node_left->parent=node->parent;
    if(node->parent==nullptr)
        root=node_left;
    else if(node==node->parent->left)
        node->parent->left=node_left;
    else
        node->parent->right=node_left;
    node_left->right=node;
    node->parent=node_left;
}

void RBTree::printTree(){
    printTreeHelper(this->root);
}

void RBTree::printTreeHelper(TreeNode* node){
    if(node!=nullptr){
        printTreeHelper(node->left);
        cout<<node->data<<endl;
        printTreeHelper(node->right);
    }
}
