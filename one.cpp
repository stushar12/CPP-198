#include<bits/stdc++.h>
using namespace std;

long countPairs(vector<int> arr) 
{
    long ans=0;
    int maxi=0;
    map<int,int> mp;
    for(auto itr : arr)
    {
        mp[itr]++;
        maxi = max(maxi,itr);
    }
    for(int i=0; i<=maxi; ++i)
    {
        if(!mp.count(i))                                                //if count of the number is 0
        continue;
        for(int j=i; j<=maxi; ++j)
        {
            if(!mp.count(j)) 
            continue;
            if(__builtin_popcountll(i&j)==1)                            //count the number of set bits in the number
            {
                if(i==j) 
                ans+=((long(mp[i])*(mp[i]-1))/2);
                else
                ans+= (long(mp[i])*mp[j]);
            }
        }
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<countPairs(arr);
}
