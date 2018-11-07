class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length - 1; int x0 = 0;
        while( n > 0){
            for(int i = 0; i < n; ++i){
                int temp = matrix[x0][i + x0];
                matrix[x0][i + x0] = matrix[x0 + n - i][x0];
                matrix[x0 + n - i][x0] = matrix[x0 + n][x0 + n - i];
                matrix[x0 + n][x0 + n - i] = matrix[x0 + i][x0 + n];
                matrix[x0 + i][x0 + n] = temp;
            }
            n -= 2;
            ++x0;
        }
        return;
    }
}