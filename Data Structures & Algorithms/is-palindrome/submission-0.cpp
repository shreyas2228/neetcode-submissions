class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int high = n - 1;
        int low = 0;

        while (low < high) {
            if (!isalnum(s[low])) {
                low++;
            } 
            else if (!isalnum(s[high])) {
                high--;
            } 
            else if (tolower(s[low]) == tolower(s[high])) {
                low++;
                high--;
            } 
            else {
                return false;
            }
        }

        return true;
    }
};
