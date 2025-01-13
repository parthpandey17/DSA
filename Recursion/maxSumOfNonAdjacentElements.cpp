#include<bits/stdc++.h>
using namespace std;

//code360
// You are given an array/list of ‘N’ integers. 
// You are supposed to return the maximum sum of the subsequence
//  with the constraint that no two elements are adjacent in the 
//  given array/list.

// try out all the subsequence with the given constraint
// pick the one with max sum
void printF(int ind,vector<int>&ds,int arr[],int n){
    if(ind==n){
        for(int i=0;i<ds.size();i++){
            cout<<ds[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //take or pick particular index into subsequence
    ds.push_back(arr[ind]);
    printF(ind+1,ds,arr,n);
    ds.pop_back();

    // not pick condition, i.e element not added to ur subsequnece
    printF(ind+1,ds,arr,n);
}
int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int>ds;
    printF(0,ds,arr,n);
}

// printing subsequence whose sum is K

void printAll(int ind, vector<int>&ds,int arr[],int n,int s,int sum){
    if(ind==n){
        if(s==sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return;
        }
        return;
    }
    //picking condition
    ds.push_back(arr[ind]);
    s+=arr[ind];
    printAll(ind+1,ds,arr,n,s,sum);
    ds.pop_back();
    s-=arr[ind];
    //not taking
    printAll(ind+1,ds,arr,n,s,sum); 
}


//printing anyone subsequence whose sum is k


bool printOne(int ind, vector<int>&ds,int arr[],int n,int s,int sum){
    if(ind==n){
        if(s==sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        //condition not satified
        return false;
    }
    //picking condition
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(printOne(ind+1,ds,arr,n,s,sum)==true) return true;
    ds.pop_back();
    s-=arr[ind];
    //not taking
    if(printOne(ind+1,ds,arr,n,s,sum)==true) return true; 
}

// count subsequence with sum k
int count(int ind,vector<int>&ds,int arr[],int n,int s,int sum){
    if(ind ==n){
        if(s==sum) return 1; // condn satisfied
        else return 0; //condn not satisfied
    }
    //pick
    ds.push_back(arr[ind]);
    s+=arr[ind];
    int l=count(ind+1,ds,arr,n,s,sum);
    ds.pop_back();
    s-=arr[ind];
// not pick
    int r=count(ind+1,ds,arr,n,s,sum);
    return l+r;
}