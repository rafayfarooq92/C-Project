//Function protoype
#include "myFunctionLibrary.h"
/**********************Function Start Here**************************************/
/*My Login Function*/
void login(FILE* inSignupPtr){
     char lemail[81],lpassword[81],lineRead[60];
     int i=0,decryption=0;
             system("cls");
             printf("\t#############\n");
printf("\t#   **      #\n");
printf("\t#   **      #\n");
printf("\t#   **      #\n");
printf("\t#   **      #\n");
printf("\t#   **      Login Screen. \n");
printf("\t#   **       \n");
printf("\t#   ******  #\n");
printf("\t#   ******  #\n");
printf("\t#############\n\n\n");

             printf("\tE-mail:");
             scanf("%s",lemail);
             printf("\tPassword:");
             i=0;
             while((*(lpassword+i)=getch())!='\r')
             {
                    printf("*");
                    i++;
             }   
                    *(lpassword+i)='\0';  
             printf("\tPin:");
             scanf("%d",&decryption);
                    
             for(i=0;i<strlen(lpassword);i++)
             {
                    *(lpassword+i)=*(lpassword+i)+decryption;
             } 
                    *(lpassword+i)='\0';  
                         
                    puts("\n");
                    
             while(fgets(lineRead,60,inSignupPtr)) /* read the name from the file */
             {
             lineRead[strlen(lineRead)-1]='\0';
             if(strcmp(lineRead,lemail)==0)
             break;
             }
             if(strcmp(lineRead,lemail)!=0)
             {
             printf("E-mail not found");
             getch();
             system("cls");
             main();
             }
             else if(strcmp(lineRead,lemail)==0)
             {
             fgets(lineRead, 60, inSignupPtr); /* read the name from the file */
             lineRead[strlen(lineRead)-1]='\0';
             
             if(strcmp(lineRead,lpassword)==0)
             {
             printf("You May Enter:");/*The Programm will excute here*/
             homeScreen();
             }
             else
             {
             printf("Ops..!Wrong Password.\nForgot your Password?\nPress any key to return to main menu:");
             getch();
             system("cls");
             main();
             }//Else loop Close
             }//else if loop Close
             }//While loop close
/***********************End********************************/
/*This is my sign up function*/
/**********************Function Start Here**************************************/

