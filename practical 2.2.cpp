#include<iostream>
#include<string>
using namespace std;

class student{
private:

  string ID;
  string name;
  int marks[3];
public:

student(){
   ID="25CE085";
   name="Panha";
   marks[0]=15;
   marks[1]=15;
   marks[2]=15;
}
 void putdata()
 {
     cout<<"student id is "<<ID<<endl;
     cout<<"Student name is "<<name<<endl;
     for(int i=0;i<3;i++){
        cout<<"marks ["<<i<<"]="<<marks[i]<<endl;
     }
     cout<<"Average = "<<average()<<endl;
 }
 void getdata()
 {
   cout<<"Enter student id: ";
    cin.ignore();
   getline(cin, ID);

   cout<<"Enter student name: ";
    cin.ignore();
   getline(cin, name);

   for(int i=0;i<3;i++){
   cout<<"Enter marks ["<<i<<"]=";
   cin>>marks[i];
   }
 }
 void display()
 {

     cout<<"Student id = "<<ID<<endl;
     cout<<"Student name = "<<name<<endl;
     for(int i=0;i<3;i++){
        cout<<"marks ["<<i<<"] = "<<marks[i]<<endl;
     }
     cout<<"Average = "<<average()<<endl;
 }
  float average()
 {
     float ave;
     ave=(marks[0]+marks[1]+marks[2])/3.0;
     return ave;
 }


};

int main()
{
   student s1;
   int choice;
   student s[100];
   s1.putdata();
   int count=0;
 do{
   cout<<"------STUDENT ACADEMIC RECORD SYSTEM------"<<endl;
   cout<<"1.Add student detail"<<endl;
   cout<<"2.Display all details"<<endl;
   cout<<"3.Exit"<<endl<<endl;
   cout<<"Enter your choice: ";
   cin>>choice;

   switch(choice){
   case 1:
       int n;

       cout<<"\nEnter number of students(for details): ";
       cin>>n;
       if(count + n<=100 && n>0){
            for(int i=0;i<n;i++){
                    cout<<"\nDetail of student "<<i+1<<endl;
                s[count].getdata();
                count++;
            }
         }
       else
        cout<<"Not enough space!"<<endl;

       break;

   case 2:
       for(int i=0;i<count;i++){
            cout<<"\n.....student "<<i+1<<" detail....."<<endl;
        s[i].display();
       }break;

   case 3:
     cout<<"Exit"<<endl;
     break;

  default:

     cout<<"Invalid choice"<<endl;

   }
 }while(choice!=3);
   return 0;
}
