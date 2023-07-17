#include <bits/stdc++.h> 
long long merge(long long *arr, int start, int mid, int end) {
    int i = start, j = mid+1, k = 0;
    long long inversions = 0;
    int temp[end-start+1];
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += mid-i+1; // count inversions
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }
    for (i = start, k = 0; i <= end; i++, k++) {
        arr[i] = temp[k];
    }
    return inversions;
}

long long mergeSort(long long *arr, int start, int end) {
    long long inversions = 0;
    if (start < end) {
        int mid = (start + end) / 2;
        inversions += mergeSort(arr, start, mid); // left half
        inversions += mergeSort(arr, mid+1, end); // right half
        inversions += merge(arr, start, mid, end); // merge
    }
    return inversions;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}
