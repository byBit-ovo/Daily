#include<iostream>

struct Node {
	int val;
	Node* next;
	Node(int v):val(v){}
};

Node* remove_nth(Node* head, int nth) {
	// 1 2 3 4 5 6 
	Node* dummy = new Node(0);
	dummy->next = head;
	Node *fast = dummy;
	Node* slow = fast;
	for(int i=0;i<nth+1;i++) {
		fast = fast->next;
	}
	while(fast != nullptr){
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	return dummy->next;

}
#include <list>
int main() {
	int n,nth;
	std::cin>>n>>nth;
	std::list<int> ls1{1,2,3};
	std::list<int> ls2{4,5,6,7};
	std::list<int> ls3;
	auto it1 = ls1.begin();
	auto it2 = ls2.begin();
	while(it1 != ls1.end() && it2 != ls2.end()) {
		ls3.push_back(*it1);
		it1++;
		ls3.push_back(*it2);
		it2++;
	}
	while(it1 != ls1.end()) {
		ls3.push_back(*it1);
		it1++;
	}
	while(it2 != ls2.end()) {
		ls3.push_back(*it2);
		it2++;
	}
	for(auto it = ls3.begin();it != ls3.end();++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return 0;
}