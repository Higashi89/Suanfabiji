#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct node{
    char data;
    int next;
    bool flag; //添加flag，先扫描一条链表，全置为true ，扫描第二条链表时若遇到true则输出并return
    node(){
        next=-1;flag=false;
    }
}n_list[100001];

int main(){
    int heada,headb,N;
    cin>>heada>>headb>>N;
    int t_pos,t_next;char t_data;
    while(N--){
        scanf("%d %c %d",&t_pos,&t_data,&t_next);
        n_list[t_pos].data=t_data;
        n_list[t_pos].next=t_next;
    }
    int lena=0,lenb=0;
    int pa=heada,pb=headb;
    while(pa!=-1){
        n_list[pa].flag=true;
        pa=n_list[pa].next;
    }
    while(pb!=-1){
        if(n_list[pb].flag){
            printf("%05d",pb); //注意格式 5位数填0
            return 0;
        }
        pb=n_list[pb].next;
    }
    cout<<"-1";

}
