//******************
//HEADER FILES USED
//******************
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>

//***************************
//CLASS FOR CUSTOMERS
//***************************

 class customer
  {
	   int cno;
	   char name[10];
	   float mbno;
	   int points;
   public :
	   void create_cust()
	    {
	     clrscr();
	     cout<<"\n...NEW CUSTOMER ENTRY...\n";
	     cout<<"\nEnter the customer number : ";
	     cin>>cno;
	     cout<<"\nEnter the name of the customer : ";
	     gets(name);
	     cout<<"\nEnter mobile number : ";
	     cin>>mbno;
	     points=0;
	    }

	   void show_cust()
	    {
	     clrscr();
	     cout<<"\nCustomer number : "<<cno;
	     cout<<"\nCustomer name : ";
	     puts(name);
	     cout<<"\nMobile number : "<<mbno;
	     if(points>0)
	      {
	       cout<<"\nBonus points : "<<points;
	      }
	    }

	   void modify_cust()
	    {
	     clrscr();
	     char reply;
	     cout<<"\nwhat do you want to modify?";
	     cout<<"\nC. Customer Number";
	     cout<<"\nN. Name";
	     cout<<"\nM. Mobile Number";
	     cin>>reply;
	     if(reply=='C'&& reply=='c')
	      {
	       cout<<"\nNew customer number : ";
	       cin>>cno;
	      }
	     else if(reply=='N' && reply=='n')
	      {
	       cout<<"\nNew name : ";
	       cin>>name;
	      }
	     else if(reply=='M' && reply=='m')
	      {
	       cout<<"\nNew mobile number : ";
	       cin>>mbno;
	      }
	    }

	   void add_points()
	    { points++; }

	   void reset_points()
	    { points=0; }

	   int return_cno()
	    { return cno; }

	   int return_points()
	    { return points; }

	   int return_mbno()
	    { return mbno; }

	   void report()
	    { cout<<"\t"<<cno<<name<<points<<endl; }
  }c1;

//**************************
//CLASS FOR ITEMS
//**************************

 class item
  {
	   int ino;
	   char iname[10];
	   float iprice;
	   int istock;
	   int idiscount;

   public :
	   void create_item()
	    {
	     clrscr();
	     cout<<"\nEnter item number : ";
	     cin>>ino;
	     cout<<"\nEnter item name : ";
	     cin>>iname;
	     cout<<"\nEnter item price : ";
	     cin>>iprice;
	     cout<<"\nEnter discount on item : ";
	     cin>>idiscount;
	     istock=100;
	    }

	   void show_item()
	    {
	     clrscr();
	     cout<<"\nItem number "<<ino;
	     cout<<"\nItem name ";
	     puts(iname);
	     cout<<"\nItem price "<<iprice;
	     cout<<"\nDiscount on item : "<<idiscount;
	     cout<<"\nAvailibilty : "<<istock<<" "<<cout<<" is left!";
	    }

	   void modify_item()
	    {
	     clrscr();
	     cout<<"\nNew item number : ";
	     cin>>ino;
	     cout<<"\nNew item name : ";
	     cin>>iname;
	     cout<<"\nNew itmen price : ";
	     cin>>iprice;
	     cout<<"\nNew discount on item : ";
	     cin>>idiscount;
	     cout<<"\nStock availability : ";
	     reset_stock();
	     cin>>istock;
	    }

	   int return_idiscount()
	    { return idiscount; }

	   int return_ino()
	    { return ino; }

	   int return_istock()
	    { return istock; }

	   void sub_stock()
	    {  istock--; }

	   int return_iprice()
	    { return iprice; }

	   void reset_stock()
	    { istock=0; }

	   void report()
	    { cout<<ino<<"\t\t"<<iname<<"\t"<<iprice<<"\t\t"<<istock; }

	   char* return_name()
	    { return iname; }
  }i1;

//******************************************
//GLOBAL DECLARATION OF FSTREAM OBJECTS
//******************************************

 fstream f1;
 fstream f2;

//******************************************
//FUNCTION TO CREATE CUSTOMER RECORD
//******************************************

 void write_customer()
  {
   char ch;
   f1.open("CUSTO.dat",ios::out|ios::binary);
   do
    {
     c1.create_cust();
     f1.write((char*)&c1,sizeof(c1));
     cout<<"\nDo you want to enter more : ";
     cin>>ch;
    }
   while(ch=='y' || ch=='Y');
   f1.close();
  }

