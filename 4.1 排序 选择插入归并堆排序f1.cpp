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
#define maxn 1005
#define N 9
void selection_sort(int a[]){
    for(int i=0;i<N;i++){
        int temp=i;
        for(int j=i;j<N;j++){
            if(a[j]>a[temp])temp=j;
        }
        cout<<temp<<endl;
        swap(a[i],a[temp]);
    }
}
void insert_sort(int a[]){
    for(int i=1;i<N;i++){
        int j=i,temp=a[i];
        while(j>0&&temp<a[j-1]){
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
}
void merge_m(int a[],int L1,int R1,int L2,int R2){
    int i=L1,j=L2,cnt=0;
    int temp[maxn];
    while(i<=R1&&j<=R2){
        if(a[i]<a[j]){
            temp[cnt++]=a[i];
            i++;
        }
        else{
            temp[cnt++]=a[j];
            j++;
        }
    }
    while(i<=R1)temp[cnt++]=a[i++];
    while(j<=R2)temp[cnt++]=a[j++];
    for(i=0;i<cnt;i++){
        a[L1+i]=temp[i];
    }
}
void merge_sort(int a[],int L,int R){
    if(L<R){
        int mid=(L+R)/2;
        merge_sort(a,L,mid);
        merge_sort(a,mid+1,R);
        merge_m(a,L,mid,mid+1,R);
    }
}

int partition_m(int a[],int L,int R){
    int temp=a[L];
    int i=L,j=R;
    while(L<R){
        //cout<<L<<' '<<R<<endl;
        while(L<R&&a[R]>=temp)R--;//这里也要加上L<R判断
        a[L]=a[R];
        while(L<R&&a[L]<=temp)L++;
        a[R]=a[L];
    }
    //cout<<L<<' '<<R<<endl;
    a[L]=temp;
    return L;
}
void quick_sort(int a[],int L,int R){
    if(L<R){

        int pos=partition_m(a,L,R);
        cout<<L<<' '<<R<<' '<<pos<<endl;
        quick_sort(a,L,pos-1);
        quick_sort(a,pos+1,R);
    }
}

void adjust(int a[],int k,int N2){//为k个元素找到合适的位置
    int temp=a[k];
    for(int i=k*2;i<N2;i++){
        cout<<temp<<' '<<i<<' '<<k<<endl;
        if(i+1<N2&&a[i]<a[i+1])
            i++;
        if(temp<a[i]){
            swap(a[k],a[i]);
            k=i;
            temp=a[k];
        }
        else break;
    }
}
void heap_sort(int a[]){
    for(int i=(N-1)/2;i>0;i--){
        adjust(a,i,N); //从最后一个有子节点的结点开始逐个向上调整
    }
    cout<<endl<<endl;
    for(int i=N-1;i>1;i--){
        swap(a[i],a[1]);//交换最后一个节点和根结点，为根节点找到适合的位置，最后一个
        adjust(a,1,i);//隐藏最后一个 把根节点在1~N-1范围内调整
    }
}
int main(){
    int a[N]={5,6,2,1,8,7,9,4,3};
    //selection_sort(a);
    //insert_sort(a);
    //merge_sort(a,0,N);
    //quick_sort(a,0,N);
    heap_sort(a);//忽略掉a[0]
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";

}

