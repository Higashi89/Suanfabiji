#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 505
int a[maxn]={0, 5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
void Heap_adjust(int p,int n){
    int temp=a[p];
    for(int i=p*2;i<=n;i*=2){
        if(i<n&&a[i]<a[i+1])
            i++;
        if(temp>a[i])
            break;
        a[p]=a[i];
        p=i;
    }
    a[p]=temp;
}

void Heap_sort(int n){
    for(int i=n/2;i>0;i--){
        Heap_adjust(i,n);
    }
    for(int i=n;i>=1;i--){
        swap(a[1],a[i]);
        Heap_adjust(1,i-1);
    }
}

int main(){
    Heap_sort(10);
    for(int i=1;i<=10;i++)
        cout<<a[i]<<' ';
}
