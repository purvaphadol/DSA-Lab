/*
Que. Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.
*/

#include<iostream>
#include<string>
#define N 10
using namespace std;

class phone
{
    public:
    string name;
    long long int number;

    phone()
    {
        name=" ";
        number=0;
    }
};

class hasht
{
    public:
    phone p[10];
    int i, idx;

    hasht()
    {
        for(i=0;i<N;i++)
        {
            p[i].name=" ";
            p[i].number=0;
        }
    }
    
    void display()
    {
        for(i=0;i<N;i++)
        {
            cout<<"\n"<<i<<"\t"<<p[i].name<<" : "<<p[i].number<<"\n";
        }
    }

    int hash(long long int key)
    {
        return key%N;
    }
    
    int linearprobe(int key)
    {
        return ((hash(key)+i)%N);
    }

    int insert(phone ph)
    {
        idx = hash(ph.number);
        if(p[idx].number==0)
        {
            p[idx]=ph;
        }
        else
        {
            for (int i = (idx + 1) % N; i != idx; i = (i + 1) % N)
            {
                idx=linearprobe(ph.number);
                if (p[i].number == 0)
                {
                    p[i] = ph;
                    break;
                }
            }
        }
    }

    int search(long long int num)
    {
        idx = hash(num);
        int flag;
        if (p[idx].number == num)
        {
            return idx;
        }
        else
        {
            for (int i = (idx + 1) % N; i != idx; i = (i + 1) % N)
            {
                if (p[i].number == num)
                {
                    flag = i;
                    break;
                }
                else
                {
                    flag = -1;
                }
            }
            return flag;
        }
    }

    void del(long long int num)
    {
        idx = hash(num);
        int f;
        if (p[idx].number == num)
        {
            p[idx].name = " ";
            p[idx].number = 0;
            cout << "Deleted Operation performed !!" << endl;
        }
        else
        {
            for (int i = (idx + 1) % N; i != idx; i = (i + 1) % N)
            {
                if (p[i].number == num)
                {
                    p[i].name = " ";
                    p[i].number = 0;
                    break;
                }
                else
                {
                    f = -1;
                }
            }
            if (f = -1)
            {
                cout << "\nNumber not found in the Phonebook" << endl;
            }
            else
            {
                cout << "Delete Operation Performed !!" << endl;
            }
        }   
    }
};

int main()
{
    int ch,n,i;
    long long int num;
    phone ph[10];
    phone b;
    hasht HT;
    int htt[10];
    do
    {
        cout<<"------MENU------\n";
        cout<<"\t1.Insertion\n";
        cout<<"\t2.Display\n";
        cout<<"\t3.Search\n";
        cout<<"\t4.Delete\n";
        cout<<"\t5.Exit\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;

        switch (ch)
        {
            case 1:
                cout<<"Enter the Number of Clients: ";
                cin>>n;
                for(i=0;i<n;i++)
                {
                    cout<<"\nEnter name: ";
                    cin>>ph[i].name;
                    cout<<"\nEnter number: ";
                    cin>>ph[i].number;
                }
                for(i=0;i<N;i++)
                {
                    HT.insert(ph[i]);
                }
                break;

            case 2:
                {
                    cout<<"\nDISPLAYING";
                    HT.display();
                }
                break;

            case 3:
                {
                    int flag;
                    cout << "Enter which contact number of client to search:" << endl;
                    cin >> num;
                    flag = HT.search(num);
                    if (flag > 0)
                    {
                        cout << "\nFound at: " << flag << endl;
                    }
                    else
                    {
                        cout << "\nNot found." << endl;
                    }
                }
                break;

            case 4:
                {
                    cout << "Enter which no. do you want to delete" << endl;
                    cin >> num;
                    HT.del(num);
                }
                break;

            case 5:
                cout<<"\nExit"<<endl;
                break;

            default:
                cout<<"\nInvalid Choice"<<endl;
                break;
        }
    } 
    while (ch!=5);
    return 0;
}

