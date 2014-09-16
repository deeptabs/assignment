#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
void call(char *fvalue, char *lvalue, char* c_time_string);
void compare(char * username, char * password, char *fvalue, char *lvalue, char *c_time_string );
char uname[20], pswrd[20],login[20],x[10],y[10],z[10];static int k=0;
int flag=0; int i=0;int l=0;int m=0;int f=0;
char username[20], password[20];int v=0;
char buffer[25];char *fvalue= NULL,*lvalue= NULL,lFlag=0;
char temp[500];char line[100];

int main(int argc, char **argv)
{
	char uname[20], pswrd[20];
	int flag=0; int k=0;
	char username[20], password[20];
	time_t current_time;
	char* c_time_string;
	current_time = time(NULL);
	int c,got;
	char *fvalue= NULL,*lvalue= NULL,lFlag=0;
	FILE * fp,*filepointer;
	if (current_time == ((time_t)-1)) {
		(void) fprintf(stderr, "Failure to compute the current time.");
        	return EXIT_FAILURE;
    	}
	c_time_string = ctime(&current_time);
	if (c_time_string == NULL) {
        	(void) fprintf(stderr, "Failure to convert the current time.");
        	return EXIT_FAILURE;
    	}

	while((c=getopt(argc,argv,"l:f:")) !=-1) {
                switch(c) {
                        case 'f':fvalue=optarg;
                                 if(strcmp(fvalue,"password.txt") != 0) {
                                         printf("Can't open the required file\n");
                                         printf("The file to be opened was password.txt. TRY AGAIN!!!\n");
                                         exit(EXIT_FAILURE);
                                 }
                                 break;
                        case 'l':lFlag=1;
				 lvalue=optarg;
                                 if(strcmp(lvalue,"log.txt") != 0) {
                                         printf("Can't open the required file\n");
                                         printf("The file to be opened was log.txt. TRY AGAIN!!!\n");
                                         exit(EXIT_FAILURE);
				 }
                                 break;
                        default:
                                 printf("Invaild input \n");
                                 exit(EXIT_FAILURE);
                }
	}
	
	filepointer=fopen("log.txt","a+");
	fprintf(filepointer,"%s\t\tInput Received:%s\n",c_time_string,fvalue);
	fflush(filepointer);
	call(fvalue,lvalue,c_time_string);
	return 0;
}

void call(char *fvalue, char *lvalue, char* c_time_string)
{
	printf("Please Enter User Name: \n");
	scanf("%s", username);
	printf("Please Enter Password: \n");
	scanf("%s",password);
	compare(username,password,fvalue,lvalue,c_time_string);
     

  }
    
void compare(char * username, char * password, char *fvalue, char *lvalue, char *c_time_string )
{	
  int i,j;char line[100];int flag1=0;
  
		       
  char* dee;
 int * dee1;
 FILE *fptr = fopen(fvalue, "r+");
     if (fptr==NULL)
	{
	printf("File not found\n");
	 }
     else
	{
	while(fgets(line, sizeof line, fptr)!=NULL) {
  char * usern;
  usern = strtok (line," ,.-");

if(strcmp(username,usern)==0)
               {
			flag=1;
			break;
                   
                }
	     	      

}   fclose(fptr);

FILE *fptr = fopen(fvalue, "a+");
while (!feof(fptr)) //while loop to run while not end of file
	
          {  i=-1,j=0,k=0,l=0,m=0;
		       //fscanf(fptr,"%s",temp);
		       fgets(temp,500,fptr);
		       //printf("%s",temp);
		      
     	       do{
			     i++;
		       }while(temp[i]!=',');	
		       i++;
    		
		        f=f+1;
		      do {  
			    pswrd[j]=temp[i];
			    i++;
			    j++;
		       } while(temp[i]!=',');
		
		pswrd[i]='\0';
		i++;
		
		
		do {  
			    login[k]=temp[i];
			    i++;
			    k++;
			    //printf("%c",login[k]);
		       } while(temp[i]!='\0');
	
		
		k++;
		login[k]='\0';
		
		
		
		
                               if(flag==1 && strcmp(password,pswrd)==0) 

               {  flag1=1;
			break;
                }
	}


               
		if(flag1==1)
               {
		   printf("welcome %s \n",username);
		   printf("Last Login : %s\n" ,login);
		   // printf("Last Login : %s %s %s %s %s \n", temp,dee,x,y,z );
		   
		    printf("current login: %s \n",c_time_string);
		    
		    fprintf(fptr,"%s,",username);
		    fprintf(fptr,"%s,",password);
		    //fwrite(",",sizeof(","),1,fptr);
		    fprintf(fptr,"%s",c_time_string);
		    //fwrite("\n",sizeof("\n"),1,fptr);
		    //printf("line number is %d" ,f);
                    fclose(fptr); 


    FILE *fileptr1,*fileptr2;
    //char filename[40];
    char ch;
    int tp = 1;
     fileptr1 = fopen("password.txt", "r");
    ch = getc(fileptr1);
    //printf("Enter file name: ");
    //scanf("%s", filename);
    //open file in read mode
    
    ch = getc(fileptr1);
   while (ch != EOF)
    {
        //printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
   // printf(" \n Enter line number of the line to be deleted:");
    //scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen("replica.txt", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
            tp++;
            //except the line to be deleted
            if (tp != f)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("password.txt");
    //rename the file replica.c to original name
    rename("replica.txt", "password.txt");
    /*printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;*/

		}
		else
			{
			 v=v+1;
			if(v==3)
				{
				printf("Maximum attempts exceeded\n");
				}
			else
 				{
				printf("Invalid Username or Password\n you have 3  chances");
			      call(fvalue,lvalue,c_time_string);
			}
		}
                  


               

          

     

    

}
 
}


































                  
   
   
   
