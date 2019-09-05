#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<unordered_map>//编译器设置中勾选c++11支持 unorder速度更快
#include<set>
#define null 0
using namespace std;
#define maxn 100005
//unordered_map<int,set<int>> in_degree,in;
vector<int> out_degree[maxn];
int in_degree_num[maxn]={0},storge[maxn];
int main(){
    int N,M;
    cin>>N>>M;
    int head,rear;
    for(int i=0;i<M;i++){
        cin>>head>>rear;
        out_degree[head].push_back(rear);
        in_degree_num[rear]++;
    }
    int K;
    cin>>K;
    vector<int> res;
    for(int i=1;i<=K;i++){
        for(int s=1;s<=N;s++){
            storge[s]=in_degree_num[s];
        }
        int temp,flag=0;
        for(int j=0;j<N;j++){
            cin>>temp;
            if(storge[temp]!=0){
                flag=1;
            }
            else{
                for(int q=0;q<out_degree[temp].size();q++){
                    int pos=out_degree[temp][q];
                    storge[pos]--;
                }
            }
        }
        if(flag)res.push_back(i-1);
    }
    for(int i=0;i<res.size();i++){
        if(i==0)cout<<res[i];
        else cout<<' '<<res[i];
    }
}

/*
#include<cstdio> //版本1 21分 1测试点超时
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<unordered_map>//编译器设置中勾选c++11支持 unorder速度更快
#include<set>
#define null 0
using namespace std;
#define maxn 100005
unordered_map<int,set<int>> in_degree,in;
int main(){
    int N,M;
    cin>>N>>M;
    int a,b;
    for(int i=1;i<=M;i++){
        scanf("%d %d",&a,&b);
        in[b].insert(a);
    }
    int K;
    cin>>K;
    vector<int> res;
    for(int k=1;k<=K;k++){
        int temp;
        in_degree=in;
        bool flag=false;
        for(int i=0;i<N;i++){
            scanf("%d",&temp);
            if(in_degree[temp].size()==0){
                for(int j=1;j<=N;j++){
                    if(in_degree[j].find(temp)!=in_degree[j].end())
                        in_degree[j].erase(temp);
                }
            }
            else{
                flag=true;
                //break; //此处中断的话本轮剩余输出会算到下一轮里
            }
        }
        if(flag)res.push_back(k-1);

    }
    for(int i=0;i<res.size();i++){
        if(i==0)cout<<res[i];
        else cout<<' '<<res[i];
    }
}
*/
