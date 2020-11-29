#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void generate_arr(vector<int>&);
void bubble_sort(vector<int>&);

int main(){
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr);
    bubble_sort(arr);
    for(int i:arr){
        cout<<i<<endl;
    }
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<20;i++){
        arr.push_back(rand()%100);
    }
}

void bubble_sort(vector<int>& arr){
    int size_of_arr=arr.size();
    for(int i=size_of_arr-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr.at(j)>arr.at(j+1)){
                swap(arr.at(j),arr.at(j+1));
            }
        }
    }
}
