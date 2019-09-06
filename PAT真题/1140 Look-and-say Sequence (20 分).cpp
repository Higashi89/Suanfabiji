#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 45
int main(){
    int D,N;
    cin>>D>>N;
    vector<int> a[maxn];
    a[1].push_back(D);
    a[2].push_back(D);a[2].push_back(1);
    for(int i=3;i<maxn;i++){
        int temp=a[i-1][0],cnt=1;
        for(int j=1;j<a[i-1].size();j++){
            if(a[i-1][j]==temp){
                cnt++;
            }
            if(a[i-1][j]!=temp){
                a[i].push_back(temp);a[i].push_back(cnt);
                temp=a[i-1][j];cnt=1;
            }
            if(j==a[i-1].size()-1){
                a[i].push_back(temp);a[i].push_back(cnt);
            }
        }
    }
    for(int i=0;i<a[N].size();i++)
        cout<<a[N][i];
}
