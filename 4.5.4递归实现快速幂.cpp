#include<cstdio>
#include<iostream>
using namespace std;
#define minn 1e-5
typedef long long LL;
//a^b%m

LL km(LL a,LL b,LL m){
    if(b==0)return 1;
    //任何数的零次方都是1
   /*此时上传到github网页忽然无法正常显示中文，之前都还正常，打开乱码文件显示提示的的是
We’ve detected the file encoding as ISO-8859-1. When you commit changes we will transcode it to UTF-8.
怀疑是因为在codeblock打开文件的情况下上传，cb默认打开文件编码不是utf8，更改cd默认编码后正常*/
    else if(b%2==1) return a*km(a,b-1,m)%m;
    else if(b%2==0) return km(a,b/2,m)*km(a,b/2,m)%m;
}
int main(){
    cout<<km(2,10,3);
}
