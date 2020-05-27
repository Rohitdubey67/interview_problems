/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
Time: O(n^2)
Space: O(1)
concept used: two pointer
*/

vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>>v;
        int i,j,k,n=a.size();
        if(n<3)
            return v;
        sort(a.begin(),a.end());
        for(i=0;i<n;i++)
        {
            int x=a[i];
            if(a[i]>0)
                return v;
            for(j=i+1,k=n-1;j<k;)
            {
                int y=a[j];
                int z=a[k];
                if(x+y+z==0)
                {
                    v.push_back({x,y,z});
                    while(j<k&&y==a[++j]) ;
                    while(j<k&&z==a[--k]) ;
                }
                else if(x+y+z<0)
                    j++;
                else
                    k--;
            }
            while(i+1<n&&a[i]==a[i+1])
                i++;
        }
        return v ;
    }
