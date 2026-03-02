#include<iostream>
#include<string>
using namespace std;

class Item{
private:
   int id;
   string name;
   float price;
   int quantity;
public:

Item():id(832), name("soap"), price(50), quantity(10) {}

Item(int ID,string Name,float Price,int Q){
    id=ID;
    name=Name;
    price=Price;
    quantity=Q;
}

void putdata()
{   cout<<"--------------"<<endl;
    cout<<"Item id is "<<id<<endl;
    cout<<"Item name is "<<name<<endl;
    cout<<"Item price is "<<price<<endl;
    cout<<"Item quantity is "<<quantity<<endl;

}

void display()
{
    cout<<"--------------"<<endl;
    cout<<"Item id: "<<id<<endl;
    cout<<"Item name: "<<name<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Quantity: "<<quantity<<endl;
}
void AddItem(int q)
{
    if(q>0){
      quantity+=q;
       cout<<"Restock successfully"<<endl;
    }
    else{
        cout<<"Invalid quantity!"<<endl;
    }
}
void Sell(int q)
{
    if(q<=quantity){
        quantity-=q;
        cout<<" sold "<<q<<" of "<<name<<endl;
    }
    else{
        cout<<"No enough stock!"<<endl;
    }
}
int getID() const { return id; }

};

int main()
{
 int choice,id,q;
 Item I;
 I.putdata();
 Item i[5]={Item(102,"face wash",120,5),
           Item(103,"shampoo",150,3),
           Item(104,"sirumn",75,11),
           Item(105,"washing powder",60,7),
           Item(106,"liquid",99,18)
           };
           do{


           cout<<"---Inventory Management System---"<<endl;
           cout<<"1.Display current Items"<<endl;
           cout<<"2.Add item"<<endl;
           cout<<"3.Sell item"<<endl;
           cout<<"4.Exit"<<endl;

           cout<<"Enter the choice: ";
           cin>>choice;
           int flag;

           switch(choice){
       case 1:

            for(int j=0;j<5;j++){
           i[j].display();
       }
       break;
       case 2:
        cout<<"Enter Item id to Add: ";
        cin>>id;
        cout<<"Enter Quantity: ";
        cin>>q;
         flag=0;
        for(int j=0;j<5;j++){
            if(i[j].getID()==id){
                i[j].AddItem(q);
                flag=1;
                break;
            }

        }
            if(flag==0){
                cout<<"Item not found!"<<endl;
            }
            break;

       case 3:
         cout<<"Enter Item id for Sell: ";
         cin>>id;
         cout<<"Enter Quantity: ";
         cin>>q;
         cin.ignore(1000,'\n');
         for(int j=0;j<5;j++){
            if(i[j].getID()==id){
                i[j].Sell(q);
            }
         }break;
       case 4:
        cout<<"Exit.........."<<endl<<".........Thank you"<<endl;
             break;
       default:
        cout<<"Invalid choice"<<endl;
        break;
           }
}while(choice!=4);

return 0;
};
