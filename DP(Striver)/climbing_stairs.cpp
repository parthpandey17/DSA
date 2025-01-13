#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.
     if(nStairs==0) return 1;
     if(nStairs==1) return 1;
     //if(nStairs<0) return 0;
    int mod = 1e9 + 7;
    int prev=1;
    int prev2=1;
    for(int i=2;i<=nStairs;i++){
        int cur=(prev+prev2)%mod;
        prev2=prev;
        prev=cur;
    }
    return prev;
}