#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<fstream.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
class patient
{
	char patname[20];
	int roomno;
	char add[20];
	char sex;
	int age;
	int recomm;
	float totalbill;


	public:
	void input();
	void output();
	void showdetails();
	char* getpatname()
	{
		return patname;
	}
	int getpatroomno()
	{
		return roomno;
	}
	float gettotalbill()
	{
		return totalbill;
	}
	patient()
	{
		strcpy(patname,'\0');
		roomno=0;
		sex='m';
		age=0;
		totalbill=200;
	}
};
void showrecom()
{
	cout<<"\n\n\tDoctor's Speciality               Number"<<endl<<endl;
	cout<<"\t General Physician                  1"<<endl;
	cout<<"\t      E.N.T.                        2"<<endl;
	cout<<"\t   Cardiologist                     3"<<endl;
	cout<<"\t   Dermatologist                    4"<<endl;
	cout<<"\tGastroenteroiogist                  5"<<endl;
	cout<<"\t   Pediatrician                     6"<<endl;
	cout<<"\t  EYE Specialist                    7"<<endl;
	cout<<"\t   Nephrologist                     8"<<endl;
}
int setroomno(int a)
{
	randomize();
	int b;
	switch(a)
	{
		case 1:
			printf("\nReff.Specialist:");
			printf("\nGeneralphysician");
			printf("Room no:");
			b=(rand()%(15-1+1))+1;
			printf("%d",b);
			return b;
		case 2:
			printf("\nReff.Specialist:");
			printf("\nE.N.T.");
			printf("Room no:");
			b=(rand()%(30-15+1))+15;
			printf("%d",b);
			return b;
		case 3:
			printf("\nReff.Specialist:");
			printf("\nCardiologist");
			printf("Room no:");
			b=(rand()%(45-30+1))+30;
			printf("%d",b);
			return b;
		case 4:
			printf("\nReff.Specialist:");
			printf("\nDermatologist");
			printf("Room no:");
			b=(rand()%(60-45+1))+45;
			printf("%d",b);
			return b;
		case 5:
			printf("\nReff.Specialist:");
			printf("\nGastroenteroiogist");
			printf("Room no:");
			b=(rand()%(75-60+1))+60;
			printf("%d",b);
			return b;
		case 6:
			printf("\nReff.Specialist:");
			printf("\nPediatrician");
			printf("Room no:");
			b=(rand()%(90-75+1))+75;
			printf("%d",b);
			return b;
		case 7:
			printf("\nReff.Specialist:");
			printf("\nEYE Specialist");
			printf("Room no:");
			b=(rand()%(105-90+1))+90;
			printf("%d",b);
			return b;
		case 8:
			printf("\nReff.Specialist:");
			printf("\nNephrologist");
			printf("Room no:");
			b=(rand()%(120-105+1))+105;
			printf("%d",b);
			return b;
		default:
			printf("wrong choice....");
	}
	return b;
}
int i,j,k,a,b,stucomp,choi5;
char choi,ans,choi2;
float total;
void patient::input()
{
	cout<<endl<<"enter the patient name: ";
	gets(patname);
	cout<<"enter the patient address: ";
	gets(add);
	cout<<"enter the patient sex: ";
	cin>>sex;
	cout<<"enter the patient age: ";
	cin>>age;
	cout<<"want to see the recommendation list: ";
	cin>>choi;
	if(choi=='y')
		showrecom();
	cout<<"enter the recommendation list: ";
	cin>>recomm;
	roomno=setroomno(recomm);
	cout<<"the allocated room number is: "<<roomno<<endl;
}
void displayrecomm(int b)
{
	switch(b)
	{
		case 1:
			printf("\nGeneralphysician");
			break;
		case 2:
			printf("\nE.N.T.");
			break;
		case 3:
			printf("\nCardiologist");
			break;
		case 4:
			printf("\nDermatologist");
			break;
		case 5:
			printf("\nGastroenteroiogist");
			break;
		case 6:
			printf("\nPediatrician");
			break;
		case 7:
			printf("\nEYE Specialist");
			break;
		case 8:
			printf("\nNephrologist");
			break;
	}
}

