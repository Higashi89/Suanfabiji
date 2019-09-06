#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
#define maxn 100005
struct school{
    int s_rank;
    string s_code;
    int s_score;
    int nums;
    school(){
        s_code="nosuchschool";
        s_score=0;
    }
}school_list[maxn];
struct s_temp{
    int score,nums;
    s_temp(){
        score=0,nums=0;
    }
};
bool cmp(school s1,school s2){
    if(s1.s_score!=s2.s_score)return s1.s_score>s2.s_score;
    else if(s1.nums!=s2.nums) return s1.nums<s2.nums;
    else return s1.s_code<s2.s_code;
}
string tolow(string s){
    for(int i=0;i<s.size();i++){
        s[i]=(char)tolower(s[i]);
    }
    return s;
}
int main(){
    //string a="AAA";
    //cout<<(char)tolower(a[0])<<endl;
    int N;
    cin>>N;
    string stu_code,sch_code;int score;
    map<string,s_temp> sch_score;
    set<string> sch_nums;
    while(N--){
        cin>>stu_code>>score>>sch_code;
        sch_code=tolow(sch_code);
        //cout<<sch_code<<endl;
        sch_nums.insert(sch_code);
        if(stu_code[0]=='B')sch_score[sch_code].score+=score/1.5;
        if(stu_code[0]=='A')sch_score[sch_code].score+=score;
        if(stu_code[0]=='T')sch_score[sch_code].score+=score*1.5;
        sch_score[sch_code].nums++;
    }
    map<string,s_temp>::iterator it;
    int cnt=0;
    for(it=sch_score.begin();it!=sch_score.end();it++){
        sch_code=it->first;s_temp t=it->second;
        school_list[cnt].nums=t.nums;
        school_list[cnt].s_score=t.score;
        school_list[cnt].s_code=sch_code;
        cnt++;
    }
    sort(school_list,school_list+maxn,cmp);
    school_list[0].s_rank=1;
    for(int i=1;school_list[i].s_code!="nosuchschool";i++){
        if(school_list[i].s_score==school_list[i-1].s_score)
            school_list[i].s_rank=school_list[i-1].s_rank;
        else
            school_list[i].s_rank=i+1;
    }
    cout<<sch_nums.size()<<endl;
    for(int i=0;school_list[i].s_code!="nosuchschool";i++){
        cout<<school_list[i].s_rank<<' '<<school_list[i].s_code<<' '<<school_list[i].s_score<<' '<<school_list[i].nums<<endl;
    }
}
