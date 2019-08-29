#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
struct node{
    int pos;
    int data;
    int next;
    int flag;
    node(){
        data=999999;
        flag=0;
        next=-1;
    }
}l_node[maxn];

bool cmp(node a,node b){
    if(a.flag==0||b.flag==0)return a.flag>b.flag;
    else return a.data<b.data;
}

int main(){
    int N,start;
    cin>>N>>start;
    int t_pos,t_data,t_next;
    while(N--){
        scanf("%d %d %d",&t_pos,&t_data,&t_next);
        l_node[t_pos].pos=t_pos;
        l_node[t_pos].data=t_data;
        l_node[t_pos].next=t_next;
    }


    int pa=start,len=0;
    while(pa!=-1){
        l_node[pa].flag=1;//给链表中的结点打上标记排除无关输入结点
        len++;
        pa=l_node[pa].next;
    }


    sort(l_node,l_node+maxn,cmp);
    for(int i=0;i<len-1;i++){
        l_node[i].next=l_node[i+1].pos;
    }
    l_node[len-1].next=-1;


    printf("%d %05d\n",len,l_node[0].pos);
    for(int i=0;i<len-1;i++){
        printf("%05d %d %05d\n",l_node[i].pos,l_node[i].data,l_node[i].next);
    }
    printf("%05d %d %d\n",l_node[len-1].pos,l_node[len-1].data,l_node[len-1].next);
}
