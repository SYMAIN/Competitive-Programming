#include <bits/stdc++.h>

using namespace std;

int main() {
    int B;
    std::cin >> B;
    
    int result = 5 * B - 400;
    std::cout << result << "\n";
    if (result < 100) {
        std::cout << 1;
    }else if (result == 100) {
        std::cout << 0;
    }else {
        std::cout << -1;
    }
}