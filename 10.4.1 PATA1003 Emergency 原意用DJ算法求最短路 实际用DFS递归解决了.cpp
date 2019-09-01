#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 505
int N,M,C1,C2;
int visit[maxn]={0};
int path[maxn][maxn];
int w[maxn];
int path_num=0,min_length=99999999,max_rescue=0;
void DFS(int index,int length,int rescue_num){
    if(index==C2){
        //cout<<path_num<<' '<<length<<' '<<min_length<<endl;
        if(length<min_length){
            path_num=1;
            min_length=length;
            max_rescue=rescue_num;
        }
        else if(length==min_length){
            path_num++;
            max_rescue=max(max_rescue,rescue_num);
        }
        return;
    }
    visit[index]=1;
    for(int i=0;i<maxn;i++){
        if(path[index][i]!=0&&!visit[i]){
            //visit[i]=1;
            //cout<<i<<' ';
            DFS(i,length+path[index][i],rescue_num+w[i]);
            visit[i]=0;
        }
    }
    //cout<<endl;

}
int main(){
    cin>>N>>M>>C1>>C2;
    for(int i=0;i<N;i++)
        cin>>w[i];
    int a,b,c;
    memset(path,0,sizeof(path));
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        path[a][b]=c;
        path[b][a]=c;
    }
    DFS(C1,0,w[C1]);
    cout<<path_num<<' '<<max_rescue<<endl;
}
