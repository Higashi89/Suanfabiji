#include<cstdio>
#include<iostream>
using namespace std;
#define minn 1e-5
typedef long long LL;
//a^b%m
void find_m(int a[],int m){
    //int i=0,j=sizeof(a)/sizeof(int)-1; 这里a作为指针传入函数，始终只有4个字节
    int i=0,j=8;
    while(i<j){
        if(a[i]+a[j]<m)i++;
        if(a[i]+a[j]>m)j--;
        if(a[i]+a[j]==m){
            cout<<a[i]<<" "<<a[j]<<endl;
            i++;j--;
        }
    }
}
int main(){
    int a[9]={1,2,3,3,3,3,4,5,6};
    find_m(a,6);
    cout<<sizeof(a)/sizeof(int);
}
