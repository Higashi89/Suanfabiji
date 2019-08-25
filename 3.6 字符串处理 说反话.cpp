#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
int main(){
string a;
string b[100];
int i=0;
while(cin>>a){ //第一反应用cin>>a 但是codeblock无法结束输入，scanf eof同样情况，但两种写法提交后都是对的
b[i++]=a;
}
for(int j=i-1;j>0;j--)
cout<<b[j]<<" ";
cout<<b[0];


/*
char a[100][100];
int i=0;
while(scanf("%s",&a[i])!=EOF){
i++;
}
for(int j=i-1;j>0;j--)
cout<<a[j]<<" ";
cout<<a[0];*/
}