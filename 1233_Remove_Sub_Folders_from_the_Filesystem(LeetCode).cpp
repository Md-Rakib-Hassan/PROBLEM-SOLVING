//https://leetcode.com/problems/remove-sub-folders-from-the-filesystem

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folder paths lexicographically to group subfolders after their parent folder
        sort(folder.begin(), folder.end());
        
        // Initialize the result vector and add the first folder as it can't be a subfolder
        vector<string> ans;
        ans.push_back(folder[0]);
        
        // Loop through the sorted folder list starting from the second element
        for (int i = 1; i < folder.size(); i++) {
            // Create a string 'last_folder' by adding '/' to the last folder in the result vector
            // This helps to match only the complete folder name
            string last_folder = ans.back() + '/';
            
            // Compare the current folder with the last folder in the result
            // If the current folder is not a subfolder of the last folder, add it to the result
            for (int j = 0; j < last_folder.size(); j++) {
                if (last_folder[j] != folder[i][j]) {
                    // The current folder is not a subfolder, so add it to the result
                    ans.push_back(folder[i]);
                    break; // Exit the loop as we don't need further comparisons
                }
            }
        }

        // Return the final list of folders without subfolders
        return ans;
    }
};
