#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include "AVLTree.h"  // Your AVLTree class header


using namespace std;

void parseLine(const string& line, AVLTree* tree)
{
    istringstream in(line);

    // First part is always the command
    string command;
    in >> command;

    // Handle all commands
    if (command == "insert")
    {
        char skip;
        in >> skip; // skip the whitespace
        string name;
        getline(in, name, '"'); // Gather name
        string id;
        in >> id;
        tree->root = tree->insertNAMEID(tree->root, name, id);
    }
    else if (command == "search")
    {
        in >> ws;
        char c;
        in.get(c);

        if (c == '"')
        {
            string name;
            getline(in, name, '"');
            // cout << "search Name " << name << "\n";
            tree->searchName(tree->root, name);
        }
        else
        {
            in.putback(c);
            string token;
            in >> token;
            // same as in input validation
            bool isNumeric = true;
            for (char c : token)
            {
                if (!isdigit(c))
                {
                    isNumeric = false;
                    break;
                }
            }

            if (isNumeric)
            {
                TreeNode* temp = tree->searchID(tree->root, token);
                if (temp == nullptr) {
                    cout << "unsuccessful" << endl;
                }
            }
            else
            {
                tree->searchName(tree->root, token);
            }
        }
    }
    else if (command == "remove")
    {
        string id;
        in >> id;
        tree->root = tree->removeID(tree->root, id);
    }
    else if (command == "removeInorder")
    {
        int i;
        in >> i;
        tree->root = tree->removeInOrderN(tree->root, i);
    }
    else if (command == "printInorder")
    {
        tree->printInOrder(tree->root);
        cout << endl;
    }
    else if (command == "printPreorder")
    {
        tree->printPreorder(tree->root);
        cout << endl;
    }
    else if (command == "printPostorder")
    {
        tree->printPostorder(tree->root);
        cout << endl;
    }
    else if (command == "printLevelCount")
    {
        tree->printLevelCount(tree->root);
    }
    else
    {
        cerr << "Unknown command: " << command << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    AVLTree* tree = new AVLTree();

    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        parseLine(line, tree);

    }
    delete tree;

    return 0;
}
