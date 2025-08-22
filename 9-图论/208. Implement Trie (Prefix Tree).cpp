// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode
{
public:
    vector<TrieNode *> children;
    bool is_end;
    TrieNode()
    {
        this->children = vector<TrieNode *>(26, nullptr); // 26个字母
        this->is_end = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        this->root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = this->root;
        for (const auto ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                // 延长前缀
                node->children[index] = new TrieNode();
                node = node->children[index];
            }
            else
            {
                // 前缀已经存在
                node = node->children[index];
            }
        }
        node->is_end = true;
    }

    bool search(string word)
    {
        TrieNode *node = this->root;
        for (const auto ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                return false;
            }
            else
            {
                node = node->children[index];
            }
        }
        if (node->is_end == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = this->root;
        for (const auto ch : prefix)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                return false;
            }
            else
            {
                node = node->children[index];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */