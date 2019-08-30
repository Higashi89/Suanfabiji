#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 1000
struct node{
    int x,y;
};
int m[maxn][maxn];
int visit[maxn][maxn];
int N,M;
int X[4]={0,-1,0,1};
int Y[4]={1,0,-1,0};
queue<node> Q;
bool judge(int x,int y){
    if(x>=0&&x<N&&y>=0&&y<M)return true;
    else return false;
}
void BFS(node s){
    Q.push(s);
    while(!Q.empty()){
        node a=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            if(judge(a.x+X[i],a.y+Y[i])&&m[a.x+X[i]][a.y+Y[i]]==1&&!visit[a.x+X[i]][a.y+Y[i]]){
                node b={a.x+X[i],a.y+Y[i]};
                Q.push(b);
                visit[a.x+X[i]][a.y+Y[i]]=1;
            }
        }
    }

}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>m[i][j];
    memset(visit,0,sizeof(visit));

    int sum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visit[i][j]&&m[i][j]==1){
                cout<<i<<' '<<j<<endl;
                node a={i,j};
                BFS(a);
                sum++;
            }
        }
    }
    cout<<sum;
    /*
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 1 1 1 0 0
0 0 0 1 1 1 0
1 1 1 1 1 0 0
1 1 1 1 0 0 0

2
    */



}
