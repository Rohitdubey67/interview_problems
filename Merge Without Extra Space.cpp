/*
Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. The task is to merge the two sorted arrays in place, i. e., we need to consider all n + m elements in sorted order, then we need to put first n elements of these sorted in first array and remaining m elements in second array.

Note: Expected time complexity is O((n+m) log(n+m)). DO NOT use extra space.  We need to modify existing arrays as following.

Input: arr1[] = {10};
       arr2[] = {2, 3};
Output: arr1[] = {2}
        arr2[] = {3, 10}  

Input: arr1[] = {1, 5, 9, 10, 15, 20};
       arr2[] = {2, 3, 8, 13};
Output: arr1[] = {1, 2, 3, 5, 8, 9}
        arr2[] = {10, 13, 15, 20} 
*/

void merge(int a[], int b[], int n, int m) 
{ 
    int i=n-1,j=0;
    while(i>=0&&j<m)
    {
        if(a[i]>b[j])
        {
            swap(a[i],b[j]);
            i--;
            j++;
        }
        else
        break;
    }
    sort(a,a+n);
    sort(b,b+m);
} 
