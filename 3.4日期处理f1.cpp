#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<cstring>
#include<set>
#include<map>
using namespace std;
#define maxn 1005

int day[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,28,31,30,31,30,31,31,30,31,30,31}};
bool isrun(int n){
    if((n%4==0&&n%100!=0)||n%400==0)return true;
    else return false;
}
int main(){
    int s1,s2;
    cin>>s1>>s2; //if(s1<s2) swap(s1,s2)即可去掉else保证s1总是较小的一个
    int y1,y2,m1,m2,d1,d2;
    y1=s1/10000,y2=s2/10000;
    m1=(s1%10000)/100,m2=(s2%10000)/100;
    d1=s1%100,d2=s2%100;
    int sum=1;
    if(s1<s2){
        while(y1!=y2||m1!=m2||d1!=d2){
            d1++;sum++;
            if(d1==day[isrun(y1)][m1]+1){
                d1=1;m1++;
            }
            if(m1==13){
                m1=1;y1++;
            }
        }
    }
    else{
        while(y1!=y2||m1!=m2||d1!=d2){
            d2++;sum++;
            if(d2==day[isrun(y2)][m2]+1){
                d2=1;m2++;
            }
            if(m2==13){
                m2=1;y2++;
            }
        }
    }
    cout<<sum;

}

