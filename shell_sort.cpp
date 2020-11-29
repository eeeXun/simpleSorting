//Kunth's sequence
//gap = gap * 3 + 1

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void generate_arr(vector<int>&);
void shell_sort(vector<int>&);

int main(){
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr);
    shell_sort(arr);
    for(int i:arr){
        cout<<i<<endl;
    }
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<20;i++){
        arr.push_back(rand()%100);
    }
}

void shell_sort(vector<int>& arr){
    int size_of_arr=arr.size();
    int gap=1;
    while(gap<size_of_arr){
        gap=gap*3+1;
    }
    while(gap>1){
        gap/=3;
        int key,j;
        for(int i=gap;i<size_of_arr;i++){
            key=arr.at(i),j=i-gap;
            while(j>=0 && key<arr.at(j)){
                arr.at(j+gap)=arr.at(j);
                j-=gap;
            }
            arr.at(j+gap)=key;
        }
    }
}
