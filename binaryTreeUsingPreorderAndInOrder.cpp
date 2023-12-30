#include<iostream>
#include<map>
#include<queue>
using namespace std;

class Node{
    public:
        Node * left;
        Node * right;
        int val;
        Node(int val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};


//brute force
int searchElement(int in[6],int element){
    for(int i = 0; i < 6;i++){
        if(element == in[i]){
            return i;
        }
    }
}


//create mapping

void mapping(int in[6],map<int,int> &valueToIndexMap){
    for(int i = 0; i < 6; i++){
        int element = in[i];
        valueToIndexMap[element] = i;
    }
}

Node * createBinaryTreeUsingPreAndInOrder(int pre[],int in[],int size, map<int,int>map, int &index,int inStartIndex,int inEndIndex){
        if(index >= size || inStartIndex < 0 || inEndIndex > size){
            return nullptr;
        }

        int element = pre[index];
        index++;
        // int position = searchElement(in, element);
        int position = map[element];
        Node * root = new Node(element);
        root->left = createBinaryTreeUsingPreAndInOrder(pre,in,size,map,index,inStartIndex,position-1);
        root->right = createBinaryTreeUsingPreAndInOrder(pre,in,size,map,index,position+1,inEndIndex);
        return root;
}

Node * createBinaryTreeUsingInAndPostOrder(int pre[],int in[],int size, map<int,int>map, int &index,int inStartIndex,int inEndIndex){
        if(index < 0 ||  inStartIndex > inEndIndex){
            return nullptr;
        }

        int element = pre[index];
        index--;
        int position = map[element];
        Node * root = new Node(element);
        root->right = createBinaryTreeUsingInAndPostOrder(pre,in,size,map,index,position+1,inEndIndex);
        root->left = createBinaryTreeUsingInAndPostOrder(pre,in,size,map,index,inStartIndex,position-1);
        return root;
}


void printTreeLevelWise(Node *root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node * front = q.front();
        q.pop();

        if(front  == nullptr){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout << front->val << " ";
            if(front->left != nullptr){
                q.push(front->left);
            }
            if(front -> right != nullptr){
                q.push(front->right);
            }
        }
    }
}


int main(){
    // int pre[6] = {10,8,6,4,5,4};
    // int in[6] = {6,8,4,10,4,5};
    // int size = 6;
    // int index = 0;
    // int inStartIndex = 0;
    // int inEndIndex = size;
    // map<int,int> valueToIndex;
    // mapping(in,valueToIndex);
    // Node *root = createBinaryTreeUsingPreAndInOrder(pre,in,size,valueToIndex,index,inStartIndex,inEndIndex);
    // printTreeLevelWise(root);


    int post[6] = {6,4,8,4,5,10};
    int in[6] = {6,8,4,10,4,5};
    int size = 6;
    int index = size - 1;
    int inStartIndex = 0;
    int inEndIndex = size-1;
    map<int,int> valueToIndex;
    mapping(in,valueToIndex);
    Node *root = createBinaryTreeUsingInAndPostOrder(post,in,size,valueToIndex,index,inStartIndex,inEndIndex);
    printTreeLevelWise(root);



    cout << "Binary tree" << endl;
}