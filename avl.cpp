/*
Que. A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Height balance tree and find the complexity for finding a keyword.
*/

#include <iostream>
#include <string.h>
using namespace std;

class AVLNode 
{
    public:
    string keyword, meaning;
    AVLNode *left, *right;
    int ht;
};

class Stack 
{
    int i;
    AVLNode* arr[20];

    public:
    Stack() 
    {
        i = -1;
    }
    inline bool full() 
    {
        return i == 19;
    }
    inline bool empty() 
    {
        return i == -1;
    }
    void push(AVLNode* n) 
    {
        if (full()) 
        {
            return;
        }
        arr[++i] = n;
    }
    void pop() 
    {
        if (empty()) 
        {
            return;
        }
        i--;
    }
    AVLNode* top() 
    {
        return arr[i];
    }
};


class AVLTree 
{
    public:
    AVLNode *root;
    AVLTree() 
    {
        root = NULL;
    }

    // ============================

    AVLNode* rotate_right(AVLNode *x) 
    {
        AVLNode *y;
        y = x->left;
        x->left = y->right;
        y->right = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    // ============================

    AVLNode* rotate_left(AVLNode *x) 
    {
        AVLNode *y;
        y = x->right;
        x->right = y->left;
        y->left = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    // ============================

    int height(AVLNode *T) 
    {
        int hl, hr;
        if (T == NULL) 
        { // external node
            return 0;
        }
        if (T->left == NULL && T->right == NULL) 
        { // leaf node
            return 0;
        }
        hl = height(T->left);
        hr = height(T->right);
        if (hl < hr) 
        {
            return hr + 1;
        }
        else 
        {
            return hl + 1;
        }
    }

    // ============================

    int BF(AVLNode *T) 
    {
        int lh, rh;
        if (T == NULL) 
        {
            return 0;
        }
        else 
        {
            if (T->left == NULL) 
            {
                lh = 0;
            }
            else 
            {
                lh = 1 + T->left->ht; // left subtree ki height + 1
            }
            if (T->right == NULL) 
            {
                rh = 0;
            }
            else 
            {
                rh = 1 + T->right->ht; // right subtree ki height + 1
            }
            return (lh - rh);
        }
    }

    // ============================

    AVLNode* LL(AVLNode *T) 
    {
        cout << "\nIn LL Rotation:\n";
        T = rotate_right(T);
        return T;
    }

    // ============================

    AVLNode* RR(AVLNode *T) 
    {
        cout << "\nIn RR Rotation:\n";
        T = rotate_left(T);
        return T;
    }

    // ============================

    AVLNode* LR(AVLNode *T) 
    {
        cout << "\nIn LR Rotation:\n";
        T->left = rotate_left(T->left);
        T = rotate_right(T);
        return T;
    }

    // ============================

    AVLNode* RL(AVLNode *T) 
    {
        cout << "\nIn RL Rotation:\n";
        T->right = rotate_right(T->right);
        T = rotate_left(T);
        return T;
    }

    // ============================

    AVLNode* insert(AVLNode* root, string newkey, string mean) 
    {
        AVLNode *newnode;
        // int lh, rh;
        newnode = new(AVLNode);
        newnode->keyword = newkey;
        newnode->meaning = mean;
        newnode->ht = 0;
        newnode->left = NULL;
        newnode->right = NULL;

        if (root == NULL) 
        {
            root = newnode;
            cout << root->keyword << " ";
        }
        else 
        {
            cout << root->keyword << " ";
            if (newkey < root->keyword) 
            {
                root->left = insert(root->left, newkey, mean);
                cout << "\nBalance Factor: " << root->keyword << "\t" << BF(root);
                if (BF(root) == 2) 
                {
                    if (newkey < root->left->keyword) 
                    {
                        root = LL(root);
                    }
                    else 
                    {
                        root = LR(root);
                    }
                }

            }

            else if (newkey > root->keyword) 
            { // just compare directly if using strings instead of char[]
                root->right = insert(root->right, newkey, mean);
                cout << "\nBalance Factor: " << root->keyword << " " << BF(root);
                if (BF(root) == -2) 
                {
                    if (newkey > root->right->keyword) 
                    {
                        root = RR(root);
                    }
                    else 
                    {
                        root = RL(root);
                    }
                }
            }
            else 
            {
                cout << "\nDuplicate word!";
            }
        }
        root->ht = height(root);
        return root;
    }

        // ============================

    string search(string word) 
    {
        if (root == NULL) 
        {
            return "Does not exist\n";
        }
        AVLNode* q = root;
        while (q != NULL) 
        {
            if (word < q->keyword) 
            {
                q = q->left;
            }
            else if (word > q->keyword) 
            {
                q = q->right;
            }
            else
            {
                return q->meaning;
            }
        }
        return "Not Found\n";
    }

    // ============================

    AVLNode *inOrderPred(AVLNode *root) 
    {
        AVLNode* q = root;
        while (q->right != NULL) 
        {
            q = q->right;
        }
        return q;
    }

    // ============================

    AVLNode* deleteNode(AVLNode* root, string key) 
    {
        if (root == NULL) 
        {
            return root;
        }
        if (key < root->keyword) 
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->keyword) 
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL && root->right == NULL) 
            {
                delete root;
                return NULL;
            }
            else if (root->right == NULL) 
            {
                AVLNode *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->left == NULL) 
            {
                AVLNode *temp = root->right;
                delete root;
                return temp;
            }
            else 
            {
                AVLNode *temp = inOrderPred(root->left);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->left = deleteNode(root->left, temp->keyword);
            }
        }
        if (root == NULL) 
        {
        return root;
        }

