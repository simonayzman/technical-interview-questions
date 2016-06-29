#include <iostream>
#include <cmath>
using namespace std;

// This implementation of a binary tree does NOT use "nodes" (and therefore has no "root" pointer)
// Instead, the Tree itself contains data, and holds pointers to its children (other Trees)
template<class ItemType>
class Tree {
 private:
   Tree<ItemType>* left;
   Tree<ItemType>* right;
   ItemType data;   
   
 public: 
   Tree(ItemType _data) : left(NULL), right(NULL), data(_data) {}
   
   bool isBalanced()
   {   
      // Base case when the current tree is a leaf (no children)
      if(left == NULL && right == NULL) 
      {
         return true; 
      }

      // Case when the current tree only has one child
      // Note that, in order for this current tree to be balanced, if one 
      // child is NULL, then the other child must be a leaf (aka, 0 height)
      else if(left == NULL && right != NULL)
      {
         return right->height() == 0; 
      }
      else if(right == NULL && left != NULL)
      {
         return left->height() == 0;  
      }
      
      // Case when the current tree has both children
      else 
      {
         bool bothChildrenAreBalanced = left->isBalanced() && right->isBalanced();
         bool differenceInChildrensHeightDoesNotExceed1 = abs(left->height() - right->height()) <= 1;
         return bothChildrenAreBalanced && differenceInChildrenHeightDoesNotExceed1; // this logically flows from the definition!
      }
   }
   
   // It was necessary to write the height function because the definition
   // of a balanced tree requires knowing the height (of its children)
   int height()
   {
      // Base case; the current tree is a leaf node (no children)
      // By definition, the height of a leaf node is 0.
      if(left == NULL && right == NULL)
      {
         return 0;
      }
      
      // Cases when the current tree has only one child
      // Only necessary to recurse downward in one direction
      else if(left == NULL && right != NULL)
      {
         return 1 + right->height();
      }
      else if(right == NULL && left != NULL)
      {
         return 1 + left->height();
      }

      // Case when the current tree has both children
      // Necessary to find the maximum between your children's heights
      else 
      {
         return 1 + max(right->height(), left->height());
      }
   }
};

