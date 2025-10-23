#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return {}; // Return an empty vector for n=0
        }

        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = n - 1;

        int num = 1;

        while (num <= n * n) {
            // Go Right: Fill the top row
            for (int c = colStart; c <= colEnd; ++c) {
                matrix[rowStart][c] = num++;
            }
            rowStart++;

            // Go Down: Fill the rightmost column
            for (int r = rowStart; r <= rowEnd; ++r) {
                matrix[r][colEnd] = num++;
            }
            colEnd--;

            // Go Left: Fill the bottom row (if there's still a bottom row)
            if (rowStart <= rowEnd) { // Crucial check for odd 'n'
                for (int c = colEnd; c >= colStart; --c) {
                    matrix[rowEnd][c] = num++;
                }
                rowEnd--;
            }

            // Go Up: Fill the leftmost column (if there's still a leftmost column)
            if (colStart <= colEnd) { // Crucial check for odd 'n'
                for (int r = rowEnd; r >= rowStart; --r) {
                    matrix[r][colStart] = num++;
                }
                colStart++;
            }
        }
        return matrix;
    }
};
