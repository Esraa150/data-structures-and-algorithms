#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int right, int mid)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i=0; i<n1; i++)
        arr1[i] = arr[left+i];
    for(int i=0; i<n2; i++)
        arr2[i] = arr[mid+1+i];
    
    int i=0; int j=0;
    int k=left;
    while(i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    // copy the remaining elements of arr1 if there are any
    while(i<n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    // copy the remaining elements of arr2 if there are any
    while(j<n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int left, int right)
{
    if(left >= right)
        return;
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, right, mid);
}
int main() {
    vector<int> A = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(A, 0, A.size()-1);
    for(int i=0; i<A.size(); i++)
        cout<<A[i]<<" ";
    return 0;
}