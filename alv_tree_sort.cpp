#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    int height,balance;
};

void generate_arr(vector<int>&);
void createTree(TreeNode*&,vector<int>);
int getLeafHeight(TreeNode*);
int getHeight(TreeNode*);
int getBalance(TreeNode*);
void rightRotate(TreeNode*&);
void leftRotate(TreeNode*&);
void insert(TreeNode*&,int);
void printTree(TreeNode*);

int main(){
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr);
    TreeNode* node=nullptr;
    createTree(node,arr);
    printTree(node);

    return 0;
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<20;i++){
        arr.push_back(rand()%100);
    }
}

void createTree(TreeNode*& node,vector<int> arr){
    for(int num:arr){
        insert(node,num);
    }
}

int getLeafHeight(TreeNode* node){
    if(node==nullptr){
        return 0;
    }
    return node->height;
}

int getHeight(TreeNode* node){
    return 1+max(getLeafHeight(node->left),getLeafHeight(node->right));
}

int getBalance(TreeNode* node){
    if(node==nullptr){
        return 0;
    }
    return getLeafHeight(node->left)-getLeafHeight(node->right);
}

void rightRotate(TreeNode*& node){
    TreeNode* tmp_left=node->left;
    TreeNode* tmp_left_right=node->left->right;
    // Rotate
    tmp_left->right=node;
    node->left=tmp_left_right;
    node=tmp_left;
    // Update height
    node->right->height=getHeight(node->right);
    node->height=getHeight(node);
}

void leftRotate(TreeNode*& node){
    TreeNode* tmp_right=node->right;
    TreeNode* tmp_right_left=node->right->left;
    // Rotate
    tmp_right->left=node;
    node->right=tmp_right_left;
    node=tmp_right;
    // Update height
    node->left->height=getHeight(node->left);
    node->height=getHeight(node);
}

void insert(TreeNode*& node,int num){
    if(node==nullptr){
        TreeNode* tmp=new TreeNode;
        node=tmp;
        node->left=nullptr;
        node->right=nullptr;
        node->data=num;
        node->height=1;
        return;
    }
    else if(num<node->data){
        insert(node->left,num);
    }
    else{
        insert(node->right,num);
    }
    node->height=getHeight(node);
    node->balance=getBalance(node);
    // Left Left
    if(node->balance>1 && node->left->balance==1){
        rightRotate(node);
    }
    // Right Right
    else if(node->balance<-1 && node->right->balance==-1){
        leftRotate(node);
    }
    // Left Right
    else if(node->balance>1 && node->left->balance==-1){
        leftRotate(node->left);
        rightRotate(node);
    }
    // Right Left
    else if(node->balance<-1 && node->right->balance==1){
        rightRotate(node->right);
        leftRotate(node);
    }
}

void printTree(TreeNode* node){
    if(node!=nullptr){
        printTree(node->left);
        cout<<node->data<<endl;
        printTree(node->right);
    }
}
