
#include <iostream>
#include<queue> 
using namespace std;


class Binary{
    public:
        int data;
        Binary* left;
        Binary* right;
        Binary(int val){
            this->data = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};


Binary * createTree(){
    cout << "Enter values of binary tree" << endl;
    int val;
    cin >> val;
    if(val == -1){
        return nullptr;
    }

    Binary *root = new Binary(val);
    cout <<"Value of left" << root->data << endl;
    root -> left = createTree();
    cout <<"Value of right" << root->data << endl;
    root -> right = createTree();

    return root;
}

void printTreePre(Binary *root){
    if(root == nullptr){
        return;
    }

    cout << "value of current node: " << root->data << endl;
    printTreePre(root->left);
    printTreePre(root->right);
}

void printTreeInOrder(Binary *root){
    if(root == nullptr){
        return;
    }

    printTreeInOrder(root->left);
    cout << "value of current node: " << root->data << endl;
    printTreeInOrder(root->right);
}

void printTreePost(Binary *root){
    if(root == nullptr){
        return;
    }

    printTreePost(root->left);
    printTreePost(root->right);
    cout << "value of current node: " << root->data << endl;
}

void printTreeLevelWise(Binary *root){
    queue<Binary*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Binary * front = q.front();
        q.pop();

        if(front  == nullptr){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
            return;
        }
        else{
            cout << front->data << " ";
            if(front->left != nullptr){
                printTreeLevelWise(front->left);
            }
            if(front -> right != nullptr){
                printTreeLevelWise(front->right);
            }
        }
    }
}

int main(){
    Binary * root = createTree();
    cout << root->data << endl;

    // printTreePre(root);
    // printTreeInOrder(root);
    // printTreePost(root);

    printTreeLevelWise(root);

    cout << "Binary" << endl;
}