#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
    int left,right;
}a[100];
bool cmp(node n1,node n2){
    if(n1.right!=n2.right)return n1.right<n2.right;
    else return n1.left>n2.left;
}
int main(){
    int k=0;
    while(scanf("%d %d",&a[k].left,&a[k].right)!=EOF){//!=EOF必须要加上 最后用ctrl+z结束输入
        k++;
    }

    sort(a,a+k,cmp);
    int t_left=0,t_right=0,ans=0;
    for(int i=0;i<k;i++){
        if(a[i].left<t_right)continue;
        else{
            t_left=a[i].left;
            t_right=a[i].right;
            ans++;
            cout<<a[i].left<<" "<<a[i].right<<endl;
        }
    }
    cout<<ans;

}
/*
4
1 3
2 4
3 5
6 7
*/
