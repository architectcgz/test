#define OK 0
#define OVERFLOW -1
#define MAXSIZE 10
#define ERROR -2
#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

//操作有初始化、清空链表、
class LinkNode {
private:
	string name;
	int age;
	double score;
	
public:
	LinkNode* next;
	LinkNode();
	~LinkNode() ;
	void setNode(string Name, int Age, double Score);
	LinkNode* getNext();
	void setNext(LinkNode* B);
	void showNode();
};
LinkNode::LinkNode() {
	this->age = 0;
	this->name = "";
	this->score = 0.0;
};
void LinkNode::showNode() {
	cout << "name: " << name << " age: " << age << " score: " << score<<endl;
}
void LinkNode::setNode(string Name, int Age, double Score) {
	this->name = Name;
	this->age = Age;
	this->score = Score;
}

LinkNode::~LinkNode(){
	
}
void LinkNode::setNext( LinkNode*B) {
	this->next = B;
}
LinkNode* LinkNode::getNext() {
	return this->next;
}
class LinkList {
private:
	LinkNode* head;
	int NodeNum;
public:
	LinkList();
	~LinkList();
	int  createLinkList(int n);
	bool isEmpty();
	void clearList();
	int addNode(int i);
	int deleteNode(int i);
	void display();
};
//初始化链表 给头结点申请空间，将头结点next域置空
// initial the list ,apply space for the head node , make it null for the node'next
LinkList::LinkList() {
	this->head = new LinkNode;
	this->head->next = NULL;
	NodeNum = 0;
}
//judge whether the list is empty
bool LinkList::isEmpty() {
	if (NodeNum == 0) return true;
	else return false;
}
//clear a list
void LinkList::clearList() {
	NodeNum = 0;
	head->setNext(NULL);
}
//destroy a list
LinkList::~LinkList() {
	delete head;
}
//create a list
int LinkList::createLinkList(int n) {
	LinkNode *newNodes = new LinkNode[n];
	if (!newNodes)return OVERFLOW;
	this->NodeNum = n;
	string name;
	int age;
	double score;
	cout << "input the information of each student : \n";
	cout << "Example: Jack 18 98.5 \n";
	for (int i = 0; i < n; ++i) {
		cin >> name >> age >> score;
		newNodes[i].setNode(name, age, score);
	}
	//this->head->next = &newNodes[0];
	this->head->setNext(&newNodes[0]);
	for (int i = 0; i < n-1 ; ++i) {
		//newNodes[i].next = &newNodes[i + 1];
		newNodes[i].setNext(&newNodes[i + 1]);
	}
	newNodes[n - 1].next = NULL;
	//newNodes[n - 1].setNext(NULL);
}

//添加结点 12345 比如添加在3的位置
int LinkList::addNode(int n) {
	if (n < 1||n>NodeNum)return ERROR;
	LinkNode* a = new LinkNode;
	cout << "input the information of the new student : \n";
	cout << "Example: Jack 18 98.5 \n";
	string name; int age; double grade;
	cin >> name >> age >> grade;
	a->setNode(name, age, grade);
	LinkNode* p = this->head->getNext();//now the pointer is pointing at the first node
	for (int i = 1; i <= n - 1; ++i) {// move the pointer to the front where we want to delete
		//p->next = p->next;
		p->setNext(p->getNext());
	}
	//a->next = p->next;
	//p->next = a;
	a->setNext(p->getNext());
	p->setNext(a);
	this->NodeNum++;
}
//delete example 1234 3
int LinkList::deleteNode(int i) {
	LinkNode* p = this->head->getNext();//now the pointer is pointing at the first node
	for (int i = 1; i <= i - 1; ++i) {// move the pointer to the front where we want to delete
		//p->next = p->next;
		p->setNext(p->getNext());
	}
	//p->next = p->next->next;
	p->setNext(p->getNext()->getNext());
	this->NodeNum--;
	return OK;
}
void LinkList::display() {
	if (NodeNum == 0 ) {
		cout << "there's no data!!";
		return;
	}
	LinkNode* p = this->head;
	if (!p->getNext()) {
		cout << "there's no data!!";
		return;
	}
	while (p->getNext()) {
		p = p->getNext();
		p->showNode();
	}
}
// Jack 18 98.5 Maron 19 89 Nick 20 98 

int main(int argc, char* argv[]) {
	LinkList L;
	L.createLinkList(3);
	L.display();
	cout << endl;
	L.addNode(2);//Rick 60 99
	L.display();
	cout << endl;
	L.deleteNode(2);
	L.display();
	L.clearList();
	cout << endl;
	L.display();

}