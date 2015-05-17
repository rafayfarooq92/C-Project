/*****************************************************************************
This is a program which is Inspired by FACEBOOK. This Program is like Facebook
we called it FAST-Mirror Version 0.0 .In this program all the key features of 
FACEBOOK are being following. Also in addition there is a database of all the 
data with name of the User file name is saved.We are also providing a facilty of 
Password Encryption. In Case user Forget his or her Password we can give him 
multiple choices to regain his/her Password. The Algorithm of password encryption
is very unique such that the administrator himself didnt know the password of 
particular person. This shows that our Software is completely Reliable and Secure.
for Further Detail you can look it into our Algorithm, we try our level best to
define and make our code easier to understand as much as we can,
******************************************************************************/

/*---------------------------------Start Welcome-------------------------------*/
//Libraries
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//Function Prototypes
#include"myFunctionLibrary.c"
#include"myFunctionLibrary.h"
int main()
{
    char menuChoice=0;
    FILE *inSignupPtr=fopen("login.txt","ab+");
/***************************Function Calls************************************/  
    fastMirrorLogo();//This prints the FAST MIRROR's logo
    mainMenuLogosandDecisions(); //tHIS pRInts other main screen logos
/*-----------------------------------------------------------------------------*/
    printf("Choice:");
    scanf(" %c",&menuChoice);
/*Login or SignUp or Forget Password*/
    switch(menuChoice){
        case 'S':
             signup(inSignupPtr);
             break;
        case 'L':
             login(inSignupPtr);
             break;
        case 'F':
             forgotPassword(inSignupPtr);
        default :
             printf("Wrong Choice."); 
             system("cls");
             main();
             break;    
}          
/*--------fclose-An important function by which you can write,append or read without closing 
-----------------------------The Console----------------------------------------*/
    fclose(inSignupPtr);
    getch();
    return 0;
}
