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

vector<int> a;
void change(int N,int D){
    int cnt=0;
    while(N!=0){
        a.push_back(N%D);
        N/=D;
    }
}
int main(){
    int A,B,D;
    cin>>A>>B>>D;
    change(A+B,D);
    for(int i=a.size()-1;i>=0;i--)
        cout<<a[i];
}

