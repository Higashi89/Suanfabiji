#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<cstring>
#include<set>
#include<map>
using namespace std;
#define maxn 1005
int a[maxn];
bool flag_max=true,flag_min=true;
void check(int N){
    for(int i=1;i<=N/2;i++){
        if(i*2+1<=N){
            if(a[i]<a[i*2]||a[i]<a[i*2+1])flag_max=false;
            if(a[i]>a[i*2]||a[i]>a[i*2+1])flag_min=false;
        }
        else{
            if(a[i]<a[i*2])flag_max=false;
            if(a[i]>a[i*2])flag_min=false;
        }
    }
}
vector<int> path;
void DFS(int i,int N){
    path.push_back(a[i]);
    if(i*2>N){
        for(int i=0;i<path.size();i++){
            if(i==0)cout<<path[i];
            else cout<<' '<<path[i];
        }
        cout<<endl;
    }
    if(i*2+1<=N)DFS(i*2+1,N);
    if(i*2<=N)DFS(i*2,N);
    path.pop_back();
}
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    DFS(1,N);
    check(N);
    if(flag_max)cout<<"Max Heap"<<endl;
    if(flag_min)cout<<"Min Heap"<<endl;
    if(!flag_max&&!flag_min)cout<<"Not Heap"<<endl;

}




// 老版
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#include<cstring>
#include<unordered_map>
#include<sstream>
using namespace std;
int N;
int a[1001];
struct nsad{
    int myid,left,right,value;
}node[1001];
vector<int> path;
bool maxn=true,minn=true;
void DFS(int id){
    node[id].myid=id;
    node[id].value=a[id];
    path.push_back(id);
    if(id*2+1<=N){
        if(a[id*2+1]>a[id])maxn=false;
        if(a[id*2+1]<a[id])minn=false;
        node[id].right=id*2+1;
        DFS(id*2+1);
    }
    else node[id].right=-1;
    if(id*2<=N){
        if(a[id*2]>a[id])maxn=false;
        if(a[id*2]<a[id])minn=false;
        node[id].left=id*2;
        DFS(id*2);
    }
    else node[id].left=-1;
    if(node[id].left==-1&&node[id].right==-1){
        for(int i=0;i<path.size();i++){
            if(i==0)cout<<a[path[i]];
            else cout<<" "<<a[path[i]];
        }
        cout<<endl;
    }
    path.pop_back();
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    DFS(1);
    if(maxn&&!minn)cout<<"Max Heap"<<endl;
    else if(!maxn&&minn)cout<<"Min Heap"<<endl;
    else cout<<"Not Heap"<<endl;

    //for(int i=1;i<=N;i++)
    //    cout<<node[i].myid<<" "<<node[i].left<<" "<<node[i].right<<" "<<node[i].value<<endl;

}
