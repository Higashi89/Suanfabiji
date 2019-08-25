#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;


bool is_prime(int k){
    if(k==1)return false;
    if(k==2)return true;
    for(int i=2;i*i<=k;i++){
        if(k%i==0)return false;
    }
    return true;
}
int main(){
    int Msize,N;
    cin>>Msize>>N;
    int Tsize=Msize;
    while(!is_prime(Tsize))Tsize++;
    int Hash[100005]={0};
    int temp;
    while(N--){
        cin>>temp;
        if(Hash[temp%Tsize]==0){
            Hash[temp%Tsize]=temp;


            if(N!=0)cout<<temp%Tsize<<" ";//此处第一反应是N!=1,要注意N--在何时进行
            else cout<<temp%Tsize;
        }
        else{
            int i=1;
            while(Hash[(temp+i*i)%Tsize]!=0&&i<=Tsize/2&&(temp+i*i)%Tsize<Tsize){
                i++;
            }
            if(Hash[(temp+i*i)%Tsize]==0&&i<=Tsize/2&&(temp+i*i)%Tsize<Tsize){
                Hash[(temp+i*i)%Tsize]=temp;
                if(N!=0)cout<<(temp+i*i)%Tsize<<" ";
                else cout<<(temp+i*i)%Tsize;
            }
            else{
                if(N!=0)cout<<"- ";
                else cout<<"-";
            }
        }
    }


}
