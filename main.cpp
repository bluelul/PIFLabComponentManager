////////////////////////////////////////////////////////
//			PIFLAB COMPONENT MANAGER
//				   LTTUNG1197
//			lttungg1197bt@gmail.com
//				   17/09/2017
////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "stdio.h"

using namespace std;

struct component
{
	int id;
	char name[20] ;
	int price ;
	int quantity;
	char type[20];
	char factory[20];
	char date[20];
	char note[50];
};
void showComponent(int i, component data[])
{
	cout<<"------------------------------"<<'\n';
	cout<<"ID:      "<<data[i].id<<'\n';							
	cout<<"TEN:     "<<data[i].name<<'\n';							
	cout<<"GIA:     "<<data[i].price<<'\n';							
	cout<<"SO LUONG:"<<data[i].quantity<<'\n';							
	cout<<"KIEU:    "<<data[i].type<<'\n';							
	cout<<"HANG SX: "<<data[i].factory<<'\n';							
	cout<<"NGAY:    "<<data[i].date<<'\n';							
	cout<<"GHI CHU: "<<data[i].note<<'\n';	
}
int main () {
	string temp;
///////////////////////////////////////////////////////
//					LOAD FILE
///////////////////////////////////////////////////////	
	fstream fs("databasePIF.txt",fstream::in);	
	
	int length;
	int is_null=0;

	////////////GET NUMBER OF COMPONENT,///////////// 
	///////AUTO SET 1 IF FILE HAS NOT CREATED//////////
	if (getline(fs,temp)) 
		length=atoi(temp.c_str());
	else 
		{
			length=1;
			is_null =1;
		}
	cout<<"NUMBER OF COMPONENT:"<<length<<'\n';
	
	//////////////UPLOAD DATA///////////////////////////
	//component *data= new component[length];
	component data[length+100]; //NEN DUNG CAP BO NHO DONG
	if (is_null==0)
	{
		for (int i = 0; i < length; ++i)
		{
			getline(fs,temp);
			data[i].id=atoi(temp.c_str());							
			getline(fs,temp);
			for(int j=0;j<20;j++) data[i].name[j]=temp[j];	
			getline(fs,temp);
			data[i].price=atoi(temp.c_str());							
			getline(fs,temp);						
			data[i].quantity=atoi(temp.c_str());							
			getline(fs,temp);
			for(int j=0;j<20;j++) data[i].type[j]=temp[j];							
			getline(fs,temp);
			for(int j=0;j<20;j++) data[i].factory[j]=temp[j];					
			getline(fs,temp);
			for(int j=0;j<20;j++) data[i].date[j]=temp[j];			
			getline(fs,temp);
			for(int j=0;j<50;j++) data[i].note[j]=temp[j];	
		}
	}	
	fs.close();

	// for (int i = 0; i < length; ++i)
	// 	{
	// 		cout<<data[i].id<<'\n';							
	// 		cout<<data[i].name<<'\n';							
	// 		cout<<data[i].price<<'\n';							
	// 		cout<<data[i].quantity<<'\n';							
	// 		cout<<data[i].type<<'\n';							
	// 		cout<<data[i].factory<<'\n';							
	// 		cout<<data[i].date<<'\n';							
	// 		cout<<data[i].note<<'\n';
	// 	}

///////////////////////////////////////////////////////
//					PROCESS
///////////////////////////////////////////////////////
	char cont='y';
	while(cont=='y')
	{
		printf("==========================================================\n");		printf("                           MENU\n");
		printf("==========================================================\n");
		printf("1. Them vào linh kien\n");
		printf("2. Xoa linh kien trong kho\n");
		printf("3. Cap nhat thong so linh kien\n");
		printf("4. Xem danh sach tat ca linh kien\n");
		printf("5. Hien thi linh kien co cung hang san xuat\n");
		printf("6. HIen thi linh kien co cung kieu\n");
		printf("7. Tim linh kien co ID\n");
		printf("8. Sap xep danh sach linh kien theo gia\n");
		printf("Nhap lua chon cua ban: \n");
		int selection;
		scanf("%d",&selection);
		switch (selection)
		{
			case 1:{
				if (is_null) length=0;
				again:	printf("Nhap ma linh kien:\n");
						scanf("%d",&data[length].id);
				if (is_null==0)
					for (int i = 0; i < length; ++i)
					{
						if (data[i].id==data[length].id)
						{
							cout<<"ID khong duoc trung!"<<'\n';
							goto again;
						}
					}

				printf("Nhap ten linh kien:\n");
				scanf("%s",data[length].name);
				
				printf("Nhap gia linh kien:\n");
				scanf("%d",&data[length].price);
				
				printf("Nhap so luong linh kien:\n");
				scanf("%d",&data[length].quantity);
				
				printf("Nhap kieu linh kien:\n");
				scanf("%s",data[length].type);
				
				printf("Nhap hang linh kien:\n");
				scanf("%s",data[length].factory);
				
				printf("Nhap ngay nhap kho:\n");
				scanf("%s",data[length].date);
				
				printf("Ghi chu:\n");
				scanf("%s",data[length].note);
				
				length++;
				
				if (is_null) 
					{
						length=1;
						is_null=0;
					}
				break;
			}
			case 2:{
				int id_inp;
				printf("Nhap id linh kien:\n");
				scanf("%d",&id_inp);
				for (int i = 0; i < length; ++i)
				{
					if (data[i].id==id_inp)
					{
						data[i]=data[length-1];
						length--;
						break;
					}
				}
				break;
			}
			case 3:{
				int id_inp;
				printf("Nhap id linh kien:\n");
				scanf("%d",&id_inp);
				for (int i = 0; i < length; ++i)
				{
					if (data[i].id==id_inp)
					{
						printf("Nhap ma linh kien moi:\n");
						scanf("%d",&data[i].id);
						
						printf("Nhap ten linh kien moi:\n");
						scanf("%s",data[i].name);
						
						printf("Nhap gia linh kien moi:\n");
						scanf("%d",&data[i].price);
						
						printf("Nhap so luong linh kien moi:\n");
						scanf("%d",&data[i].quantity);
						
						printf("Nhap kieu linh kien moi:\n");
						scanf("%s",data[i].type);
						
						printf("Nhap hang linh kien moi:\n");
						scanf("%s",data[i].factory);
						
						printf("Nhap ngay nhap kho moi:\n");
						scanf("%s",data[i].date);
						
						printf("Ghi chu moi:\n");
						scanf("%s",data[i].note);
						break;
					}
				}
				break;
			}
			case 4:{
				for (int i = 0; i < length; ++i)
					showComponent(i,data);			
				break;
			}
			case 5:{
				char fac_inp[20];
				printf("Nhap hang linh kien:\n");
				scanf("%s",fac_inp);
				for (int i = 0; i < length; ++i)
				{
					if (strcmp(fac_inp,data[i].factory)==0)
					showComponent(i,data);
				}
				break;
			}
			case 6:{
				char type_inp[20];
				printf("Nhap kieu linh kien:\n");
				scanf("%s",type_inp);
				for (int i = 0; i < length; ++i)
				{
					if (strcmp(type_inp,data[i].type)==0)
					showComponent(i,data);
				}
				break;
			}
			case 7:{
				int id_inp;
				printf("Nhap id linh kien:\n");
				scanf("%d",&id_inp);
				for (int i = 0; i < length; ++i)
				{
					if (data[i].id==id_inp)
					showComponent(i,data);
				}
				break;
			}
			case 8:{
				for (int i = 0; i < length; ++i)
					{
						for (int j = 0; j < i; ++j)
						{
							if (data[i].price>data[j].price)
							{
								component temp;
								temp=data[i];
								data[i]=data[j];
								data[j]=temp;
							}
						}
					}	
				break;
			}
		}
		printf("Tiep tuc? y/n:");
		scanf("%c",&cont);scanf("%c",&cont);
	}
	
///////////////////////////////////////////////////////
//					SAVE FILE
///////////////////////////////////////////////////////
		//open exist file to write or create new file
	fs.open("databasePIF.txt",fstream::trunc|fstream::out);

	if (fs.is_open())
	{
		fs<<length<<'\n';	
		for (int i = 0; i < length; ++i)
		{
			fs<<data[i].id<<'\n';							
			fs<<data[i].name<<'\n';							
			fs<<data[i].price<<'\n';							
			fs<<data[i].quantity<<'\n';							
			fs<<data[i].type<<'\n';							
			fs<<data[i].factory<<'\n';							
			fs<<data[i].date<<'\n';							
			fs<<data[i].note<<'\n';
		}
	}		
	fs.close();
  return 0;
}

	//////////////////READ WRITE FILE SAMPLE CODE/////////////
	/*
		fs.open("test1.txt");
		for (int i = 0; i < 10; ++i)
		{
			string a;
			getline(fs,a);
			cout<<atoi(a.c_str())+1<<'\n';		
		}
		fs.close();
	*/

	/*
	  string line[10];
	  fstream myfile ("example.txt");

	  if (myfile.is_open())
	  {
	    myfile << "This fdasis a line.\n";
	    myfile << "This is another line.\n";
	    myfile.close();
	  }

	  	int length=0;
	  	myfile.open("example.txt");
		if (myfile.is_open())
		{
		    while ( getline (myfile,line[length]) )
		    {
		      //cout << line << '\n';
		    	length++;
		    }
		    myfile.close();

			for (int i = 0; i < length; ++i)
			{
				cout<<line[i]<<'\n';
			}
		}
	  else cout << "Unable to open file";
	  */
