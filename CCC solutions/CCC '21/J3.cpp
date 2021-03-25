#include <bits/stdc++.h>

void solve(std::string str, std::string& prev) {
    int a1 = str[0] - 48;
    int a2 = str[1] - 48;
    int a3 = std::stoi(str.substr(2,3));
    
    int res = a1 + a2;
    if (res % 2 == 0 && res != 0) { // even
        prev = "right"; 
    }else if (res % 2 == 1) {
        prev = "left";
    }
    std::cout << prev << " " << a3 << "\n";
} 

int main() {
    std::string N;
    std::string prev = "";
    std::cin >> N;
    while (N != "99999") {
        
        solve(N,prev);
        std::cin >> N;
    }
    return 0;
}