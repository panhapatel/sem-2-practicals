#include<iostream>
using namespace std;

class Wallet{

int id;
string name;
float balance;

public:
/*
wallet(int userid,string username,float bal=0)
{
    id=userid;
    name=username;
    balance=bal;
}*/
void money(){
cout<<"Enter User id: ";
cin>>id;
cin.ignore();
cout<<"Enter User name: ";
getline(cin,name);
cout<<"Enter current balance: ";
cin>>balance;
}
void loadmoney(float amount){
   if(amount>0){
    balance=balance+amount;
   }
   else {
    cout<<"Invalid amount"<<endl;
   }

}
void TransferMoney(Wallet &w2,float amount){
   if(amount<=0)
    cout<<"Invalid amount";
   else if(balance<amount)
    cout<<"Insufficient balance"<<endl;
   else{
    balance = balance - amount;
    w2.balance+=amount;
    cout<<"Transferred successfully"<<endl;
   }

}
void display(){
   cout<<"Wallet id: "<<id<<endl;
   cout<<"User name: "<<name<<endl;
   cout<<"Balance: "<<balance<<endl;

}
};
int main()
{   int choice,amount;
    Wallet w1,w2;
    cout<<"-----Details of wallet w1-----"<<endl;

    w1.money();
    cout<<"-----Details of wallet w2-----"<<endl;

    cin.ignore();
    w2.money();
    do{
      cout<<"----choice----"<<endl;
      cout<<"1.Load Money"<<endl;
      cout<<"2.Transfer Money"<<endl;
      cout<<"3.Display Money"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice){
    case 1:
        cout<<"Enter amount: ";
        cin>>amount;
        w1.loadmoney(amount);
        break;

    case 2:
        cout<<"Enter amount to transfer: ";
        cin>>amount;
        w1.TransferMoney(w2,amount);
        break;
    case 3:
        cout<<"-- wallet 1 Details--"<<endl;
        w1.display();
         cout<<"-- wallet 2 Details--"<<endl;
        w2.display();
        break;
    case 4:
        cout<<"**Exit**"<<endl;
        break;
    default:
        cout<<"Tnvalid choice";

      }

    }while(choice!=4);

    return 0;
}