void signup(FILE*inSignupPtr)
{
    char name[81],userName[81],fName[81],email[81],securitychoice[40],password[81],dateOfBirth[81],country[81],city[81],province[81],semester[81],interests[81];
    int decryption=0,i,wrongPassword=0,security;
    char ext[]=".txt";
    char ext3[]="Inbox.txt";
    char profile[]="Profile.txt";
    
    FILE *inSecurityPtr=fopen("security.txt","ab+");
    
    system("cls");
    printf("\t#############\n");
printf("\t#  *******  #\n");
printf("\t#  *******  #\n");
printf("\t# *         #\n");
printf("\t#  ******   #\n");
printf("\t#  ******    Sign Up screen.\n");
printf("\t#        *   \n");
printf("\t# *******   #\n");
printf("\t# *******   #\n");
printf("\t#############\n\n\n");
    printf("\tUser Name:");
    scanf("%s",userName);
    printf("\tFather Name:");
    scanf("%s",fName);
    printf("\tE-mail:");
    scanf("%s",email);
    passagain:
    printf("\tPassword:");
    
    for(i=0;(*(password+i)=getch())!='\r';i++)
    {
         printf("*");
    }
         *(password+i)='\0';  
    printf("\n\tPassword decryption---What is your Pin key-(1-9):");     
    scanf("%d",&decryption);
    for(i=0;i<strlen(password);i++)
    {       
         *(password+i)=*(password+i)+(decryption);    
    }  
    for(i=0;i<strlen(password);i++)
    {
         if(*(password+i)>=65 && *(password+i)<=90 || *(password+i)>=97 && *(password+i)<=122)
             wrongPassword++;
    }
    if(wrongPassword==strlen(password))
    {
         printf("Oops,Wrong or weak Password.Please Enter again and your password must contain Numeric keys.");
         goto passagain;// I know its bad programming to do this but sometime you cant help it 
    }                                   
    fprintf(inSignupPtr,"\n");
    printf("\tDate Of Birth-(DD/MM/YYYY):");
    scanf("%s",dateOfBirth);
    printf("\tCountry:");
    scanf("%s",country);
    printf("\tCity:");
    scanf("%s",city);
    printf("\tProvince:");
    scanf("%s",province);
    printf("\tStuding Semester:");
    scanf("%s",semester);
    printf("\tGender:");
    scanf("%s",interests);
    printf("\n\tThese are some Security option-\"BE CAREFUL\"");
    printf("\n\t1-Chose your favourite Friend.\n");
    printf("\t2-Chose your favourite Teacher.\n");
    printf("\t3-Chose your favourite Birth Place.\n");
    scanf("%d",&security);
    switch(security){
          case 1:
               printf("\n\tPlease Input name of your favourite Friend:");
               scanf("%s",securitychoice);
               for(i=0;i<strlen(securitychoice);i++)
               {       
                        *(securitychoice+i)=*(securitychoice+i)+5;    
               }  
    
               fprintf(inSecurityPtr,"%s",email);
               fprintf(inSecurityPtr,"\n");
               fprintf(inSecurityPtr,"%s",securitychoice);
               fprintf(inSecurityPtr,"\n");
               
               break;
          case 2:
               printf("\n\tPlease input name of your favourite Teacher:");
               scanf("%s",securitychoice);
               for(i=0;i<strlen(securitychoice);i++)
               {       
                        *(securitychoice+i)=*(securitychoice+i)+5;    
               }  
               fprintf(inSecurityPtr,"%s",email);
               fprintf(inSecurityPtr,"\n");
               fprintf(inSecurityPtr,"%s",securitychoice);
               fprintf(inSecurityPtr,"\n");
               break;
          case 3:
               printf("\n\tPlease input name of your Birth Place:");
               scanf("%s",securitychoice);
               for(i=0;i<strlen(securitychoice);i++)
               {       
                        *(securitychoice+i)=*(securitychoice+i)+5;    
               }  
               fprintf(inSecurityPtr,"%s",email);
               fprintf(inSecurityPtr,"\n");
               fprintf(inSecurityPtr,"%s",securitychoice);
               fprintf(inSecurityPtr,"\n");
               break;
               }//Close of Switch                    
    fprintf(inSignupPtr,"%s",email);
    fprintf(inSignupPtr,"\n");
    fprintf(inSignupPtr,"%s",password);
    fprintf(inSignupPtr,"\n");
    strcat(userName,ext);
    FILE *innerSecurity=fopen(userName,"ab+");
    *(userName+strlen(userName)-4)='\0';
    fprintf(innerSecurity,"%s",userName);
    fprintf(innerSecurity,"\n");
    fprintf(innerSecurity,"%s",password);
    fprintf(innerSecurity,"\n");
    
    strcat(userName,profile);
    FILE *profilePtr=fopen(userName,"ab+");
    *(userName+strlen(userName)-11)='\0';
    fprintf(profilePtr,"User Name:");
    fprintf(profilePtr,"%s",userName);
    fprintf(profilePtr,"*");
    fprintf(profilePtr,"Father Name:");
    fprintf(profilePtr,"%s",fName);
    fprintf(profilePtr,"*");
    fprintf(profilePtr,"Province:");
    fprintf(profilePtr,"%s",province);
    fprintf(profilePtr,"*");
    fprintf(profilePtr,"City:");
    fprintf(profilePtr,"%s",city);
    fprintf(profilePtr,"*");
    fprintf(profilePtr,"Country:");
    fprintf(profilePtr,"%s",country);
    fprintf(profilePtr,"*");
    fprintf(profilePtr,"Date Of Birth-(DD/MM/YYYY):");
    fprintf(profilePtr,"%s",dateOfBirth);
    fprintf(profilePtr,"*");
    fprintf(profilePtr,"Gender:");
    fprintf(profilePtr,"%s",interests);
    fprintf(profilePtr,"*");
    printf("Press any key to return to main menu:");
    getch();
    system("cls");
    /*Closing Files*/
    fclose(profilePtr);
    fclose(inSignupPtr);
    fclose(innerSecurity);
    fclose(inSignupPtr);
    
    main();
}
/*******************************Start Here*********************************/
 /*MY FORGOT Password function*/
