#include<cstdio>
#include<iostream>
using namespace std;
#define minn 1e-5
#define maxn 100
typedef long long LL;
//a^b%m
void merge_two(int a[],int L1,int R1,int L2,int R2){
    int temp[maxn];
    int i=L1,j=L2,cnt=0;
    while(i<=R1&&j<=R2){
        if(a[i]>a[j]){//错写成a[L1]>a[L2]
            temp[cnt++]=a[j++];
        }
        else temp[cnt++]=a[i++];
    }
    while(i<=R1)temp[cnt++]=a[i++];
    while(j<=R2)temp[cnt++]=a[j++];
    for(int i=0;i<cnt;i++)
        a[L1+i]=temp[i];

}
void merge_sort(int a[],int left,int right){
    if(left<right){
        cout<<left<<' '<<right<<endl;
        int mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge_two(a,left,mid,mid+1,right);
    }
}

int main(){
    int a[7]={66,12,33,57,64,27,18};
    merge_sort(a,0,6);
    for(int i=0;i<7;i++)
        cout<<a[i]<<' ';
}
