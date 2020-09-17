#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {

    int tmp_color = image[sr][sc];
    if (tmp_color == newColor)
      return image;
    if (image[sr][sc] != 0)
      image[sr][sc] = newColor;
    if (sr - 1 >= 0 && tmp_color == image[sr - 1][sc])
      floodFill(image, sr - 1, sc, newColor);
    if (sr + 1 < image.size() && tmp_color == image[sr + 1][sc])
      floodFill(image, sr + 1, sc, newColor);
    if (sc - 1 >= 0 && tmp_color == image[sr][sc - 1])
      floodFill(image, sr, sc - 1, newColor);
    if (sc + 1 < image[0].size() && tmp_color == image[sr][sc + 1])
      floodFill(image, sr, sc + 1, newColor);

    return image;
  }
};

int main(int argc, char **argv) {
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}, {1, 0, 1}};
  auto solution = new Solution();
  solution->floodFill(image, 1, 1, 2);

  return 0;
}
