#include <iostream>
#include <vector>

void subset(){
    for(int b=0; b<(1<<n); b++)
    {
        std::vector<int> subsetl;
        for(int i=0; i<n;i++)
            if (b&(1<<i)) 
              subsetl.push_back(i);
        for(int i=0; i<subsetl.size(); i++)
            std::cout<<subsetl[i]<<" ";
        std::cout<<"\n";
    }
}

int main(){
    subset();
    return 0;
}
