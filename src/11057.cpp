#include <iostream>
using namespace std;

int N;
long long cache[1001][10];
int mod = 10007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	
	for (int e = 0; e <= 9; e++)
		cache[1][e] = 1;
	
	for (int length = 1; length <= N; length++) {
		for (int endNum = 0; endNum <= 9; endNum++) {
			for (int curr = 0; curr <= endNum; curr++) {
				cache[length][endNum] += cache[length - 1][curr];
				cache[length][endNum] %= mod;
			}
		}
	}
	
	long long res = 0;
	for (int i = 0; i <= 9; i++)
		res += cache[N][i];
	cout << res % mod << endl;
	
}