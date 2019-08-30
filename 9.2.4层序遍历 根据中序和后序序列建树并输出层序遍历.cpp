#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 100
#define null 0
struct node{
    int data;
    struct node *L,*R;
};
int N;
int in_list[maxn];
int post[maxn];

node* create(int pl,int pr,int il,int ir){
    if(pl>pr){
        return null;
    }
    node *n=(node*)malloc(sizeof(node));
    n->data=post[pr];
    int k,l_len;
    for(int i=0;i<N;i++){
        if(in_list[i]==post[pr]){
            k=i;
            break;
        }
    }
    l_len=k-il;
    n->L=create(pl,pl+l_len-1,il,k-1);
    n->R=create(pl+l_len,pr-1,k+1,ir);
    return n;
}
void level_tra(node *n){
    queue<node*> Q;
    Q.push(n);
    bool flag=true;
    while(!Q.empty()){
        node* s=Q.front();
        Q.pop();
        if(flag){
            cout<<s->data;
            flag=false;
        }
        else cout<<' '<<s->data;
        if(s->L!=null)Q.push(s->L);
        if(s->R!=null)Q.push(s->R);
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>post[i];
    for(int i=0;i<N;i++)
        cin>>in_list[i];
    node *n=create(0,N-1,0,N-1);  //node *n=create(0,6,0,6); 没改成N-1出现段错误
    level_tra(n);

}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
4 1 6 3 5 7 2
*/
