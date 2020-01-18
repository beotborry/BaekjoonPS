#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	//preprocessing
	memset(isPrime, true, sizeof(isPrime));
	
	for (int i = 3; i <= 1000000; i += 2) {
		if(isPrime[i] == false)
			continue;
		for (int multiply = 3; i * multiply <= 1000000; multiply += 2) {
			isPrime[i * multiply] = false;
		}
	}
	
	while(cin >> n) {
		if(n == 0)
			break;
		for (int a = 3; a <= 100000; a += 2) {
			if(isPrime[a] == false)
				continue;
			else if(isPrime[a] == true) {
				int b = n - a;
				if(isPrime[b] == false)
					continue;
				else {
					cout << n << " = " << a << " + " << b << "\n";
					break;
				}
			}
		}
	}
}