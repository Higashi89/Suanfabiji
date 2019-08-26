#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int a[10]={0};
    int x;
    for(int i=0;i<10;i++){
        cin>>x;
        a[i]=x;
    }
    int first=0;
    for(int i=1;i<10;i++){
        if(a[i]!=0){
            first=i;
            break;
        }
    }
    cout<<first;//只用输1位除0以外的最小数就行，剩下的在0之后输出
    for(int i=0;i<10;i++){
        if(i!=first) //一开始把这个判断放在for里面了导致到first循环中断出错
            for(int j=0;j<a[i];j++)
                cout<<i;
        else
            for(int j=0;j<a[first]-1;j++)
                cout<<first;
    }
    //2 2 0 0 0 3 0 0 1 0
}
