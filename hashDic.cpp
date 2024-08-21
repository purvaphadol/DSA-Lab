/*
Que. Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key).
*/

#include <iostream>
#include <string.h>
#define MAX 20
#define SIZE 30
using namespace std;
class node
{
    public:
        char word[SIZE], meaning[SIZE];
        node *next;
};

class hashing
{
    node *t[MAX];
    int pos;
    public:
        hashing()
        {
            for (int i=0; i<MAX; i++)
            {
                t[i]=new node;
                t[i]=NULL;
            }
        }
        void display();
        void create();
        void insert(node *);
        int hash(char[]);
        void del(char[]);
        void search(char[]);
        void deleteAll();
};

void hashing :: deleteAll()
{
    for (int i=0; i<MAX; i++)
    {
        t[i]=NULL;
    }
}

void hashing :: display()
{
    node *temp;
    cout << "\nLetter \tWord  \tMeaning" << endl;
    for (int i=0; i<MAX; i++)
    {
        temp=t[i];
        cout<<char(i+65)<<" :\t\t ";
        if (t[i]==NULL)
        {
            cout<<" ";
        }
        else
        {
            while (temp->next!=NULL)
            {
                cout<<temp->word<<" : "<<temp->meaning<<"-->";
                temp=temp->next;
            }
            if (temp->next == NULL)
            {
                cout<<temp->word<<" : "<<temp->meaning<<"-->";
            }
        }
        cout<<endl;
    }
}

void hashing::create()
{
    node *New;
    New=new node;
    cout<<"ENTER WORD : ";
    cin>>New->word;
    cin.ignore();
    cout<<"ENTER MEANING : ";
    cin.getline(New->meaning,30);
    New->next=NULL;
    insert(New);
}

int hashing :: hash(char word[SIZE])
{
    return (toupper(word[0])-65);
}

void hashing::insert(node *New)
{
    pos=hash(New->word);
    node *temp;
    temp=t[pos];
    if (t[pos]==NULL)
    {
        t[pos]=New;
    }
    else
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=New;
    }
}

void hashing::del(char word[])
{
    int count=0;
    pos=hash(word);
    node *temp,*prev;
    temp=t[pos];
    if (t[pos]==NULL)
    {
        cout<<"No Such Element Is Found"<< endl;
    }
    else
    {
        if (strcmp(temp->word, word) == 0)
        {
            if (temp->next==NULL)
            {
                t[pos]=NULL;
            }
            else
            {
                t[pos]=temp->next;
            }
        }
        else
        {
            while (temp!=NULL)
            {
                prev=temp;
                temp=temp->next;
                if (strcmp(temp->word, word) == 0)
                {
                    prev->next=temp->next;
                    break;
                }
                else
                {
                    count=-1;
                }
            }
            if (temp==NULL)
            {
                count = -1;
            }
        }
        if (count==-1)
        {
            cout<<"No Such Element Is Found"<<endl;
        }
        else
        {
            cout<<word<<" is Deleted"<<endl;
        }
    }
}

void hashing::search(char word[])
{
    pos=hash(word);
    node *temp;
    temp=t[pos];

    if (t[pos]==NULL)
    {
        cout<<"NO RESULTS FOUND";
    }
    else
    {
        while (temp!=NULL)
        {
            if (strcmp(temp->word, word) == 0)
            {
                cout<<"Meaning of "<<word<<" is :"<<temp->meaning<<endl;
                break;
            }
            else
            {
                temp=temp->next;
            }
        }
        if (temp==NULL)
        {
            cout<<"Word Not Found In Dictionary"<<endl;
        }
    }
}

int main()
{
    hashing h;
    char key[SIZE];
    int ch;
    do
    {
        cout<<"\n\t---DICTIONARY---"<<endl;
        cout<<"\t1.Insert \n\t2.Display \n\t3.Delete \n\t4.Search \n\t5.Exit" << endl;
        cout<<"\t----------------"<<endl;

        cout<<"Enter Your Choice: ";
        cin>>ch;

        switch (ch)
        {
            case 1:
                h.create();
                break;

            case 2:
                h.display();
                break;

            case 3:
                cout<<"\nEnter Word To Be Deleted : ";
                cin>>key;
                h.del(key);
                break;

            case 4:
                cout <<"\nEnter Word To Be Searched : ";
                cin>>key;
                h.search(key);
                break;

            case 5:
                cout<<"Exit";
                exit(0);

            default:
                cout<<"\nInvalid Choice"<< endl;
                break;
        }
    }
    while (ch!=5);
    return 0;
}

/*
OUTPUT

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 1 
ENTER WORD : Objective
ENTER MEANING : Aim

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 1
ENTER WORD : Accelerate
ENTER MEANING : To speed up

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 1
ENTER WORD : Accurate
ENTER MEANING : Correct

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 2

Letter  Word    Meaning
A :              Accelerate : To speed up-->Accurate : Correct-->
B :
C :
D :               
E :
F :
G :
H :
I :
J :
K :
L :
M :
N :
O :              Objective : Aim-->
P :
Q :
R :
S :
T :

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 3

Enter Word To Be Deleted : Accurate
Accurate is Deleted

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 2

Letter  Word    Meaning
A :              Accelerate : To speed up-->
B :
C :
D :
E :
F :
G :
H :
I :
J :
K :
L :
M :
N :
O :              Objective : Aim-->
P :
Q :
R :               
S :
T :

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 4

Enter Word To Be Searched : Objective
Meaning of Objective is :Aim

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 4

Enter Word To Be Searched : Ability
Word Not Found In Dictionary

        ---DICTIONARY---
        1.Insert
        2.Display
        3.Delete
        4.Search
        5.Exit
        ----------------
Enter Your Choice: 5
Exit
*/
