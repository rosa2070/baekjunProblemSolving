#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;

typedef int element;

int is_empty_() {
	return (top == -1);
}

int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element e) {
	if (is_full()) {
		fprintf(stderr, "스택이 포화상태입니다.\n");
		return;
	}
	else {
		stack[++top] = e;
	}
}

int size() {
	return top + 1;
}

int pop() {
	if (is_empty_()) {
		return -1;
	}
	else return stack[top--];
}

int top_() {
	if (is_empty_()) {
		return -1;
	}
	else return stack[top];
}

int main() {
	int orderNum; // 명령 갯수
	cin >> orderNum;

	for (int i = 0; i < orderNum; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int element;
			cin >> element; // push되는 원소
			push(element);
		}
		else if (order == "pop") {
			cout << pop()<< endl;
		}
		else if (order == "size") {
			cout << size() << endl;
		}
		else if (order == "empty") {
			cout << is_empty_() << endl;
		}
		else if (order == "top") {
			cout << top_() << endl;
		}
	}
}
