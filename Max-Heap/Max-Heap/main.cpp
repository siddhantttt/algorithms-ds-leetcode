#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& arr, int node){
    
    int left = 2*node, right = 2*node+1;
    
    if (left > arr.size() || right > arr.size())
        return;
    
    if (arr[node] <arr[left]){
        int temp = arr[node];
        arr[node] = arr[left];
        arr[left] = temp;
    }
    
    else if (arr[node] < right){
        int temp = arr[node];
        arr[node] = arr[right];
        arr[right] = temp;
    }
    
    else return;
        
}



void buildMaxHeap(vector<int>& arr){
    for (int i = arr.size()/2; i>=1; i--){
        maxHeapify(arr, i);
    }
}

int main(){
    vector<int> arr{0, 11, 5, 4, 3, 2, 1, 15, 45};
    
    buildMaxHeap(arr);
        return 0;
    
}
