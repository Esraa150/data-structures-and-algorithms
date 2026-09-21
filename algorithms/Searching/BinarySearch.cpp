#include <iostream>
using namespace std;
int BinarySearch(int* arr, int size, int x)
{
    int start = 0;
    int end = size-1;
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(arr[mid] > x)
            end = mid-1;
        else if(arr[mid] < x)
            start = mid+1;
        else
            return mid;
    }
    return -1;
}
int main() {
    int A[] = {2, 3, 4, 10, 40};
    int res = BinarySearch(A, sizeof(A)/sizeof(A[0]), 10);
    if(res == -1)
        cout<<"Not found!";
    else
        cout<<"Element found at index: "<<res;
    return 0;
}