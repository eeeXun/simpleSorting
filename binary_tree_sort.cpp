#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

void generate_arr(vector<int>& arr);
void createTree(Node*&,vector<int>);
void insert(Node*&,int);
void printTree(Node*);

int main(){
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr);
    Node* tree=nullptr;
    createTree(tree,arr);
    printTree(tree);
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<20;i++){
        arr.push_back(rand()%100);
    }
}

void createTree(Node*& tree,vector<int> arr){
    for(int num:arr){
        insert(tree,num);
    }
}

void insert(Node*& tree,int num){
    if(tree==nullptr){
        Node* tmp=new Node;
        tree=tmp;
        tree->left=nullptr;
        tree->right=nullptr;
        tree->data=num;
    }
    else{
        if(num<tree->data){
            if(tree->left==nullptr){
                Node* tmp=new Node;
                tree->left=tmp;
                tmp->left=nullptr;
                tmp->right=nullptr;
                tmp->data=num;
            }
            else{
                insert(tree->left,num);
            }
        }
        else{
            if(tree->right==nullptr){
                Node* tmp=new Node;
                tree->right=tmp;
                tmp->left=nullptr;
                tmp->right=nullptr;
                tmp->data=num;
            }
            else{
                insert(tree->right,num);
            }
        }
    }
}

void printTree(Node* tree){
    if(tree!=nullptr){
        printTree(tree->left);
        cout<<tree->data<<endl;
        printTree(tree->right);
    }
}
