#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b); //欧几里得算法，即辗转相除法
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;//即a*b/(ab最大公约数) 防止溢出先除后惩
}
int main(){
    cout<<gcd(6,8)<<" "<<lcm(6,8)<<endl;
}
