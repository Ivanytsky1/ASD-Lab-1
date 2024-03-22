#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Given array B
    int B[4][6] = {
        {3, 6, 1, 8, 2, 5},
        {9, 4, 7, 2, 5, 1},
        {2, 7, 4, 9, 3, 6},
        {8, 1, 5, 3, 6, 7}
    };


    // Find the maximum element and its string
    int maxElement = B[0][0];
    int maxRowIndex = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (B[i][j] > maxElement) {
                maxElement = B[i][j];
                maxRowIndex = i;
            }
        }
    }

    // Sort the row with the maximum element using Shell sort
    vector<int> row(B[maxRowIndex], B[maxRowIndex] + 6);
    int gap, i, j, temp;
    for (gap = 6 / 2; gap > 0; gap /= 2) {
        for (i = gap; i < 6; ++i) {
            temp = row[i];
            for (j = i; j >= gap && row[j - gap] > temp; j -= gap) {
                row[j] = row[j - gap];
            }
            row[j] = temp;
        }
    }


    // Output the sorted string
    cout << "Sorted row with max element: ";
    for (int i = 0; i < 6; ++i) {
        cout << row[i] << " ";
    }
    cout << endl;

    return 0;
}