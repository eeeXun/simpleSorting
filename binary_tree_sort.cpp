#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int data;
};

void generate_arr(vector<int>&);
void createTree(TreeNode*&,vector<int>);
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

void createTree(TreeNode*& tree,vector<int> arr){
    for(int num:arr){
        insert(tree,num);
    }
}

void insert(TreeNode*& node,int num){
    if(node==nullptr){
        TreeNode* tmp=new TreeNode;
        node=tmp;
        node->left=nullptr;
        node->right=nullptr;
        node->data=num;
    }
    else if(num<node->data){
        insert(node->left,num);
    }
    else{
        insert(node->right,num);
    }
}

void printTree(TreeNode* node){
    if(node!=nullptr){
        printTree(node->left);
        cout<<node->data<<endl;
        printTree(node->right);
    }
}
