#include<cstdio>
#include<iostream>
using namespace std;
#define maxn 1000
int sum=0,N,max_weight=0;
int p[maxn],w[maxn];
void DFS(int pos,int price,int weight){
    if(pos==N){
        sum=max(sum,price);
        return;
    }
    DFS(pos+1,price,weight);
    if(weight+w[pos]<=max_weight)DFS(pos+1,price+p[pos],weight+w[pos]);
}

int main(){
    cin>>N>>max_weight;
    for(int i=0;i<N;i++)
        cin>>w[i];
    for(int i=0;i<N;i++)
        cin>>p[i];
    DFS(0,0,0);
    cout<<sum;
}

/*
5 8
3 5 1 2 2
4 5 2 1 3
*/
