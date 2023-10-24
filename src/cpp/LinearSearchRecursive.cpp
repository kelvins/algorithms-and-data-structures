#include <iostream>
#include <vector>
using namespace std;

bool  linearSearchRecursive(int arr[], int n, int index, int target){
    if(index >= n){
        return false;
    }

    if(arr[index] == target){
        return true;
    }

    return linearSearchRecursive(arr,n, index+1, target);
}

int main(){
    int n;
    cout<< "Enter The size of array : ";
    cin>> n;
    int arr[n];
    cout<<"Enter the element of array : "<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the element you need to search in the array : ";
    cin>>target;
    bool answer = linearSearchRecursive(arr, n, 0, target);
    if(answer){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
}