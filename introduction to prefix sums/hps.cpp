#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    int n;
    fin >> n;

    char temp;
    int h[n+1], p[n+1], s[n+1];
    h[0] = p[0] = s[0] = 0;
    for (int i = 1; i <= n ; i++) {
        fin >> temp;
        h[i] = h[i-1];
        p[i] = p[i-1];
        s[i] = s[i-1];
        if (temp == 'H') {
            p[i]++;
        } else if (temp == 'P') {
            s[i]++;
        } else {
            h[i]++;
        }
    }

    int perms[6];
    for (int i = 0; i < 6; i++) {
        perms[i] = 0;
    }
    for (int i = 0; i <= n ; i++) {
        perms[0] = max(perms[0], p[n] - p[i] + h[i]);
        perms[1] = max(perms[1], s[n] - s[i] + h[i]);
        perms[2] = max(perms[2], s[n] - s[i] + p[i]);
        perms[3] = max(perms[3], h[n] - h[i] + p[i]);
        perms[4] = max(perms[4], h[n] - h[i] + s[i]);
        perms[5] = max(perms[5], p[n] - p[i] + s[i]);
    }

    int result = 0;
    for (int i = 0; i < 6 ; i++) {
        result = max(result, perms[i]);
    }
    
    fout << result << '\n';
    return 0;
}