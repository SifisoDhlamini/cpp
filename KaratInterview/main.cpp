/**
Imagine we have an image. We'll represent this image as a simple 2D array where every pixel is a 1 or a 0. The image you get is known to have a single rectangle of 0s on a background of 1s.

Write a function that takes in the image and returns one of the following representations of the rectangle of 0's: top-left coordinate and bottom-right coordinate OR top-left coordinate, width, and height.

image1 = [
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 1, 1, 1, 1],
]

Sample output variations (only one is necessary):

findRectangle(image1) =>
  row: 2, column: 3, width: 3, height: 2
  2,3 3,5 -- row,column of the top-left and bottom-right corners

Other test cases:

image2 = [
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 0],
]

findRectangle(image2) =>
  row: 4, column: 6, width: 1, height: 1
  4,6 4,6

image3 = [
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 0, 0],
  [1, 1, 1, 1, 1, 0, 0],
]

findRectangle(image3) =>
  row: 3, column: 5, width: 2, height: 2
  3,5 4,6

image4 = [
  [0, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
]

findRectangle(image4) =>
  row: 0, column: 0, width: 1, height: 1
  0,0 0,0

image5 = [
  [0],
]

findRectangle(image5) =>
  row: 0, column: 0, width: 1, height: 1
  0,0 0,0

All Test Cases:
(top-left, width, height) or (top-left, bottom-right)
findRectangle(image1) => 2,3 3,2  or  2,3 3,5
findRectangle(image2) => 4,6 1,1  or  4,6 4,6
findRectangle(image3) => 3,5 2,2  or  3,5 4,6
findRectangle(image4) => 0,0 1,1  or  0,0 0,0
findRectangle(image5) => 0,0 1,1  or  0,0 0,0

n: number of rows in the input image
m: number of columns in the input image
*/
#include <iostream>
#include <vector>
using namespace std;

// space: O(1)
//  int firstZero(const vector<int>& v)
//  {
//    int sizeOfV = v.size();

//   for(int i = 0; i < sizeOfV; i++){
//     return accumulate(v.begin(), v.end(), 0)
//   }

//   return -1;
// }

void findRectangle(const vector<vector<int>> &rect)
{
    int r_size = rect.size();
    int c_size = rect[0].size();
    vector<int> result = {};
    for (int row = 0; row < r_size; row++)
    {

        for (int col = 0; col < c_size; col++)
        {
            if (rect[row][col] == 0)
            {
                result.push_back(row);
                result.push_back(col);
                int current_botC = col;
                int current_botR = row;

                while (current_botC < c_size - 1 && rect[current_botR][current_botC + 1] == 0)
                {
                    current_botC++;
                }

                while (current_botR < r_size - 1 && rect[current_botR + 1][current_botC] == 0)
                {
                    current_botR++;
                }
                result.push_back(current_botR);
                result.push_back(current_botC);

                cout << result[0] << "," << result[1] << " " << result[2] << "," << result[3] << endl;
                result.clear();
                return;
            }
        }
    }
}

int main()
{
    vector<vector<int>> image1 = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1},
    };

    vector<vector<int>> image2 = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0},
    };

    vector<vector<int>> image3 = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0},
    };

    vector<vector<int>> image4 = {
        {0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
    };

    vector<vector<int>> image5 = {
        {0},
    };

    findRectangle(image1);
    findRectangle(image2);
    findRectangle(image3);
    findRectangle(image4);
    findRectangle(image5);
}
