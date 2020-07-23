#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    //    cin >> n;
    //    cin >> m;
    cin >> n;
    vector<int> ch2;
    int b = n;
    b = n;
    while (b != 0) {
        ch2.push_back(b % 2);
        b = b / 2;
    }
    for (int i = 0; i < ch2.size(); i++) {
        cout << ch2[i];
    }
    cout << endl;
    reverse(ch2.begin(), ch2.end());

    for (int i = 0; i < ch2.size(); i++) {
        cout << ch2[i];
    }
    cout << endl;
    int z = 0, nn = 0;
    for (int l = ch2.size() - 1; l >= 0; --l) {
        nn = nn + ch2[l] * pow(10, z);
        z++;
    }
    cout << nn << endl;
    int result = nn;
    result = result & 0377;
    cout << result << endl;
    result = result ^ 0125;
    cout << result << endl;
    if (nn < 0) {
        result = result ^ 037777777400;
    }
    cout << result << endl;

}