#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long N, M; cin >> N >> M;
	cout << ((N > M) ? N - M : M - N);
}