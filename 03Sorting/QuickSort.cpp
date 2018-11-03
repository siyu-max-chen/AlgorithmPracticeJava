#include <iostream>
using namespace std;

void quicksort(int x[], int left, int right) {
    // Complexity: O(n*log n)
    // best case: (n)
    // worse case: (n^2)
    if (right - left < 1)
        return;
    int pivot = (x[left] + x[right]) / 2;
    int i = left, j = right;
    while (i < j) {        //O(n)
        while (x[i] <= pivot && i < right)
            i++;
        while (x[j] > pivot && j > left)
            j--;
        if (i < j)
            swap(x[i], x[j]);
    }
    quicksort(x, left, i - 1);  // logn
    quicksort(x, i, right);
}

int main(){
    int a[10] = {7,2,3,6,5,10,4,9,8,1};
    quicksort(a, 0, 9);
    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
}