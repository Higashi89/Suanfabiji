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
while(cin>>a){ //��һ��Ӧ��cin>>a ����codeblock�޷��������룬scanf eofͬ�������������д���ύ���ǶԵ�
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