#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
} 

int main()
{
    int top, bottom;
    cin >> top;
    cin >> bottom;
    if (top % bottom == 0){
        cout << top / bottom;
    }else{
        int whole = 0;
        int temp = gcd(top, bottom);
        if (top > bottom){
            whole = top / bottom;
            top = top % bottom;
        }
        if (top % temp == 0 && bottom % temp == 0){
            top = top / temp;
            bottom = bottom / temp;
        }
        if (whole == 0){
            cout << top << "/" << bottom;
        }else{
            cout << whole << " " << top << "/" << bottom;
        }
    }
    return 0;
}