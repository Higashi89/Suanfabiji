#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 1000
int father[maxn],N;
int is_father[maxn];
void init(){
    for(int i=1;i<=N;i++){
        father[i]=i;
        is_father[i]=1;
    }
}
void Union(int a,int b){
    while(father[a]!=a){
        a=father[a];
    }
    while(father[b]!=b){
        b=father[b];
    }
    father[a]=b;
    is_father[a]=0;
    is_father[b]=1;
    //cout<<a<<' '<<b<<' '<<is_father[a]<<' '<<is_father[b]<<endl;
}
int main(){
    int M,a,b;
    cin>>N>>M;
    init();
    while(M--){
        cin>>a>>b;
        Union(a,b);
    }
    int sum=0;
    for(int i=1;i<=N;i++)
        sum+=is_father[i];
    cout<<sum;
}

/*
7 5
1 2
2 3
3 1
1 4
5 6

3
*/
