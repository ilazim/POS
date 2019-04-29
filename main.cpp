#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int c=1;
class Sale;
class Inventory
{
public:

    string product[100];
    int price[100];
    int quantity[100];
    void create()
    {

        int ch=0;
        cout<<"Enter the name, initial quantity and price of the products"<<endl;
        while(1)
        {

            cout<<"Enter the name of product "<<c<<endl;
            cin>>product[c];
            cout<<"Enter the price of product "<<c<<endl;
            cin>>price[c];
            cout<<"Enter the quantity of product "<<c<<endl;
            cin>>quantity[c];
            cout<<"Do you want to add another item? Press 1 for yes 2 for no: ";
            cin>>ch;
            if (ch==2)
                break;
            else if (ch==1)
                c++;


        }


    }
    void show()
    {

        int a;
        for(a=1; a <= c; a++)
        {
            cout<<"Item number: "<<a<<endl;
            cout<<"Name: "<<product[a]<<endl;
            cout<<"Price: "<<price[a]<<endl;
            cout<<"Available in stock:"<<quantity[a]<<endl;
        }

    }
    friend void choice(Inventory obj, Sale obj2);
};

class Sale:public Inventory
{
    public:
    friend void choice(Inventory obj, Sale obj2);
    Sale()
    {
        cout<<"The list of available products:"<<endl;
        Inventory::show();
    }
    void order()
    {
        int temp,ch1;
        cout<<"Welcome to the order menu"<<endl;
x:
        cout<<"Enter the item number of the product:"<<endl;
        cin>>temp;
        if (temp <= c)
        {
            system("cls");
            cout<<"You have selected item number"<<temp<<endl;
            cout<<"Name: "<<Inventory::product[temp]<<endl;
            cout<<"Price: "<<Inventory::price[temp]<<endl;
            cout<<"Available in stock:"<<Inventory::quantity[temp]<<endl;
            cout<<"Would you like to confirm the order? Press 1 for yes 2 for no: ";;
            cin >> ch1;
            if (ch1==1)
            {
                int saleQty;
c:
                cout<<"Enter the number of "<<Inventory::product[temp]<< "you want ";
                cin>>saleQty;
                system("cls");
                if (saleQty>Inventory::quantity[temp])
                {
                    cout<<"Not enough in stock, please update!";
                    goto c;
                }
                else
                {
                    Inventory::quantity[temp]=Inventory::quantity[temp]-saleQty;
                    cout<<"Item name: "<<Inventory::product[temp]<<endl;
                    cout<<"Total quantity: "<<saleQty<<endl;
                    cout<<"Total price="<<saleQty*Inventory::price[temp]<<endl;
                    cout<<"Remaining quantity in stock: "<<Inventory::quantity[temp];

                }


            }
            else
            {
                cout<<"Wrong choice, try again"<<endl;
                goto x;
            }
        }
    }

};

    void Choice(Inventory obj, Sale obj2)
    {
        int choice, choice2;
        cout<<"Do you want to start sale operations or update inventory?"
            <<endl
            <<"Press 1 for inventory"
            <<endl
            <<"Press 2 for sales"
            <<endl;
        cin>>choice;
        if (choice==1)
        {
            obj.create();
            system("cls");
            cout<<"Do you want to view the inventory?"
                <<endl
                <<"Press 1 yes"
                <<endl
                <<"Press 2 no"
                <<endl;
            cin>>choice2;
            if (choice2==1)
            {
                obj.show();

            }
            else
                obj2.order();
        }

    }
    int main()
    {
        Inventory obj;
        Sale obj2;
        Choice(obj, obj2);

        return 0;
    }

