#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100
#define null 0
struct node{
    int data;
    struct node *L,*R;
};
vector<int> data;
int N; //默认条件是 根据先序可以唯一确定一颗二叉搜索树
void insert_Z(node* &n,int pos){
    int temp=data[pos];
    //cout<<temp<<' '<<n<<endl;
    if(n==null){
        n=(node*)malloc(sizeof(node));
        n->data=temp;
        n->L=null;
        n->R=null;
    }
    else{
        if(temp>=n->data)insert_Z(n->R,pos);
        else insert_Z(n->L,pos);
    }
}
vector<int> pre,pre_m;
void pre_Z(node *n){
    if(n==null)return;
    pre.push_back(n->data);
    pre_Z(n->L);
    pre_Z(n->R);
}
void pre_F(node *n){
    if(n==null)return;
    pre_m.push_back(n->data);
    pre_F(n->R);
    pre_F(n->L);
}
vector<int>post,post_m;
void post_Z(node *n){
    if(n==null)return;
    post_Z(n->L);
    post_Z(n->R);
    post.push_back(n->data);
}
void post_F(node *n){
    if(n==null)return;
    post_F(n->R); //镜像树的后序左右要倒一下
    post_F(n->L);
    post_m.push_back(n->data);
}

int main(){
    cin>>N;
    node* n=null;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        data.push_back(temp);
        insert_Z(n,i);
    }
    pre_Z(n);
    pre_F(n);
    post_Z(n);
    post_F(n);
    if(pre==data){
        cout<<"YES"<<endl;
        for(int i=0;i<post.size();i++){
            if(i==0)cout<<post[i];
            else cout<<' '<<post[i];
        }
    }
    else if(pre_m==data){
        cout<<"YES"<<endl;
        for(int i=0;i<post_m.size();i++){
            if(i==0)cout<<post_m[i];
            else cout<<' '<<post_m[i];
        }
    }
    else
        cout<<"NO";

}
