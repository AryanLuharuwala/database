#include <iostream>
#include <algorithm?>
#include <vector>

using namespace std;
int main(){
    int n, num, i;
    
    cin>>n;
    int arr[n];
    cin>>num;
    while(i<n){
        cin>>arr[i];
        i++;
    };
    sort(arr.begin(),arr.end());
    target(num);
}
void target(x){
    int flag=0;int x=0;
    while(x>arr[0]){
        for(auto j:n){
            if (x==arr[j])
            {flag++; continue;}
            else{
             target(x-arr[j]);}
        
        }
        

        if flag==0
        cout<<x;
    }
}