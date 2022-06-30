#include<bits/stdc++.h>
using namespace std ;

int solve(int a){
    if(a==0)
        return 0 ;
    if(a==1)
        return 1 ;
        
    return solve(a-1) + a ;
}

int main(){
    int t ; 
    cin >> t ;
    
    while(t--){
        int a , b ;
        cin >> a >> b ;
        cout << solve(min(a,b)) << "\n" ;
    }
    
    return 0 ;
}