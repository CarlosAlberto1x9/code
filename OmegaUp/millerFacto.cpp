#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstring>
#include <cassert>

using namespace std;

typedef long double dbl;

const int N=2e6+10;

int np, prime[N];
bool isp[N];

void sieve(int N) {
    memset(isp, true, sizeof isp);
    isp[0] = isp[1] = false;
    for(int i=2; i<N; i++) if(isp[i]) {
        prime[++np]=i;
        for(int j=2*i; j<N; j+=i) {
            isp[j]=false;
        }
    }
}

int mul(int a, int b, int m) {
    a%=m; if(a<0) a+=m;
    b%=m; if(b<0) b+=m;
    int q = ((dbl)a * (dbl)b) / (dbl)m;
    int r = a*b - q*m;
    return (r<0 ? r+m:r);
}

int pwr(int a, int n, int m) {
    int ans(1);
    while(n) {
        if(n & 1) ans = mul(ans, a, m);
        if(n >>= 1) a = mul(a, a, m);
    }
    return ans%m;
}

int myrand(int n) {
    return rand()%n*rand()%n*rand()%n;
}

bool ispmiller(int p) { // O(30*logp)
    if(p<2) return false;
    if(p==2) return true;
    if(p%2==0) return false;
    int s=p-1; s>>=__builtin_ctzll(s);
    for(int i=0; i<60; i++) {
        int val=pwr(myrand(p-1)+1,s,p), temp=s;
        while(temp!=p-1 and 1<val and val<p-1) {
            val=mul(val,val,p);
            temp<<=1;
        }
        if(val!=p-1 and temp%2==0) return false;
    }
    return true;
}

int pollardrho(int n) { // O(n^0.25)
    if(n==1) return 1;
    if(n%2==0) return 2;
    int c=myrand(n-1)+1, x=myrand(n-2)+2, y=x;
    int d=1; while(d==1) {
        x=mul(x,x,n)+c; if(x>=n) x-=n;
        y=mul(y,y,n)+c; if(y>=n) y-=n;
        y=mul(y,y,n)+c; if(y>=n) y-=n;
        d=__gcd(abs(x-y),n);
        if(d==n) return (ispmiller(n) ? n:pollardrho(n));
    }
    return d;
}

int main() 
{
    int z, n;

    cin >> z;

    sieve(1e6);

    vector<int> factors;

    for (int w=0;w<z;++w)
    {
        cin >> n;
        if(ispmiller(n)) {
            cout << n << '\n';
            continue;
        }

        factors.clear();

        for(int i=1; i<=np and prime[i]*prime[i]<=n; i++) {
            if(n%prime[i]==0) {
                while(n%prime[i]==0) {
                    n /= prime[i];
                    factors.push_back(prime[i]);
                }
            }
        }

        if(ispmiller(n)) {
            factors.push_back(n);
        }
        else if(n>1) { 
            int x = pollardrho(n);
            //assert(x > 1e6); could fail
            factors.push_back(x);
            factors.push_back(n/x);
        }

        sort(factors.begin(),factors.end());

        for(int i=0; i<(int)factors.size()-1; i++) 
            cout << factors[i] << ' ';
        cout << (factors.empty() ? 1 : factors.back()) << '\n';
    }    

    return 0;
}