/*#include<iostream>
 using namespace std;
 class base{
 public:int a;
 protected: int b;
 private: int c;
 public:
 base(){
 a=10;b=20;c=30;
 }
 void print(){
 cout<<a<<" "<<b<<" "<<c<<endl;
 }
 };
 class derived: public base{
 public:
 void change(){
 a=100;
 b=200;
 c=300;
 cout<<a<<" "<<b<<endl;
 }
 };
 main(){
 base ob1;
 ob1.print();//10,20,30
 derived ob2;
 ob2.change();//10,20,30
 }
 #include<iostream>
 using namespace std;
 class base{
 public:int a;
 protected: int b;
 private: int c;
 public:
 base(){
 cout<<"Base const"<<endl;
 a=10;b=20;c=30;
 }
 base(int a,int b,int c){
 cout<<"Base para const"<<endl;
 this->a=a;this->b=b;this->c=c;
 }
 void print(){
 cout<<a<<" "<<b<<" "<<c<<endl;
 }
 };
 class derived: public base{
 public:int d;
 protected: int e;
 private: int f;
 public:
 derived(){
 cout<<"Deried const"<<endl;
 d=40;e=50;f=60;
}
 derived(int a,int b,int c,int d, int e,int f):base(a,b,c)
 {
 cout<<"Deried para const"<<endl;
 this->d=d;this->e=e;this->f=f;
 }
 void printderived(){
 base::print();
 cout<<d<<" "<<e<<" "<<f<<endl;
 }
 };
 main(){
 //base ob1;
 //ob1.print();//10,20,30
 //base ob2(100,200,300);
 //ob1.print();
 derived ob3;//base default, derived default
 ob3.printderived();//
 derived ob4(100,200,300,400,500,600);//
 ob4.printderived();//
 }*/
 #include<iostream>
 using namespace std;
 class base1{
 protected: int a;
 public:
 void set1(){
 cout<<"enter value of a in base 1"<<endl;
 cin>>a;
 }
 void print1(){
 cout<<a<<endl;
 }
 };
 class base2{
 protected: int a;
 public:
 void set2(){
 cout<<"enter value of a in base 2"<<endl;
 cin>>a;
 }
 void print2(){
 cout<<a<<endl;
}
 };
 class derived: public base1,base2{
 protected: int a;
 public:
 void setderived(){
 base1::set1();
 base2::set2();
 cout<<"enter value of derived a"<<endl;
 cin>>a;
 }
 void printderived(){
 base1::print1();
 base2::print2();
 cout<<a<<endl;
 }
 };
 main(){
 // base ob1;//ob1.a
 // ob1.set();
 // ob1.print();
 derived ob2;//ob2.a,base1::a,base2::a
 ob2.setderived();
 ob2.printderived();
 }
