#include<bits/stdc++.h>
using namespace std;
// // recursion method--overlapping subproblems
// int f(int ind,vector<int>&heights){
//     if(ind==0){
//         return 0;
//     }
//     int left = f(ind-1,heights)+ abs(heights[ind]-heights[ind-1]);
//     int right=INT_MAX;
//     if(ind>1){
//         right=f(ind-2,heights)+ abs(heights[ind]-heights[ind-2]);
//     }
//     return min(left,right);
// }

// //now using memoization-->dp

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, vector<int>& heights, vector<int>& dp) {
//     if (ind == 0) return 0; // Base case: No cost at the first step
    
//     if (dp[ind] != -1) return dp[ind]; // Return cached result

//     int left = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
//     int right = INT_MAX;
//     if (ind > 1) {
//         right = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
//     }

//     return dp[ind] = min(left, right);
// }

// int frogJump(int n, vector<int>& heights) {
//     vector<int> dp(n, -1);  // Initialize DP array of size `n`
//     return f(n - 1, heights, dp);
// }

// int main() {
//     int n;
//     cin >> n;
    
//     vector<int> heights(n);
//     for (int i = 0; i < n; i++) {
//         cin >> heights[i]; // Read heights input
//     }

//     int ans = frogJump(n, heights);
//     cout << ans << endl;
    
//     return 0;
// }

// // now using tabulation--bottom up approach

// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n,0);
//     dp[0]=0;
//     for(int i=1;i<n;i++){
//         int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
//         int ss=INT_MAX;
//         if(i>1){
//             ss=dp[i-2]+abs(heights[i]-heights[i-2]);
//         }
//         dp[i]=min(fs,ss);
//     }
//     return dp[n-1]; 
// }

// // // now space optimization--without using dp array

// int frogJump(int n, vector<int> &heights)
// {
//     int prev=0;
//     int prev2=0;
//     for(int i=1;i<n;i++){
//         int fs=prev+abs(heights[i]-heights[i-1]);
//         int ss=INT_MAX;
//         if(i>1){
//             ss=prev2+abs(heights[i]-heights[i-2]);
//         }
//         int curi=min(fs,ss);
//         prev2=prev;
//         prev=curi;
//     }
//     return prev; 
// }

// // modified frog jump-- with k steps
// //normal recursion
// int f(int ind,int a[]){
//     if(ind==0) return 0;
//     int minSteps=INT_MAX;
//     int k;
//     for(int j=1;j<k;j++){
//         if(ind-j>=0){
//             int jmp=f(ind-j,a)+ abs(a[ind]-a[ind-j]);
//             minSteps=min(minSteps,jmp);
//         }
//     }
//     return minSteps;
// }
// // memoization--top down
// int func(int ind,vector<int>a,vector<int>&dp){
//     if(ind==0) return 0;
//     if(dp[ind]!=-1) return dp[ind];
//     int minSteps=INT_MAX;
//     int k;
//     for(int j=1;j<=k;j++){
//         if(ind-j>=0){
//             int jmp=func(ind-j,a,dp)+ abs(a[ind]-a[ind-j]);
//             minSteps=min(minSteps,jmp);
//         }
//     }
//     return dp[ind]=minSteps;
// }
// T.C->O(N*k) S.C->O(N)+O(N)

//Tabulation-bottom up
int frog(int n,vector<int>& a,int k)
{
    vector<int> dp(n,0);
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jmp=dp[i-j]+ abs(a[i]-a[i-j]);
                minSteps=min(minSteps,jmp);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=frog(n,a,k);
    cout<<ans;
}

// t.c->O(n*k) s.c->o(n)