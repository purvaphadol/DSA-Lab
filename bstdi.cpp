/*
Que. A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation. 
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<stack>
using namespace std;

class node
{
	public:
		string word,mean;
		node *left;
		node *right;
		node()
		{
			left=NULL;
			right=NULL;
		}

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
	 	void insert();
	 	void preorder(node *);
	 	void inorder(node *);
	 	void postorder(node *);
	 	void inorderNR(node *);
		void postorder_NR(node *);
	 	void descending(node *);
	 	node* successor(node* root);
	 	node* remove(node* , string);
	 	void search(string,node *);
	 	void update(string,string ,node *);
};

void bstree::create()
{
	if(root==NULL)
	{	root=new(node);
		cout<<"\nEnter the word and mean: ";
		cin>>root->word>>root->mean;
		return ;
	}
}

void bstree::insert()
{	
	node *temp,*p;
	if(root==NULL)
	{	
		create();
		return;
	}
	p=new(node);
	cout<<"\nEnter the word and mean: ";
	cin>>p->word>>p->mean;
	
	temp=root;
	while(temp!=NULL)
	{
		if(p->word<temp->word)
		{
			if(temp->left==NULL)
			{
				temp->left=p;
				break;
			}
			else
			{
				temp=temp->left;
			}
		}
		else if(p->word>temp->word)
		{
			if(temp->right==NULL)
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
			cout<<"\nAlready inserted";
			break;
		}
	}
}

void bstree::inorder(node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout<<root->word<<"-"<<root->mean<<" --> ";
		inorder(root->right);
	}
	else
	{
		return;
	}
}

void bstree::preorder(node *root)
{	
	if (root!=NULL)
	{
		cout<<root->word<<"-"<<root->mean<<" --> ";
		preorder(root->left);
		preorder(root->right);
	}
	else
	{return;}
}

void bstree :: postorder(node *root)
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->word<<"-"<<root->mean<<" --> ";
	}
	else
	{return;}
}

void bstree:: inorderNR(node* root)
{
	
	stack<node *>s1;
	node *temp=root;
	do{
		while(temp != NULL)
		{
			s1.push(temp);
			temp = temp->left;
		}
		if(s1.empty())
		{break;}
		temp = s1.top();
		s1.pop();
		cout<<"\t"<<temp->word<<"-"<<temp->mean<<" --> ";
		temp = temp->right;
	}
	while(1);
}

void bstree::postorder_NR(node *root)
{
    stack<node*> s1, s2;
    node *T = root;
    cout << "\n";
    s1.push(T);
    while (!s1.empty())
    {
        T = s1.top();
        s1.pop();
        s2.push(T);
        if (T->left != NULL)
            s1.push(T->left);
        if (T->right != NULL)
            s1.push(T->right);
    }
    while (!s2.empty())
    {
        root = s2.top();
        s2.pop();
        cout<<"\t"<<root->word<<"-"<<root->mean<<" --> ";
    }
}

void bstree :: descending(node *root)
{
	stack<node *>s1;
	node *temp=root;
	do{
		while(temp != NULL)
		{
			s1.push(temp);
			temp = temp->right;
		}
		if(s1.empty())
		{break;}
		temp = s1.top();
		s1.pop();
		cout<<"\t"<<temp->word<<"-"<<temp->mean<<" --> ";
		temp = temp->left;
	}
	while(1);
}

node* bstree:: successor(node* root) 
{
    while (root->left != NULL)
        root = root->left;
        return root;
}

node* bstree::remove(node* root, string key) 
{
    if(root == NULL)
        return root;
    
    if(key < root->word)
        root->left = remove(root->left, key);

    else if(root->word < key)
        root->right = remove(root->right, key);

    else {                    
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if (root->left == NULL)
                return root->right;

        else if (root->right == NULL)
            return root->left;
            node *IS = successor(root->right);
            root->word = IS->word;
            root->right = remove(root->right, IS->word);
    }
    return root;
}

void bstree::search(string value,node *root)
{
	node *temp=root;
	int count=0;
	if(temp==NULL)
	{cout<<"\nEmpty binarry search tree";}
	while(temp!=NULL)
	{
		if(temp->word==value)
		{	
			cout<<"\nWord found \n";
			cout<<temp->word<<"--"<<temp->mean<<" ";
			break;
		}
		else if(value<temp->word)
		{
			temp=temp->left;
			
 		}
		else
		{
			temp=temp->right;

		}
		count++;
	}
	if(temp==NULL)
	{
		cout<<"\nWord not found";
	}
}

void bstree::update(string value,string newmean,node *root)
{
	node *temp=root;
	int count=0;
	if(temp==NULL)
	{
		cout<<"\nEmpty binarry search tree";
	}
	while(temp!=NULL)
	{
		if(temp->word==value)
		{	
			temp->mean=newmean;
			cout<<temp->word<<"--"<<temp->mean<<" ";
			break;
		}
		else if(value<temp->word)
		{
			temp=temp->left;
			
 		}
		else
		{
			temp=temp->right;

		}
		count++;
	}
	if(temp==NULL)
	{
		cout<<"\nWord not found";
	}
}
int main()
{
	string findme,newmean,wordchg,x;
	bstree bs1;
	int n,ch;
	do
	{
		cout<<"\n**MENU**\n 1.INSERT \n 2.INORDER \n 3.PREORDER \n 4.INORDER NR \n 5.POSTORDER \n 6.SEARCH \n 7.UPDATE \n 8.DELETE \n 9.POSTORDER NR \n 10.EXIT"<<endl;
		cout<<"\nEnter your choice : ";
		cin>>ch;
	
	switch(ch)
	{
		case 1:
			cout<<"\nEnter number of entries: ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				bs1.insert();
			}
			break;
		case 2:
			cout<<"\nTree representation using inorder : "<<endl;
			bs1.inorder(bs1.root);
			break;
		case 3:		
			cout<<"\nTree representation using preorder: ";
			bs1.preorder(bs1.root);
			break;
		case 4:
			cout<<"\nINORDER NON RECURSIVE : "<<endl;
			bs1.inorderNR(bs1.root);
			cout<<"\nDESCENDING ORDER : "<<endl;
			bs1.descending(bs1.root);
			break;
		case 5:
			cout<<"\nPOSTORDER : "<<endl;
			bs1.postorder(bs1.root);
			break;
		case 6:
			cout<<"\nEnter word to be search: ";
			cin>>findme;
			bs1.search(findme,bs1.root);
			break;
		case 7:
			cout<<"\nEnter word and its new meaning : ";
			cin>>wordchg>>newmean;
			bs1.update(wordchg,newmean,bs1.root);
			break;
		case 8:
		    cout << "Enter key : ";
		    cin >> x;
		    bs1.remove(bs1.root, x);
		    break; 
		case 9:
			cout<<"\nPOSTORDER NR : "<<endl;
			bs1.postorder_NR(bs1.root);
			break;           
		case 10:
			cout<<"\nExit"<<endl;
			exit(10);
			break;
		default:
			cout<<"\nInvalid Choice"<<endl;
			break;
	}
	}while(ch != 10);
	return 0;
}
/*
OUTPUT
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 1

Enter number of entries: 5

Enter the word and mean: legacy
bequest

Enter the word and mean: vigilant
watchful

Enter the word and mean: abhor
hate

Enter the word and mean: bitter 
unpleasant

Enter the word and mean: short
small

**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 2

Tree representation using inorder :
abhor-hate --> bitter-unpleasant --> legacy-bequest --> short-small --> vigilant-watchful -->
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 3

Tree representation using preorder: legacy-bequest --> abhor-hate --> bitter-unpleasant --> vigilant-watchful --> short-small -->
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 4

INORDER NON RECURSIVE :
        abhor-hate -->  bitter-unpleasant -->   legacy-bequest -->      short-small -->         vigilant-watchful -->
DESCENDING ORDER :
        vigilant-watchful -->   short-small -->         legacy-bequest -->      bitter-unpleasant -->   abhor-hate -->
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 5

POSTORDER :
bitter-unpleasant --> abhor-hate --> short-small --> vigilant-watchful --> legacy-bequest -->
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 6

Enter word to be search: vigilant
Word found
vigilant--watchful
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 7

Enter word and its new meaning : bitter
undelight
bitter--undelight
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 8
Enter key : short

**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 9

POSTORDER NR :
        bitter-undelight -->    abhor-hate -->  vigilant-watchful -->   legacy-bequest --> 
**MENU**
 1.INSERT
 2.INORDER
 3.PREORDER
 4.INORDER NR
 5.POSTORDER
 6.SEARCH
 7.UPDATE
 8.DELETE
 9.POSTORDER NR
 10.EXIT

Enter your choice : 10

Exit
*/