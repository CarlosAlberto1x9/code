#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    cin >> m;
    int b[m];
    for(int i=0; i<m; ++i) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int i=0, j=0;
    int ans = 0;
    while(i<n && j<m) {
        if ( abs(a[i]-b[j]) <= 1 ) {
            ans++;
            i++; j++;
        } else {
            if( a[i] < b[j] ) i++; 
            else j++;
        }
    }
    cout << ans << '\n';
    return 0;
}