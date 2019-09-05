#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin>>N;
    int a[105];
    for(int i=1;i<=N;i++)
        cin>>a[i];
    int guess[105];
    bool flag=false;
    for(int i=1;i<N&&!flag;i++){
        for(int j=i+1;j<=N;j++){

            memset(guess,0,sizeof(guess));
            guess[i]=1;guess[j]=1;

            int cnt1=0,cnt2=0;
            for(int k=1;k<=N;k++){
                int absk=a[k]<0?-a[k]:a[k];
                //cout<<a[k]<<' '<<absk<<' '<<guess[absk]<<endl;
                if(a[k]<0&&guess[absk]==0||a[k]>0&&guess[absk]==1){
                    cnt1++;
                    if(k==i||k==j){
                        cnt2++;  //猜测两个狼人ij 其中一个说谎
                    }
                }
            }

            if(cnt1==2&&cnt2==1){
                cout<<i<<' '<<j;
                flag=true;
                break;
            }
            //cout<<endl;
        }
    }
    if(!flag)cout<<"No Solution";
}


/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#include<cstring>
#include<unordered_map>
#include<sstream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int a[N+1];
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    int sum,s1,s2;bool flag=true;
    int b[N+1];
    for(int i=1;i<=N&&flag;i++){
        for(int j=i+1;j<=N&&flag;j++){
            s1=-1;s2=-1;
            sum=0;
            fill(b,b+N+1,1);
            b[i]=-1;b[j]=-1;
            vector<int> lie;
            for(int k=1;k<=N;k++){
                int f=abs(a[k]);
                if(a[k]*b[f]<0)lie.push_back(k);
            }
            if(lie.size()==2&&b[lie[0]]+b[lie[1]]==0){
                s1=i;s2=j;
                flag=false;
                break;
            }
        }
    }
    if(s1!=-1&&s2!=-1)
        cout<<s1<<" "<<s2;
    else cout<<"No Solution";

}
*/
