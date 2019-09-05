#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<unordered_map>//编译器设置中勾选c++11支持 unorder速度更快
#include<set>
#define null 0
using namespace std;
#define maxn 100005
bool isprime(int n){
    if(n==0||n==1)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    int Msize,N,M;
    cin>>Msize>>N>>M;

    for(int i=Msize;;i++){
        if(isprime(i)){
            Msize=i;
            break;
        }
    }

    int a[maxn]={0};

    int t;
    for(int i=0;i<N;i++){
        cin>>t;
        bool flag=false;
        for(int j=0;j<=Msize;j++){
            int pos=(t+j*j)%Msize;
            if(a[pos]==0){
                a[pos]=t;
                flag=true;
                break;
            }
        }
        if(!flag){

            cout<<t<<" cannot be inserted."<<endl;
        }
    }
    double sum=0;
    for(int i=0;i<M;i++){
        cin>>t;
        for(int j=0;j<=Msize;j++){
            sum++;
            int pos=(t+j*j)%Msize;
            //cout<<pos<<' ';
            if(a[pos]==t||a[pos]==0)
                break;
        }
    }
    printf("%.1f",sum/M);



}


/*
#include <iostream>
#include <vector>
using namespace std;
bool isprime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int tsize, n, m, a;
    scanf("%d %d %d", &tsize, &n, &m);
    while(!isprime(tsize)) tsize++;
    vector<int> v(tsize);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int flag = 0;
        for (int j = 0; j < tsize; j++) {
            int pos = (a + j * j) % tsize;
            if (v[pos] == 0) {
                v[pos] = a;
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", a);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        for (int j = 0; j <= tsize; j++) {
            ans++;
            int pos = (a + j * j) % tsize;
            if (v[pos] == a || v[pos] == 0) break;
        }
    }
    printf("%.1lf\n", ans * 1.0 / m);
    return 0;
}

*/
