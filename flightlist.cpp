/*
Que. There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph. Check whether the graph is connected or not. Justify the storage representation used. 
*/

#include<iostream>
#include<string>
using namespace std;
#define maxSize 20

class node
{
    public:
        string cityName;
        node *link;
        int fuel,time;
        
        node()
        {
            cityName="NA";
            link=NULL;
            fuel=0;
            time=0;
        }
};


class flightSystem
{
    private:
        node *cityList[maxSize];
        int cityCount;
        
   public:
        
        flightSystem()
        {
            for(int i=0;i<maxSize;i++)
            {
                cityList[i]=new node;
            }
            cityCount=0;
        }
        
        void create();
        void insertCity(string name);
        void insertFlight(string name1,string name2);
        int index(string c);
        void displayCities();
        void displayRoutes();
        void searchCity(string name1);
        void searchFlight(string name1,string name2);
};

void flightSystem::create()
{
    int n;
    cout<<"How many cities do you want to enter ? ";
    cin>>n;
    if(n<=0)
    {
        cout<<"Number of Cities should be greater than 0"<<endl;
        return;
    }
    cityCount=n;
    cout<<"Enter the cities :"<<endl;
    for(int i=0;i<cityCount;i++)
    {
        cin>>cityList[i]->cityName;
    }
    cout<<"Flight System Created !!"<<endl;
}


void flightSystem::insertCity(string name)
{
    int flag=index(name);
    
    if(flag>=0)
    {
        cout<<"City already exists!!"<<endl;
    }
    else
    {
        cityList[cityCount]->cityName=name;
        cityCount++;
        cout<<"City Inserted Successfully !!"<<endl;
    }
}

int flightSystem::index(string c)
{
    for(int i=0;i<cityCount;i++)
    {
        if(cityList[i]->cityName==c)
        {
            return i;
        }
    }
    return -1;
}

void flightSystem::insertFlight(string name1,string name2)
{
    int pos=index(name1);
    node *temp=cityList[pos];
    node *newNode=new node();
    newNode->cityName=name2;
    cout<<"Enter the Fuel Required : ";
    cin>>newNode->fuel;
    cout<<"Enter the Time Required : ";
    cin>>newNode->time;
    
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=newNode;
    cout<<"Route Inserted Successfully!!"<<endl;
}


void flightSystem::displayCities()
{
    for(int i=0;i<cityCount;i++)
    {
        cout<<cityList[i]->cityName<<endl;
    }
    cout<<endl;
}


void flightSystem::displayRoutes()
{
    int i;
    node *temp;
    
    for(i=0;i<cityCount;i++)
    {
        temp=cityList[i];
        while(temp!=NULL)
        {
            cout<<temp->cityName<<" -> ";
            temp=temp->link;
        }
        cout<<endl;
    }
}

void flightSystem::searchCity(string name1)
{
    int i;
    node *temp;
    for(i=0;i<cityCount;i++)
    {
        if(cityList[i]->cityName==name1)
        {
            cout<<"City found at position "<<i<<endl;
            break;
        }
    }
    
    cout<<"Flights from this city are : "<<endl;
    
    temp=cityList[i];
    while(temp->link!=NULL)
    {
        temp=temp->link;
        cout<<temp->cityName<<endl;   
    }
}

void flightSystem::searchFlight(string city1,string city2)
{
    int pos=index(city1);
    node *temp=cityList[pos];
    while(temp->link!=NULL)
    {
        temp=temp->link;
        if(temp->cityName==city2)
        {
            cout<<"Flight exists between "<<city1<<" and "<<city2<<endl;
            cout<<"Time of flight : "<<temp->time<<endl;
            cout<<"Fuel Required during flight : "<<temp->fuel<<endl;
            return;
        }
    }
    //else
    cout<<"No Direct Flight exists between "<<city1<<" and "<<city2<<endl;
    
}

