// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int search(int A[], int l, int h, int key);

 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        cout << search(A, 0, n - 1, key) << endl;
    }
return 0;
}// } Driver Code Ends

// int pivotSearch(int *arr,int l,int h){
//     while(l<h){
//         int mid=(l+h)/2;
//         if(arr[mid]<arr[h]){
//             h=mid-1;
//         }
//         else{
//             l=mid+1;
//         }
//     }
//     return l;
// }

int search(int arr[], int l, int h, int key){
    //complete the function here
    int lo=0,hi=h;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(arr[mid]<arr[hi]){
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    
    int left=0,right=h;
    // if(arr[hi]==key){
    //     return hi;
    // }
    if(key>=arr[lo] && key<=arr[right]){
        left=lo;
    }
    else{
        right=lo;
    }
    
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
    
}