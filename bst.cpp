/*
Que. Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
1. Insert new node
2. Find number of nodes in longest path from root (Height of the tree)
3. Maximum and Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
*/

#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *left, *right;
};

class bstree
{
	public:
	node *root;
	bstree()
	{
		root=NULL;
	}
	void create();
	void insert(int data);
	void search(int key);
	int countnode (node *root);
	void inorderR(node *root);
	void preorderR(node *root);
	void postorderR(node *root);
	int findmax(node *root);
	int findmin(node *root);
	void mirror(node *root);
	int treehgt(node *root);
};

void bstree :: create()
{
	root=new node;
	root->left=root->right=NULL;
	cout<<"\nEnter the Data: ";
	cin>>root->data;
}

void bstree :: insert(int data)
{
	node *temp, *p;
	if (root==NULL)
	{ 
		create();
		return;
	}
	p=new node;
	p->left=p->right=NULL;
	cout<<"\nEnter the Data: ";
	cin>>p->data;
	
	temp=root;
	while (temp!=NULL)
	{
		if (p->data < temp->data)
		{
			if (temp->left==NULL)
			{
				temp->left=p;
				break;
			}
			else
			{
				temp=temp->left;
			}
		}
		else if(p->data > temp->data)
		{
			if (temp->right==NULL)
			{
				temp->right=p;
				break;
			}
			else
			{
				temp=temp->right;
			}
		}
		else
		{
			cout<<"\nAlready Inserted Data"<<endl;
		}
	}
}

void bstree :: search(int key)
{
	cout<<"\nEnter the key to be Search: ";
	cin>>key;
	node *temp=root;
	int count=0;
	if (temp==NULL)
		cout<<"\nEmpty BST"<<endl;
	while (temp!=NULL)
	{
		if (temp->data==key)
			break;
		if (key < temp->data)
			temp=temp->left;
		else
			temp=temp->right;
		count++;
	}
	if (temp==NULL)
		cout<<"\nNode not Found"<<endl;
	else
	{
		cout<<"\nNode is found!"<<endl;
	}
}

int bstree :: countnode(node *root)
{
	if (root==NULL)
		return 0;
	else 
		return (1+countnode(root->right) + countnode(root->left));
}

void bstree :: inorderR(node *root)
{
	if (root!=NULL)
	{
		inorderR(root->left);
		cout<<root->data<<"\t";
		inorderR(root->right);
	}
}

void bstree :: preorderR(node *root)
{
	if (root!=NULL)
	{
		cout<<root->data<<"\t";
		preorderR(root->left);
		preorderR(root->right);
	}
}

void bstree :: postorderR(node *root)
{
	if (root!=NULL)
	{
		postorderR(root->left);
		postorderR(root->right);
		cout<<root->data<<"\t";
	}
}

int bstree :: findmax(node *root)
{
	node *temp=root;
	while (temp->right!=NULL)
		temp=temp->right;
	return (temp->data);
}

int bstree :: findmin(node *root)
{
	node *temp=root;
	while (temp->left!=NULL)
		temp=temp->left;
	return (temp->data);
}

int bstree :: treehgt(node *root)
{
	int hl,hr;
	if (root==NULL)
		return 0;
	if (root->left==NULL && root->right==NULL)
		return 0;
		
	hl=treehgt(root->left);
	hr=treehgt(root->right);

	if (hr>hl)
		return (hr+1);
	return (hl+1);
}

int main()
{
	bstree b;
	int ch,data,n;
	char key;
	do
	{
		cout<<"\n*** BINARY SEARCH TREE ***";
		cout<<"\n\t1.Insert \n\t2.No of Nodes \n\t3.Maximum & Minimum Data \n\t4.Inorder \n\t5.Preorder \n\t6.Postorder \n\t7.Search \n\t8.Height \n\t9.Exit"<<endl;
		cout<<"\nEnter Your Choice: ";
		cin>>ch;
		
		switch (ch)
		{
			case 1:
				cout<<"\nHow many nodes do you want to insert ? : ";
				cin>>n;
				for (int i=0; i<n;i++)
				{
					b.insert(n);
				}
				break;
			
			case 2:
				cout<<"\nNumber of Nodes : "<<b.countnode(b.root)<<endl;
				break;
				
			case 3:
				cout<<"Maximum Data: "<<b.findmax(b.root)<<endl;
				cout<<endl;
				cout<<"Minimum Data: "<<b.findmin(b.root)<<endl;
				break;
			
			case 4:
				b.inorderR(b.root);
				break;
				
			case 5:
				b.preorderR(b.root);
				break;
				
			case 6:
				b.postorderR(b.root);
				break;
				
			case 7:
				b.search(key);
				break;

			case 8:
				cout<<"\nTree Height : "<<b.treehgt(b.root)<<endl;
				break;

			case 9:
				cout<<"Exit"<<endl;
				break;
				
			default:
				cout<<"\nInvalid Choice"<<endl;
				break;
		}
	}
	while (ch!=9);
	return 0;
}

/*
OUTPUT

*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 1

How many nodes do you want to insert ? : 6

Enter the Data: 20

Enter the Data: 10

Enter the Data: 40

Enter the Data: 30

Enter the Data: 50

Enter the Data: 5

*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 2

Number of Nodes : 6

*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 3
Maximum Data: 50

Minimum Data: 5

*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 4
5       10      20      30      40      50
*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 5
20      10      5       40      30      50
*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 6
5       10      30      50      40      20
*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 7

Enter the key to be Search: 30

Node is found!

*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 8

Tree Height : 2

*** BINARY SEARCH TREE ***
        1.Insert
        2.No of Nodes
        3.Maximum & Minimum Data
        4.Inorder
        5.Preorder
        6.Postorder
        7.Search
        8.Height
        9.Exit

Enter Your Choice: 9
Exit
*/
