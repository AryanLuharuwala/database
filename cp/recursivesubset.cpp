#include <vector>
#include <iostream>

std::vector<int> subset;
int n;

void search(int k) {
    if (k == n) {
        // process subset
        for(int i = 0; i < subset.size(); i++) {
            std::cout << subset[i] << ' ';
        }
        std::cout << '\n';
    } else {
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }
}

int main() {
    std::cin >> n;
    search(0);
    return 0;
}
