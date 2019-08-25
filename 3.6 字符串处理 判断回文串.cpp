#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin>>a;
    bool flag=true;
    for(int i=0;i<a.length()/a2;i++){ //获取长度第一反应想到的是length但是没有自动提示换成了strlen提示报错不适用于string类，又换回length
        if(a[i]!=a[a.length()-1-i])flag=false;
    }
    if(flag)cout<<"YES";
    else cout<<"NO";
}