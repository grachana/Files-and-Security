
//The project is to manage files
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dir.h>
#include<dirent.h>

void mainMenu();
void login();
void createAcc();
void manage();
void listAccount();
void viewFile();
void createFile_or_updateFile();
void updateFile();
void deletFile();
void listFile();


char accountName[30],name[30],fname[30],*p;
FILE* fp; FILE* fs ;char data[1000];
char location[50]="C:\\cfile\\";
int option,i,fnum,j;
char str[30]="hello world";
char msg[30];

void main(int argc)
{
	clrscr();
	mainMenu();
	printf("WELCOME TO CFILES\n\n");

		if (argc != 2)
		{
			printf("usage: opendir dirname\n");
		exit(1);
		}
	listFile(strcat("c:\\cfile\\",accountName));

	getch();
}

void mainMenu()
{
	int option;
	while(1)
	{
	printf("1.view account list\n2.login\n3.create an account\n4.exit\n\n");
	printf("enter your option\n");
	scanf("%d",&option);
	switch (option)
	{
	case 1 : listAccount();break;
	case 2 : login();break;
	case 3 : createAcc(); break;
	case 4 : exit(0);
	default : printf("Invalid option\n");break;
	}  }

}
void createAcc()
{
	FILE* fa;
	//char *p;
	printf("create an account\n\n");
	printf("enter your name\n");
	scanf("%s",&name);
	strcat(location,name);
	mkdir(location);
	strcat(location,"\\");
	printf("location:%s\n",location);
	printf("your account is created\n");
	manage();
	exit;
}


void manage()
{
	printf("ENTER   1 TO CREATE FIle OR UPDATE FILE\n");
	printf("        2 TO VIEW FILE CONTENTS\n");
	printf("        3 TO LIST FILE\n");
	printf("enter your option\n");
	scanf("%d",&option);
       switch (option)
		{
			case 1 : createFile_or_updateFile();break;
			case 2 : viewFile();break;
			case 3 : listFile();break;

		}   exit;
		mainMenu();

}

void createFile_or_updateFile()
{
 //	strcat(location,"\\");
	printf("enter the name of the file\n");
	printf("\\");
	scanf("%s",&fname);
 //	printf("enter the account name\n");
 //	scanf("%s",&accountName);
	strcat(location,accountName);
	strcat(location,"\\");
	strcat(location,fname);
	//strcat(p,fname);
	printf("p:%s\n",location);
	fs=fopen(strcat(location,".txt"),"a");

	//updateFile();
	printf("enter the data \n");
	scanf("%s",&data);
	fprintf(fs,"%s\n",data);
	// fwrite(&data,sizeof(data),1,fs);
	fclose(fs);
	printf("your file has been created succesfully\n");
	exit(1);
       manage();


}
void listAccount()
{
       char *s,acc_name[30];
       //	char *viewfilename;
	DIR *directory=NULL;
	struct dirent *box;
      //	printf("enter the account name\n");
	//scanf("%d",&accountName);
     //	strcat(accountName,"\\");
       directory=opendir("c:\\cfile\\");
       if(directory==NULL)
       {
		fprintf(stderr,"can't open dir\n");
       }
       box = readdir(directory);

       while(box!=NULL)

       {
	printf("accounts list = %s\n",box->d_name);
	box=readdir(directory);
	}


}

void login()
{
	printf("Enter the AccountName that exists in c:\\cfile\\\n");
	scanf("%s",&accountName);
	p =searchpath(accountName);
	printf("%s\n\n",p);
	strcat(p,"\\");

	if(p!=NULL)
	{
		printf("your account exits!\n\n");
		printf("welcome to your account\n\n");
		manage();
	}
	else
	{
		printf("your account doesnot exists in the current directory\n\n");
		mainMenu();
	}
	manage();
	exit;

}

void viewFile()
{
	char *data1;
	fgets(data1,strlen(data),fs);
	printf("%s\n",data);
}

void listFile()
{
  DIR *dir;  char *dirname;
  struct dirent *ent;
  printf("enter the account name\n");
  scanf("%s",&accountName);
  dirname=strcat("c:\\cfile\\",accountName);
  printf("First pass on '%s':\n",dirname);
  if ((dir = opendir(dirname)) == NULL)
  {
    perror("Unable to open directory");
    exit(1);
  }
  while ((ent = readdir(dir)) != NULL)
    printf("%s\n",ent->d_name);

 /* printf("Second pass on '%s':\n",dirname);
  rewinddir(dir);
  while ((ent = readdir(dir)) != NULL)
    printf("%s\n",ent->d_name);
  if (closedir(dir) != 0)
    perror("Unable to close directory");  */

}
