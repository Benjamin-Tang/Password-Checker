#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
 char p[150];					// declaring string to read from
 int i = 0;					// declaring variable to increment string
 int pwLength = 0;				// declaring variable for password length
 int charSetSize = 0;				// declaring variable for character set size
 int upperCaseCount = 0;			// declaring variable for upper case counter
 int lowerCaseCount = 0;			// declaring variable for lower case counter
 int digitCount = 0;				// declaring variable for digit counter
 int lowSpecialCount = 0;			// declaring variable for low special counter
 int highSpecialCount = 0;			// declaring variable for high special counter

 scanf("%[^\n]s",p);				// asking for user input from terminal

 pwLength =  strlen(p);				// calculating password length

 for(i = 0; i < pwLength; i++)			// loop to increment character set size counters
	{
	if ((p[i] >= 0 && p[i] <= 31) || (p[i] >= 34 && p[i] <= 35) || (p[i] >= 39 && p[i] <= 44) || p[i] == 47 || p[i] == 60 || p[i] == 62 || (p[i] >= 91 && p[i] <= 93) || p[i] == 96 || (p[i] >= 123 && p[i] <= 127))
	{
	pwLength = i;
	break;
	}
 	else if (p[i] >= 'A' && p[i] <= 'Z')
		upperCaseCount++;
	else if (p[i] >= 'a' && p[i] <= 'z')
		lowerCaseCount++;
	else if (p[i] >= '0' && p[i] <= '9')
		digitCount++;
	else if (p[i] == ' ' || p[i] == '!' || p[i] == '$' || p[i] == '&' || p[i] == '-' || p[i] == '.' || p[i] == '%')
		lowSpecialCount++;
	else if (p[i] == ':' || p[i] == ';' || p[i] == '?' || p[i] == '@' || p[i] == '_' || p[i] == '=' || p[i] == '^')
		highSpecialCount++;
	} 




 if(upperCaseCount > 0){										// using if statements to find the appropriate character set size values that are present
	charSetSize = charSetSize + 26;}
 if(lowerCaseCount > 0){
	charSetSize = charSetSize + 26;}
 if(digitCount > 0){
	charSetSize = charSetSize + 10;}
 if(lowSpecialCount > 0){
	charSetSize = charSetSize + 7;}
 if(highSpecialCount > 0){
	charSetSize = charSetSize + 7;}




 if(pwLength < 12)											// using if and nested if statements for passwords under 12 characters in length
	{												// using if statements for the five quality metrics that must be met
	if(upperCaseCount <= 0 || lowerCaseCount <= 0 || digitCount <= 0 || (lowSpecialCount <= 0 && highSpecialCount <= 0) || pwLength < 6) 	
		{
		printf("Quality metric failed because:\n");

		if(upperCaseCount <= 0)
			printf("\t- No Uppercase character present\n\n");
		if(lowerCaseCount <= 0)
			printf("\t- No Lowercase character present\n\n");	
		if(digitCount <= 0)
			printf("\t- No Digit character present\n");
		if(lowSpecialCount <= 0 && highSpecialCount <= 0)
			printf("\t- No special character present\n\n");
		if(pwLength < 6)
			printf("\t- Password length less than 6 characters\n\n");
		printf("Length: %d\n",pwLength);							// informing user of password length
		printf("Char set size: %d\n", charSetSize);						// informing user of character set size
		printf("Estimated hours to hack: %4.3e", (pow(charSetSize,pwLength))/36000000); 	// informing user of hours needed to hack password
		}
	else
		{	 										// for passwords that are under 12 characters, but meet all quality metrics
		 printf("Quality metric passed.\n\n");							// informing user that password meets requirements
		 printf("Length: %d\n",pwLength);							// informing user of password length
		 printf("Char set size: %d\n", charSetSize);						// informing user of character set size
		 printf("Estimated hours to hack: %4.3e", (pow(charSetSize,pwLength))/36000000); 	// informing user of hours needed to hack password
		}
	}


													/* the next 4 else if statements used to check 
													for the quality metrics for passwords that are 12 or more characters long */
else if(pwLength >= 12 && upperCaseCount >= 0 && lowerCaseCount <= 0 && digitCount <= 0 && (lowSpecialCount <= 0 && highSpecialCount <= 0))
	{												
	printf("Quality metric failed because:\n");
	printf("\t- Only Uppercase characters present\n\n");
	printf("Length: %d\n",pwLength);								// informing user of password length
	printf("Char set size: %d\n", charSetSize);							// informing user of character set size
	printf("Estimated hours to hack: %4.3e", (pow(charSetSize,pwLength))/36000000); 		// informing user of hours needed to hack password
	}
else if(pwLength >= 12 && upperCaseCount <= 0 && lowerCaseCount >= 0 && digitCount <= 0 && (lowSpecialCount <= 0 && highSpecialCount <= 0))
	{
	printf("Quality metric failed because:\n");
	printf("\t- Only Lowercase characters present\n\n");
	printf("Length: %d\n",pwLength);								// informing user of password length
	printf("Char set size: %d\n", charSetSize);							// informing user of character set size
	printf("Estimated hours to hack: %4.3e", (pow(charSetSize,pwLength))/36000000); 		// informing user of hours needed to hack password
	}
else if(pwLength >= 12 && upperCaseCount <= 0 && lowerCaseCount <= 0 && digitCount >= 0 && (lowSpecialCount <= 0 && highSpecialCount <= 0))
	{
	printf("Quality metric failed because:\n");
	printf("\t- Only Digit characters present\n\n");
	printf("Length: %d\n",pwLength);								// informing user of password length
	printf("Char set size: %d\n", charSetSize);							// informing user of character set size
	printf("Estimated hours to hack: %4.3e", (pow(charSetSize,pwLength))/36000000); 		// informing user of hours needed to hack password
	}
else if(pwLength >= 12 && upperCaseCount <= 0 && lowerCaseCount <= 0 && digitCount <= 0 && (lowSpecialCount >= 0 || highSpecialCount >= 0))
	{
	printf("Quality metric failed because:\n");
	printf("\t- Only special characters present\n\n");
	printf("Length: %d\n",pwLength);								// informing user of password length
	printf("Char set size: %d\n", charSetSize);							// informing user of character set size
	printf("Estimated hours to hack: %4.3e", (pow(charSetSize,pwLength))/36000000); 		// informing user of hours needed to hack password
	}
	

else
	{
  printf("Quality metric passed.\n\n");									// informing user that password meets requirements
  printf("Length: %d\n",pwLength);									// informing user of password length
  printf("Char set size: %d\n", charSetSize);								// informing user of character set size
  printf("Estimated hours to hack: %4.3e\n", (pow(charSetSize,pwLength))/36000000); 			// informing user of hours needed to hack password
	}




    return 0;
}