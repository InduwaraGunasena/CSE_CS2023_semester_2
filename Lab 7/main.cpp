#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int element) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = element;              // set root as the element you input to this function.
  temp->left = temp->right = NULL;  // set node left and ride leaf as NULL.
  return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL) {
        // Traverse left side tree
        traverseInOrder(root->left);

        // Traverse root and print that
        cout << root -> key << " ";

        // Traverse right side tree
        traverseInOrder(root -> right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    // Return a new node if the tree is empty
    if (node == NULL) return newNode(key);

    // Traverse to the right place and insert the node
    if (key < node->key){
        node->left = insertNode(node->left, key);
    }else{
        node->right = insertNode(node->right, key);
    }

    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    // Return if the tree is empty
  if (root == NULL) return root;

    // Finding the node which we want to delete.
  if (key < root->key){
    root->left = deleteNode(root->left, key);
  } else if (key > root->key){
    root->right = deleteNode(root->right, key);
  } else {

    if (root->left == NULL) { // if the left child is NULL, take the right child as temp and release memory.
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {  // if the right child is NULL, take the left child as temp and release memory.
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *current = root->right;

    while (current && current->left != NULL)  // Finding the leftmost leaf to find the inorder successor.
        current = current->left;

    // If the node has two children
    struct node *temp = current;

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;

    }
  }

  traverseInOrder(root);
}
