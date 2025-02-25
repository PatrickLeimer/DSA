#include <iostream>
#include <AVLTree.h>
#include <vector>
using namespace std;


int main(){

    AVLTree* avlTree = new AVLTree();

    avlTree->printLevelCount(avlTree->root);

    string name = "Patrick Leimer", id = "12345678";
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "A", "00000001");
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "B", "00000002");
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "C", "00000003");
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "D", "00000004");
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "E", "00000005");
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "F", "00000006");
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "G", "00000007");
    avlTree->root = avlTree->insertNAMEID(avlTree->root, "H", "00000008");
    cout << endl;

    // Search ID
    cout << "Searches: " << endl;
    avlTree->searchID(avlTree->root, "00000001");

    // Search Name
    avlTree->searchName(avlTree->root, "B");
    cout << endl;

    // Remove methods
    // avlTree->root = avlTree->removeInOrderN(avlTree->root, 6);
    // avlTree->root = avlTree->removeID(avlTree->root, "00000006");

    cout << endl;
    // Print nodes in Inorder (sorted order)
    cout << "Inorder Traversal:" << endl;
    avlTree->printInOrder(avlTree->root, "root");
    cout << "\n";

    cout << "Preorder Traversal:" << endl;
    avlTree->printPreorder(avlTree->root);
    cout << "\n";

    cout << "Postorder Traversal:" << endl;
    avlTree->printPostorder(avlTree->root);
    cout << "\n";

    cout << "Print Level Count:" << endl;
    avlTree->printLevelCount(avlTree->root);

    delete avlTree;


    return 0;
}
