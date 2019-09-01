#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100
#define null 0
struct node{
    int w;
    vector<int> child;
}nodes[maxn];
bool cmp(int a,int b){
    //return a>b;
    return nodes[a].w>nodes[b].w; //vector 的sort cmp函数写法 错了
}
int N,M,S;
vector<int> path;

void DFS(int index,int sum){
    path.push_back(nodes[index].w);
    //cout<<endl<<index<<' '<<sum<<endl;
    if(sum==S){
        if(nodes[index].child.size()!=0)return;
        for(int i=0;i!=path.size();i++){
            if(i==0)cout<<path[i];
            else cout<<' '<<path[i];
        }
        cout<<endl;
    }
    if(sum>S){
        return;
    }
    for(int i=0;i<nodes[index].child.size();i++){
        DFS(nodes[index].child[i],sum+nodes[nodes[index].child[i]].w);
        path.pop_back();
    }

}

int main(){
    cin>>N>>M>>S;
    for(int i=0;i<N;i++){
        cin>>nodes[i].w;
    }
    int mother,child_num,temp;
    for(int i=0;i<M;i++){
        cin>>mother>>child_num;
        for(int j=0;j<child_num;j++){
            cin>>temp;
            nodes[mother].child.push_back(temp);
        }
        sort(nodes[mother].child.begin(),nodes[mother].child.end(),cmp);
    }
    DFS(0,nodes[0].w);

}
