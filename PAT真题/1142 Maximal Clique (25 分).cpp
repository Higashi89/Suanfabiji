#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
#define maxn 205
int main(){
    int Nv,Ne;
    cin>>Nv>>Ne;
    int m[maxn][maxn];
    memset(m,0,sizeof(m));
    for(int i=1;i<maxn;i++)
        m[i][i]=1;
    int a,b;
    while(Ne--){
        cin>>a>>b;
        m[a][b]=1;m[b][a]=1;
    }
    int M;
    cin>>M;
    while(M--){
        int K;
        cin>>K;
        set<int>path;
        int t;
        for(int i=0;i<K;i++){
            cin>>t;
            path.insert(t);
        }
        bool NotC=false;
        for(set<int>::iterator it=path.begin();it!=path.end();it++){
            for(set<int>::iterator it2=path.begin();it2!=path.end();it2++){
                if(m[*it][*it2]==0)NotC=true;
            }
        }
        if(NotC){
            cout<<"Not a Clique"<<endl;
            continue;
        }
        set<int> Adj;
        for(set<int>::iterator it=path.begin();it!=path.end();it++){
            int node_now=*it;
            for(int j=1;j<=Nv;j++){
                if(m[node_now][j]==1&&path.find(j)==path.end()){
                    Adj.insert(j);
                }
            }
        }
        bool is_M=false;
        for(set<int>::iterator it=Adj.begin();it!=Adj.end();it++){
            int flag=1;
            for(set<int>::iterator it2=path.begin();it2!=path.end();it2++){
                if(m[*it][*it2]==0){
                    flag=0;
                }
            }
            if(flag)is_M=true;
        }
        if(is_M)cout<<"Not Maximal"<<endl;
        else cout<<"Yes"<<endl;
    }
}