void patient::output()
{
	cout<<"Patient name is: "<<patname<<endl;
	cout<<"Patient room no is: "<<roomno<<endl;
	cout<<"Patient age is: "<<age<<endl;
	cout<<"Patient sex is: "<<sex<<endl;
	cout<<"Patient address is: "<<add<<endl;
	cout<<"Patient recommended doctor is: ";
	displayrecomm(recomm);

}
void addpatient()
{
	fstream f1;
	patient P;
	f1.open("patient.dat",ios::out|ios::app|ios::binary);
	do
	{
		clrscr();
		cout<<"\t\t*************** ADD PATIENT ***************"<<endl;
		cout<<endl;
		P.input();
		cout<<endl<<"patient added.."<<endl;
		f1.write((char*)&P,sizeof(P));
		cout<<endl<<"Want to add more?";
		cin>>choi;
	}while(choi=='y'||choi=='Y');
	f1.close();
}
void searchpatient()
{
	D:
	int flag=0;
	int ch;
	char fullname[20];
	fstream f1;
	cout<<"\t\t*************** SEARCH PATIENT ***************"<<endl;
	cout<<endl;
	patient P;
	cout<<endl<<"Enter the patient name u want to search: ";
	gets(fullname);
	f1.open("patient.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&P,sizeof(P));
	while(!f1.eof())
	{
		if(strcmp(fullname,P.getpatname())==0)
		{
			cout<<endl<<"\t\t\tPatient found..."<<endl;
			cout<<endl;
			P.output();
			flag=1;
		}
		f1.read((char*)&P,sizeof(P));
	}
	f1.close();
	if(flag==0)
	cout<<"Patient not found!!!!!"<<endl;
	cout<<endl<<"Want to search for about more patients: ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto D;
	}
}
void deletepatient()
{
	E:
	int flag=0;
	int ch;
	char fullname[20];
	fstream f1,f2;
	patient P;
	cout<<"\t\t*************** DELETE PATIENT ***************"<<endl;
	cout<<endl<<"Enter the patient name you want to delete: ";
	gets(fullname);
	f1.open("patient.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	f1.read((char*)&P,sizeof(P));
	while(!f1.eof())
	{
		if(strcmp(fullname,P.getpatname())==0)
		{
			flag=1;
			f2.write((char*)&P,sizeof(P));
		}
		f1.read((char*)&P,sizeof(P));
	}
	f1.close();
	f2.close();
	if(flag==1)
	cout<<"Patient recorded deleted"<<endl;
	if(flag==0)
	cout<<"This patient is not in your hospital :( "<<endl;
	remove("patient.dat");
	rename("temp.dat","patient.dat");
	cout<<endl<<"Want to delete records of more patients ? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto E;
	}
}
void updatepatient()
{
	F:
	fstream f1,f2;
	int flag=0;
	cout<<"\t\t*************** UPDATE PATIENT ***************"<<endl;
	f1.open("patient.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	int updateno;
	char fullname[20];
	cout<<endl<<"Enter the name of the patient you want to update: ";
	gets(fullname);
	patient P;
	f1.read((char*)&P,sizeof(P));
	while(!f1.eof())
	{
		if(strcmp(fullname,P.getpatname())==0)
		{
			clrscr();
			cout<<"\t\t\tEnter new updated information of patient: "<<endl;
			cout<<endl;
			P.input();
			f2.write((char*)&P,sizeof(P));
			flag=1;
		}
		else
		f2.write((char*)&P,sizeof(P));
	f1.read((char*)&P,sizeof(P));
	}
	f1.close();
	f2.close();
	remove("patient.dat");
	rename("temp.dat","patient.dat");
	if(flag==1)
	cout<<"patient record updated..."<<endl;
	else
	cout<<"This patient doen't in your hospital!!!!"<<endl;
	cout<<"Want to update records of more patients? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto F;
	}
}
class doctor
{
	char docname[20];
	int age;
	char address[20];
	char sex;
	int specialityno;

	public:
	void input();
	void output();
	void showdetail();

