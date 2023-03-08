//This programme is for simple Encryption & Decryption



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>


    int password=119804;
    char w,spt;
    int plen,key,ascii;
    int count=0;

    int ran_key();
    int key_pin();
    int encryption_decryption();
    int encryption();
    int decryption();



    int main(){
    encryption_decryption();
    system("CLS");
    printf("\n\n\t\t\t\tThe program ends here...");
    printf("\n\n\t\t-------------------------------------------------\n\n");
    getch();
    getch();
    getch();
    return 0;

}




    int ran_key(){
        time_t seconds;

    seconds = time(NULL);

    long long second=seconds;

    key= 2+(second%22);

    return key;

    }





    int key_pin(){

    int pinmach;
    tryagain:

        if(count>0){
            printf("\nYou enter wrong passwor %d time/s. You can try more %d time/s.\n\n",count,3-count);
        }
    printf("Please Enter your Pin to know your Encryption key: ");
    scanf("%d",&pinmach);
    if(password==pinmach){
        printf("Password Matched successfully..\n\n");
          printf("Your automatic key is %d",key);
            count==0;

    }
    else{
        printf("Password Not Matched..\n\a");


        count++;


        if(count>=3){
           printf("\n\nSorry You try Maximum time..We  will exit you from the program for security issue.\n\n");
            printf("\n\n\t\t\t\tThe program ends here...");
    printf("\n\n\t\t-------------------------------------------------\n\n");
           exit(0);
           }
           printf("If you want to re-enter your password press a key.\n");
           getch();
           system("CLS");
           goto tryagain;
    }


}




int encryption_decryption(){
        char  enorde;





            system("CLS");
            printf("\t\t\t-------------------------------------------------\n");
                printf("\t\t\t|\tWelcome to Encryption Decryption. \t|\n");
    printf("\t\t\t-------------------------------------------------\n\n\n");
    printf("Please enter E if you want Encryption or press D if you want Decryption: ");
    scanf(" %c",&enorde);





    if(enorde=='e'||enorde=='E'){
        encryption();
    }




       else if(enorde=='d'||enorde=='D'){
        decryption();

    }



    else{
        printf("\nYou choose wrong value");
    }



    printf("\n\n Do you want Encrypt or Decrypt again???\n");
    printf("If you want Encrypt or Decrypt again press 'Y'.And if you don't want press 'N': ");
    scanf(" %c",&w);
    if((w=='y'||w=='Y')||(w=='n'|| w== 'N'))
    printf("");


        else{
            printf("You Press a wrong Key..Note: If you press wrong key again...This programme will exit....\n");
            printf("\nPlease enter a valid(Y/N) key: ");
            scanf(" %c",&w);


            if((w=='y'||w=='Y')||(w=='n'||w== 'N'))
                printf("");
            else{
                        printf("\nSorry..You Press a wrong key Again..\n\a");
    }
    }
    if(w=='n'||w=='N'){
        system("EXIT");
    }
    if(w=='y'||w=='Y'){
        encryption_decryption();
    }


}







int encryption(){
    char plaintext[500];

    printf("\nPlease enter the Plain text: ");

        fflush(stdin);

        gets(plaintext);

        plen=strlen(plaintext);

        ran_key();

        printf("\nThe chipher text is: ");

        for(int i=0;i<plen;i++){

               ascii = plaintext[i];

         if(ascii==32){

            printf("%c",ascii);


         }

         else if(ascii>=65 && ascii<=90){
            int temp;
            temp=ascii-65;
            temp=(temp+key)%26;
            temp=temp+65;

            printf("%c",temp);
         }



        else if(ascii>=97 && ascii<=122){
            int temp;
            temp=ascii-97;
            temp=(temp+key)%26;
            temp=temp+97;
            printf("%c",temp);
         }
         else if( (ascii>=48 && ascii<=58) || (ascii>=33 && ascii<=48)  || (ascii>=58 && ascii<=65) ||(ascii==92)||(ascii==94) ||(ascii==95) ){
            int temp;
            temp=ascii;
            printf("%c",temp);
         }


        }

        printf("\n\n");
        key_pin();

}






int decryption(){
        char ciphertext[500];

        printf("\nPlease enter the Cipher text: ");

        fflush(stdin);

        gets(ciphertext);

        plen=strlen(ciphertext);

        printf("\nPlease enter the Key: ");

        scanf(" %d",&key);

        printf("\nThe chipher text is: ");

        for(int i=0;i<plen;i++){

               ascii = ciphertext[i];
         if(ascii==32){

            printf("%c",ascii);

         }
         else if(ascii>=65 && ascii<=90){
            int temp;

            temp=ascii-65;

            temp=(temp-key)%26;

            if(temp<0){

                temp+=26;
            }

            temp=temp+65;

            printf("%c",temp);
         }
        else if(ascii>=97 && ascii<=122){

            int temp;

            temp=ascii-97;

            temp=(temp-key)%26;

            if(temp<0){

                temp+=26;
            }


            temp=temp+97;

            printf("%c",temp);

         }
     else if( (ascii>=48 && ascii<=58) || (ascii>=33 && ascii<=48)  || (ascii>=58 && ascii<=65) ||(ascii==92)||(ascii==94) ||(ascii==95) ){
            int temp;
            temp=ascii;
            printf("%c",temp);
         }

    }


}
