#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;


int d[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};


bool isrun(int year){
    if((year%4==0&&year%100!=0)||year%400==0)return true;
    else return false;
}


int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    if(a<b)swap(a,b);
    int y1,y2,m1,m2,d1,d2;
    y1=a/10000,y2=b/10000;
    m1=(a%10000)/100,m2=(b%10000)/100;
    d1=a%100,d2=b%100; //这里第一反应是a%10
    cout<<y1<<" "<<m1<<" "<<d1<<endl;
    cout<<y2<<" "<<m2<<" "<<d2<<endl<<endl;
    int sum=1;
    while(y1!=y2||m1!=m2||d1!=d2){
        cout<<y2<<" "<<m2<<" "<<d2<<endl;
        if(d2<d[m2][isrun(y2)]){
            d2++;sum++;
            continue;//不加continue的话20130130 20130131会陷入死循环
        }
        if(d2==d[m2][isrun(y2)]){
            d2=1;m2++;sum++;
            if(m2==13){
                y2++;m2=1;
            }
        }
    }
    cout<<sum;




}