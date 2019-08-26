#include<cstdio>
#include<iostream>
using namespace std;
#define minn 1e-5
typedef long long LL;
//a^b%m

LL km(LL a,LL b,LL m){
    if(b==0)return 1;
    //任何数的零次方都是1 
    else if(b%2==1) return a*km(a,b-1,m)%m;
    else if(b%2==0) return km(a,b/2,m)*km(a,b/2,m)%m;
}
int main(){
    cout<<km(2,10,3);
}