void forgotPassword(FILE *inSignupPtr){
    FILE *inSecurityPtr=fopen("security.txt","rb+");  
    char lemail[81],lpassword[81],lineRead[60],securitychoice[40];
    int security=0,i=0;
    system("cls");
    printf("\t#############\n");
printf("\t#  ******** #\n");
printf("\t#  ******** #\n");
printf("\t#  **       #\n");
printf("\t#  ******** #\n");
printf("\t#  ********  Forget Password Screen\n");
printf("\t#  **        \n");
printf("\t#  **       #\n");
printf("\t#  **       #\n");
printf("\t#############\n\n\n");

    printf("\tE-mail:");
    scanf("%s",lemail);
    while(fgets(lineRead,60,inSignupPtr)) /* read the name from the file */
    {
    lineRead[strlen(lineRead)-1]='\0';
    if(strcmp(lineRead,lemail)==0)
    break;
    }
    fgets(lineRead,60, inSignupPtr); /* read the name from the file */
    lineRead[strlen(lineRead)-1]='\0';
    puts(lineRead);
    printf("\nEncrypt Password=Decrypt Password-(Your best key from each ASCII Character)");
    printf("\nOr press \"Y\" If you want to login with Security question:");
    if(getch()=='y'||getch()=='Y')
    {
              printf("\nThese are some security option.");
              printf("\n1-Chose your favourite Friend.\n");
              printf("2-Chose your favourite Teacher.\n");
              printf("3-Chose your favourite Birth Place.\n");
              scanf("%d",&security);
    switch(security){
          case 1:
               printf("\n\tPlease input name of your favourite cousin:");
               scanf("%s",securitychoice);
               while(fgets(lineRead,60,inSecurityPtr)) /* read the name from the file */
               {
                   lineRead[strlen(lineRead)-1]='\0';
                   if(strcmp(lineRead,lemail)==0)
                   break;
               }
               fgets(lineRead,60, inSecurityPtr); /* read the name from the file */
               lineRead[strlen(lineRead)-1]='\0';
               for(i=0;i<strlen(securitychoice);i++)
               {       
                        *(securitychoice+i)=*(securitychoice+i)+5;    
               }  
               if(strcmp(lineRead,securitychoice)!=0)
               printf("\nSorry,Wrong ans.Come any other day.lolx");
               else if(strcmp(lineRead,securitychoice)==0)
               {
               printf("\n\tYou May Enter");
               homeScreen();
               }
               
               break;
          case 2:
               printf("\n\tPlease input name of your favourite Teacher:");
               scanf("%s",securitychoice);
               while(fgets(lineRead,60,inSecurityPtr)) /* read the name from the file */
               {
                   lineRead[strlen(lineRead)-1]='\0';
                   if(strcmp(lineRead,lemail)==0)
                   break;
               }
               fgets(lineRead,60, inSecurityPtr); /* read the name from the file */
               lineRead[strlen(lineRead)-1]='\0';
               for(i=0;i<strlen(securitychoice);i++)
               {       
                        *(securitychoice+i)=*(securitychoice+i)+5;    
               }  
               if(strcmp(lineRead,securitychoice)!=0)
               printf("\nSorry,Wrong ans.Come any other day.lolx");
               else if(strcmp(lineRead,securitychoice)==0)
               {
               printf("\n\tYou May Enter");
               homeScreen();
               }
               break;
          case 3:
               printf("\n\tPlease input name of your Birth Place:");
               scanf("%s",securitychoice);
               while(fgets(lineRead,60,inSecurityPtr)) /* read the name from the file */
               {
                   lineRead[strlen(lineRead)-1]='\0';
                   if(strcmp(lineRead,lemail)==0)
                   break;
               }
               fgets(lineRead,60, inSecurityPtr); /* read the name from the file */
               lineRead[strlen(lineRead)-1]='\0';
               for(i=0;i<strlen(securitychoice);i++)
               {       
                        *(securitychoice+i)=*(securitychoice+i)+5;    
               }  
               if(strcmp(lineRead,securitychoice)!=0)
               printf("\nSorry,Wrong Ans.Come any other Day");
               else if(strcmp(lineRead,securitychoice)==0)
               {
               printf("\n\tYou May Enter");
               homeScreen();
               }
               
               break;
               }  //Close Switch
               } //Close if
                                                      
    printf("\nPlease press any key to return to main menu.");                 
    getch();   
    system("cls");
    main();
}
/*********************Starts Here**************************************/
/*This is the Function of home screen*/
void homeScreen()
{
     int homeScreenChoice,i=0,decryption=0;
     time_t t;
  	 time(&t);
     char ext[]="Profile.txt";
     char ext2[]=".txt";
     char ext3[]="Inbox.txt";
     char profileopen[30],yourName[30],date[30],userName[30],password[30],lineRead[30],fName[81],province[30],interests[30],city[30],country[30],dateOfBirth[30];
     char wallUpdate[2000];
     *(wallUpdate+0)='0';
     char reader=0;
     FILE *generalWall=fopen("general.txt","ab+");
     system("cls");
     printHomeScreen();
     printf("\n\nPlease make approperiate chioce:\n\n\n\n\n");
     sendMassages();
     printseeProfiles();
     printingProfile();
     printInbox();
     printcheckWall();
     printUpdateStatus();
     scanf("%d",&homeScreenChoice);
     switch(homeScreenChoice){
              case 1:
                   massage();
                   break;
              case 2:
                   system("cls");
                   printf("User Name:");
                   scanf("%s",profileopen);
                   strcat(profileopen,ext);
                   FILE *readProfile=fopen(profileopen,"ab+");
                   printf("\n");
                   while(fscanf(readProfile,"%c",&reader)!=EOF)
                   {                          
                   if(reader=='*')
                   printf("\n");
                   else
                   printf("%c",reader);
                   }
                   fclose(readProfile);
                   printf("\nPress any key to return to Home Screen");
                   getch();                   
                   system("cls");
                   homeScreen();
                   break;
              case 3:
                    system("cls");
                    printf("User Name:");
                    scanf("%s",userName);
                    printf("Password:");
                    while((*(password+i)=getch())!='\r')
                    {
                    printf("*");
                    i++;
                    }   
                    *(password+i)='\0';  
                    printf("\tPin:");
                    scanf("%d",&decryption);
                    for(i=0;i<strlen(password);i++)    
                    {
                    *(password+i)=*(password+i)+decryption;
                    } 
                    *(password+i)='\0';  
                    strcat(userName,ext2);
                    FILE *accessupProfile=fopen(userName,"r");
                    *(userName+strlen(userName)-4)='\0';
                    while(fgets(lineRead,60,accessupProfile)) /* read the name from the file */
                    {
                    lineRead[strlen(lineRead)-1]='\0';
                    if(strcmp(lineRead,userName)==0)
                    break;
                    }
                    fgets(lineRead,60, accessupProfile); /* read the name from the file */
                    lineRead[strlen(lineRead)-1]='\0';
                    if(strcmp(password,lineRead)==0)
                    {
                    strcat(userName,ext);
                    FILE *updateProfile=fopen(userName,"w");
                    *(userName+strlen(userName)-11)='\0';
                    printf("NOTE:\n\tUpdating of Profile is limited to personal information for this version 0.0.\nFor this you will have same login password and same pasword and username for updating profile for next time.\n\"**YOU WILL CHANGE ONLY PERSONAL INFORMATION IN THIS VERSION**\"\n");
                    printf("\tUser Name:");
                    scanf("%s",userName);
                    printf("\tFather Name:");
                    fprintf(updateProfile,"User Name:");
                    fprintf(updateProfile,"%s",userName);
                    fprintf(updateProfile,"*");
                    scanf("%s",fName);
                    printf("\tDate Of Birth-(MM-DD-YYYY):");
                    fprintf(updateProfile,"Father Name:");
                    fprintf(updateProfile,"%s",fName);
                    fprintf(updateProfile,"*");
                    scanf("%s",dateOfBirth);
                    fprintf(updateProfile,"Date Of Birth-(DD/MM/YYYY):");
                    fprintf(updateProfile,"%s",dateOfBirth);
                    fprintf(updateProfile,"*");
                    printf("\tCountry:");
                    scanf("%s",country);
                    fprintf(updateProfile,"Country:");
                    fprintf(updateProfile,"%s",country);
                    fprintf(updateProfile,"*");
                    printf("\tCity:");
                    scanf("%s",city);
                    fprintf(updateProfile,"City:");
                    fprintf(updateProfile,"%s",city);
                    fprintf(updateProfile,"*");
                    printf("\tProvince:");
                    scanf("%s",province);
                    fprintf(updateProfile,"Province:");
                    fprintf(updateProfile,"%s",province);
                    fprintf(updateProfile,"*");
                    printf("\tGender:");
                    scanf("%s",interests);
                    fprintf(updateProfile,"Gender:");
                    fprintf(updateProfile,"%s",interests);
                    fprintf(updateProfile,"*");
                    fclose(updateProfile);
                    printf("Profile Updated Press Any key to return Home Screen");
                    getch();
                    system("cls");
                    homeScreen();
                    }
                    else if(strcmp(password,lineRead)!=0)
                    {
                    printf("Oops..!Wrong Password.\nForgot your Password?\nPress any key to return to Home Screen:");
                    getch();
                    system("cls");
                    fclose(accessupProfile);
                    homeScreen();
                    }
                    break;
              case 4:
                    seeInbox();
                    break;
              case 5:
                   system("cls");
                   i=0;
                   reader='0';
                   while(fscanf(generalWall,"%c",&reader)!=EOF)
                   {                          
                   if(reader=='*')
                   {
                   printf("\n");
                   }
                   else if(reader == ' ') 
                   printf(" ");
                   else
                   printf("%c",reader);
                   }
                   printf("Press any key to return to Home Screen.");
                   getch();
                   system("cls");
                   homeScreen();
                   break;
              case 6:      
                   system("cls");                                
                   updateStatus();
                   break;
              default:
                   system("cls");
                   printf("Wrong Choice,\n");
                   printf("Press any key to return to Main\n");
                   main();
                   break;
                   }//Switch Close
}//Function Close
     
