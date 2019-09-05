#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<unordered_map>//编译器设置中勾选c++11支持 unorder速度更快
#include<set>
#define null 0
using namespace std;
#define maxn 205
int path[maxn][maxn];
int main(){
    int N,M;
    cin>>N>>M;
    int a,b,c;
    memset(path,0,sizeof(path));
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        path[a][b]=c;
        path[b][a]=c;
    }
    int query;
    cin>>query;
    int minn=999999999,min_pos=1;
    for(int k=1;k<=query;k++){
        int nums;
        bool flag=true;
        cin>>nums;
        int this_path[N+1];
        set<int> city_num;
        for(int i=0;i<nums;i++){
            cin>>this_path[i];
            city_num.insert(this_path[i]);
        }
        int length=0;
        for(int i=0;i<nums-1;i++){
            if(path[this_path[i]][this_path[i+1]]==0){
                cout<<"Path "<<k<<": NA (Not a TS cycle)"<<endl;
                flag=false;
            }
            else{
                length+=path[this_path[i]][this_path[i+1]];
            }
        }
        if(flag&&this_path[0]!=this_path[nums-1]||city_num.size()<N)cout<<"Path "<<k<<": "<<length<<" (Not a TS cycle)"<<endl;
        else if(flag&&city_num.size()==N&&nums==N+1){
            cout<<"Path "<<k<<": "<<length<<" (TS simple cycle)"<<endl;
            if(length<minn){
                minn=length;
                min_pos=k;
            }
        }
        else if(flag&&city_num.size()==N&&nums>N+1){
            cout<<"Path "<<k<<": "<<length<<" (TS cycle)"<<endl;
            if(length<minn){
                minn=length;
                min_pos=k;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n",min_pos,minn);

}
