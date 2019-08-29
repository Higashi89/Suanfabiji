#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define maxn 1000
int A[maxn],N,K,X,max_squa=0;
vector<int> temp,ans;

void DFS(int pos,int nums,int sum_now,int sum_squa_now){
    if(pos==N){
        if(nums==K&&sum_now==X){
            if(sum_squa_now>max_squa){
                ans=temp;
                max_squa=sum_squa_now;
            }
        }
        return;
    }
    temp.push_back(A[pos]);
    DFS(pos+1,nums+1,sum_now+A[pos],sum_squa_now+A[pos]*A[pos]);
    temp.pop_back();
    DFS(pos+1,nums,sum_now,sum_squa_now);
}
int main(){
    cin>>N>>K>>X;
    for(int i=0;i<N;i++)
        cin>>A[i];
    DFS(0,0,0,0);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    /*
4 2 6
2 3 3 4
    */
}
