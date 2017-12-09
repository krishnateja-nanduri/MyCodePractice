//https://www.hackerrank.com/challenges/swap-nodes-algo/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
 int data;
 public:
 Node * children[2];
 Node();
 Node(int);
 ~Node();
 void setData(int);
 int getData();
};

Node::Node(){
 children[0] = NULL;
 children[1] = NULL;
}

Node::Node(int _data){
 data = _data;
 children[0] = NULL;
 children[1] = NULL;
}

Node::~Node(){
 for(int i = 0; i < 2; i++){
  if(children[i] != NULL){
   delete(children[i]);
  }
  children[i] = NULL;
 }
}

void Node::setData(int _data){
 data = _data;
}

int Node::getData(){
 return data;
}

class Tree {
 Node * root;
 void swapNodesLevel(Node **,int,int);
 void printPreorder(Node *);
 void printInOrder(Node *);
 public:
 Tree();
 void addChildPair(int,int,int);
 void print();
 void swapNodes(int);
};

Tree::Tree(){
 root = new Node(1);
}

void Tree::addChildPair(int left, int right, int pos){
 vector<Node *> queue;
 Node * ptr;
 queue.push_back(root);
 while(queue.size() > 0){
  ptr = queue[0];
  if(pos == 0){
   if(left == -1){
    ptr->children[0] = NULL;
   } else {
    ptr->children[0] = new Node(left);
   }
   if(right == -1){
    ptr->children[1] = NULL;
   } else {
    ptr->children[1] = new Node(right);
   }
   break;
  }
  queue.erase(queue.begin());
  for(int i = 0; i < 2; i++){
   if(ptr->children[i] != NULL){
    queue.push_back(ptr->children[i]);
   }
  }
  pos--;
 }
 
}

void Tree::print(){
 printInOrder(root);
 cout << endl;
}

void Tree::printPreorder(Node * ptr){
 cout << ptr->getData() << " ";
 if(ptr->children[0] != NULL){
  printPreorder(ptr->children[0]);
 }
 if(ptr->children[1] != NULL){
  printPreorder(ptr->children[1]);
 }
}

void Tree::printInOrder(Node * ptr){
 if(ptr->children[0] != NULL){
  printInOrder(ptr->children[0]);
 }
 cout << ptr->getData() << " ";
 if(ptr->children[1] != NULL){
  printInOrder(ptr->children[1]);
 }
}

void Tree::swapNodes(int depth){
 swapNodesLevel(&root,depth,1);
}

void Tree::swapNodesLevel(Node ** ptr,int depth,int current){
 if(current % depth == 0){
  Node * temp = (*ptr)->children[0];
  (*ptr)->children[0] = (*ptr)->children[1];
  (*ptr)->children[1] = temp;
 }
 for(int i = 0; i < 2; i++){
  if((*ptr)->children[i] != NULL){
   swapNodesLevel(&((*ptr)->children[i]),depth,current+1);
  }
 }
}

int main() {
 int nodes; cin >> nodes;
 int a, b;
 Tree * mytree = new Tree();
 for(int i = 0; i < nodes; i++){
  cin >> a >> b;
  mytree->addChildPair(a,b,i);
 }
 cin >> a;
 while(a--){
  cin >> b;
  mytree->swapNodes(b);
  mytree->print();
 }
    return 0;
}
