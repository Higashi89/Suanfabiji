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
    int N;char a;
    cin>>N>>a;
    for(int i=0;i<ceil(N/2.0);i++){
        if(i==0||i==ceil(N/2.0)-1){// cmath 向上取整  floor(double x)向下取整
            for(int j=0;j<N;j++)
                cout<<a;
            cout<<endl;
        }
        else{
            cout<<a;
            for(int j=0;j<N-2;j++)
                cout<<' ';
            cout<<a<<endl;
        }
    }

}

