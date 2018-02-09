/*

Name: Tree.h

Creator: Adam Hock

Date Started: 12/19/2017

Description: This header was created to help me practice the data structures
I learned in my C++ class that I took in the spring of 2017. The headers are
not mine. I used the header files created by my professor, Dennis 
Castleberry, to practice implementing some basic functions with this data 
structure. Methods that I have modified or created from scratch are denoted 
by a comment as the first line of said functions. The link to the original 
header files can be found here.

https://github.com/dcastl2/advanced-cpp/tree/master/notes/data

*/


#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <utility>
class TreeNode {
  private:
    int key;
    TreeNode *left;
    TreeNode *right;

  public:
    TreeNode(int key);
    void insert(int key);
    void preOrder();
    void inOrder();
    void postOrder();
    /*The following methods were created by Adam Hock.*/
    int  size();
    int  height();
    void reverse();
};

class Tree {
  private:
    TreeNode *root;
  public:
    Tree();
    Tree(int *a, int n);
    void insert(int key);
    void preOrder();
    void inOrder();
    void postOrder();
    /*The following methods were created by Adam Hock.*/
    int  size();
    int  height();
    void reverse();
};

TreeNode::TreeNode(int key) {
  this->key = key;
  left = right = NULL;
}

void TreeNode::insert(int key) {
  if (key <= this->key) 
    if (left)   left->insert(key);
    else        left = new TreeNode(key);
  else 
    if (right) right->insert(key);
    else       right = new TreeNode(key);
}

void TreeNode::inOrder() {
  if (left)  left->inOrder();
  std::cout << key << "\t";
  if (right) right->inOrder();
}

void TreeNode::preOrder() {
  std::cout << key << "\t";
  if (left)  left->preOrder();
  if (right) right->preOrder();
}

void TreeNode::postOrder() {
  if (left)  left->postOrder();
  if (right) right->postOrder();
  std::cout << key << "\t";
}

int TreeNode::size() {
    /*This method was written by Adam Hock. It returns the size of the tree by
     counting the number of nodes in the tree. */
  return 1 + (left  ? left->size()  : 0)
           + (right ? right->size() : 0);
}

int TreeNode::height() {
    /*This method was written by Adam Hock. It returns the height of the tree
      recursively from the root to the lowest possible branch. */
  return 1 + std::max(
                 (left  ? left->height()  : 0),
                 (right ? right->height() : 0)
                );
}

void TreeNode::reverse() {
    /*This method was written by Adam Hock. It returns the reverse of the 
      tree recursively. */
    if (left)
        left->reverse();
    if (right)
        right->reverse();
    std::swap(left, right);
}

Tree::Tree() {
  root = NULL;
}

Tree::Tree(int *a, int n) {
  int i;
  root = new TreeNode(a[0]);
  for (i=1; i<n; i++)
    root->insert(a[i]);
}

void Tree::insert(int key) {
  if (root) root->insert(key);
  else      root = new TreeNode(key);
}

void Tree::inOrder() {
  if (root) root->inOrder();
  std::cout << std::endl;
}

void Tree::preOrder() {
  if (root) root->preOrder();
  std::cout << std::endl;
}

void Tree::postOrder() {
  if (root) root->postOrder();
  std::cout << std::endl;
}

int Tree::size() {
  if (!root) return 0;
  return root->size();
}

int Tree::height() {
  if (!root) return 0;
  return root->height();
}

void Tree::reverse() {
    if (root) root->reverse();
    std::cout << std::endl;
}

#endif


/* TREE_H */

