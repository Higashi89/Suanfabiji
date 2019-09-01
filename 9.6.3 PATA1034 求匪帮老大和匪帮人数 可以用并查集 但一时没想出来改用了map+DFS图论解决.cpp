#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

map<string,int> visit;
map<string,vector<string> > adj;
map<string,int> w;
map<string,int> res;
int N,K;
int cnt;
int total;
string head;

void DFS(string s){
    vector<string>::iterator it=adj[s].begin();
    visit[s]=1;
    cnt++;
    total+=w[s];
    if(w[s]>w[head])head=s;
    for(;it!=adj[s].end();it++){
        if(!visit[*it])
            DFS(*it);
    }
}
int main(){
    cin>>N>>K;
    string a,b;int t;
    for(int i=0;i<N;i++){
        cin>>a>>b>>t;
        visit[a]=0;visit[b]=0;
        adj[a].push_back(b);adj[b].push_back(a);
        w[a]+=t;w[b]+=t;
    }
    map<string,int>::iterator it=visit.begin();
    for(;it!=visit.end();it++){
        if(it->second==0){
            cnt=0;head=it->first;total=0;
            DFS(it->first);
        }
        if(cnt>2&&total/2>K){
            res[head]=cnt;
        }
    }
    cout<<res.size()<<endl;
    for(it=res.begin();it!=res.end();it++){
        cout<<it->first<<' '<<it->second<<endl;
    }

}
