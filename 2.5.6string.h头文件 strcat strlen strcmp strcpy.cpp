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
    char s[400];
    gets(s);
    printf("%s\n",s);
    cout<<strlen(s)<<endl;
    char s2[40];
    strcpy(s2,s); //s2=s;
    strcat(s2,s); //s2+=s;
    //a的字典序小于b aab的字典序小于aaaa
    cout<<strcmp("aaa","bbb")<<' '<<strcmp("bbb","aaa")<<' '<<strcmp("aaa","aaa")<<endl;
    cout<<s<<' '<<s2<<endl;
}

