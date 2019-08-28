#include<cstdio>
#include<iostream>
using namespace std;
#define maxn 10005

int prime[maxn]={0};
//bool check[maxn]={true};//不知为什么出错
int check[maxn]={0};
void make_prime(int b){
    int pos=0;
    for(int i=2;i<=maxn;i++){
        if(pos>b)break; //减少没必要的循环
        if(check[i]==0){
            prime[pos++]=i;
            for(int j=i;j<=maxn;j+=i) //把所有能整除i的数剔除掉
                check[j]=1;
        }
        //cout<<"i="<<i<<"check[i]="<<check[i]<<' '<<prime[i]<<endl;
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    make_prime(b);
    int cnt=0;
    for(int i=a;i<=b;i++){
        cout<<prime[i-1];
        cnt++;
        if(cnt%10!=0&&i!=b)cout<<' ';
        else cout<<endl;
    }
}
