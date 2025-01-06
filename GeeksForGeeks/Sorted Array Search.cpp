int searchInSorted(int arr[], int n, int k) {
    int l = 0, h = n-1;
    
    while(l<=h) {
        int m = (h-l)/2+ l;
        if(arr[m] == k)
            return 1;
        if(arr[m] > k)
            h = m-1;
        else
            l = m+1;
    }
    return -1;
}