        root->ht = height(root);
        int balance = BF(root);
        if (balance > 1 && BF(root->left) >= 0) 
        {
            return LL(root);
        }
        if (balance > 1 && BF(root->left) < 0) 
        {
            return LR(root);
        }
        if (balance < -1 && BF(root->right) <= 0)
        {
            return RR(root);
        }
        if (balance < -1 && BF(root->right) > 0) 
        {
            return RL(root);
        }
        return root;
    }

    // ============================

    void inOrderTraversal() 
    {
        if (root == NULL) 
        {
            cout << "Tree does not exist\n";
            return;
        }
        cout << "--- In-Order Traversal ---\n\n";
        Stack s;
        AVLNode* q = root;
        while (true) 
        {
            while (q != NULL) 
            {
                s.push(q);
                q = q->left;
            }
            if (s.empty()) 
            {
                break;
            }
            q = s.top();
            s.pop();
            cout << q->keyword << " ";
            q = q->right;
        }
    }

    void inorder(AVLNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->keyword<<" : "<<root->meaning<<endl;
            inorder(root->right);
        }
    }
};

// ====================================

int main(int argc, char const *argv[]) 
{
    int ch;
    AVLTree t;
    string word, meaning;
    do 
    {
        cout << "\n\n(1) Insert Data \n(2) Search Data \n(3) Delete Data \n(4) In-order Traversal \n(5)Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) 
        {
            case 1:
                cout << "Enter word: ";
                getline(cin, word);
                cout << "Enter meaning: ";
                getline(cin, meaning);
                t.root = t.insert(t.root, word, meaning);
                break;

            case 2:
                cout << "Enter word to be searched: ";
                getline(cin, word);
                meaning = t.search(word);
                cout << "Meaning: " << meaning;
                break;

            case 3:
                cout << "Enter word to delete: ";
                getline(cin, word);
                t.deleteNode(t.root, word);
                break;

            case 4:
                t.inOrderTraversal();
                break;

            case 5:
                cout<<"\nExit"<<endl;
                break;

            default:
                cout << "Invalid choice\n";
                break;
        }
    } 
    while (ch!=5);
    return 0;
}

/*
OUTPUT

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 1
Enter word: absence
Enter meaning: lack
absence

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 1
Enter word: borrow
Enter meaning: take
absence borrow
Balance Factor: absence -1

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 1
Enter word: justify
Enter meaning: defend
absence borrow justify
Balance Factor: borrow -1
Balance Factor: absence -2
In RR Rotation:

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 1
Enter word: generate
Enter meaning: produce
borrow justify generate
Balance Factor: justify 1
Balance Factor: borrow -1

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 2
Enter word to be searched: borrow
Meaning: take     

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 4
--- In-Order Traversal ---
absence borrow generate justify

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 3
Enter word to delete: generate

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 4
--- In-Order Traversal ---
absence borrow justify

(1) Insert Data
(2) Search Data
(3) Delete Data
(4) In-order Traversal
(5)Exit
Enter choice: 5

Exit
*/