NAME:  Deepta B S

USN:   1PI12IS031

QUESTION NUMBER:  3

source code file: asn3_3.c


instructions    :  --- the file must be compiled using the comand
		    "gcc asn2_3.c"    
			
		   --- the file can be run using
			"./a.out -f password.txt -l log.txt "
PROGRAM EXCECUTION:
1.Initially the name and password is checked if it matches the username and password. Once it matches the last login time is stored in an array login[] and displayed on the console.
2.The current time is taken, the username, password,and the current login is appended into the file.
3.The previous line with its name,password and the last login is deleted by coping all the lines except the very line into another file called "replica.txt", which is hence renamed as "password.txt".
	
BUGS:
1.We are getting segmentation fault due to the empty lines present in the password.txt after first excecution due to two main reasons
      1. Since the current line is getting appended after a line.
      2. Since when the username and password is present in the 1st line, the first line is deleted with empty first line.
2. The program works perfectly if we manualy go to the password.txt and delete the spaces due to the new line appended.

TRIALS:
1.We tried various methods to delete the empty spaces, we used fseek but failed to delete the empty spaces. Hence we resorted to creating new file replica and replacing it.Yet we are getting the same error. But if the empty spaces are deleted the code works perfectly. 