//**************************************
//FUNCTION TO CREATE ITEM RECORD
//**************************************

 void write_item()
  {
   char ch;
   f1.open("ITEM.dat",ios::out|ios::binary);
   do
    {
     i1.create_item();
     f1.write((char*)&i1,sizeof(i1));
     cout<<"\nDo you want to enter more : ";
     cin>>ch;
    }
   while(ch=='y' || ch=='Y');
   f1.close();
  }

//*********************************************
//FUNCTION TO MODIFY CUSTOMER'S RECORD
//*********************************************

 void modify_customer()
  {
   clrscr();
   int flag=0;
   int no=0;
   cout<<"\nEnter customer number of record you want to modify : ";
   cin>>no;
   f1.open("CUSTO.dat",ios::in|ios::binary);
   while(f1.read((char*)&c1,sizeof(c1)) && flag==0)
    {
     if(c1.return_cno()==no)
      {
       cout<<"\nCustomer found !";
       c1.show_cust();
       cout<<"\nEnter the new details....";
       c1.modify_cust();
       int pos=-1*sizeof(c1);
       f1.seekg(pos,ios::cur);
       f1.write((char*)&c1,sizeof(c1));
       cout<<"\n\nRecord updated!";
       flag=1;
      }
    }
   f1.close();
   if(flag==0)
    {
     cout<<"\nRecord not found!";
    }
   getch();
  }

//*****************************************
//FUNCTION TO MODIFY ITEM'S RECORD
//*****************************************

 void modify_item()
  {
   clrscr();
   int flag=0;
   char no=0;
   cout<<"\nEnter item number you want to modify : ";
   cin>>no;
   f1.open("ITEM.dat",ios::in|ios::binary);
   while(f1.read((char*)&i1,sizeof(i1)) && flag==0)
    {
     if(i1.return_ino()==no)
      {
       cout<<"\nItem found!";
       i1.show_item();
       cout<<"\nEnter the new details...";
       i1.modify_item();
       int pos=-1*sizeof(i1);
       f1.seekg(pos,ios::cur);
       f1.write((char*)&i1,sizeof(i1));
       flag=1;
      }
    }
   f1.close();
   if(flag==0)
    {
     cout<<"\nItem not fund!";
    }
   getch();
  }

//**************************************
//FUNCTION TO DELETE CUSTOMER'S RECORD
//**************************************

 void delete_customer()
  {
   clrscr();
   int no=0;
   int flag=0;
   cout<<"\nEnter the customer number of record you want to delete : ";
   cin>>no;
   fstream f2;
   f1.open("CUSTO.dat",ios::in|ios::binary);
   f2.open("temp.dat",ios::out|ios::binary);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&c1,sizeof(c1)))
    {
     if(c1.return_cno()!=no)
      {
       f2.write((char*)&c1,sizeof(c1));
      }
     else
      { flag=1; }
    }
   f1.close();
   f2.close();
   remove("CUSTO.dat");
   rename("temp.dat","CUSTO.dat");
   if(flag==1)
    { cout<<"\nRecord deleted!"; }
   else
    { cout<<"\nRecord not found"; }
   getch();
  }

//************************************
//FUNCTION TO DELETE ITEM'S RECORD
//************************************

 void delete_item()
  {
   clrscr();
   char no=0;
   fstream f2;
   cout<<"\nEnter the item number of record you want to delete : ";
   cin>>no;
   f1.open("ITEM.dat",ios::in|ios::binary);
   f2.open("temp2.dat",ios::out|ios::binary);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&i1,sizeof(i1)))
    {
     if(i1.return_ino()!=no)
      {
       f2.write((char*)&i1,sizeof(i1));
      }
    }
   f1.close();
   f2.close();
   remove("ITEM.dat");
   rename("temp2.dat","ITEM.dat");
   cout<<"\nRecord deleted!";
   getch();
  }

