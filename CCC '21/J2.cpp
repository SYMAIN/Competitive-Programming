#include <bits/stdc++.h>

int main() {
    int N;
    std::vector<std::pair<std::string,int>> save;
    std::cin >> N;
    
    int x;
    std::string name;
    for (int i=0;i<N;i++) {
        std::cin >> name;
        std::cin >> x;
        save.push_back({name,x});
    }
    
    int max = 0;
    std::string str;
    for (int i=0;i<save.size();i++) {
        if (save[i].second > max) {
            max = save[i].second;
            str = save[i].first;
        }
    }std::cout << str;
    return 0;
}