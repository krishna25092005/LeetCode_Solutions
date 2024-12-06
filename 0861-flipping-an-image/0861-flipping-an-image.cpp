class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for (auto& row : image) {
            int left = 0, right = n - 1;
            while (left <= right) {
                // Swap and invert
                int temp = row[left] ^ 1; // Invert left element
                row[left] = row[right] ^ 1; // Invert right element
                row[right] = temp; // Assign the inverted left element to the right
                
                left++;
                right--;
            }
        }
        
        return image;
    }
};