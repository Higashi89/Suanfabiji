#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    if(N==1){
        cout<<"1=1";
        return 0;
    }
    else{
        int k;
        bool first=true;
        cout<<N<<'=';
        for(int i=2;i<=N;i++){
            k=0;
            if(N%i==0){ //等价于素数表的筛法
                if(first)first=false;
                else cout<<'*';
                cout<<i;
                while(N%i==0){
                    N/=i;
                    k++;
                }
                if(k>1)cout<<'^'<<k;
            }
        }
    }

}
//97532468
