#include<cstdio>
#include<iostream>
using namespace std;
#define minn 1e-5
double f(double x){
    return x*x; //����һ��ʼд����int����
}
int main(){
    double left=0,right=2,mid; //һ��ʼϰ������������int����
    while(right-left>minn){
        mid=(right+left)/2;
        if(f(mid)<2)left=mid;
        else right=mid;
        cout<<left<<" "<<right<<" "<<mid<<endl;
    }
    cout<<mid;
}
