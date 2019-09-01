#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 505
int N,M,S,D;
int path[maxn][maxn];
int price[maxn][maxn];
int visit[maxn];
vector<int> f_route,route;
int min_price=99999999,min_length=99999999;

void DFS(int index,int length,int price_now){
    if(index==D){
        /*for(int i=0;i<route.size();i++){
            cout<<route[i]<<' ';
        }
        cout<<endl;
        cout<<length<<' '<<price_now<<endl;*/
        if(length<min_length){
            min_length=length;
            min_price=price_now;
            f_route=route;
        }
        else if(length==min_length){
            if(price_now<min_price){
                min_price=price_now;
                f_route=route;
            }
        }
        return;
    }
    visit[index]=1;
    for(int i=0;i<N;i++){
        if(path[index][i]!=0&&!visit[i]){
            route.push_back(i);
            DFS(i,length+path[index][i],price_now+price[index][i]);
            visit[i]=0;
            route.pop_back(); //回溯 一开始没写
        }
    }
}

int main(){
    cin>>N>>M>>S>>D;
    int a,b,c,d;
    memset(visit,0,sizeof(visit));
    memset(price,0,sizeof(price));
    memset(path,0,sizeof(path));
    for(int i=0;i<M;i++){
        cin>>a>>b>>c>>d;
        path[a][b]=c;path[b][a]=c;
        price[a][b]=d;price[b][a]=d;
    }
    route.push_back(S);
    DFS(S,0,0);
    for(int i=0;i<f_route.size();i++){
        cout<<f_route[i]<<' ';
    }
    cout<<min_length<<' '<<min_price;
}
