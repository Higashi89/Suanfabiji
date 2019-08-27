#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long sum=0;
    int SP[100005]={0},ST[100005]={0};
    //SP[i]表示第i位及之前有几个P ST[i]同理
    for(int i=s.length()-1;i>=0;i--){
        if(i==s.length()-1){
            if(s[i]=='T')ST[i]=1;
        }
        else{
            if(s[i]=='T')ST[i]=ST[i+1]+1;
            else ST[i]=ST[i+1];
        }
    }

    for(int i=0;i<s.length();i++){
        if(i==0){
            if(s[i]=='P')SP[i]=1;
        }
        else{
            if(s[i]=='P')SP[i]=SP[i-1]+1;
            else SP[i]=SP[i-1];
        }
    }
    //最后遇到A就计算这位之前的sumP*这位之后的sumT
    for(int i=0;i<s.length();i++){
        if(s[i]=='A')sum+=SP[i]*ST[i];
    }

    cout<<sum%1000000007;
    //PATTPTATA
}

/*
另一种思路
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int i,j;
    long long P=0,PA=0,PAT=0;
    for(i=0;i<s.size();i++){
        if(s[i]=='P'){
            P++;
        }
        if(s[i]=='A'){
            PA+=P;
        }
        if(s[i]=='T'){
            PAT+=PA;
        }
    }
    cout<<PAT%1000000007<<endl;

}
*/
