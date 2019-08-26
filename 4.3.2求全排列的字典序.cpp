#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int N=3;
int P[22];
bool visit[22]={false};
void show_q(int index){
    if(index==N+1){
        for(int i=1;i<=N;i++){
            cout<<P[i];
        }
        cout<<endl;
    }
    else{
        for(int i=1;i<=N;i++){
            if(!visit[i]){
                P[index]=i;visit[i]=true;
                show_q(index+1);
                visit[i]=false;
            }
            //visit[i]=false; 原本是写在这里，出现了错误
        }
    }
}
int main(){
    show_q(1);
}