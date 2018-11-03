#include <iostream>
using namespace std;

static int n = 5;

void quicksort(int x[], int left, int right) {
    if (right - left < 1){
        return;
    }
    else {
        int pivot = (x[left] + x[right]) / 2;
        int i = left, j = right;
        while (i < j) {        //O(n)
            while (x[i] <= pivot && i < right)
                i++;
            while (x[j] > pivot && j > left)
                j--;
            if (i < j) {
                swap(x[i], x[j]);
            }
        }
        quicksort(x, left, i - 1);  // logn
        quicksort(x, i, right);
    }
}

void MergeSort(int a[], int b[], int c[]){
    // one time in MergeSort
    // overall Complexity: O(n*log n)
    int i = 0, j = 0, k = 0;
    while(i < n && j < n){
        if(a[i] < b[j]){
            c[k] = a[i];
            i++;
        }
        else{
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if(i == n)
        for(;j < n; j++,k++)
            c[k] = b[j];
    else
        for(;i < n; i++,k++)
            c[k] = a[i];
}

int main(){
    int a[n] = {10,4,9,8,1};
    int b[n] = {7,2,3,6,5};
    quicksort(a, 0, n-1);  // analog that a is sorted
    quicksort(b, 0, n-1);  // analog that b is sorted
    int c[2*n] = {};
    MergeSort(a, b, c);
    for(int i = 0; i < 10; i++)
        cout << c[i] << " ";
    cout << endl;
    //delete[] c;
}