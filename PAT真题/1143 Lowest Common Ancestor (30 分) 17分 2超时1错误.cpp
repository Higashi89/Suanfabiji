#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;
#define maxn 100005
#define null 0
typedef struct node{
    int data,height;
    struct node *LN,*RN,*last;
}node,*L_node;

int M,N;
int a[maxn];
L_node pre(L_node L,int i,int H){

    if(L==null){
        L=(L_node)malloc(sizeof(node));
        L->data=a[i];
        L->LN=L->RN=null;
        L->height=H;
        L->last=null;
        //return L;
    }

    else{
        if(a[i]<L->data){
            L->LN=pre(L->LN,i,H+1);
            L->LN->last=L;
        }
        if(a[i]>=L->data){
            L->RN=pre(L->RN,i,H+1);
            L->RN->last=L;
        }
    }
    return L;
}
unordered_map<int,L_node> m;
void make_map(L_node L){
    if(L){
        m[L->data]=L;
        //cout<<L->data<<' ';
    }
    else return;//必须加上这一句
    make_map(L->LN);
    make_map(L->RN);
}
int main(){
    cin>>M>>N;
    L_node L=null;
    for(int i=0;i<N;i++){
        cin>>a[i];
        L=pre(L,i,0);
    }
    make_map(L);
    int a,b;
    while(M--){
        cin>>a>>b;
        if(m.find(a)==m.end()&&m.find(b)==m.end()){
            printf("ERROR: %d and %d are not found.\n",a,b);
            continue;
        }
        else if(m.find(a)==m.end()){
            printf("ERROR: %d is not found.\n",a);
            continue;
        }
        else if(m.find(b)==m.end()){
            printf("ERROR: %d is not found.\n",b);
            continue;
        }

        L_node La=m[a],Lb=m[b];
        if(La->height<Lb->height){
            while(La->height<Lb->height){
                Lb=Lb->last;
            }
            if(La==Lb){
                printf("%d is an ancestor of %d.\n",a,b);
                continue;
            }
        }
        if(La->height>Lb->height){
            while(La->height>Lb->height){
                La=La->last;
            }
            if(La==Lb){
                printf("%d is an ancestor of %d.\n",b,a);
                continue;
            }
        }
        //cout<<La->data<<' '<<Lb->data<<endl;
        while(La!=Lb){
            La=La->last;Lb=Lb->last;
        }
        printf("LCA of %d and %d is %d.\n",a,b,La->data);
    }

}
