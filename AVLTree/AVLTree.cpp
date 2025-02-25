//
// Created by Patrick on 2/14/2025.
//

#include "AVLTree.h"
#include <string>
#include <iostream>
#include <regex>

using namespace std;

// Constructors and Destructors -----------------------------------------------

TreeNode::TreeNode() : h(1), name(""), id(""), left(nullptr), right(nullptr) {};
TreeNode::TreeNode(const string& NAME, const string& ID): h(1), name(NAME), id(ID), left(nullptr), right(nullptr) {}

TreeNode::~TreeNode() {
    // cout << "Destroying node (" << name << ", " << id << ")\n"; for testing purposes
};

AVLTree::AVLTree() : root(nullptr) {};

// Deletion helper function
void freeMem(TreeNode* r) {
    if (!r) return;
    freeMem(r->left);
    freeMem(r->right);
    delete r;
}

AVLTree::~AVLTree() {
    freeMem(root);
    root = nullptr;

};

//------------------------------------------------------------

// Helper functions -------------------------------------------
bool inputValidation(const string& ID, const string& name) {

    // Check that every character in id is a digit.
    for (char c : ID) {
        if (!isdigit(c)) {
            return false;
        }
    }

    //check that it is 8 digits and search that is unique
    if (ID.length() != 8 || ID.empty()) {
        return false;
    }

    // search to check for repeated values -> done in the insert

    //check with regex that the name matches the specifications
    regex pattern("^[A-Za-z\\s]+$");
    if (!(regex_match(name, pattern))) {
        return false;
    }

    return true;
}

int getBalanceFactor(TreeNode* node) {
    if (node == nullptr) return 0;
    int l = (node->left)  ? node->left->h  : 0;
    int r = (node->right) ? node->right->h : 0;

    return l - r;
}

bool fixHeight(TreeNode* root) {
    if (root == nullptr) return false;
    root->h =  1 + max(root->left ? root->left->h : 0, root->right ? root->right->h : 0);
    return true;
}

TreeNode* rotateRight(TreeNode* root) {
    TreeNode* x   = root->left;
    TreeNode* B  = x->right;  // B is x’s right subtree

    x->right = root;  // x’s right subtree becomes root
    root->left  = B; // root’s left subtree becomes B

    // Update heights
    fixHeight(root);
    fixHeight(x);

    // x is now root
    return x;
}

TreeNode* rotateLeft(TreeNode* root) {

    TreeNode* x   = root->right;  // x is root’s right child
    TreeNode* B  = x->left;   // B is x’s left subtree

    // Perform rotation
    x->left  = root;
    root->right = B;

    // Update heights
    fixHeight(root);
    fixHeight(x);

    // y is now root of this subtree
    return x;

}

TreeNode* balance(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    fixHeight(root);

    int bf = getBalanceFactor(root);

    if (bf > 1) { // Left heavy
        if (getBalanceFactor(root->left) < 0) { //Left subtree is right heavy
            // LR rotation
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        } else {
            // LL rotation
            root = rotateRight(root);
        }
    }
    else if (bf < -1) { // Right heavy
        if (getBalanceFactor(root->right) > 0) {
            // RL rotation
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        } else {
            // RR rotation
            root = rotateLeft(root);
        }
    }

    fixHeight(root);

    return root;
}

TreeNode* findMin(TreeNode* r) {
    if (r == nullptr || r->left == nullptr) {
        return r;
    }
    return findMin(r->left);
}

void gatherInOrder(TreeNode* r, vector<string>& list) {
    if (r == nullptr) return;
    gatherInOrder(r->left, list);
    list.push_back(r->id);
    gatherInOrder(r->right, list);
}

void collect(TreeNode* node, const string& NAME, vector<string>& matches) {
    if (!node)
        return;
    if (node->name == NAME) {
        matches.push_back(node->id);
    }
    collect(node->left, NAME, matches);
    collect(node->right, NAME, matches);
}

//------------------------------------------------------------

TreeNode* AVLTree::insertNAMEID(TreeNode* r, string name, string id) {
    /*
    * Add a Student object into the tree with the specified name, NAME, and GatorID number, ID.
    * Balance the tree automatically if necessary.
    * The ID must be unique.
    * The ID and NAME must satisfy the constraints stated below.
    * Also, prints “successful” if insertion is successful and prints “unsuccessful” otherwise.
    * NAME identifier will be separated by double inverted commas for parsing, e.g., "Josh Smith."
    */

    // Validate input //Check with regex or check if it's unique id -> searchID(r, id) != nullptr
    if (!(inputValidation(id, name)) || searchID(r, id) != nullptr) {
        cout << "unsuccessful" << searchID(r, id)  << endl;
        return r; // if not validated
    }

    // Insert using recursion
    if (r == nullptr) { // Base case
        r = new TreeNode(name, id); // NOT the default constructor
        cout << "successful" << endl;
        return r;
    } else if (stoi(id) < stoi(r->id)) {
        r->left = insertNAMEID(r->left, name, id);
    } else {
        r->right = insertNAMEID(r->right, name, id);
    }

    // Balance -> height is fixed when balanced
    r = balance(r);

    return r;
}

