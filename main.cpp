#include <iostream>
#include <queue>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void insertRecursive(BSTNode*& root, int value){
   if(!root) {
	root = new BSTNode(value);
	return;
   }
   if(value < root->data) {
	inserRecursive(root->left, value);
   }
   if(value > root->data) {
	insertRecursive(root->right, value);
   }
}

void insertIterative(BSTNode*& root,int value) {
     if(!root) {
	root = new BSTNode(value);
	return;
     }
// Set up a trailing pointer
     BSTNode* cur = root;
     BSTNode* parent = nullptr;

     while (cur) {
	parent = cur;
        if(value < cur->data) {
            cur = cur->left;
       }else if(value > cur->data) {
            cur = cur->right;
       }else {
         return; // duplicate so ignore
        }
     }
	if(value < parent->data){
	    parent->left = new BSTNode(value);
	} else{
	    parent-right = new BSTNode(value);
	}
}

bool searchRecursive(BSTNode* root, int key) {
    if(!root) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(key < root->data) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}

bool searchIterative(BSTNode* root, int key) {
    BSTNode* cur = root;
    while (cur) {
        if(key == cur->data) {
            return true;
        }
        if (key < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return false;
}

void inorderPrint(BSTNode* root) {
    if(!root) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void preorderPrint(BSTNode* root) {
    if(!root) {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postorderPrint(BSTNode* root) {
    if(!root) {
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";

}

void levelorder(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<BinaryTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";
        if (current->left) { q.push(current->left);}
        if (current->right) { q.push(current->right);}
    }
}

int main(){

return 0;
}

