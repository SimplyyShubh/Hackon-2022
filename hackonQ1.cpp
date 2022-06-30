#include <bits/stdc++.h>
using namespace std;


int findOdd(vector<int> &nums, int i, int n){
    unordered_map<int,int> map ;
    int c = 0;

    for(int j = i ; j<n ; j++)
        map[nums[j]]++ ;
        
    for(auto x: map)
        if(x.second %2 != 0)
            c++ ;

    return c ;
}

vector<int> solve(int q, vector<int> arr, vector<vector<int>> queries){
    vector<int> out ; 

    for (int i = 0; i < q; i++)
    {
        if (queries[i][0] == 1)
            arr[queries[i][1] - 1] = queries[i][2];
        else
            out.push_back(findOdd(arr, queries[i][1] - 1, queries[i][2]));
    }
    return out;
}

int main()
{
    vector<int> arr = {1,2,3,2} ; 
    vector<vector<int>> queries = { 
        {2,1,3},
        {1,2,4},
        {2,1,4}
    } ;
    vector<int> res = solve(3, arr, queries) ;
    for(auto r : res){
        cout<<r<<" " ;
    }
    return 0;
}