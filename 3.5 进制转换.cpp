#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int A,B,D;
    cin>>A>>B>>D;
    int sum=A+B;
    int ans[1000],pos=0;
    while(sum!=0){ //�˴���һ��Ӧд����sum/D!=0 �ᵼ�� 11 0 ���011 ��һλ
        ans[pos++]=sum%D;
        sum/=D;
    }
    for(int i=pos-1;i>=0;i--)
        cout<<ans[i];
}