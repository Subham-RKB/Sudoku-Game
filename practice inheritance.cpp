#include<iostream>
using namespace std;
/*class base{
	public: int a;
	protected:int b;
	private: int c;
	public:
		base(){
			cout<<"Base::"<<endl;
			a=10;b=20;c=30;
		}
		base(int a,int b,int c){
			this->a =a;
			this-> b =b;
			this->c =c;	
		}
		void print(){
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
};
class derived: public base{
	public: int d;
	protected: int e;
	private: int f;
	public:
		derived(){
			cout<<"Derived ::"<<endl;
			d=40;
			e=50;
			f=60;
		}
		derived(int a,int b,int c,int d,int e,int f):base(a,b,c){
			this->d =d;
			this->e=e;
			this->f=f;
			
		}
	void printderived(){
		base::print(); 
		cout<<d<<" "<<e<<" "<<f<<endl;
	}
	
};
main(){
	base ob1;
	ob1.print();
	base ob2(100,200,300);
	ob2.print();
	derived ob3;
	ob3.printderived();
	derived ob4(100,200,300,1000,2000,3000);
	ob4.printderived();
}
class base{

	protected:int a;

	public:
		void set(){
			cin>>a;
		}
		void print(){
			cout<<a<<endl;
		}
};
class derived: public base{
	protected: int a;
	public:
	void setderived(){
		base::set();
		cin>>a;
	}
	void printderived(){
		base::print(); 
		cout<<a<<endl;
	}
	
};
main(){
	base ob1;
	ob1.set();
	ob1.print();
	derived ob2;
	ob2.setderived();
	ob2.printderived();
}
void job_scheduling::schedule(){
	job temp;
	for(int i=0;i<no_of_jobs;i++){
		for(int j=i+1;j<no_of_jobs;j++){
			if(jobs[i].id>jobs[j].id){
				temp=jobs[i];
				jobs[i]=jobs[j];
				jobs[j]=temp;
			}
		}
	}
}
class job
{
    int id; 
    char name[20];
	int time;
	int memory;
	public:
		void get();
		int get_Id();
		int get_time();
		int get_memory();
};
class jobs{
	protected:
		int n;
		job joob[20];
	public:
		void get();
		void print();
		void schedule();
};
class timejs:public jobs{
	public:
		void schedule();
};
class spacejs:public jobs{
	public:
		void schedule();
};
void job::get(){
	cin>>id>>name>>time>>memory;
}
void job::print(){
	cout<<id<<name<<time<<memory;
}
int job::get_id(){
	return id;
}
int job::get_time(){
	return time;
} 
int job::get_memory(){
	return memory;
}
#include <stdio.h> 
#include <string.h> 
void search(char* p, char* t){ 
    int a = strlen(p); 
    int b = strlen(t);
    for (int i = 0; i <= b - a; i++) { 
        int j;
        for (j = 0; j < a; j++) 
            if (t[i + j] != p[j]) 
                break; 
  
        if (j == a)
            printf("Pattern found at index %d \n", i); 
    } 
}
int main(){ 
    char t[100]; 
    char p[100];
	printf("Give a word::\n");
	scanf("%s",t);
	printf("Give a small part of word to search in above given word::\n");
	scanf("%s",p); 
    search(p, t); 
    return 0; 
}*/ 
#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
#include <limits.h>   
struct Stack  
{  
unsigned capacity;  
int top;  
int *array;  
};  
struct Stack* createStack(unsigned capacity)  
{  
    struct Stack* stack =  
        (struct Stack*) malloc(sizeof(struct Stack));  
    stack -> capacity = capacity;  
    stack -> top = -1;  
    stack -> array =  
        (int*) malloc(stack -> capacity * sizeof(int));  
    return stack;  
}    
int isFull(struct Stack* stack)  
{  
return (stack->top == stack->capacity - 1);  
}  
int isEmpty(struct Stack* stack)  
{  
return (stack->top == -1);  
}   
void push(struct Stack *stack, int item)  
{  
    if (isFull(stack))  
        return;  
    stack -> array[++stack -> top] = item;  
}  
int pop(struct Stack* stack)  
{  
    if (isEmpty(stack))  
        return INT_MIN;  
    return stack -> array[stack -> top--];  
}    
void moveDisk(char fromPeg, char toPeg, int disk)  
{  
    printf("Move the disk %d from %c to %c \n",  
        disk, fromPeg, toPeg);  
}  
void moveDisksBetweenTwoPoles(struct Stack *src,  
            struct Stack *dest, char s, char d)  
{  
    int pole1TopDisk = pop(src);  
    int pole2TopDisk = pop(dest);   
    if (pole1TopDisk == INT_MIN)  
    {  
        push(src, pole2TopDisk);  
        moveDisk(d, s, pole2TopDisk);  
    }  
    else if (pole2TopDisk == INT_MIN)  
    {  
        push(dest, pole1TopDisk);  
        moveDisk(s, d, pole1TopDisk);  
    }   
    else if (pole1TopDisk > pole2TopDisk)  
    {  
        push(src, pole1TopDisk);  
        push(src, pole2TopDisk);  
        moveDisk(d, s, pole2TopDisk);  
    }   
    else
    {  
        push(dest, pole2TopDisk);  
        push(dest, pole1TopDisk);  
        moveDisk(s, d, pole1TopDisk);  
    }  
}  
void tohIterative(int num_of_disks, struct Stack  
            *src, struct Stack *aux,  
            struct Stack *dest)  
{  
    int i, total_num_of_moves;  
    char s = 'A', d = 'C', a = 'B';    
    if (num_of_disks % 2 == 0)  
    {  
        char temp = d;  
        d = a;  
        a = temp;  
    }  
    total_num_of_moves = pow(2, num_of_disks) - 1;  
    for (i = num_of_disks; i >= 1; i--)  
        push(src, i);  
  
    for (i = 1; i <= total_num_of_moves; i++)  
    {  
        if (i % 3 == 1)  
        moveDisksBetweenTwoPoles(src, dest, s, d);  
  
        else if (i % 3 == 2)  
        moveDisksBetweenTwoPoles(src, aux, s, a);  
  
        else if (i % 3 == 0)  
        moveDisksBetweenTwoPoles(aux, dest, a, d);  
    }  
}   
int main()  
{  
    int num_of_disks;
	printf("Enter the no. of disk::");
	scanf("%d",&num_of_disks);  
    struct Stack *src, *dest, *aux;   
    src = createStack(num_of_disks);  
    aux = createStack(num_of_disks);  
    dest = createStack(num_of_disks);  
    tohIterative(num_of_disks, src, aux, dest);  
    return 0;  
}  
