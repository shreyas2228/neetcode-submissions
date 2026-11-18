
class WordDictionary {
private:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    Node* root;

    bool dfs(string &word, int index, Node* node) {

        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        if (ch == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->children[i] != nullptr) {

                    if (dfs(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }

            return false;
        }

        int pos = ch - 'a';

        if (node->children[pos] == nullptr) {
            return false;
        }

        return dfs(word, index + 1, node->children[pos]);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {

        Node* curr = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
