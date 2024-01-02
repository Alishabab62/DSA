#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node * insertIntoBST(Node * root, int val){
    if(root == NULL){
        Node * newRoot = new Node(val);
        return newRoot;
    }
    if(root->data > val){
        root->left = insertIntoBST(root->left, val);
    }
    else{
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void createBST(Node * &root){
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node *root){
    // if(root == NULL){
    //     return;
    // }
    queue<Node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << curr->data << " Level ";
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

Node * createDDLFromBST(Node * root , Node * &head){
    if(root == NULL){
        return NULL;
    }
    Node * rightSubTree = createDDLFromBST(root->right,head);

    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    Node * leftSubTree = createDDLFromBST(root->left,head);
    return head;
}

void printDDL(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << "LL";
        temp = temp->right;
    }
}


Node * createBSTFromDDL(Node * &head,int size){
    if(head == NULL || size <=0){
        return NULL;
    }
    Node * left = createBSTFromDDL(head,size/2);

    Node * root = head;
    root -> left = left;
    head = head->right;

    Node * right = createBSTFromDDL(head,size - size/2 - 1 );
    root -> right = right;
    return root;
}

int main(){
    // Node * root = NULL;
    // createBST(root);
    // Node * head = NULL;
    // createDDLFromBST(root,head);
    // printDDL(head);
    // Node * temp = createBSTFromDDL(head,3);
    // cout << endl;
    // levelOrderTraversal(temp);
    return 0;
}