TreeNode* AVLTree::removeID(TreeNode* r, const string& ID) {
    /*
    Find and remove the account with the specified ID from the tree.
    [Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit]
    If deletion is successful, print ““successful.”
    If the ID does not exist within the tree, print “unsuccessful.”
    You must prioritize replacing a removed node with its inorder successor for the case where the deleted node has two children.
     */

    if (r == nullptr) {
        cout << "unsuccessful" << endl;
        return r;
    } else if (stoi(ID) < stoi(r->id)) {
        r->left = removeID(r->left, ID);
    } else if (stoi(ID) > stoi(r->id)) {
        r->right = removeID(r->right, ID);
    } else {
        if (r->left == nullptr) {
            TreeNode* temp = r->right;
            delete r;
            cout << "successful" << endl;
            return balance(temp);
        } else if (r->right == nullptr) {
            TreeNode* temp = r->left;
            delete r;
            cout << "successful" << endl;
            return balance(temp);
        } else {
            TreeNode* successor = findMin(r->right);
            r->id = successor->id;
            r->name = successor->name;
            r->right = removeID(r->right, successor->id);
        }
    }
    //Balance
    return balance(r);
}

TreeNode* AVLTree::searchID(TreeNode* r, const string& ID) {
    /*
    Search for the student with the specified ID from the tree.
    If the ID was found, print out their NAME.
    If the ID does not exist within the tree, print “unsuccessful.”

     */
    if (r == nullptr || stoi(ID) == stoi(r->id)) {
        if(r != nullptr) {
            cout << r->name << endl;
            return r;
        } else {
            return nullptr;
        }
        return r;
    } else if (stoi(ID) < stoi(r->id)) {
        return searchID(r->left, ID);
    } else {
        return searchID(r->right, ID);
    }


}

TreeNode* AVLTree::searchName(TreeNode* r, const string& NAME) {
    /*
    Search for the student in the tree with the specified name, NAME.
    If the student's name was found, print the associated ID.
    If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
    If the name does not exist within the tree, print “unsuccessful.”
    NAME identifier will be surrounded by double quotes for parsing, e.g., "Josh Smith."

    */
    vector<string> matches;
    collect(r, NAME, matches);

    if (matches.empty()) {
        cout << "unsuccessful" << endl;
    } else {
        for (const string& id : matches) {
            cout << id << endl;
        }
    }

    return r; // Return r for compatibility

}

//Printing functionalities --------------------------------------------------------------
void InOrder(TreeNode* r, vector<string>& names) {
    if (!r) return;
    // Recurse on the left subtree
    InOrder(r->left, names);

    // Add Data for Printing
    names.push_back(r->name);

    // Recurse on the right subtree
    InOrder(r->right, names);
}

void AVLTree::printInOrder(TreeNode* r) {
    /*
     * Print out a comma separated inorder traversal of the names in the tree.
     */
    vector<string> n;
    InOrder(r, n);
    for (size_t  i = 0; i < n.size(); i++) {
        cout << n[i];
        if (i != n.size() - 1) {
            cout << ", ";
        }
    }

}

void preOrder(TreeNode* r, vector<string>& names) {
    if (!r) return;
    // Print Root First
    names.push_back(r->name);

    // Recurse on the left subtree
    preOrder(r->left, names);

    // Recurse on the right subtree
    preOrder(r->right, names);
}

void AVLTree::printPreorder(TreeNode* r) {
    /*
     * Print out a comma separated inorder traversal of the names in the tree.
     */
    vector<string> n;
    preOrder(r, n);
    for (size_t  i = 0; i < n.size(); i++) {
        cout << n[i];
        if (i != n.size() - 1) {
            cout << ", ";
        }
    }
}

void postOrder(TreeNode* r, vector<string>& names) {
    if (!r) return;

    // Recurse on the left subtree, get the leftmost first
    postOrder(r->left, names);

    // Recurse on the right subtree
    postOrder(r->right, names);

    // Print leftmost and then go to the right, later going into the root of that subtree
    names.push_back(r->name);
}

void AVLTree::printPostorder(TreeNode* r) {
    /*
     * Print out a comma separated inorder traversal of the names in the tree.
     */
    vector<string> n;
    postOrder(r, n);
    for (size_t  i = 0; i < n.size(); i++) {
        cout << n[i];
        if (i != n.size() - 1) {
            cout << ", ";
        }
    }
}

void AVLTree::printLevelCount(TreeNode* r) {
    /*
    * Prints the number of levels that exist in the tree.
    * Prints 0 if the head of the tree is null. For example, the tree in Fig. 1 has four levels.
     */

    if (!r) {
        cout << 0 << endl;
        return;
    }
    cout << r->h << endl;
}
//----------------------------------------------------------------------------------------

TreeNode* AVLTree::removeInOrderN(TreeNode* r, int N) {
    /*
     * Remove the Nth GatorID from the inorder traversal of the tree (N = 0 for the first item, etc).
     * If removal is successful, print “successful.”
     * Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit.
     * If the Nth GatorID does not exist within the tree, print “unsuccessful.”
     */

    if (r == nullptr || N < 0) {
        cout << "unsuccessful" << endl;
        return r;
    }
    vector<string> idList;
    gatherInOrder(r, idList);

    if ( N >= (int)idList.size()) {
        cout << "unsuccessful" << endl;
        return r;
    }

    string idToRemove = idList[N];
    r = removeID(r, idToRemove);

    return r;

}

