#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int left, int right)
{
    int pivot = arr[right];
    int i = left-1;
    for(int j=left; j<right; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;

    return i+1;
}
void quickSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex-1);
        quickSort(arr, pivotIndex+1, right);
    }
}
int main() {
    vector<int> A = {64, 34, 25, 12, 22, 11, 90};
    quickSort(A, 0, A.size()-1);
    for(int i=0; i<A.size(); i++)
        cout<<A[i]<<" ";
    return 0;
}