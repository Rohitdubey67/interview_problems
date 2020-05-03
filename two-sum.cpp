/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// sol:1 
// Time: O(n^2)
// Space: O(1)

vector<int> twoSum(vector<int>& a, int t) {
        int i,j;
        vector<int>v;
        for(i=0;i<a.size();i++)
        {
            for(j=i+1;j<a.size();j++)
            {
                if(a[i]+a[j]==t)
                {
                    v.push_back(i);
                    v.push_back(j);
                    //return v;
                    break;
                }
            }
        }
        return v;
    }
    
    
 // sol:2
 // Time:O(nlogn)
 // space: O(n)
 // concept: Two pointer method 
 
 vector<int> twoSum(vector<int>& a, int t) {
        vector<int>v;
        vector<pair<int,int>>p;
        int i,j;
        for(i=0;i<a.size();i++)
        {
            pair<int,int>m;
            m.first=a[i];
            m.second=i;
            p.push_back(m);
        }
        sort(p.begin(),p.end());
        i=0,j=a.size()-1;
        while(i<j)
        {
            if(p[i].first+p[j].first==t)
            {
                v.push_back(p[i].second);
                v.push_back(p[j].second);
                break;
            }
            else if(p[i].first+p[j].first>t)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return v;
    }
    
 // sol:3
 // Time: O(n)
 // Space: O(n)
 //concept used: Hashing
 
 vector<int> twoSum(vector<int>& a, int t) {
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<a.size();i++)
        {
            if(m.find(t-a[i])!=m.end())
            {
                v.push_back(m[t-a[i]]);
                v.push_back(i);
                break;
            }
            else
                m[a[i]]=i;
        }
        return v;
    }
