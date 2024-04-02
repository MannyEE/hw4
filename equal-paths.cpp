#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
#include <algorithm>
using namespace std;


// You may add any prototypes of helper functions here
int treeDepth(Node* root, bool& validTree);

bool equalPaths(Node * root)
{
    // Add your code below

    bool validTree = true;
    treeDepth(root, validTree);
 
    return validTree;
 
}

int treeDepth(Node* root, bool& validTree){

    if (root == nullptr)return 0;
    if (validTree == false) return 0;

    int leftHeight = treeDepth(root->left, validTree);
    int rightHeight = treeDepth(root->right, validTree);

    if (((root->left != nullptr) && (root->right != nullptr)) && (leftHeight != rightHeight)) validTree = false; 
    else if ( (root->left == nullptr) && (root->right != nullptr)) return (1 + rightHeight);
    else if ( (root->left != nullptr) && (root->right == nullptr)) return (1 + leftHeight);
    
    if (leftHeight > rightHeight) return (1 + leftHeight);
    else return (1 + rightHeight);


}


