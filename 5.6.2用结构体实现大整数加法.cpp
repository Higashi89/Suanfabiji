#include<iostream>
#include<cstring>
using namespace std;
struct bign{
    int data[40];
    int len;
    bign(){ //结构体的同名初始化函数
        memset(data,0,sizeof(data));
        len=0;
    }
};
bign bign_in(char a[]){
    bign t;
    int len=strlen(a);
    t.len=len;
    for(int i=0;i<len;i++){
        t.data[i]=a[len-1-i]-'0';
    }
    return t;
}

bign bign_add(bign a,bign b){
    bign c;
    int carry=0,i;
    for(i=0;i<a.len||i<b.len;i++){
        c.data[i]=a.data[i]+b.data[i]+carry;
        carry=c.data[i]/10;
        c.data[i]%=10;
    }
    c.len=i;
    if(carry>0)c.data[c.len++]=carry;
    return c;
}

void show_bign(bign a){
    for(int i=a.len-1;i>=0;i--)
        cout<<a.data[i];
}
int main(){
    char a[40],b[40];
    scanf("%s %s",a,b);
    cout<<a<<b<<endl;
    bign ba=bign_in(a);
    bign bb=bign_in(b);
    show_bign(bign_add(ba,bb));
}
// 1234 9123 10357
