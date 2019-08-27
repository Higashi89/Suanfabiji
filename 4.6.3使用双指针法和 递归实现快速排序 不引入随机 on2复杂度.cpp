#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int q_change(int a[],int L,int R){
    int temp=a[L]; //提取出该区间内第一个数，比他小的放他左边，比他大的放右边
    while(L<R){
        while(L<R&&a[R]>temp)R--;
        a[L]=a[R];
        while(L<R&&a[L]<temp)L++;
        a[R]=a[L];
    }
    a[L]=temp;
    return L;
}

void q_sort(int a[],int L,int R){
    cout<<L<<" "<<R<<endl;
    if(L<R){
        int pos=q_change(a,L,R);
        q_sort(a,L,pos-1);
        q_sort(a,pos+1,R); // 原本写成 q_sort(a,pos,R);出错
    }
}

int main(){
    int a[11]={35,18,16,72,24,65,12,88,45,28,55};
    q_sort(a,0,10);
    for(int i=0;i<11;i++)
        cout<<a[i]<<" ";
}
