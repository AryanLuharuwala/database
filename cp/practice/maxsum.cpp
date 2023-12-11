#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subset(){
    long long n;long long best=0;
    vector<long long> x;
    cin>>n;
    x.resize(n);
    
    for (long long i=0; i<n;i++){
        cin>>x[i];
    }
    for(long long b=0; b<(1<<n); b++)
    {   
        std::vector<long long> subsetl;
        for(long long i=0; i<n;i++)
            if (b&(1<<i)) 
              subsetl.push_back(x[i]);
       /* for(int i=0; i<subsetl.size(); i++)
            std::cout<<subsetl[i]<<" ";
        std::cout<<"\n";
        */
        sort(subsetl.begin(),subsetl.end());
        if (!subsetl.empty()) {
            long long rev = subsetl[0]*subsetl.size();
            best = max(best,rev);
        }
    }
    cout<<best;
}

int main(){
    subset();
    return 0;
}
