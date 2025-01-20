#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;

    long long x, n;
    while (t--) {
        cin >> x >> n;

        long long result = x;
        if (x % 2 == 0) {

            if (n % 4 == 1) result -= n;
            else if (n % 4 == 2) result += 1;
            else if (n % 4 == 3) result += (n + 1);

        } 
        else {

            if (n % 4 == 1) result += n;
            else if (n % 4 == 2) result -= 1;
            else if (n % 4 == 3) result -= (n + 1);

        }

        cout << result << endl;
    }
}
