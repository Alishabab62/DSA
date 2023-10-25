#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int arr[][4],int rows,int cols,int newX,int newY,vector<vector<bool> >&visited){
        if(
            (newX < rows && newX >= 0)&&
            ( newY < cols && newY >= 0) && 
            (visited[newX][newY] == false) && 
            (arr[newX][newY] == 1)
            ){
            return true;
        }else{
            return false;
        }
}

void maze(int arr[][4],int rows,int cols,int srcx,int srcy,string &ans,vector<vector<bool> >&visited){
    if((srcx == rows-1) && (srcy = cols -1)){
        cout << ans << endl;
        return;
    }

    // UP movement
    int newX = srcx -1;
    int newY = srcy;
        if(isSafe(arr,rows,cols,newX,newY,visited)){
            visited[newX][newY] = true;
            ans.push_back('U');
            maze(arr,rows,cols,newX,newY,ans,visited);
            visited[newX][newY] = false;
            ans.pop_back();
    }

    // RIGHT movement
    newX = srcx;
    newY = srcy+1;
        if(isSafe(arr,rows,cols,newX,newY,visited)){
            visited[newX][newY] = true;
            ans.push_back('R');
            maze(arr,rows,cols,newX,newY,ans,visited);
            visited[newX][newY] = false;
            ans.pop_back();
    }

    // DOWN movement
    newX = srcx +1;
    newY = srcy;
        if(isSafe(arr,rows,cols,newX,newY,visited)){
            visited[newX][newY] = true;
            ans.push_back('D');
            maze(arr,rows,cols,newX,newY,ans,visited);
            visited[newX][newY] = false;
            ans.pop_back();
    }

    // LEFT movement
    newX = srcx;
    newY = srcy-1;
        if(isSafe(arr,rows,cols,newX,newY,visited)){
            visited[newX][newY] = true;
            ans.push_back('L');
            maze(arr,rows,cols,newX,newY,ans,visited);
            visited[newX][newY] = false;
            ans.pop_back();
    }


}
int main(){
    int mazeRat[][4]={
        {1,0,0,0},
        {1,0,0,0},
        {1,1,1,0},
        {0,1,1,1}
    };
    int srcx = 0;
    int srcy = 0;
    int row = 4;
    int col = 4;
    string ans = "";
    vector<vector<bool> >visited(row,vector<bool>(col,false));
    visited[srcx][srcy] = true;
    maze(mazeRat,row,col,srcx,srcy,ans,visited);
    return 0;
}