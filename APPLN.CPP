#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
void get();
void search();
void del();
void disp();
void menu();
int n;
class student
{
	int rollno;
	char name[30];
	int age;
	public:
	student *left,*right;
	void getdata();
	void putdata();
	int roll();
}*root,s[10],*p,*q;
void student :: getdata()
{
	clrscr();
	cout<<"\nEnter the rollno. of student : ";cin>>rollno;
	cout<<"\nEnter the name of student : ";gets(name);
	cout<<"\nEnter the age of student : ";cin>>age;
}
void student :: putdata()
{
cout<<"\n=============================================================\n";
cout<<"Rollno.\tName\tAge\n";
cout<<rollno<<"\t"<<name<<"\t"<<age;
cout<<"\n=============================================================\n";
}
int student :: roll()
{
	return rollno;
}

void menu()
{
int i;
clrscr();
for(i=0;i<80;i++)
cout<<"=";
cout<<"\n\t\t\t> > > > M E N U < < < <\n\n";
for(i=0;i<80;i++)
cout<<"=";
cout<<"\n";
cout<<"\n\t\t\t1. Insert a record in BST... \n";
cout<<"\n\t\t\t2. Delete a record from BST... \n";
cout<<"\n\t\t\t3. Search for roll number in BST... \n";
cout<<"\n\t\t\t4. Display the record of entered roll number... \n";
cout<<"\n\t\t\t5. Exit...\n";
int ch;
cout<<"\n\nEnter the choice from above : \n";
cin>>ch;
switch(ch)
{
	case 1 :
		get();
		break;
	case 2 :
		del();
		break;
	case 3 :
		search();
		break;
	case 4 :
		disp();
		break;
	case 5 :
		exit(0);
	default :
		cout<<"\nWrong Choice...\n";
}
}

void get()
{
clrscr();
int i,n;
char ch;
cout<<"\nEnter the no. of students : ";cin>>n;
for(i=0;i<n;i++)
{
	s[i].getdata();
	if(i==0)
	{
		root=&s[i];
		root->left=NULL;
		root->right=NULL;
		p=root;
	}
	else if(s[i].roll()<root->roll())
	{
		ch='l';
		p=root;
		q=p;
		p=p->left;
		while(p!=NULL)
		{
			if(s[i].roll()<p->roll())
			{
				ch='l';
				if(p->left==NULL)
					q=p;
				p=p->left;
			}
			else
			{
				ch='r';
				if(p->right==NULL)
					q=p;
				p=p->right;
			}
		}
		if(ch=='l')
		{
			p=&s[i];
			p->left=NULL;
			p->right=NULL;
			q->left=p;
		}
		else
		{
			p=&s[i];
			p->left=NULL;
			p->right=NULL;
			q->right=p;
		}
	}

	else
	{
		ch='r';
		p=root;
		q=p;
		p=p->right;
		while(p!=NULL)
		{
			if(s[i].roll()<p->roll())
			{
				ch='l';
				if(p->left==NULL)
					q=p;
				p=p->left;
			}
			else
			{
				ch='r';
				if(p->right==NULL)
					q=p;
				p=p->right;
			}
		}
		if(ch=='l')
		{
			p=&s[i];
			p->left=NULL;
			p->right=NULL;
			q->left=p;
		}
		else
		{
			p=&s[i];
			p->left=NULL;
			p->right=NULL;
			q->right=p;
		}
	}
}
cout<<"\n\nAll roll numbers stored...";
getch();
menu();
}

void search()
{
	clrscr();
	p=root;
	cout<<"\nEnter the roll number to be searched : ";
	int a;
	cin>>a;
	if(a==root->roll())
		cout<<"\nIt is the root node...\n";
	else
	{
	cout<<"\nFrom Root node the route is :\n";
	while(p!=NULL)
	{
		if(a<p->roll())
		{
			p=p->left;
			cout<<"left\n";
		}
		else
		{
			p=p->right;
			cout<<"right\n";
		}
		if(a==p->roll())
			break;
	}
	if(p==NULL)
	{
		clrscr();
		cout<<"\nThe roll number is not in the list...";
	}
	}
	getch();
	menu();
}

void del()
{
	clrscr();
	student *r;
	int x;
	cout<<"\nEnter the rollno. to be deleted : ";
	cin>>x;
	p=root;
	q=root;
	r=root;
	int i=0;
	char ch1,ch2;
	while(r!=NULL)
	{
		if(x==r->roll())
			break;
		else if(x<r->roll())
		{
			if(i>0 && ch1=='l')
			{
				q=q->left;
				ch2='l';
			}
			else if(i>0 && ch1=='r')
			{
				q=q->right;
				ch2='r';
			}
			if(i>1 && ch2=='l')
				p=p->left;
			else if(i>1 && ch2=='r')
				p=p->right;
			r=r->left;
			ch1='l';
		}
		else
		{
			if(i>0 && ch1=='l')
			{
				q=q->left;
				ch2='l';
			}
			else if(i>0 && ch1=='r')
			{
				q=q->right;
				ch2='r';
			}
			if(i>1 && ch2=='l')
				p=p->left;
			else if(i>1 && ch2=='r')
				p=p->right;
			r=r->right;
			ch1='r';
		}
		i++;
	}
	if(r==NULL)
		cout<<"\nThe roll number is not in the tree...\n";
	else
	{
		if(r==root)
			cout<<"\nYou cannot delete root node...";
		else if(r->left==NULL && r->right==NULL)
		{
			if(q->right==r)
				q->right=NULL;
			else
				q->left=NULL;
			delete r;
		}
		else if(r->left==NULL || r->right==NULL)
		{
			if(p==q)
			{
				if(r->left==NULL)
				{
					if(q->left==r)
						root->left=r->right;
					else
						root->right=r->right;
				}
				else
				{
					if(q->left==r)
						root->left=r->left;
					else
						root->right=r->left;
				}
				delete r;
			}
			else
			{
				p=q;
				q=r;
				if(r->left==NULL)
					r=r->right;
				else if(r->right==NULL)
					r=r->left;
				if(p->right==q)
					p->right=r;
				else if(p->left==q)
					p->left=r;
				delete q;
			}
		}
		else
		{
			p=r;
			r=r->right;
			while(r->left!=NULL)
			{
				r=r->left;
			}
			if(q->right==p)
			{
				r->right=(q->right)->right;
				r->left=(q->right)->left;
				q->right=r;
			}
			else
			{
				r->right=(q->left)->right;
				r->left=(q->left)->left;
				q->left=r;
			}
			delete p;
		}
		cout<<"\nThe record of entered roll number is deleted...";
	}
	getch();
	menu();
}

void disp()
{
	clrscr();
	p=root;
	cout<<"\nEnter the roll number whose record to be displayed : ";
	int a;
	cin>>a;
	if(a==root->roll())
		root->putdata();
	else
	{
	while(p!=NULL)
	{
		if(a<p->roll())
			p=p->left;
		else
			p=p->right;
		if(a==p->roll())
			break;
	}
	if(p==NULL)
	{
		clrscr();
		cout<<"\nThe roll number is not in the list...";
	}
	else
		p->putdata();
	}
	getch();
	menu();
}

void main()
{
clrscr();
menu();
getch();
}