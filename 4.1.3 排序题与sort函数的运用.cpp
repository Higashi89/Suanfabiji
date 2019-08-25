#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct student{
    char reg_num[24]; //第一反应用的string+cin但是我中途也糊涂了，不知道到底是不是出错了，以防万一还是用strcpy strcmp好了。
    int loc_num,
    loc_rank,
    final_score,
    final_rank;
}student;
student stu[30005];
bool cmp(student s1,student s2){
    if(s1.final_score!=s2.final_score)return s1.final_score>s2.final_score;
    else return strcmp(s1.reg_num,s2.reg_num)<0; //即s1<s2
}
int main(){
    int K,N;
    cin>>K;
    char t_regnum[24];
    int t_score;
    int pos=0;
    for(int loc=1;loc<=K;loc++){
        cin>>N;
        int j=N;
        while(j--){
            scanf("%s %d",t_regnum,&t_score);
            strcpy(stu[pos].reg_num,t_regnum);
            stu[pos].final_score=t_score;
            stu[pos].loc_num=loc;
            pos++;
        }
        sort(stu+pos-N,stu+pos,cmp);
        int l_rank=2;
        stu[pos-N].loc_rank=1;
        for(int i=pos-N+1;i<pos;i++){
            if(stu[i].final_score==stu[i-1].final_score)stu[i].loc_rank=stu[i-1].loc_rank;
            else stu[i].loc_rank=l_rank;
            l_rank++;
        }
    }
    sort(stu,stu+pos,cmp);
    int f_rank=2;
    stu[0].final_rank=1;
    for(int i=1;i<pos;i++){
        if(stu[i].final_score==stu[i-1].final_score)stu[i].final_rank=stu[i-1].final_rank;
        else stu[i].final_rank=f_rank;
        f_rank++;
    }
    cout<<pos<<endl;
    for(int i=0;i<pos;i++){
        cout<<stu[i].reg_num<<" "<<stu[i].final_rank<<" "<<stu[i].loc_num<<" "<<stu[i].loc_rank<<endl;
    }
}
