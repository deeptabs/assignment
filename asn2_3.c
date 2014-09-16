#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
void call(char *fvalue, char *lvalue);
void compare(char * username, char * password, char *fvalue, char *lvalue);
char uname[20], pswrd[20];int k=0;
int flag=0; int i=0;
char username[20], password[20];
char buffer[25];char *fvalue= NULL,*lvalue= NULL,lFlag=0;
char temp[50];char line[100];

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
	call(fvalue,lvalue);
	return 0;
}

void call(char *fvalue, char *lvalue)
{
	printf("Please Enter User Name: \n");
	scanf("%s", username);
	printf("Please Enter Password: \n");
	scanf("%s",password);
	compare(username,password,fvalue,lvalue);
     

  }
    
void compare(char * username, char * password, char *fvalue, char *lvalue)
{	
  int i,j;char line[100];int flag1=0;
  
  
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

FILE *fptr = fopen(fvalue, "r+");
while (!feof(fptr)) //while loop to run while not end of file

          {  i=-1,j=0;
		       fscanf(fptr,"%s",temp);
     	       do{
			     i++;
		       }while(temp[i]!=',');	
		       i++;
    		
		       
		      do {  
			    pswrd[j]=temp[i];
			    i++;
			    j++;
		       } while(temp[i]!='\0');
		
		pswrd[i]='\0';
		
                               if(flag==1 && strcmp(password,pswrd)==0) 

               {  flag1=1;
			break;
                }
	}

               
		if(flag1==1)
               {
		   printf("Welcome %s\n",usern);
		}
		else
			{
			 k=k+1;
			if(k==3)
				{
				printf("Maximum attempts exceeded\n");
				}
			else
 				{
				printf("Invalid Username or Password\n you have 3  chances");
			      call(fvalue,lvalue);
			}
		}
                  


               

          }

     

     fclose(fptr); 

}


