#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define MAX_QUEUE_SIZE 100
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

typedef int element;

int is_empty_() {
	return (front == rear);
}

int is_full() {
	return (rear == (MAX_QUEUE_SIZE - 1));
}

void push(element e) {
	if (is_full()) {
		fprintf(stderr, "큐가 포화상태입니다.\n");
		return;
	}
	else {
		queue[++rear] = e;
	}
}

int size() {
	return (rear - front);
}

int pop() {
	if (is_empty_()) {
		return -1;
	}
	else return queue[++front];
}

int front_() {
	if (is_empty_()) {
		return -1;
	}
	int item = queue[++front];
	front--;
	return item;
}

int rear_() {
	if (is_empty_()) {
		return -1;
	}
	else return queue[rear];
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
			cout << pop() << endl;
		}
		else if (order == "size") {
			cout << size() << endl;
		}
		else if (order == "empty") {
			cout << is_empty_() << endl;
		}
		else if (order == "front") {
			cout << front_() << endl;
		}
		else if (order == "back") {
			cout << rear_() << endl;
		}

	}
}
