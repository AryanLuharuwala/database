#include <vector>
#include <iostream>

std::vector<int> permutation;
std::vector<bool> chosen;
int n;

void search() {
    if (permutation.size() == n) {
        // process permutation
        for(int i = 0; i < permutation.size(); i++) {
            std::cout << permutation[i] << ' ';
        }
        std::cout << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    std::cin >> n;
    chosen.resize(n);
    search();
    return 0;
}
