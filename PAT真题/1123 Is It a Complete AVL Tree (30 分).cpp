#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;
#define maxn 100005
#define null 0
typedef struct node{
    int data,height;
    struct node *LN,*RN;
}node,*L_node;
int get_height(L_node L){
    if(!L)return 0;
    else return L->height;
}
int get_balance(L_node L){
    return get_height(L->LN)-get_height(L->RN);
}
void re_height(L_node L){
    L->height=max(get_height(L->LN),get_height(L->RN))+1;
}
void R_s(L_node &L){
    L_node temp=L->LN;
    L->LN=temp->RN;
    temp->RN=L;
    re_height(L);
    re_height(temp);
    L=temp;
}
void L_s(L_node &L){
    L_node temp=L->RN;
    L->RN=temp->LN;
    temp->LN=L;
    re_height(L);
    re_height(temp);
    L=temp;
}
void insert_node(L_node &L,int x){
    //if(L)cout<<L->data<<' ';
    if(!L){
        L=(L_node)malloc(sizeof(node));
        L->data=x;
        L->LN=L->RN=null;
        L->height=1; //不能设为0，否则无法区别叶子节点和null结点
        //cout<<L->data<<' ';
        return;
    }
    if(x<L->data){
        insert_node(L->LN,x);
        re_height(L);
        if(get_balance(L)==2){
            if(get_balance(L->LN)==1){
                R_s(L);
            }
            else if(get_balance(L->LN)==-1){
                L_s(L->LN);
                R_s(L);
            }
        }
    }
    else if(x>=L->data){ //这里一定要加else 否则递归后返回来到这里时值发生变化
        insert_node(L->RN,x);
        re_height(L);
        if(get_balance(L)==-2){
            if(get_balance(L->RN)==-1){
                L_s(L);
            }
            else if(get_balance(L->RN)==1){
                R_s(L->RN);
                L_s(L);
            }
        }
    }
    //cout<<endl<<endl;
}
int N,a[maxn];
void create(L_node &L){
    int t;
    for(int i=0;i<N;i++){
        cin>>t;
        insert_node(L,t);
        //cout<<a[i]<<' ';
    }
    //cout<<endl;
    return;
}

bool judge(L_node L){ //判断完全二叉树

    queue<L_node> Q;
    Q.push(L);
    while(Q.front()){
        L_node p=Q.front();
        Q.push(p->LN);//若不为空节点则输入其子节点，直到遇到空节点
        Q.push(p->RN);
        Q.pop();
    }
    while(!Q.empty()){ //如果是完全二叉树，此时队列里是没有元素的
        if(Q.front())return false;
        Q.pop();
    }
    return true;
}
void level_t(L_node L){
    queue<L_node> Q;
    Q.push(L);
    bool first=true;
    while(!Q.empty()){
        L_node temp=Q.front();
        Q.pop();
        if(first){
            cout<<temp->data;
            first=false;
        }
        else{
            cout<<' '<<temp->data;
        }
        if(temp->LN)Q.push(temp->LN);
        if(temp->RN)Q.push(temp->RN);
    }

}
int main(){
    cin>>N;
    L_node L=null;
    create(L);
    level_t(L);
    if(judge(L))cout<<endl<<"YES"<<endl;
    else cout<<endl<<"NO"<<endl;
}

/*
6
88 70 61 96 120 90*/