	char* getdocname()
	{
		return docname;
	}
	int getspecialityno()
	{
		return specialityno;
	}
	int getdocage()
	{
		return age;
	}
	char getdocsex()
	{
		return sex;
	}
};
void doctor::input()
{
	cout<<endl<<"enter the doctor name: ";
	gets(docname);
	cout<<endl<<"enter the doctor age: ";
	cin>>age;
	cout<<endl<<"enter the doctor sex: ";
	cin>>sex;
	cout<<"want to see the speciality list: ";
	cin>>choi2;
	if(choi2=='y')
		showrecom();
	cout<<endl<<"enter the doctor speciality number: ";
	cin>>specialityno;
}
void doctor::output()
{
	cout<<"Doctor name is: "<<docname<<endl;
	cout<<"Doctor age is: "<<age<<endl;
	cout<<"Doctor sex is: "<<sex<<endl;
	cout<<"Doctor speciality is: ";
	displayrecomm(specialityno);
}
void adddoctor()
{
	fstream f1;
	doctor D;
	f1.open("doctor.dat",ios::out|ios::app|ios::binary);
	do
	{
		clrscr();
		cout<<"\t\t*************** ADD DOCTOR ***************"<<endl;
		cout<<endl;
		D.input();
		cout<<endl<<"Doctor added.."<<endl;
		f1.write((char*)&D,sizeof(D));
		cout<<endl<<"Want to add more?";
		cin>>choi;
	}while(choi=='y'||choi=='Y');
	f1.close();
}
void searchdoctor()
{
	D:
	int flag=0;
	int ch;
	char fullname[20];
	fstream f1;
	cout<<"\t\t*************** SEARCH DOCTOR ***************"<<endl;
	cout<<endl;
	doctor D;
	cout<<endl<<"Enter the doctor name u want to search: ";
	gets(fullname);
	f1.open("doctor.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&D,sizeof(D));
	while(!f1.eof())
	{
		if(strcmp(fullname,D.getdocname())==0)
		{
			cout<<endl<<"\t\t\tDoctor found..."<<endl;
			cout<<endl;
			D.output();
			flag=1;

		}
		f1.read((char*)&D,sizeof(D));
	}
	f1.close();
	if(flag==0)
	cout<<"Doctor info not found!!!!!"<<endl;
	cout<<endl<<"Want to search for about more doctor ? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto D;
	}
}
void deletedoctor()
{
	E:
	int flag=0;
	int ch;
	char fullname[20];
	fstream f1,f2;
	doctor D;
	cout<<"\t\t*************** DELETE DOCTOR ***************"<<endl;
	cout<<endl<<"Enter the doctor name you want to delete: ";
	gets(fullname);
	f1.open("doctor.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	f1.read((char*)&D,sizeof(D));
	while(!f1.eof())
	{
		if(strcmp(fullname,D.getdocname())==0)
		{
			flag=1;
			f2.write((char*)&D,sizeof(D));
		}
		f1.read((char*)&D,sizeof(D));
	}
	f1.close();
	f2.close();
	if(flag==1)
	cout<<"Doctor deleted"<<endl;
	if(flag==0)
	cout<<"This doctor is not in your hospital :( "<<endl;
	remove("doctor.dat");
	rename("temp.dat","doctor.dat");
	cout<<endl<<"Want to delete records of more doctors ? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto E;
	}
}
void updatedoctor()
{
	F:
	fstream f1,f2;
	int flag=0;
	char fullname[20];
	cout<<"\t\t*************** UPDATE DOCTOR ***************"<<endl;
	f1.open("doctor.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::app|ios::binary);
	int updateno;
	cout<<endl<<"Enter the name of the doctor you want to update: ";
	cin>>updateno;
	doctor D;
	f1.read((char*)&D,sizeof(D));
	while(!f1.eof())
	{
		if(strcmp(fullname,D.getdocname())==0)
		{
			clrscr();
			cout<<"\t\t\tEnter new updated information of doctor: "<<endl;
			cout<<endl;
			D.input();
			f2.write((char*)&D,sizeof(D));
			flag=1;
		}
		else
		f2.write((char*)&D,sizeof(D));
	f1.read((char*)&D,sizeof(D));
	}
	f1.close();
	f2.close();
	remove("doctor.dat");
	rename("temp.dat","doctor.dat");
	if(flag==1)
	cout<<"Doctor record updated..."<<endl;
	else
	cout<<"This doctor doen't in your hospital!!!!"<<endl;
	cout<<"Want to update records of more doctors? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		clrscr();
		goto F;
	}
}
int compname(char a[])
{
	fstream f1;
	int f=0;
	cout<<endl;
	patient P;
	f1.open("patient.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&P,sizeof(P));
	while(!f1.eof())
	{
		if(strcmp(a,P.getpatname())==0)
		{
			clrscr();
			cout<<"\t\t*************** WELCOME "<<P.getpatname()<<" ***************";
			f=1;
		}
		f1.read((char*)&P,sizeof(P));
	}
	f1.close();
	return f;
}
void showdoc(int c)
{
	Z:
	fstream f1;
	doctor D;
	f1.open("doctor.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&D,sizeof(D));
	cout<<"Doctor name:          age:          sex:"<<endl;
	while(!f1.eof())
	{
		if(D.getspecialityno()==c)
		{
			int k3;
			k3=strlen(D.getdocname());
			cout<<D.getdocname();
			k3=22-k3;
			for(int i=0;i<k3;i++)
				cout<<" ";
			cout<<D.getdocage();
			for(int j=0;j<14;j++)
				cout<<" ";
			cout<<D.getdocsex();
			cout<<endl;
		}
		f1.read((char*)&D,sizeof(D));
	}
	f1.close();
	getch();
}
void schoolbus()
{
	int i, gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	for (i = 0; i <= 420; i = i + 5)
	{
		setcolor(WHITE);
		line(0+i, 270, 210 + i, 270);
		line(0 + i, 330, 0 + i, 270);
		line(30+i,295,30+i,270);
		line(60+i,295,60+i,270);
		line(90+i,295,90+i,270);
		line(120+i,295,120+i,270);
		line(150+i,295,150+i,270);
		line(180+i,295,180+i,270);
		line(0+i,295,210+i,295);
		line(210 + i, 330, 210 + i, 270);

		setcolor(LIGHTBLUE);
		outtextxy(65+i,305,"AMBULANCE");

		setcolor(DARKGRAY);
		circle(65 + i, 330, 15);
		circle(65 + i, 330, 2);
		circle(145 + i, 330, 15);
		circle(145 + i, 330, 2);

		setcolor(BROWN);
		line(-2000,345,2000,345);

		setcolor(WHITE);
		line(0 + i, 330, 50 + i, 330);
		line(80 + i, 330, 130 + i, 330);
		line(210 + i, 330, 160 + i, 330);
		setcolor(RED);
		setfillstyle(SOLID_FILL,YELLOW);
		circle(50,50,40);
		floodfill(50,50,RED);
		delay(100);

		setcolor(BLACK);
		line(0+i, 270, 210 + i, 270);
		line(0 + i, 330, 0 + i, 270);
		line(30+i,295,30+i,270);
		line(0+i,295,210+i,295);
		line(60+i,295,60+i,270);
		line(90+i,295,90+i,270);
		line(120+i,295,120+i,270);
		line(150+i,295,150+i,270);
		line(180+i,295,180+i,270);
		line(210 + i, 330, 210 + i, 270);
		outtextxy(65+i,305,"AMBULANCE");

		circle(65 + i, 330, 15);
		circle(65 + i, 330, 2);
		circle(145 + i, 330, 15);
		circle(145 + i, 330, 2);

		line(0 + i, 330, 50 + i, 330);
		line(80 + i, 330, 130 + i, 330);
		line(210 + i, 330, 160 + i, 330);
		setfillstyle(SOLID_FILL,BLACK);
		circle(50,50,40);
		floodfill(50,50,BLACK);
	}
	closegraph();
}
void showinfo(char b[])
{
	fstream f1;
	patient P;
	f1.open("patient.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&P,sizeof(P));
	while(!f1.eof())
	{
		if(strcmp(b,P.getpatname())==0)
			P.output();
		f1.read((char*)&P,sizeof(P));
	}
	f1.close();
}
void showbill(char d[])
{
	fstream f1;
	patient P;
	f1.open("patient.dat",ios::in|ios::binary|ios::app);
	f1.read((char*)&P,sizeof(P));
	while(!f1.eof())
	{
		if(strcmp(d,P.getpatname())==0)
		       cout<<"the registration charge: "<<P.gettotalbill()<<endl;
		f1.read((char*)&P,sizeof(P));
	}
	f1.close();
}
int choi7;
void main()
{
	schoolbus();
	int choi4,rec,choi1,choi3,result,choi6;
	char patientname[20],patientname1[20];
	printf("X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X\n");
	printf("X *           *  * * * * *  *           * * *     * *     *     *   * * * * * X\n");
	printf("X  *         *   *          *          *         *   *    * * * *   *         X\n");
	printf("X   *   *   *    * * *      *         *         *     *   *  *  *   * * *     X\n");
	printf("X    * * * *     *          *          *         *   *    *     *   *         X\n");
	printf("X     *   *      * * * * *  * * * * *   * * *     * *     *     *   * * * * * X\n");
	printf("X                                                                             X\n");
	printf("X                                                                             X\n");
	printf("X                             * * * * *    * *                                X\n");
	printf("X                                 *       *   *                               X\n");
	printf("X                                 *      *     *                              X\n");
	printf("X                                 *       *   *                               X\n");
	printf("X                                 *        * *                                X\n");
	printf("X                                                                             X\n");
	printf("X                                                                             X\n");
	printf("X    ***      *      **    *   * * *  * * *  * * *  *       *  **    *  *     X\n");
	printf("X  *         * *     * *   *     *    *      *       *     *   * *   *  *     X\n");
	printf("X   * *     *   *    *  *  *     *    * *    * *      *   *    *  *  *  *     X\n");
	printf("X       *  * * * *   *   * *  *  *    *      *         * *     *   * *  *     X\n");
	printf("X   ***   *       *  *    **    **    * * *  * * *      *      *    **  *     X\n");
	printf("X                                                                             X\n");
	printf("X                       --- MADE BY HARSH GUPTA AND MAYANK KUMAR GAUTAM....   X\n");
	printf("X                                                                             X\n");
	printf("X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X\n");
	delay(3500);
	clrscr();
	lb:
	cout<<"\t       *************** WELCOME TO OUR HOSPITAL ***************"<<endl;
	A:
	for(a=0;a<8;a++)
	cout<<endl;
	cout<<"\t\t\tENTER:"<<endl;
	cout<<"\t\t\t1. LOGIN..."<<endl;
	cout<<"\t\t\t2. I AM A PATIENT..."<<endl;
	cout<<"\t\t\t3. EXIT..."<<endl;
	cout<<endl<<"\t\t\tENTER YOUR CHOICE: ";
	cin>>k;
	clrscr();
	char arr[10];
	fflush(stdin);
	switch(k)
	{
		case 1:
		a:
		cout<<"\t"<<endl;
		cout<<"ENTER PASSWORD: "<<endl;
		for(int i=0;i<10;i++)
		{
			arr[i]=getch();
			cout<<"*";
		}
		if(strcmp(arr,"harshgupta")!=0)
		{
			clrscr();
			cout<<"LOGGING IN";
			for(a=0;a<5;a++)
			{
				cout<<".";
				delay(250);
			}
			b:
			clrscr();
			cout<<"\t\t*************** ADMIN FILE IS READY ***************";
			for(a=0;a<8;a++)
			cout<<endl;
			cout<<"\t\t\tWHAT DO YOU WANT TO DO?"<<endl;
			cout<<endl<<"\t\t\t1. PATIENT.."<<endl;
			cout<<"\t\t\t2. DOCTORS.."<<endl;
			cout<<"\t\t\t3. SHOW ALL DOCTORS.."<<endl;
			cout<<"\t\t\t4. GENERATE BILL.."<<endl;
			cout<<"\t\t\t5. LOGOUT.."<<endl;
			cout<<"\t\t\tEnter your choice: ";
			cin>>rec;
			switch(rec)
			{
				case 1:
					re:
					clrscr();
					cout<<"\t\t*************** PATIENT FILE IS READY ***************";
					for(a=0;a<8;a++)
						cout<<endl;
					cout<<"\t\t\t1. Add patient.."<<endl;
					cout<<"\t\t\t2. Search patient.."<<endl;
					cout<<"\t\t\t3. Delete patient.."<<endl;
					cout<<"\t\t\t4. Update patient.."<<endl;
					cout<<"\t\t\t5. Exit.."<<endl;
					cout<<endl<<"\t\t\Enter your choice: ";
					cin>>choi7;
					switch(choi7)
					{
						case 1:
							clrscr();
							addpatient();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 2:
							clrscr();
							searchpatient();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 3:
							clrscr();
							deletepatient();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 4:
							clrscr();
							updatepatient();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto re;
						case 5:
							clrscr();
							cout<<"COMING OUT";
							for(a=0;a<5;a++)
							{
								cout<<".";
								delay(250);
							}
							clrscr();
							goto b;

						default:
						cout<<"Wrong choice want to enter more?"<<endl;
						cin>>choi;
						if(choi=='y'||choi=='Y')
						goto b;
						else
						break;
					}
					break;
				case 2:
					rece:
					clrscr();
					cout<<"\t\t*************** DOCTOR FILE IS READY ***************";
					for(a=0;a<8;a++)
						cout<<endl;
					cout<<endl<<"\t\t\t1. Add doctor.."<<endl;
					cout<<"\t\t\t2. Search doctor.."<<endl;
					cout<<"\t\t\t3. Delete doctor.."<<endl;
					cout<<"\t\t\t4. Update doctor.."<<endl;
					cout<<"\t\t\t5. Logout.."<<endl;
					cout<<endl<<"\t\t\Enter your choice: ";
					cin>>a;
					switch(a)
					{
						case 1:
							clrscr();
							adddoctor();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 2:
							clrscr();
							searchdoctor();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 3:
							clrscr();
							deletedoctor();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 4:
							clrscr();
							updatedoctor();
							clrscr();
							cout<<"Now enter again..."<<endl;
							goto rece;
						case 5:
							clrscr();
							cout<<"YOU ARE LOGGSNG OUT";
							for(a=0;a<5;a++)
							{
								cout<<".";
								delay(250);
							}
							clrscr();
							goto b;

						default:
						cout<<"Wrong choice want to enter more?"<<endl;
						cin>>choi;
						if(choi=='y'||choi=='Y')
						goto b;
						else
						break;
					}
					break;
				case 3:
					stu:
					clrscr();
					cout<<endl<<endl<<"\t\t\tEnter speciality of the doctor"<<endl<<endl;
					cout<<"\t\t\t1. General Physician.."<<endl;
					cout<<"\t\t\t2. E.N.T..."<<endl;
					cout<<"\t\t\t3. Cardiologist.."<<endl;
					cout<<"\t\t\t4. Dermatologist.."<<endl;
					cout<<"\t\t\t5. Gastroenteroiogist.."<<endl;
					cout<<"\t\t\t6. Pediatrician.."<<endl;
					cout<<"\t\t\t7. EYE Specialist.."<<endl;
					cout<<"\t\t\t8. Nephrologist.."<<endl;
					cout<<"\t\t\t9. Back"<<endl;
					cout<<"\t\t\tEnter your choice: ";
					cin>>choi1;
					switch(choi1)
					{
						case 1:
							clrscr();
							showdoc(1);
							clrscr();
							goto stu;
						case 2:
							clrscr();
							showdoc(2);
							clrscr();
							goto stu;
						case 3:
							clrscr();
							showdoc(3);
							clrscr();
							goto stu;
						case 4:
							clrscr();
							showdoc(4);
							clrscr();
							goto stu;
						case 5:
							clrscr();
							showdoc(5);
							clrscr();
							goto stu;
						case 6:
							clrscr();
							showdoc(6);
							clrscr();
							goto stu;
						case 7:
							clrscr();
							showdoc(7);
							clrscr();
							goto stu;
						case 8:
							clrscr();
							showdoc(8);
							clrscr();
							goto stu;
						case 9:
							clrscr();
							goto b;
						default:
							clrscr();
							cout<<"wrong choice:"<<endl;
							cout<<"enter again..."<<endl;
							clrscr();
							goto stu;
					}
					break;
				case 4:
					clrscr();
					cout<<"\t\t\n\nenter the name of the patient: ";
					gets(patientname1);
					cout<<"\n\n";
					showbill(patientname1);
					getch();
					goto b;
				case 5:
					clrscr();
					cout<<"\t\t\tLOGGING OUT";
					for(a=0;a<5;a++)
					{
						cout<<".";
						delay(250);
					}
					clrscr();
					goto A;

				default:
				cout<<"Wrong choice want to enter more?"<<endl;
				cin>>choi;
				if(choi=='y'||choi=='Y')
				goto b;
			}
		}
		else
		{
			cout<<endl<<"Wrong password"<<endl;
			cout<<endl<<"Want to try again?: ";
			cin>>choi;
			if(choi=='y'||choi=='Y')
			{
				clrscr();
				goto a;
			}
			else
			{
				clrscr();
				goto lb;
			}
		}
		break;
		case 2:
			st:
			clrscr();
			cout<<"\t\t*#*#*#*#*#*#*#* WELCOME TO PATIENT PORTAL *#*#*#*#*#*#*#*";
			for(a=0;a<8;a++)
				cout<<endl;
			cout<<"\t\tPress..."<<endl;
			cout<<"\t\t1. New patient"<<endl;
			cout<<"\t\t2. Existing patient"<<endl;
			cout<<"\t\t3. Exit"<<endl;
			cout<<"\t\tenter: ";
			cin>>choi3;
			switch(choi3)
			{
				case 1:
					clrscr();
					cout<<"\t\t*#*#*#*#*#*#*#* WELCOME TO PATIENT PORTAL *#*#*#*#*#*#*#*";
					for(a=0;a<8;a++)
						cout<<endl;
					cout<<"\t\tHere are the doctor's details:"<<endl;
					stu1:
					clrscr();
					cout<<endl<<endl<<"\t\t\tEnter speciality of the doctor"<<endl<<endl;
					cout<<"\t\t\t1. General Physician.."<<endl;
					cout<<"\t\t\t2. E.N.T..."<<endl;
					cout<<"\t\t\t3. Cardiologist.."<<endl;
					cout<<"\t\t\t4. Dermatologist.."<<endl;
					cout<<"\t\t\t5. Gastroenteroiogist.."<<endl;
					cout<<"\t\t\t6. Pediatrician.."<<endl;
					cout<<"\t\t\t7. EYE Specialist.."<<endl;
					cout<<"\t\t\t8. Nephrologist.."<<endl;
					cout<<"\t\t\t9. Back"<<endl;
					cout<<"\t\t\tEnter your choice: ";
					cin>>choi4;
					switch(choi4)
					{
						case 1:
							clrscr();
							showdoc(1);
							clrscr();
							goto stu1;
						case 2:
							clrscr();
							showdoc(2);
							clrscr();
							goto stu1;
						case 3:
							clrscr();
							showdoc(3);
							clrscr();
							goto stu1;
						case 4:
							clrscr();
							showdoc(4);
							clrscr();
							goto stu1;
						case 5:
							clrscr();
							showdoc(5);
							clrscr();
							goto stu1;
						case 6:
							clrscr();
							showdoc(6);
							clrscr();
							goto stu1;
						case 7:
							clrscr();
							showdoc(7);
							clrscr();
							goto stu1;
						case 8:
							clrscr();
							showdoc(8);
							clrscr();
							goto stu1;
						case 9:
							clrscr();
							goto st;
						default:
							clrscr();
							cout<<"wrong choice:"<<endl;
							cout<<"enter again..."<<endl;
							clrscr();
							goto stu1;
					}
				break;
			case 2:
				cout<<"enter patient name: ";
				gets(patientname);
				clrscr();
				result=compname(patientname);
				if(result==1)
				{
					we:
					for(a=0;a<5;a++)
					cout<<endl;
					hell:
					cout<<"\t\tWhat do you want to do.."<<endl;
					cout<<"\t\t1. Show bill"<<endl;
					cout<<"\t\t2. Show all info"<<endl;
					cout<<"\t\t3. exit"<<endl;
					cout<<"\t\tenter: ";
					cin>>choi6;
					switch(choi6)
					{
						case 1:
							clrscr();
							showbill(patientname);
							getch();
							clrscr();
							goto hell;
						case 2:
							clrscr();
							showinfo(patientname);
							getch();
							clrscr();
							goto hell;
						case 3:
							clrscr();
							goto st;

					}
					getch();
				}
				else
				{
					clrscr();
					cout<<"\t\tSORRY!!!!!"<<endl;
					cout<<endl<<"you are not a patient of your hospital"<<endl;
					cout<<"enter again...";
					delay(500);
					goto st;
				}
			case 3:
				clrscr();
				goto lb;
		      }
		case 3:
			break;
		default:
			clrscr();
			cout<<"Wrong choice enter again..."<<endl;
			delay(700);
			goto lb;
		}
	}
