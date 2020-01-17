#include <iostream>
#include <cstring>
using namespace std;

class queue{
public:
	void push(int x) {
		arr[back++] = x;
		back %= 2000000;
		size += 1;
	}
	int pop() {
		if(size == 0)
			return -1;
		int ret = arr[front];
		front = (front + 1) % 2000000;
		size -= 1;
		return ret;
	}
	int getSize(){
		return size;
	}
	bool isEmpty() {
		return (size == 0) ? true : false;
	}
	int getFront() {
		return (size == 0) ? -1 : arr[front];
	}
	int getBack() {
		if(size == 0)
			return -1;
		return (back == 0) ? arr[1999999] : arr[back - 1];
	}
private:
	int arr[2000000];
	int size = 0;
	int front = 0, back = 0;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N; cin >> N;
	queue q;
	while(N--) {
		string order; cin >> order;
		if(order == "push") {
			int x; cin >> x;
			q.push(x);
		} else if(order == "pop")
			cout << q.pop() << "\n";
		else if(order == "front")
			cout << q.getFront() << "\n";
		else if(order == "back")
			cout << q.getBack() << "\n"; 
		else if(order == "size")
			cout << q.getSize() << "\n";
		else if(order == "empty")
			cout << q.isEmpty() << "\n";
	}
}