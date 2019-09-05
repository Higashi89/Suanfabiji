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
#define maxn 10005
typedef struct node{
    int data,level;
    struct node *L,*R,*last;
}node,*L_node;
int N,M;
int pre[maxn];
int in[maxn];
map<int,L_node> m;
L_node create(int preL,int preR,int inL,int inR,int level){
    //cout<<preL<<' '<<preR<<' '<<inL<<' '<<inR<<endl;
    if(preL>preR){
        return null;
    }
    L_node a=(L_node)malloc(sizeof(node));
    a->last=null;
    a->data=pre[preL];
    a->level=level;
    m[a->data]=a;
    int pos;
    for(int i=inL;i<=inR;i++){
        if(in[i]==pre[preL])pos=i;
    }
    int len=pos-inL;
    a->L=create(preL+1,preL+len,inL,pos-1,level+1);if(a->L!=null)a->L->last=a;
    a->R=create(preL+1+len,preR,pos+1,inR,level+1);if(a->R!=null)a->R->last=a;

    return a;
}


/*
int tree[maxn];
queue<L_node> Q;
void level_t(L_node l){
    Q.push(l);
    int cnt=1;
    while(!Q.empty()){
        L_node temp=Q.front();
        Q.pop();
        tree[cnt++]=temp->data;
        cout<<temp->data<<endl;
        if(temp->L!=null)Q.push(temp->L);
        if(temp->R!=null)Q.push(temp->R);
    }
}
*/
void check(int a,int b){
    if(m.find(a)==m.end()&&m.find(b)==m.end()){
        printf("ERROR: %d and %d are not found.\n",a,b);
        return;
    }
    if(m.find(a)==m.end()){
        printf("ERROR: %d is not found.\n",a);
    }
    if(m.find(b)==m.end()){
        printf("ERROR: %d is not found.\n",b);
    }
    if(m.find(a)!=m.end()&&m.find(b)!=m.end()){
        L_node La=m[a],Lb=m[b];
        //cout<<(La->level)<<' '<<(Lb->level)<<endl;
        //if(La->level<Lb->level)swap(La,Lb);
        while(La->level>Lb->level)La=La->last;
        if(La==Lb){
            printf("%d is an ancestor of %d.\n",b,a);
            return;
        }
        while(La->level<Lb->level)Lb=Lb->last;
        if(La==Lb){
            printf("%d is an ancestor of %d.\n",a,b);
            return;
        }
        while(La!=Lb){
            La=La->last;
            Lb=Lb->last;
        }
        printf("LCA of %d and %d is %d.\n",a,b,La->data);

    }


}


int main(){
    cin>>M>>N;
    for(int i=0;i<N;i++)
        cin>>in[i];
    for(int i=0;i<N;i++)
        cin>>pre[i];

    L_node l=create(0,N-1,0,N-1,0);
    //cout<<(m.find(6)!=m.end())<<endl;
    int a,b;
    while(M--){
        cin>>a>>b;
        check(a,b);
    }
    /*
    level_t(l);
    for(int i=1;i<=8;i++)
        cout<<tree[i]<<' ';*/

}

