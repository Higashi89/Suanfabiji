#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int return_min(int x){
    int a[4];
    for(int i=0;i<4;i++){
        a[i]=x%10;
        x/=10;
    }
    sort(a,a+4);
    int r=1,sum=0;
    for(int i=3;i>=0;i--){
        sum+=r*a[i];
        r*=10;
    }
    return sum;
}
int return_max(int x){
    int a[4];
    for(int i=0;i<4;i++){
        a[i]=x%10;
        x/=10;
    }
    sort(a,a+4);
    int r=1,sum=0;
    for(int i=0;i<4;i++){
        sum+=r*a[i];
        r*=10;
    }
    return sum;
}
/*
bool all_same(int x){
    int a[4];
    for(int i=0;i<4;i++){
        a[i]=x%10;
        x/=10;
    }
    bool flag=true;
    for(int i=1;i<4;i++)
        if(a[i]!=a[i-1])flag=false;
    return flag;
}*/
int main(){
    //cout<<return_min(6767)<<" "<<return_max(6767);
    int N;
    cin>>N;
    int a,b;
    while(N!=6174&&N!=0){ //在这里判0的话就不需要allsame函数了
        a=return_max(N);
        b=return_min(N);
        printf("%04d - %04d = %04d\n",a,b,a-b);
        N=a-b;
    }

}

