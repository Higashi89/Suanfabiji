//22分 每次提交测试点不一样 22/19 答案错误/超时 但有一个测试点就是过不了
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
using namespace std;
struct student{
    string all;
    string level;
    string site;
    string date;
    string id;
    int score;
}stu[10005];
struct type3{
    int site;
    int num;
};

bool cmp(student s1,student s2){
    if(s1.score!=s2.score)return s1.score>s2.score;
    else return s1.all<s2.all;
}
bool cmp2(type3 t1,type3 t2){
    if(t1.num!=t2.num)return t1.num>t2.num;
    else return t1.site<t2.site;
}

int main(){
    int N,M;
    cin>>N>>M;
    string t1;int t2;
    for(int i=0;i<N;i++){
        cin>>t1>>t2;
        stu[i].all=t1;
        stu[i].level=t1[0];
        stu[i].site=t1.substr(1,3);
        stu[i].date=t1.substr(4,6);
        stu[i].id=t1.substr(10,3);
        stu[i].score=t2;
    }

    int type;string t3;
    sort(stu,stu+N,cmp);
    for(int j=1;j<=M;j++){
        bool flag=false;
        cin>>type>>t3;
        if(type==1){
            cout<<"Case "<<j<<": "<<type<<' '<<t3<<endl;
            if(stu[0].level==t3){
                    flag=true;
            }
            if(flag){
                for(int i=0;i<N;i++){
                    if(stu[i].level==t3){
                        cout<<stu[i].all<<' '<<stu[i].score<<endl;
                    }
                }
            }
            else cout<<"NA"<<endl;
        }
        if(type==2){
            int cnt=0,sum=0;
            for(int i=0;i<N;i++){
                if(stu[i].site==t3){
                    cnt++;
                    sum+=stu[i].score;
                    flag=true;
                }
            }
            cout<<"Case "<<j<<": "<<type<<' '<<t3<<endl;
            if(flag)cout<<cnt<<' '<<sum<<endl;
            else cout<<"NA"<<endl;
        }
        if(type==3){
            vector<type3> ty3;
            int m[1000]={0};
            for(int i=0;i<N;i++){
                if(stu[i].date==t3){
                    m[stoi(stu[i].site)]++;
                    flag=true;
                }
            }
            for(int i=0;i<1000;i++){
                if(m[i]!=0){
                    type3 ttt={i,m[i]};
                    ty3.push_back(ttt);
                }
            }
            cout<<"Case "<<j<<": "<<type<<' '<<t3<<endl;
            if(flag){
                sort(ty3.begin(),ty3.end(),cmp2);
                for(int i=0;i<ty3.size();i++){
                    cout<<ty3[i].site<<' '<<ty3[i].num<<endl;
                }
            }
            else{
                cout<<"NA"<<endl;
            }
        }

    }
}