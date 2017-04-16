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
#include <ctime>
 
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

int N, M;   // Number of vertices and edges
vector<pair<pii,int> > al;  // List of all the edges
int dst[1000005];    // Storing minimum distance to all vertices

void shortestPath(int source)
{
    for (int i = 0; i < N; i++)
        dst[i] = INF;
    dst[source] = 0;
 
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int u = al[j].F.F;
            int v = al[j].F.S;
            int cost = al[j].S;
            if (dst[u] != INF && dst[u] + cost < dst[v])
                dst[v] = dst[u] + cost;
        }
    }
}

int main()
{
    srand(time(NULL));
    for(int i = 1;i <= 500000;i*=5) {
        for(int j = 1;j <= 500000;j*=5) {
            al.clear();
            N = i;
            M = j;
            for(int k =0;k<j;k++) {
                al.pb(mp(mp(rand()%i,rand()%i),rand()%10000 - 5000));
            }
            clock_t begin = clock();
            shortestPath(rand()%i);
            clock_t end = clock();
            cout << "Time Taken: (" << i*j << "): " << ((double)((double)(end-begin))/CLOCKS_PER_SEC) << " sec" << endl;
        }
    }
 
    return 0;
}