/*********************Starts Here********************************/     
/*My Logos Definitions*/
void fastMirrorLogo(){
     printf("\td88888b  .d8b.  .d8888. d888888b \n");
     printf("\t88'     d8' `8b 88'  YP `~~88~~' \n");
     printf("\t88ooo   88ooo88 `8bo.      88    \n");
     printf("\t88~~~   88~~~88   `Y8b.    88    \n");
     printf("\t88      88   88 db   8D    88    \n");
     printf("\tYP      YP   YP `8888Y'    YP    \n\n\n");
     printf(".88b  d88. d888888b d8888b. d8888b.  .d88b.  d8888b. \n");
     printf("88'YbdP`88   `88'   88  `8D 88  `8D .8P  Y8. 88  `8D \n");
     printf("88  88  88    88    88oobY' 88oobY' 88    88 88oobY' \n");
     printf("88  88  88    88    88`8b   88`8b   88    88 88`8b   Version 0.0\n");
     printf("88  88  88   .88.   88 `88. 88 `88. `8b  d8' 88 `88. \n");
     printf("YP  YP  YP Y888888P 88   YD 88   YD  `Y88P'  88   YD \n\n\n\n");
     }
/*This is Main Menu options logos*/
void mainMenuLogosandDecisions(){
      printf("#############\n");
      printf("#  *******  #\n");
      printf("#  *******  #\n");
      printf("# *         #\n");
      printf("#  ******   #\n");
      printf("#  ******    TO Sign up For a New account.\n");
      printf("#        *   \n");
      printf("# *******   #\n");
      printf("# *******   #\n");
      printf("#############\n\n\n");
      printf("#############\n");
      printf("#   **      #\n");
      printf("#   **      #\n");
      printf("#   **      #\n");
      printf("#   **      #\n");
      printf("#   **       TO login to your account.\n");
      printf("#   **       \n");
      printf("#   ******  #\n");
      printf("#   ******  #\n");
      printf("#############\n\n\n");
      printf("#############\n");
      printf("#  ******** #\n");
      printf("#  ******** #\n");
      printf("#  **       #\n");
      printf("#  ******** #\n");
      printf("#  ********  To Reterive your Password,OR login.(FORGOT PASSWORD?)\n");
      printf("#  **        \n");
      printf("#  **       #\n");
      printf("#  **       #\n");
      printf("#############\n\n\n");
      }
     
