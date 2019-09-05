#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef struct bNode{
    int data;
    struct bNode *LN,*RN;
}bNode,*L_bNode;
#define maxn 1005
#define null 0
int a[maxn],M,N;
int flag_min=1,flag_max=1;
L_bNode create(L_bNode L,int i){
    if(i>N)return null;
    if(L==null&&i<=N){
        L=(L_bNode)malloc(sizeof(bNode));
        L->data=a[i];
        //cout<<L->data<<' ';
        L->LN=null;L->RN=null;
    }
    L->LN=create(L->LN,i*2);
    L->RN=create(L->RN,i*2+1);
    return L;
}

void check_max(L_bNode L){
    if(L->LN&&L->RN)
        if(L->data<L->LN->data||L->data<L->RN->data)
            flag_max=0;
    if(L->LN&&!L->RN)
        if(L->data<L->LN->data)
            flag_max=0;
    if(L->LN)check_max(L->LN);
    if(L->RN)check_max(L->RN);

}
void check_min(L_bNode L){
    //cout<<endl<<L->data<<' '<<flag_min;
    if(L->LN&&L->RN)
        if(L->data>L->LN->data||L->data>L->RN->data)
            flag_min=0;
    if(L->LN&&!L->RN)
        if(L->data>L->LN->data)
            flag_min=0;
    if(L->LN)check_min(L->LN);
    if(L->RN)check_min(L->RN);

}
int post[maxn],cnt;
void post_t(L_bNode L){
    if(L->LN)post_t(L->LN);
    if(L->RN)post_t(L->RN);
    if(L)post[cnt++]=L->data;
}
int main(){
    cin>>M>>N;
    while(M--){
        for(int i=1;i<=N;i++){
            cin>>a[i];
        }
        L_bNode L=null;
        L=create(L,1);
        flag_max=1,flag_min=1;
        check_max(L);
        check_min(L);
        if(flag_max==flag_min)cout<<"Not Heap"<<endl;
        if(flag_max&&!flag_min)cout<<"Max Heap"<<endl;
        if(!flag_max&&flag_min)cout<<"Min Heap"<<endl;
        cnt=1;
        post_t(L);
        for(int i=1;i<=N;i++){
            if(i==1)cout<<post[i];
            else cout<<' '<<post[i];
        }
        cout<<endl;
    }


}