int main()
{
    flightSystem fs;
    int ch;
    string city1,city2;
    
    fs.create();
    do
    {
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"\tMENU"<<endl;
        cout<<"1. Insert City\n2. Insert Flight Route\n3. Search City"<<endl;
        cout<<"4. Search Flight Route\n5. Display Cities\n6. Display Flight Route\n7. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<"------------------------------------------------------------------------------"<<endl;
        
        switch(ch)
        {
            case 1: cout<<"Enter the name of the City to enter : ";
                    cin>>city1;
                    fs.insertCity(city1);
                    break;
                    
            case 2: cout<<"Enter source city : ";
                    cin>>city1;
                    cout<<"Enter destination city : ";
                    cin>>city2;
                    fs.insertFlight(city1,city2);
                    break;
                   
            case 3: cout<<"Enter the name of city to search : ";
                    cin>>city1;
                    fs.searchCity(city1);
                    break;
                    
            case 4: cout<<"Enter source city : ";
                    cin>>city1;
                    cout<<"Enter destination city : ";
                    cin>>city2;
                    fs.searchFlight(city1,city2);
                    break;
                   
            case 5: cout<<"Displaying Cities : "<<endl;
                    fs.displayCities();
                    cout<<endl;
                    break;
                
            case 6: cout<<"Displaying Flight Routes : "<<endl;
                    fs.displayRoutes();
                    break;
              
            case 7: cout<<"Exit"<<endl;
                    break;
            
            default : cout<<"Incorrect Choice "<<endl;
                      break;
        }
    }
    while(ch!=7);
    return 0;
}
/*
OUTPUT
How many cities do you want to enter ? 5
Enter the cities :
A
B
C
D
E
Flight System Created !!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 2
------------------------------------------------------------------------------
Enter source city : A
Enter destination city : B
Enter the Fuel Required : 13
Enter the Time Required : 6
Route Inserted Successfully!!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 2
------------------------------------------------------------------------------
Enter source city : A
Enter destination city : E
Enter the Fuel Required : 11
Enter the Time Required : 5
Route Inserted Successfully!!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 2
------------------------------------------------------------------------------
Enter source city : B
Enter destination city : C
Enter the Fuel Required : 14
Enter the Time Required : 7
Route Inserted Successfully!!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 2
------------------------------------------------------------------------------
Enter source city : C
Enter destination city : D
Enter the Fuel Required : 9
Enter the Time Required : 4
Route Inserted Successfully!!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 2
------------------------------------------------------------------------------
Enter source city : D
Enter destination city : E
Enter the Fuel Required : 8
Enter the Time Required : 3
Route Inserted Successfully!!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 5
------------------------------------------------------------------------------
Displaying Cities :
A
B
C
D
E


------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 6
------------------------------------------------------------------------------
Displaying Flight Routes :
A -> B -> E ->
B -> C ->
C -> D ->
D -> E ->
E ->
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 2
------------------------------------------------------------------------------
Enter source city : B
Enter destination city : A
Enter the Fuel Required : 10
Enter the Time Required : 4
Route Inserted Successfully!!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 2
------------------------------------------------------------------------------
Enter source city : D
Enter destination city : C
Enter the Fuel Required : 6
Enter the Time Required : 2
Route Inserted Successfully!!
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 6
------------------------------------------------------------------------------
Displaying Flight Routes :
A -> B -> E ->
B -> C -> A ->
C -> D ->
D -> E -> C ->
E ->
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 3
------------------------------------------------------------------------------
Enter the name of city to search : C
City found at position 2
Flights from this city are :
D
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 3
------------------------------------------------------------------------------
Enter the name of city to search : A
City found at position 0
Flights from this city are :
B
E
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 4
------------------------------------------------------------------------------
Enter source city : B
Enter destination city : D
No Direct Flight exists between B and D
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 4
------------------------------------------------------------------------------
Enter source city : A
Enter destination city : E
Flight exists between A and E
Time of flight : 5
Fuel Required during flight : 11
------------------------------------------------------------------------------
        MENU
1. Insert City
2. Insert Flight Route
3. Search City
4. Search Flight Route
5. Display Cities
6. Display Flight Route
7. Exit
Enter your choice : 7
------------------------------------------------------------------------------
Exit
*/
