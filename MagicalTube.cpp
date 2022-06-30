#include<bits/stdc++.h>
using namespace std;
 
unordered_map<int, int> freqMap;
unordered_map<int, stack<int> > setMap;
vector<int> ans ;
int maxfreq = 0;
 
void push(int x)
{
 
    int freq = freqMap[x] + 1;
    freqMap[x]= freq;
 
    if (freq > maxfreq)
        maxfreq = freq;

    setMap[freq].push(x);
}
 
int pop()
{
 
    int top = setMap[maxfreq].top();
    setMap[maxfreq].pop();
 
    freqMap[top]--;
 
    if (setMap[maxfreq].size() == 0)
        maxfreq--;

    ans.push_back(top);
    
    return top;
}
 
int main()
{
 
    // Push elements to the stack
    push(62);
    push(49);

    pop() ;

    for(auto x : ans){
        cout<< x <<" " ;
    }
 
    // Pop elements
    // cout << (pop()) << "\n" ;
    // cout << (pop());
    return 0;
}