/*This is the definition fo Update Status by Rafay*/
void updateStatus()
{
    time_t t;
  	time(&t);
	char i;
	char status[1000];
	char fstatus;
	char username[10];
FILE* generalWall=fopen("general.txt","a+");
fseek(generalWall,0,SEEK_SET);
                   
printf("Please Update Your Status.\nIf you Want To Update your Status \"Anonymously\" Press \"A\" otherwise Press \"N\"\n" );
scanf(" %c",&i);
if(i=='A'||i=='a')
{
printf("Write:\n");
gets(status);
gets(status);
getchar();
fprintf(generalWall,"%s\n",status);
fprintf(generalWall,"*The Status was Updated at %s by Anonymous*\n", ctime(&t));
}
else
if(i=='N'||i=='n')
{
printf("Write:\n");
gets(status);
gets(status);
printf("Enter your Name:");
scanf("%s",username);
fprintf(generalWall,"%s",status);
fprintf(generalWall,"\n*The Status was Updated at %s by %s*\n", ctime(&t),username);
}
else{
     printf("Wrong Choice.\nPress Any Key To Return To Main Screen");
     getch();
     system("cls");
     main();
     }
fclose(generalWall);
printf("Press any key to continue to home screen.!");
getch();
homeScreen();
}

/***************************Starts Here**********************************/
/*This is the definition of check inbox msgs*/
void seeInbox()
{
    system("cls"); 
    int i=0,decryption=0;
    char password[30],lineRead[30];
	char userName[20];
	char ext[]="Inbox.txt";
	char ext2[]=".txt";
	printf("Please Enter Your User Name:");
	scanf("%s",userName);
	printf("Please Enter Your Password:");
	while((*(password+i)=getch())!='\r')
                    {
                    printf("*");
                    i++;
                    }   
                    *(password+i)='\0'; 
    printf("\tPin:");
    scanf("%d",&decryption);
    for(i=0;i<strlen(password);i++)    
    {
    *(password+i)=*(password+i)+decryption;
    } 
    *(password+i)='\0';
    strcat(userName,ext2);
    FILE *accessInbox=fopen(userName,"r");
    *(userName+strlen(userName)-4)='\0';
    while(fgets(lineRead,60,accessInbox)) /* read the name from the file */
    {
    lineRead[strlen(lineRead)-1]='\0';
    if(strcmp(lineRead,userName)==0)
    break;
    }
    fgets(lineRead,60, accessInbox); /* read the name from the file */
    lineRead[strlen(lineRead)-1]='\0';
    if(strcmp(lineRead,password)==0)
    {                      
    strcat(userName,ext);                
	FILE *readMessage=fopen(userName,"r");
	*(userName+strlen(userName)-9)='\0';
    char reader;
    int i=0;
    while(fscanf(readMessage,"%c",&reader)!=EOF)
    {                          
    if(reader=='*')
    printf("\n");
    else
    printf("%c",reader);
    }//while loop close
    printf("\nPress any key to return to Home Screen.!");
    getch();
    system("cls");
    homeScreen();
    }//If loop Close
    else if(strcmp(password,lineRead)!=0)
    {
    printf("Wrong Password.\nPress any key to return to Home Screen.");
    getch();
    system("cls");
    homeScreen();
    }    
  //  fclose(readMessage); 
    
}

