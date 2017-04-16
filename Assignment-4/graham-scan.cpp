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

Coord pivot;

int helper(Coord a, Coord b, Coord c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

int dist(Coord a, Coord b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool polar_order(Coord a, Coord b)  {
    int order = helper(pivot, a, b);
    if (order == 0)
        return dist(pivot, a) < dist(pivot, b);
    return (order == -1);
}

int main()  {
    Coord array[] = {{5, 5}, {1, 2}, {0, 1}, {3, -1}, {-5, -5}, {1, 1}};
    int N = sizeof(array)/sizeof(array[0]);

    stack<Coord> hull;

    if (N >= 3) {
	    int leastY = 0;
	    for (int i = 1; i < N; i++)
	        if (array[i] < array[leastY])
	            leastY = i;

	    Coord temp = array[0];
	    array[0] = array[leastY];
	    array[leastY] = temp;

	    pivot = array[0];
	    sort(array + 1, array + N, polar_order);

	    hull.push(array[0]);
	    hull.push(array[1]);
	    hull.push(array[2]);

	    for (int i = 3; i < N; i++) {
	        Coord top = hull.top();
	        hull.pop();
	        while (helper(hull.top(), top, array[i]) != -1)   {
	            top = hull.top();
	            hull.pop();
	        }
	        hull.push(top);
	        hull.push(array[i]);
	    }
	}

    while (!hull.empty())   {
        Coord p = hull.top();
        hull.pop();

        printf("(%d, %d)\n", p.x, p.y);
    }

    return 0;
}