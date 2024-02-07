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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node * insertIntoBST(Node * root, int val){
    if(root == nullptr){
        root = new Node(val);
        return root;
    }

    if(root->data > val){
        cout << root->data  << "Left" << val << endl ;
        root ->left = insertIntoBST(root->left, val);
    }
    else{
        cout << root->data << "Right" << val << endl ;
        root ->right = insertIntoBST(root->right, val);
    }
    return root;
}


void createBST(Node * &root){
    int value;
    cout << "Enter data: " << endl;
    cin >> value;

    while(value != -1){
        root = insertIntoBST(root, value);
        cout << "Enter data: " << endl;
        cin >> value;
    }
}

void levelTraversal(Node * root){
    
    queue<Node *>q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node * front = q.front();
        q.pop();

        if(front == nullptr){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout << front->data <<  " ";
                if(front -> left != nullptr){
                    q.push(front -> left);
                }
                if(front -> right != nullptr){
                    q.push(front -> right);
                }
        }
    }
    
}

void inOrderTraversal(Node * root){
    if(root == nullptr){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

bool binarySearch(Node * root,int value,vector<int>path){
    if(root == nullptr){
        return false;
    }
    if(root ->data == value){
        path.push_back(root->data);
        return true;
    }
    bool left = false;
    bool right = false;
    if(root->data > value){
        left = binarySearch(root->left,value,path);
        path.push_back(root->data);
    }else{
        right = binarySearch(root->right,value,path);
        path.push_back(root->data);
    }
    return left || right;
}

int min(Node * root){
    if(root == nullptr){
        return root->data;
    }
}


int main(){

    Node * root = nullptr;
    createBST(root);
    cout << root->data << endl;

    // levelTraversal(root);
    // inOrderTraversal(root);
    vector<int> path;
    int target;
    cout << " Enter target:" << endl;
    cin >> target;
    while(target != 0){
        bool ans = binarySearch(root,target,path);
      
        if(ans == true){
        cout << "Element found: " << endl;
          for(int i=0; i<path.size();i++){
        cout << path[i] << " ";
    }
        }
        else{
            cout << "No element found: " << endl;
              for(int i=0; i<path.size();i++){
        cout << path[i] << " ";
    }
        }
        cout << " Enter target:" << endl;
        cin >> target;
    }
  
   

}