#include<cstdio>
#include<iostream>
using namespace std;
#define minn 1e-5
double f(double x){
    return x*x; //参数一开始写成了int报错
}
int main(){
    double left=0,right=2,mid; //一开始习惯性声明成了int报错
    while(right-left>minn){
        mid=(right+left)/2;
        if(f(mid)<2)left=mid;
        else right=mid;
        cout<<left<<" "<<right<<" "<<mid<<endl;
    }
    cout<<mid;
}
