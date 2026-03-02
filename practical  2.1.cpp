#include<iostream>
using namespace std;

class rectangle
{
private:
    float l;
    float w;
public:

    void Add()
    {
        cout<<"Enter length: ";
        cin>>l;
        cout<<"Enter width: ";
        cin>>w;
    }
    void update()
    {
        cout<<"Enetr new length: ";
        cin>>l;
        cout<<"Enter new width: ";
        cin>>w;

    }
    void display()
    {
        cout<<"LENGTH: "<<l<<endl;
        cout<<"WIDTH: "<<w<<endl;
        cout<<"AREA: "<<area()<<endl;
        cout<<"PARIMETER: "<<perimeter()<<endl;
    }
    int area()
    {
        int a;
        a=l*w;
        return a;
    }
    int perimeter()
    {
        int p;
        p=2*(l+w);
        return p;
    }

};

int main(){

rectangle R[50];
int choice;
int count=0;
int flag;
do{
 cout<<"--------Rectangle management system--------"<<endl;
 cout<<"1.Add rectangle"<<endl;
 cout<<"2.Updating dimensions"<<endl;
 cout<<"3.Dispaly all"<<endl;
 cout<<"4.Exit"<<endl;

 cout<<"Enetr choice: ";
 cin>>choice;

 switch(choice){

  case 1:
      if(count<50){
      cout<<"Add rectangle "<<count+1<<endl;
      R[count].Add();
      cout<<"Rectangle added successfully"<<endl;

      count++;
      }
      else
        cout<<"No enough space!"<<endl;
      break;


  case 2:{
    int n;
    flag=0;
    cout<<"Enetr rectangle number to update: ";
    cin>>n;
    for(int i=0;i<=count;i++){
        if(n>0 && n<=count){
            R[i].update();
            flag=1;
            cout<<"Rectangle update successfully"<<endl;
            break;
        }
    }
    if(flag!=1)
    cout<<"Invalid rectangle number!"<<endl;
    break;
  }
  case 3:
    for(int i=0;i<count;i++){
        cout<<"Details of Rectangle "<<i+1<<endl;
        R[i].display();
    }
      break;

  case 4:
    cout<<"---Exit---"<<endl;
    break;
  default:
    cout<<"Invalid choice"<<endl;

 }
}while(choice!=4);

return 0;

}
