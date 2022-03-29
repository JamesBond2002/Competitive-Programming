class Node
{
public:
    int data, cnt = 0;
    Node* next[2];
    ~Node()
    {
        delete next[0]; delete next[1];
        next[0] = NULL; next[1] = NULL;
    }
};

class Trie
{
public:
    Node* head;
    int MAX_BIT = 63;
    Trie(int MAX_BIT)
    {
        this->MAX_BIT = MAX_BIT;
        head = new Node();
    }
    bool in_trie(int x)
    {
        Node* curr = head;
        for(int i = MAX_BIT; ~i; i--)
        {
            int bit = (bool)(x & (1ll << i));
            if(curr->next[bit] == NULL)
                return 0;
        }
        return 1;
    }
    void insert(int x)
    {
        Node* curr = head;
        // if(in_trie(x))
        //     return;
        curr->cnt++;
        for(int i = MAX_BIT; ~i; i--)
        {
            int bit = (bool)(x & (1ll << i));
            if(curr->next[bit] == NULL)
                curr->next[bit] = new Node();
            curr = curr->next[bit];
            curr->cnt++;
        }
    }
    void remove(int x)
    {
        Node* curr = head;
        if(!in_trie(x))
            return;
        curr->cnt--;
        for(int i = MAX_BIT; ~i; i--)
        {
            int bit = (bool)(x & (1ll << i));
            curr = curr->next[bit];
            curr->cnt--;
        }
    }
    int XOR(int x, bool max = 1)
    {
        Node* curr = head;
        int res = 0;
        for(int i = MAX_BIT; ~i; i--)
        {
            int bit = (bool)(x & (1ll << i));
            if(max)
            {
                if(curr->next[1-bit] != NULL)
                    res |= (1ll << i), curr = curr->next[1-bit];
                else
                    curr = curr->next[bit];
            }
            else
            {
                if(curr->next[bit] != NULL)
                    curr = curr->next[bit];
                else
                    res |= (1ll << i), curr = curr->next[1-bit];
            }
        }
        return res;
    }

    void Query();

    ~Trie()
    {
        delete head;
        head = NULL;
    }
};
