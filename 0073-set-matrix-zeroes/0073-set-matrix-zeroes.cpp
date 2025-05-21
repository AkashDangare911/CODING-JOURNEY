class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();        
        
        bool firstRowZero = false;
        bool firstColZero = false;

        // check if there are any zeros in first row and column
        for(int i=0; i<rows; i++){
            if(matrix[i][0] == 0){
                firstRowZero = true;
            }
        }
        for(int j=0; j<cols; j++){
            if(matrix[0][j] == 0){
                firstColZero = true;
            }
        }


        // traverse and check which rows and cols are going to become 0
        // and store them in first row and col
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        

        // make zero in matrix if firstRow/firstCol has 0 in it
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                   matrix[i][j] = 0;
                }
            }
        }

        // if firstRow has zero make first row 0
        if(firstRowZero == true){
            for(int i=0; i<rows; i++){
                matrix[i][0] = 0;
            }
        }

        // if firstCol has zero make first col 0
        if(firstColZero == true){
            for(int j=0; j<cols; j++){
                matrix[0][j] = 0;
            }
        }
    }
};