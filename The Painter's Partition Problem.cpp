/*
Dilpreet wants to paint his dog- Buzo's home that has n boards with different lengths[A1, A2,..., An]. 
He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.The problem is to 
find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, 
say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.
Example:
Input:
2
2 4
10 10 10 10
2 4
10 20 30 40
Output:
20
60
*/
 
 #include<bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[100][100];
int sum(int*a,int l,int r)
{
    int k=0,i;
    for(i=l;i<r;i++)
    k+=a[i];
    return k;
}
int solve(int*a,int n,int k)
{
    if(dp[k][n]==-1)
    {
    if(n==1)
    return a[0];
    if(k==1)
    return sum(a,0,n);
    int best=INT_MAX;
    for(int i=0;i<n;i++)
    {
       best=min(best,max(solve(a,i,k-1),sum(a,i,n))); 
    }
     dp[k][n]=best;
    }
    return dp[k][n];
}
int main()
 {
     int t,n,i,j,k;
     cin>>t;
     while(t--)
     {
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
            dp[i][j]=-1;
        }
         cin>>k>>n;
         int a[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         cout<<solve(a,n,k)<<endl;
     }
	return 0;
}
