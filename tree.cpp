#include <iostream>
#include <string>

using namespace std;


class Node {
public:
  int data;
  Node * left;
  Node * right;
  Node() {
    data = 1;
    left = NULL;
    right = NULL;
  };
};


class Tree {
private:
  Node * Root;
  int count;
public:
  Tree();
  int size() const;
  bool isEmpty() const;
  Node * createNode(int val);
  Node * insertLeft(Node * root, int val);
  Node * insertRight(Node * root, int val);
};

Tree::Tree() {
  // Root = NULL;
  count = 0;
}

int Tree::size() const {
  return count;
}

bool Tree::isEmpty() const {
  if (size() == 0) {
    return true;
  }
  return false;
}

Node * Tree::createNode(int val) {
  Node * newNode = new Node;
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node * Tree::insertLeft(Node * root, int val) {
  Node* newNode = createNode(val);
  root->left = newNode;
  count++;
  return newNode;
}

Node * Tree::insertRight(Node * root, int val) {
  Node * newNode = createNode(val);
  root->right = newNode;
  count++;
  return newNode;
}


int main() {
  Tree myTree;
  Node * root = myTree.createNode(1);
  Node * markOriginal = root; // use this to go back to the first root
  myTree.insertLeft(root,2);
  myTree.insertRight(root,22);
  root = root->left;
  myTree.insertLeft(root,33);
  myTree.insertRight(root,44);
  root = markOriginal;
  cout << root->right->data << endl;

}
