#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
string s;
int N,K;
int toint(int st,int e){
    int sum=0,b=1;
    for(int i=e;i>=st;i--){
        int t=s[i]-'0';
        sum+=t*b;
        b*=10;
    }
    return sum;
}
bool isprime(int n){
    if(n==0||n==1)return false;
    int flag=true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)flag=false;
    }
    if(flag)return true;
    return false;
}
int main(){
    cin>>N>>K;
    cin>>s;
    int flag=0;
    for(int i=0;i<=N-K;i++){ //要写成i<=N-K 不是<N-K
        int temp=toint(i,i+K-1);
        if(isprime(temp)){
            flag=1;
            for(int j=i;j<i+K;j++)
                cout<<s[j];
            break;
        }
    }
    if(!flag)cout<<"404";

}




//老版
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<cmath>
using namespace std;
bool is_prime(int i){
    if(i==0||i==1)return false;
    if(i==2)return true;
    for(int j=2;j<=sqrt(i);j++){
        if(i%j==0)return false;
    }
    return true;
}
int main(){
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    for(int i=0;i<=a-b;i++){
        if(is_prime(stoi(s.substr(i,b)))){
            cout<<s.substr(i,b)<<endl;
            return 0;
        }
    }
    cout<<"404"<<endl;

}