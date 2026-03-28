#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If only one row, zigzag is same as input
        if (numRows == 1 || numRows >= s.size())
            return s;

        // Create a vector of strings, each representing a row
        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = false;

        // Traverse each character in the string
        for (char c : s) {
            rows[curRow] += c; // add character to current row

            // When we reach top or bottom, change direction
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;

            // Move to next row
            curRow += goingDown ? 1 : -1;
        }

        // Combine all rows into one string
        string result;
        for (string &row : rows)
            result += row;

        return result;
    }
};
