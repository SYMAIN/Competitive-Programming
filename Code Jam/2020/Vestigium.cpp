#include <iostream>
#include <set>
#include <vector>

int main() {
    int X, N;
    std::cin >> X;
    for (int i = 0; i < X; i++) {
        int ROW = 0, COL = 0, trace = 0;
        std::cin >> N;
        int a,x=0,y=0;
        std::vector<std::set<int>> col(N);
        std::vector<bool> _col(N);
        for (int j = 0; j < N; j++) {
            std::set<int> row;
            bool _row = 0;
            for (int k = 0; k < N; k++) {
                std::cin >> a;
                if (row.find(a) != row.end() && !_row){
                    ROW++;
                    _row = 1;
                }
                else {
                    row.insert(a);
                }

                if (col[k].find(a) != col[k].end() && !_col[k]) {
                    COL++;
                    _col[k] = 1;
                }
                else {
                    col[k].insert(a);
                }

                if (x == j && y == k) {
                    trace += a;
                    x++;
                    y++;
                }
            }
        }

        std::cout << "Case #" << i + 1 << ": " << trace << " " << ROW << " " << COL << "\n";

    }
}