/*A good printing again*/
void printHomeScreen()
{
    printf("*****Welcome to FAST MIRROR v0.0*****\n");
    printf(" _   _  _____  __  __  ____    ___   ___  ____  ____  ____  _  _ \n");
    printf("( )_( )(  _  )(  \\/  )( ___)  / __) / __)(  _ \\( ___)( ___)( \\( )\n");
    printf(" ) _ (  )(_)(  )    (  )__)   \\__ \\( (__  )   / )__)  )__)  )  ( \n");
    printf("(_) (_)(_____)(_/\\/\\_)(____)  (___/ \\___)(_)\\_)(____)(____)(_)\\_)\n");
}

void sendMassages()
{
    printf("\t\t     __  __ \n");
printf("\t\t    (  \\/  )\n");
printf("Press \" 1 \" to send  )    ( assages.\n");
printf("\t\t    (_/\\/\\_)\n\n\n");

}

void printInbox()
{
    printf("\t\t      ____ \n");
    printf("\t\t     (_  _)\n");
    printf("Press \" 4  \" to check _)(_nbox. \n");
    printf("\t\t     (____)\n\n\n");
}

void printUpdateStatus()
{
    printf("\t\t __  __ \n");
printf("\t\t(  )(  )\n");
printf("Press \" 6 \" to   )(__)( pdate status.\n");
printf("\t\t(______)\n\n\n");
}

