#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct Fraction{
    int up,down;
};
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
Fraction reduction(Fraction &a){//一开始忘了加&，函数运行完a值没有变化
    if(a.down<0){
        a.down=-a.down;a.up=-a.up;//规定down不能为负
    }
    if(a.up==0)a.down==1;
    else{
        int d=gcd(abs(a.up),abs(a.down));//分子分母同除最小公因数
        a.up/=d;a.down/=d;
    }
    return a;
}
int main(){
    Fraction a;
    a.up=12,a.down=20;
    reduction(a);
    cout<<gcd(12,20)<<endl;
    cout<<a.up<<" "<<a.down<<endl;
    return 0;
}