//*******************************************
//FUNCTION TO DISPLAY LIST OF ALL THE ITEMS
//*******************************************

 void disp_item()
  {
   clrscr();
   f1.open("ITEM.dat",ios::in|ios::binary);
   if(!f1)
    {
     cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
     cout<<"\n\n\n Program is closing ....";
     getch();
     return;
    }
   cout<<"\n\n\t\tProduct MENU\n\n";
   cout<<"====================================================\n";
   cout<<"P.NO.\t\tNAME\t\tPRICE\t\tSTOCK\n";
   cout<<"====================================================\n";
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&i1,sizeof(i1)))
    {
      i1.report();
      cout<<endl;
    }
   f1.close();
  }
 //********************************************
 //FUNCTION TO DISPLAY RECORD OF ALL CUSTOMERS
 //********************************************

 void disp_allcust()
  {
   clrscr();
   f1.open("CUSTO.dat",ios::in|ios::binary);
   if(!f1)
    {
     cout<<"ERROR!!!FILE COULD NOT BE OPENED.\n\n\n GO BACK TO ADMIN MENU TO CREATE RECORD!";
     cout<<"PROGRAM IS CLOSING!";
     getch();
     return;
    }
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&c1,sizeof(c1)))
    {
     c1.show_cust();
    }
   f1.close();
   getch();
  }

 void disp_scust(int n)
  {
   clrscr();
   int flag=0;
   f1.open("CUSTO.dat",ios::in|ios::binary);
   while(f1.read((char*)&c1,sizeof(c1)) && flag==0)
    {
      if(c1.return_cno()==n)
       {
	 c1.show_cust();
	 flag=1;
       }
    }
   f1.close();
   if(flag==0)
    {
     cout<<"\n\nNo such customer exist!";
    }
   getch();
  }

 void disp_sitem(int n)
  {
   clrscr();
   int flag=0;
   f1.open("ITEM.dat",ios::in|ios::binary);
   while(f1.read((char*)&i1,sizeof(i1)) && flag==0)
    {
     if(i1.return_ino()==n)
      {
       i1.show_item();
       flag=1;
      }
    }
   if(flag==0)
    {
     cout<<"\n\nNo such item available!";
    }
   f1.close();
   getch();
  }
//******************************************************************
//GLOBAL DECLARATION OF VARIABLES USED IN PURCHASE AND BILL FUNCTION
//******************************************************************

 int quan[50],itnum[50],c=0;
 float amt,damt,disc,disc2,disct,total=0;

