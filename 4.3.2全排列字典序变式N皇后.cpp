#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int N=8,counter=0;
int P[22];
bool visit[22]={false};
void show_q(int index){
    if(index==N+1){
        int flag=true;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(abs(j-i)==abs(P[j]-P[i])) //i P[i] 分别对应一个点的横坐标和纵坐标
                    flag=false;
            }
        }
        if(flag){
            counter++;
        }
        return;
    }
    else{
        for(int i=1;i<=N;i++){
            if(!visit[i]){
                P[index]=i;visit[i]=true;
                show_q(index+1);
                visit[i]=false;
            }
        }
    }
}
int main(){
    show_q(1);
    cout<<counter;
}