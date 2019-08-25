#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int N,max_amount;
    cin>>N>>max_amount;
    float k[N+1],p[N+1],s[N+1];
    for(int i=0;i<N;i++){
        scanf("%f",&k[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%f",&p[i]);
        s[i]=p[i]/k[i];
    }
    int m=0;
    float tp=0;
    while(m<max_amount){
        float max_s=0;int pos=0;//max_s一开始声明成了int类型，在最大值比较时出错
        for(int i=0;i<N;i++){
            if(s[i]>max_s){
                max_s=s[i];pos=i;
            }
        }
        tp+=((max_amount-m)>k[pos]?k[pos]:max_amount-m)*s[pos];
        m+=(max_amount-m)>k[pos]?k[pos]:max_amount-m;
        s[pos]=0;


    }
    printf("%.2f",tp);
    /*
3 20
18 15 10
75 72 45
    */




}
