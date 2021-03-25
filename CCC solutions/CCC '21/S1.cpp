#include <bits/stdc++.h>

int main() {
    int N,a;
    std::cin >> N;
    std::vector<int> height;
    std::vector<int> width;
    for (int i=0;i<N + 1;i++) {
        std::cin >> a;
        height.push_back(a);
    }
    for (int i=0;i<N;i++) {
        std::cin >> a;
        width.push_back(a);
    }
    double total = 0;
    for (int i=0;i<height.size()-1;i++) {
        total += width[i] * (height[i] + height[i + 1]) / 2.0;
    }
    std::cout << std::fixed << total;
    return 0;
}