//****************************************
//FUNCTION FOR PURCHASE OF AN ITEM
//****************************************

 void purchase()
  {
   clrscr();
   int cunum=0;
   char reply=0;
   cout<<"\t\t....Welcome dear customer....";
   cout<<"\nEnter your customer number : ";
   cin>>cunum;
   f1.open("CUSTO.dat",ios::in|ios::binary);
   f1.open("ITEM.dat",ios::in|ios::binary);
   while(f1.read((char*)&c1,sizeof(c1)))
    {
     if(c1.return_cno()==cunum)
      {
       do
	{
	 while(f1.read((char*)&i1,sizeof(i1)))
	  { i1.show_item(); }
	 cout<<"\nEnter item number : ";
	 cin>>itnum[c];
	 while(f1.read((char*)&i1,sizeof(i1)))
	  {
	   if(i1.return_ino()==itnum[c])
	    {
	     int a=i1.return_istock();
	     if(a!=0)
	      {
	       cout<<"\nEnter quantity : ";
	       cin>>quan[c];
	       c++;
	       i1.sub_stock();
	      }
	     else if(a==0)
	      {
		cout<<"\nStock over!! ";
		continue;
	      }
	    }
	   else
	    { cout<<"\nNo such item!!"; }
	  }
	 cout<<"\nDo you want to buy more :" ;
	 cin>>reply;
	}
       while(reply=='Y' || reply=='y');
       cout<<"\nThank you for shopping with us!";
      }
     else
      { cout<<"\nNo such customer exist!"; }
    }
   f1.close();
   getch();
  }

 void getbill()
  {
   cout<<"\n\n********************************INVOICE************************\n";
   cout<<"\nItem No.\tItem Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
   for(int x=0;x<=c;x++)
    {
     f1.open("ITEM.dat",ios::in|ios::binary);
     while(f1.read((char*)&i1,sizeof(i1)))
      {
       if(i1.return_ino()==itnum[x])
	{
	 disc2=i1.return_idiscount();
	 disct=disc+disc2;
	 amt=i1.return_iprice()*quan[x];
	 damt=amt-(amt*disct/100);
	 cout<<"\n"<<itnum[x]<<"\t"<<i1.return_name()
	 <<"\t"<<quan[x]<<"\t\t"<<i1.return_iprice()<<"\t"<<amt<<"\t\t"<<damt;
	 total+=damt;
	}
       f1.read((char*)&i1,sizeof(i1));
      }
     f1.close();
    }
   cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
   getch();
  }

 void calcdisc(int)
  {
   int gp,d;
   gp=c1.return_points();
   if(gp==0)
    { d=d+(gp*10); }
   else if(gp==10)
    { d=d+(gp*10); }
   else if(gp==20)
    { d=d+(gp*10); }
   disc=d;
  }

 void intro()
  {
   clrscr();
   gotoxy(35,11);
   cout<<"GROCERY";
   gotoxy(35,14);
   cout<<"SHOPPING";
   gotoxy(35,17);
   cout<<"SYSTEM";
   cout<<"\n\nMADE BY : MAYANK NEGI";
   cout<<"\n\nSCHOOL : ST MARKS'S SE SEC PUBLIC SCHOOL";
   getch();
  }

 void admin_menu()
  {
   clrscr();
   int ch3;
   cout<<"\n\n\n*****ADMIN MENU*****\n\n\n";
   cout<<"\n1. Add a customer";
   cout<<"\n2. Add an item";
   cout<<"\n3. Modify a customer";
   cout<<"\n4. Modify an item.";
   cout<<"\n5. Delete a customer.";
   cout<<"\n6. Delete an item.";
   cout<<"\n7. Search a specific customer.";
   cout<<"\n8. Search a specific item.";
   cout<<"\n9. Display all customers.";
   cout<<"\n10. Previous menu.";
   cout<<"\n0. Exit";
   cout<<"\nEnter your choice : ";
   cin>>ch3;
   switch(ch3)
    {
     case 1 : write_customer();
	      break;
     case 2 : write_item();
	      break;
     case 3 : modify_customer();
	      break;
     case 4 : modify_item();
	      break;
     case 5 : delete_customer();
	      break;
     case 6 : delete_item();
	      break;
     case 7 : {
	       clrscr();
	       int num=0;
	       cout<<"\n\nEnter the customer number : ";
	       cin>>num;
	       disp_scust(num);
	       break;
	      }
     case 8 : {
	       clrscr();
	       int num=0;
	       cout<<"\n\nEnter the item number : ";
	       cin>>num;
	       disp_sitem(num);
	       break;
	      }
     case 9 : disp_allcust();
	      break;
     case 10 : return;
     case 0 : exit(0);
     default : cout<<"\a";
    }
  }

 void customer_menu()
  {
   clrscr();
   int ch1;
   cout<<"\t\t\t*****CUSTOMER MENU*****\t\t\t";
   cout<<"\nSelect your choice : ";
   cout<<"\n\n1. See items list.";
   cout<<"\n\n2. Purchase item.";
   cout<<"\n\n3. Search item.";
   cout<<"\n\n4. previous menu.";
   cout<<"\n\n0. Exit.";
   cout<<"\n\nEnter your choice : ";
   cin>>ch1;
   switch(ch1)
    {
      case 1 : disp_item();
	       break;
      case 2 : purchase();
	       getbill();
	       break;
      case 3 : {
	       clrscr();
	       int num=0;
	       cout<<"\n\nEnter the item number : ";
	       cin>>num;
	       disp_sitem(num);
	       break;
	      }
      case 4 : return;
      case 0 : exit(0);
      default : cout<<"\a";
    }
  }

 void main()
  {
   clrscr();
   int ch;
   intro();
   clrscr();
   do
    {
     cout<<"\t\t\t******MAIN MENU******\t\t\t";
     cout<<"\n\n1. CUSTOMER";
     cout<<"\n\n2. ADMINISTRATOR";
     cout<<"\n\n0. EXIT";
     cout<<"\n\nSelect you choice : ";
     cin>>ch;
     switch(ch)
      {
	case 1 : customer_menu();
		 break;
	case 2 : admin_menu();
		 break;
	case 0 : exit(0);
	default : cout<<"\a";
      }
    }
   while(ch!=0);
   getch();
  }
