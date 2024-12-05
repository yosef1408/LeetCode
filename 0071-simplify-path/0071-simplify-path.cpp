class Solution {

/*
    To simplify the given path, the following constraints must be followed:
    1. Ignore each occurrence of "." (current directory).
    2. Move back to the parent directory for each occurrence of "..".
    3. Treat consecutive slashes ("/") as a single slash.
    4. Remove any trailing slash at the end of the path.

    Pseudocode:
    - Iterate over the input string:
        a) Replace multiple consecutive slashes with a single slash.
        b) Remove any trailing slash.
    - Use a stack to store directory names:
        a) Push valid directory names onto the stack.
        b) Pop the stack for ".." to move to the parent directory.
    - Construct the simplified path using the stack and return it.

    Algorithm:
    - Use a sliding window approach in a while loop to process the input string.
    - Time complexity: O(n), where n is the length of the string.
    - Space complexity: O(n), for storing directory names in the stack.
    - The stack efficiently tracks directory traversal, making it simple to handle ".." and other cases.
*/

public:
    string simplifyPath(string path) {
        
        vector<string> stack; // Hold Directory value;
        string prompt = "";
        int n = path.size();

        for(int i = 1 ; i <= n ;i++)
        {
            // process the old prompt;
            if(path[i] == '/' || i == n){
                if(prompt == "..")
                {
                    if(!stack.empty())
                        stack.pop_back();
                }
                else if(prompt  == "."){}
                else{
                    if(prompt != "")
                        stack.push_back(prompt);
                }
                prompt = "";

            }else{
                prompt += path[i];
            }
        }


        // now we have all directory names build the path;
        string simplePath = "/";
        for(int i = 0 ; i < stack.size();i++)
        {
            simplePath+= stack[i];
            if(i != stack.size()-1)
                simplePath += '/';
        }

        return simplePath;
    }
};