
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
#define maxn 10005
struct node{
    int a,b;
}v[maxn];
int main(){
    int N,M;
    cin>>N>>M;
    int ta,tb;
    for(int i=0;i<M;i++){
        scanf("%d %d",&ta,&tb);
        v[i].a=ta;v[i].b=tb;
    }
    int K;
    cin>>K;
    int color[maxn];
    while(K--){
        memset(color,0,sizeof(color));
        set<int> s;
        bool flag=true;
        for(int i=0;i<N;i++){
            scanf("%d",&color[i]);
            s.insert(color[i]);
        }
        for(int i=0;i<M;i++){
            if(color[v[i].a]==color[v[i].b]){
                flag=false;
            }
        }
        if(flag)cout<<s.size()<<"-coloring"<<endl;
        else cout<<"No"<<endl;

    }

}




//老版
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
struct stu{
    int a1,b1;
}v[10001];
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
        scanf("%d %d",&v[i].a1,&v[i].b1);
    int K;
    cin>>K;
    while(K--){
        bool flag=true;
        int a[10001];
        set<int> num;
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
            num.insert(a[i]);
        }
        for (int i = 0; i < M; i++) {
            if (a[v[i].a1] == a[v[i].b1]) {
                flag = false;
                break;
            }
        }
        if(flag)printf("%d-coloring\n",num.size());
        else printf("No\n");
    }
    return 0;
}

