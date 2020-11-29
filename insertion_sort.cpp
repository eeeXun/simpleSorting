#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void generate_arr(vector<int>&);
void insetion_sort(vector<int>&);

int main(){
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr);
    insetion_sort(arr);
    for(int i:arr){
        cout<<i<<endl;
    }
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<20;i++){
        arr.push_back(rand()%100);
    }
}

void insetion_sort(vector<int>& arr){
    int size_of_arr=arr.size();
    int key,j;
    for(int i=1;i<size_of_arr;i++){
        key=arr.at(i),j=i-1;
        while(j>=0 && key<arr.at(j)){
            arr.at(j+1)=arr.at(j);
            j--;
        }
        arr.at(j+1)=key;
    }
}
