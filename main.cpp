#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
void prints(vector<vector<int>> &a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isvalid(vector<vector<int>> &a, int i, int j, int n, int num){
    for(int k=0; k<n; k++){
        if(a[i][k]== num || a[k][j]==num)
            return false;
    }
    int rt= sqrt(n);
    int sti= i- (i % rt);
    int stj= j- (j % rt);
    for(int x=sti; x<sti+rt; x++){
        for(int y=stj; y<stj+rt; y++){
            if(a[x][y] == num)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>> &a, int i, int j, int n){
    if(i==n){
        cout<<"I am termination of program"<<endl;
        prints(a, n);
        return true;
    }
    // wrapping around and moving to the next row
    if(j==n){
        cout<<"***** I am row end! ***** "<<j<<endl;
        return sudokuSolver(a, i+1, 0, n);
    }
    // checking if there is any element already present in question
    if(a[i][j]!=0){
        cout<<" I am not equal to zero "<<a[i][j]<<endl;
        return sudokuSolver(a, i, j+1, n);
        
    }
    
    for(int num=1; num<=n; num++){
        if(isvalid(a, i, j, n, num)){
            a[i][j]=num;
            cout<<"Value Set "<<num<<endl;
            bool subAns= sudokuSolver(a, i, j+1, n);
            if(subAns){
                return true;
            }
        }
            //Backtracking
            cout<<"I have Back tracked "<<a[i][j]<<endl;
            a[i][j]=0;
        
    }
    return false;
}
int main(){
    vector<vector<int>> a {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    
    sudokuSolver(a, 0, 0, 9);
    
    cout<<endl;
    
    
    return 0;
}
