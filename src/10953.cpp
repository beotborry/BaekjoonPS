#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T;
	while(T--) {
		string order; cin >> order;
		int a, b;
		a = order[0] - '0';
		b = order[2] - '0';
		cout << a + b << "\n";
	}
}