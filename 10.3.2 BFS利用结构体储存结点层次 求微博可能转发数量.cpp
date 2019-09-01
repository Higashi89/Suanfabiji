#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define maxn 1005 //1000会有一个测试点不通过
using namespace std;
struct node{
    int data;
    int level;
}Node[maxn];

void node_init(){
    for(int i=0;i<maxn;i++){
        Node[i].data=i;
    }
}
int cnt;
map<int,vector<int> > adj;
int visit[maxn]={0};
int N,L;
queue<node> Que;
void BFS(int index){
    Node[index].level=0;
    Que.push(Node[index]);
    int level=0;
    visit[index]=1;
    while(!Que.empty()){
        node now=Que.front();
        Que.pop();
        for(int i=0;i<adj[now.data].size();i++){
            if(!visit[adj[now.data][i]]&&now.level+1<=L){
                node temp={adj[now.data][i],now.level+1};
                visit[adj[now.data][i]]=1; //visit必须写在这里，放进队列后判visit真，一开始写在for之外出错
                Que.push(temp);
                cnt++;
                //cout<<temp.data<<' ';
            }
        }
        //cout<<endl;

    }
}
int main(){
    cin>>N>>L;
    int num,t;
    node_init();
    for(int i=1;i<=N;i++){
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>t;
            adj[t].push_back(i);
        }
    }
    cin>>num;
    int Q;
    while(num--){
        cnt=0;
        memset(visit,0,sizeof(visit));
        cin>>Q;
        BFS(Q);
        cout<<cnt<<endl;
    }
}
