#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<unordered_map>//�����������й�ѡc++11֧�� unorder�ٶȸ���
#include<set>
#define null 0
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;   //1.�����ڽӱ�  ÿ�β�ѯnums[N]������Ԫ��visit[nums[i]]=1
    int a,b;  //2.Ȼ���nums�г��ֵ�n��Ԫ�� ��ѯm[num[i]].size()���Ƿ���visit�г��ֹ�����
    map<int,vector<int> >m; //������mapҲ�ܹ�
    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    //cout<<*m["20001"].find("20002");
    int num;
    while(M--){
        cin>>num;
        bool flag=true;
        int Q[100001]={0};
        int nums[1005];
        for(int i=0;i<num;i++){
            scanf("%d",&a);
            Q[a]=1;
            nums[i]=a;
        }

        for(int i=0;i<num;i++){
            for(int j=0;j<m[nums[i]].size();j++){
                if(Q[m[nums[i]][j]]==1)
                    flag=false;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}
