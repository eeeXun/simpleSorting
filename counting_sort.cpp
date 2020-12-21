#include<iostream>
#include<vector>
#include<cstring>
#include<ctime>
using namespace std;

void generate_arr(vector<int>&);
void counting_sort(vector<int>&);

int main(){
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr);
    counting_sort(arr);
    for(int i:arr){
        cout<<i<<endl;
    }

    return 0;
}

void generate_arr(vector<int>& arr){
    for(int i=0;i<10;i++){
        arr.push_back(rand()%10);
    }
}

void counting_sort(vector<int>& arr){
    int Range=10,size_of_arr=arr.size();
    int count[Range],output[size_of_arr];
    memset(count,0,sizeof(count));
    for(int i=0;i<size_of_arr;i++){
        count[arr.at(i)]++;
    }
    for(int i=1;i<Range;i++){
        count[i]+=count[i-1];
    }
    for(int i=size_of_arr-1;i>=0;i--){
        output[count[arr.at(i)]-1]=arr.at(i);
        count[arr.at(i)]--;
    }
    for(int i=0;i<size_of_arr;i++){
        arr.at(i)=output[i];
    }
}
