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
    for(int i=0;i<a.length()/a2;i++){ //��ȡ���ȵ�һ��Ӧ�뵽����length����û���Զ���ʾ������strlen��ʾ����������string�࣬�ֻ���length
        if(a[i]!=a[a.length()-1-i])flag=false;
    }
    if(flag)cout<<"YES";
    else cout<<"NO";
}