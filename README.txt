NAME:  Deepta B S

USN:   1PI12IS031

QUESTION NUMBER:  3

QUESTION TITLE:   Write a “login” program for a user that asks the user to enter a username and a password. The
username and password should have a matching entry in the file which has the data stored in
the following format:
username1,password1
username2,password2
username3,password3
...
If the username and password matches an entry in the file, display a message saying “Welcome
<username>!”. If a matching entry is not found, display a message “Wrong
username/password, please try again” and prompt the user to enter his/her credentials again.
Allow a maximum of upto 3 consecutive incorrect attempts and then the program should
terminate saying “Maximum attempts exceeded”. Consider at least 20 entries in the file
containing username and passwords.



source code file: asn2_3.c


instructions    :  --- the file must be compiled using the comand
		    "gcc asn2_3.c"    
			
		   --- the file can be run using
			"./a.out -f password.txt -l log.txt "
PROGRAM EXCECUTION:
		1. The log file has only the date time and the text file name.
	        2. if user does not type password.txt as the text file input in getopt, the program will show error.
	        3.if user does not type log.txt as the text file input in getopt for -l, the program will show error.
		4. A buffer is kept and conditon  {usern = strtok (line," ,.-")} is used thid function points to the first string 			  before "," and hence stores it as username. it sets flag to 1 if it matches the username typed by user
		5. File is close and a new pointer is hence opened, it is incremented till the pointer crosses the "," using a do 			   while loop.
		6.once the pointer crosses the "," the string of characters are stored in pswrd[] and compared with password types by the 			  user. if flg is 1 and password matches , password will be accepted.
		7. If wrong name or username then a count of three chances are given by calling function call() then program 			   terminates.	
BUGS:
	My program will not work efficintly with space in between names, i could make it work by putting the string of charactes till 		"," in another array. It works like that i have tried.But i wanted the program to work with {usern = strtok (line," ,.-")} since i put 		lots of effort understanding it.

	do {
	i++;
	uname[j]=text[i]
 } while(text[i]!=',');

 if(strcmp(username,uname)==0 && strcmp(password,pswrd)==0)
		
		would work with space as well.
