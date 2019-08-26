#include<cstdio>
#include<iostream>
using namespace std;
#define minn 1e-5
typedef long long LL;
//a^b%m

LL km(LL a,LL b,LL m){
    int ans=1;
    while(b>0){
        cout<<ans<<" "<<a<<" "<<b<<endl;
        if(b&1){//等价于b%2==1
            ans=ans*a%m;
        }
        b=b>>1;//等价于b/2 第一反应写成了b
        a=a*a;//a变为a的二次方

    }
    return ans;
}
int main(){
    cout<<km(2,5,3);
}
