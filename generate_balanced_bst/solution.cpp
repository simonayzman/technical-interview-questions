#include <iostream>
#include <vector>

using namespace std;

// This implementation of a binary tree DOES use 
// "nodes" (and therefore has a "root" pointer)
template<class T>
class Tree {
public:
   void createTree(const vector<T>& sortedVec);
private:

   struct TreeNode
   {
      T data;
      TreeNode<T>* right;
      TreeNode<T>* left;      
   };

   TreeNode<T>* root;

   void createTree(TreeNode<T>*& treeNode, const vector<T>& sortedVec, int start, int end);

   /* Other possible implementation that returns "updated" tree! 
   Note the new return type (TreeNode<T>*) and changed first parameter (no &)

   TreeNode<T>* createTree(TreeNode<T>* treeNode, const vector<T>& sortedVec, int start, int end);
   
   */

};

template <class T>
void Tree<T>::createTree(const vector<T>& sortedVec) 
{
   // Shortcut case; if the tree has data, abort the operation
   // The tree must be empty in order to be generated with a sorted vector
   if(root != NULL)
   {
      return;
   }

   // Kick off the initial call to the recursive helper
   createTree(root, sortedVec, 0, sortedVec.size()-1);

   /* Code using other implementation of createTree()
   
   root = createTree(root, sortedVector, 0, sortedVec.size()-1);
   
   */
}

template <class T>
void Tree<T>::createTree(TreeNode<T>*& treeNode, const vector<T>& sortedVec, int start, int end) 
{
   // Base case when the start and end have crossed (because of mid +/- 1 in the recursive calls)
   if(end < start)
   {
      return;
   }
   
   else 
   {
      int mid = (end + start) / 2;
       
      TreeNode<T>* treeNode = new TreeNode<T>;
      treeNode->data = sortedVec[mid];

      createTree(treeNode->left, sortedVec, start, mid - 1);
      createTree(treeNode->right, sortedVec, mid + 1, end);
   }
}

/*
Other possible implementation of createTree that returns "updated tree"

template <class T>
TreeNode<T>* Tree<T>::createTree(TreeNode<T>* treeNode, const vector<T>& sortedVec, int start, int end) 
{
   // Base case when the start and end have crossed (because of mid +/- 1 in the recursive calls)
   if(end < start)
   {
      return NULL;
   }
   
   else 
   {
      int mid = (end + start) / 2;
       
      TreeNode<T>* treeNode = new TreeNode<T>;
      treeNode->data = sortedVec[mid];

      treeNode->left = createTree(treeNode->left, sortedVec, start, mid - 1);
      treeNode->right = createTree(treeNode->right, sortedVec, mid + 1, end);\

      return treeNode;
   }
}
*/
