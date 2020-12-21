#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void generate_arr(vector<int>&);
void selection_sort(vector<int>&);

int main(){
    vector<int> arr;
    generate_arr(arr);
    int sizeof_list=arr.size();
    selection_sort(arr);
    for(int i:arr){
        cout<<i<<endl;
    }

    return 0;
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<20;i++){
        arr.push_back(rand()%100);
    }
}

void selection_sort(vector<int>& arr){
    int size_of_arr=arr.size();
    for(int i=0;i<size_of_arr;i++){
        int index_min=i;
        for(int j=i+1;j<size_of_arr;j++){
            if(arr.at(index_min)>arr.at(j))
                index_min=j;
        }
        swap(arr.at(i),arr.at(index_min));
    }
}
