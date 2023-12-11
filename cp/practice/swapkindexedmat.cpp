#include <iostream>
#include <algorithm>
#include <vector>


void solve(){
    int k,m,temp;
    k=3;m=4;
    int a[4];
    a[0]=3;
    a[1]=4;
    a[2]=5;
    a[3]=7;


    for (int i=0;i<m;i++){
        if(i%2==0){
            if(i-k>=0) {
                temp=a[i];
                a[i]=a[i-k];
                a[i-k]=temp;
            }
            else {
                temp=a[i];
                a[i]=a[m-((i-k)%m)];
                a[m-((i-k)%m)]=temp;
            }
        }
        else {
            if(i+k<m){
                temp=a[i];
                a[i]=a[i+k];
                a[i+k]=temp;}
            else {
                temp=a[i];
                a[i]=a[((i-k)%m)];
                a[(i-k)%m]=temp;}
        }
    }

    for (int i=0;i<m;i++){
        printf(a[i]+" ");
    }
        
}
int main(){
    solve();
    return 0;
}