void printseeProfiles()
{
    printf("\t\t ___ \n");
printf("\t\t/ __)\n");
printf("Press \" 2 \" to  \\__ \\ee profile(s).\n");
printf("\t\t(___/\n\n\n");
}

void printcheckWall()
{
    printf("\t\t  ___ \n");
printf("\t\t / __)\n");
printf("Press \" 5  \" to ( (__ heck wall. \n");
printf("\t\t \\___)\n\n\n");
}

void printingProfile()
{
    printf("\t\t\t ____ \n");
printf("\t\t\t(  _ \\\n");
printf("Press \"  3  \" to update  )___/rofile.\n");
printf("\t\t\t(__)  \n\n\n");
 
}
void massage()
{
     char ext3[]="Inbox.txt";
     char recieverName[30],wallUpdate[3000];
     system("cls"); 
    int i=0,decryption=0;
    char password[30],lineRead[30];
	char userName[20];
	char ext[]="Inbox.txt";
	char ext2[]=".txt";
	printf("Please Enter Your User Name:");
	scanf("%s",userName);
	printf("Please Enter Your Password:");
	while((*(password+i)=getch())!='\r')
                    {
                    printf("*");
                    i++;
                    }   
                    *(password+i)='\0'; 
    printf("\tPin:");
    scanf("%d",&decryption);
    for(i=0;i<strlen(password);i++)    
    {
    *(password+i)=*(password+i)+decryption;
    } 
    *(password+i)='\0';
    strcat(userName,ext2);
    FILE *accessInbox=fopen(userName,"r");
    *(userName+strlen(userName)-4)='\0';
    while(fgets(lineRead,60,accessInbox)) /* read the name from the file */
    {
    lineRead[strlen(lineRead)-1]='\0';
    if(strcmp(lineRead,userName)==0)
    break;
    }
    fgets(lineRead,60, accessInbox); /* read the name from the file */
    lineRead[strlen(lineRead)-1]='\0';
    if(strcmp(lineRead,password)==0)
    {                      
                   printf("TO,\nUser Name:");
                   scanf("%s",recieverName);
                   strcat(recieverName,ext3);
                   FILE *inbox=fopen(recieverName,"wb+");
                   *(recieverName+strlen(recieverName)-9)='\0';
                   fprintf(inbox,"Your Name:");
                   fprintf(inbox,recieverName);
                   fprintf(inbox,"*");
                   fprintf(inbox,"From,");
                   fprintf(inbox,userName);
                   fprintf(inbox,"*");
                   fprintf(inbox,"Wrote:*");
                   printf("Write:\n");    
                   gets(wallUpdate);
                   gets(wallUpdate);
                                  
                   for(i=0;i<strlen(wallUpdate);i++)
                   {
                   fprintf(inbox,"%c",*(wallUpdate+i));
                   }
                   fprintf(inbox,"*");
                   fclose(inbox);
                   printf("Press Any key to return to Home Screen:");
                   getch();
                   system("cls");
                   homeScreen();
                   
     }
     else
     printf("\nPassword or Email does not exit.\nPress any key to return to home screen");
     getch();
     system("cls");
     homeScreen();



}



