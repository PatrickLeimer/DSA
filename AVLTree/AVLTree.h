//
// Created by Patrick on 2/14/2025.
//

#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool inputValidation(const string& ID, const string& name);

struct TreeNode {
    int h;
    string name;
    string id;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(const string& NAME, const string& ID);
    ~TreeNode();

};

struct AVLTree {
    TreeNode* root;
    //Constructor and destructor
    AVLTree();
    ~AVLTree();
    //--------------------------

   TreeNode* insertNAMEID(TreeNode* root, string name, string id);
   TreeNode* removeID(TreeNode* r, const string& ID);
   TreeNode* searchID(TreeNode* r, const string& ID);
   TreeNode* searchName(TreeNode* r, const string &NAME);
    //-------------------------------------------------------------------------------

   //Printing in different orders
   void printInOrder(TreeNode* r);
   void printPreorder(TreeNode* r);
   void printPostorder(TreeNode* r);
   void printLevelCount(TreeNode* r);

    //--------------------------------------------------------------------------------

   TreeNode* removeInOrderN(TreeNode* r, int N);

};

void gatherInOrder(TreeNode* r, vector<string>& list);

#endif //AVLTREE_H
