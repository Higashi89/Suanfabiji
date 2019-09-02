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
int main(){
    string s;
    cin>>s;
    bool flag=true;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])flag=false;
    }
    if(flag)cout<<"YES";
    else cout<<"NO";
}

