#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<windows.h>
#define cls system("CLS");
using namespace std;
const int MAX=50;

class User
{
public:
    int faculty()
    {
      ifstream inputFile("faculty.txt");
        if(!inputFile.is_open())
        {
            cout<<"Error opening the file!"<<endl;
            return 1;
        }
        string searchData;
        bool foundData = false;
        while(!foundData)
        {
            cout<<"\nEnter the ID: ";
            cin>>searchData;
            string line;
            while(getline(inputFile, line))
            {
                size_t found = line.find(searchData);
                if(found != string::npos)
                {
                    cout<<"\nFound : "<<line<<"\n";
                    foundData = true;
                    break;
                }
            }
            if(!foundData)
            {
                cout<<"\nData not found. Please enter correct data.\n"<<endl;
                inputFile.clear();
                inputFile.seekg(0);
            }
        }
        inputFile.close();
        return 0;
    }
    int staff()
    {
      ifstream inputFile("staff.txt");
        if(!inputFile.is_open())
        {
            cout<<"Error opening the file!"<<endl;
            return 1;
        }
        string searchData;
        bool foundData = false;

        while (!foundData)
        {
            cout<<"\nEnter the ID: ";
            cin>>searchData;
            string line;
            while (getline(inputFile, line))
            {
                size_t found = line.find(searchData);
                if(found != string::npos)
                {
                    cout<<"\nFound : "<<line<<endl;
                    foundData = true;
                    break;
                }
            }
            if(!foundData)
            {
                cout<<"\nData not found. Please enter correct data.\n"<<endl;
                inputFile.clear();
                inputFile.seekg(0);
            }
        }
        inputFile.close();
        return 0;
    }
    int student()
    {
      ifstream inputFile("student.txt");
        if(!inputFile.is_open())
        {
            cout<<"Error opening the file!"<<endl;
            return 1;
        }
        string searchData;
        bool foundData = false;
        while (!foundData)
        {
            cout<<"\nEnter the ID: ";
            cin>>searchData;
            string line;
            while (getline(inputFile, line))
            {
                size_t found = line.find(searchData);
                if(found != string::npos)
                {
                    cout<<"\nFound : "<<line<<endl;
                    foundData = true;
                    break;
                }
            }
            if(!foundData)
            {
                cout<<"\nData not found. Please enter correct data.\n"<<endl;
                inputFile.clear();
                inputFile.seekg(0);
            }
        }
        inputFile.close();
        return 0;
    }
};
class Account
{
private:
    double balance;
public:
    Account(){}
    Account(double b)
    {
        balance = b;
    }
    void after_orderbalance(double price)
    {
        balance=balance-price;
    }
    void getinfo()
    {
        cout<<endl<<endl;
        cout<<"Final Balance: "<<balance<<" Taka"<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    }
};
class Order
{
public:
    int itemNum,quantity;
};
class Menu
{
private:
    string name;
    double price;
    int Count=0;
    int n=10;
    Order orders[MAX];
public:
    void items(string n,double p)
    {
        name=n;
        price=p;
    }
    void displayMenu(Menu a[])
    {
        cout<<setw(20)<<left<<"Item"<<setw(15)<<right<<"Price"<<endl;
        cout<<"--------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<i+1<<". "<<setw(20)<<left<<a[i].name<<setw(10)<<right<<a[i].price<<" BDT"<<endl<<endl;
        }
    }
    void addItem(Menu b[])
    {
        if(n<MAX)
        {
            n++;
            cout<<"Enter the name of the item: ";
            cin>>b[n-1].name;
            cout<<"Enter the price of the item: ";
            cin>>b[n-1].price;
            cout<<b[n-1].name<<" has been added to the menu."<<endl;
        }
        else
        {
            cout<<"Menu is full. Cannot add more items."<<endl;
        }
    }
    void removeItem(Menu c[])
    {
        int x,y=-1;
        cout<<"Enter the number of the item which you want to remove: ";
        cin>>x;
        for(int i=0;i<n;i++)
        {
            if((i+1)==x)
            {
                cout<<c[i].name<<" has been removed from the menu."<<endl;
                y=i;
                break;
            }
        }
        if(y != -1)
        {
            for(int i=y;i<n-1;i++)
            {
                c[i]=c[i+1];
            }
            n--;
        }
        else
        {
            cout<<"Item not found in the menu."<<endl;
        }
    }
    double displayOrder(Menu m[])
    {
        double total=0;
        cout<<"Your orders:"<<endl;
        cout<<setw(20)<<left<<"Item"<<setw(15)<<right<<"Quantity        "<<setw(10)<<right<<"Price per item"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        for(int i=0;i<Count;i++)
        {
            int itemIndex=orders[i].itemNum-1;
            cout<<i+1<<". "<<setw(20)<<left<<m[itemIndex].name<<setw(0)<<right<<orders[i].quantity<<setw(20)<<right<<m[itemIndex].price<<" BDT"<<endl;
            total=total+(orders[i].quantity * m[itemIndex].price);
        }
        cout<<"Total price: "<<total<<" BDT"<<endl;

        return total;
    }
    void addOrder()
    {
        int itemN,Quantity;
        cout<<"Enter the number of the item to order: ";
        cin>>itemN;
        if(itemN>0 && itemN<=n)
        {
            cout<<"Enter the quantity to order: ";
            cin>>Quantity;
            if(Count<MAX)
            {
                orders[Count].itemNum=itemN;
                orders[Count].quantity=Quantity;
                Count++;
                cout<<"Order placed successfully."<<endl;
            }
            else
            {
                cout<<"Maximum order limit reached. Cannot add more orders."<<endl;
            }
        }
        else
        {
            cout<<"Invalid item number. Please try again."<<endl;
        }

    }
    void removeOrder()
    {
        int orderNum;
        cout<<"Enter the number of the order to remove: ";
        cin>>orderNum;

        if(orderNum>0 && orderNum<=Count)
        {
            for(int i=orderNum-1;i<Count-1;i++)
            {
                orders[i]=orders[i+1];
            }
            Count--;
            cout<<"Order removed successfully."<<endl;
        }
        else
        {
            cout<<"Invalid order number. Please try again."<<endl;
        }
    }
    void order(Menu m[])
    {
        int choice;
        while(choice != 4)
        {
            cout<<"\nOrder Menu: "<<endl;
            cout<<"1. Display Orders"<<endl;
            cout<<"2. Add Order"<<endl;
            cout<<"3. Remove Order"<<endl;
            cout<<"4. Back to Main Menu"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice)
            {
            case 1:
                if(Count==0)
                {
                    cout<<"No orders placed yet."<<endl;
                }
                else
                {
                    double requiredtk=displayOrder(m);
                    Account acc(5000);
                    acc.after_orderbalance(requiredtk);
                    acc.getinfo();
                }
                break;
            case 2:
                addOrder();
                break;
            case 3:
                removeOrder();
                break;
            case 4:
                break;
            default:
                cout<<"Invalid option. Please try again."<<endl;
            }
        }
    }
};
void welcome()
{
      cout<<"\n\n\t\t\t\t\t WELCOME\n";
      cout<<"\t\t\t\t\t   TO ";
      Sleep(350);
      cout<<"\n\t\t\t\t\t  I";
      Sleep(130);
      cout<<"U";
      Sleep(130);
      cout<<"B";
      Sleep(130);
      cout<<"A";
      Sleep(130);
      cout<<"T";
      Sleep(130);
      cout<<"\n\t\t\t\t\tC";
      Sleep(130);
      cout<<"a";
      Sleep(130);
      cout<<"f";
      Sleep(130);
      cout<<"e";
      Sleep(130);
      cout<<"t";
      Sleep(130);
      cout<<"e";
      Sleep(130);
      cout<<"r";
      Sleep(130);
      cout<<"i";
      Sleep(130);
      cout<<"a \n\n\n";
      Sleep(650);
      Sleep(3350);
      system("CLS");
}
int main()
{
    welcome();

    int option;

    cout<<"Select option\n";
    cout<<"1. Faculty\n";
    cout<<"2. Staff\n";
    cout<<"3. Student\n";
    cout<<"\nEnter the option: ";
    cin>>option;

    User u;
    if(option == 1)
    {
        u.faculty();
    }
    else if(option == 2)
    {
        u.staff();
    }
    else if(option == 3)
    {
        u.student();
    }

    Menu a[MAX];
    a[0].items("Tea",10);
    a[1].items("Coffee",15);
    a[2].items("Coke",20);
    a[3].items("Samosa",5);
    a[4].items("Singara",5);
    a[5].items("Cake",35);
    a[6].items("Sandwich ",50);
    a[7].items("Burger",30);
    a[8].items("Lunch Special",60);
    a[9].items("Breakfast Special",30);

    int option1=-1;
    while(option1 != 5)
    {
        cout<<"\nPlease select an option: "<<endl;
        cout<<"1. Display Menu"<<endl;
        cout<<"2. Add Item(s) to Menu"<<endl;
        cout<<"3. Remove Item(s) from Menu"<<endl;
        cout<<"4. Order"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>option1;

        switch(option1)
        {
        case 1:
            a[0].displayMenu(a);
            break;
        case 2:
            a[0].addItem(a);
            break;
        case 3:
            a[0].removeItem(a);
            break;
        case 4:
            a[0].order(a);
            break;
        case 5:
           cout<<"Exiting the program. Thank you!"<<endl;
            break;
        default:
            cout<<"Invalid option. Please try again."<<endl;
        }
    }

      return 0;
}






