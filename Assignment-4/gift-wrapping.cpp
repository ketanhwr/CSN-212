#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
 
using namespace std;
 
#define endl '\n'
#define MOD 1000000007ULL
#define INF 1000000000
#define eps 1e-8
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(X) cerr << " --> " << #X << " = " << X << endl
#define sd(x) scanf("%d",&(x))
#define slld(x) scanf("%lld",&(x))
#define pd(x) printf("%d\n",(x))
#define plld(x) printf("%lld\n",(x))
#define gcd __gcd
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef vector< vector<int> > vvi;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
class Coord {
    public:
        int x, y;

        bool operator < (Coord b) {
            if (y != b.y)
                return y < b.y;
            return x < b.x;
        }
};

int helper(Coord p, Coord q, Coord r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(Coord array[], int n)
{
    if (n < 3)
        return;
 
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (array[i].x < array[l].x)
            l = i;

    int p = l, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (helper(array[p], array[i], array[q]) == 2)
                q = i;
        next[p] = q;
        p = q;
    } while (p != l);

    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
            cout << "(" << array[i].x << ", " << array[i].y << ")\n";
    }
}

int main()
{
    Coord array[] = {{5, 5}, {1, 2}, {0, 1}, {3, -1}, {-5, -5}, {1, 1}};
    int n = sizeof(array) / sizeof(array[0]);
    convexHull(array, n);
    return 0;
}