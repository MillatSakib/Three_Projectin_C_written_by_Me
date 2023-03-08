#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
//#inlcude <conio.h>
char pass[]="s@lAuddin";
int id=222902036;
bool log_in(int pid,int ipass){
    if(strcmp(pass,ipass) && id==pid){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int id,count=0;
    char pass[50];
    printf("Please enter your id: ");
    scanf("%d",&id);
    printf("Plese enter your password: ");
    while(pass[count-1]!=13){
        pass[count]=getch();
        count++;
        if(pass[count-1]==8){
            count--;
            continue;

        }
        printf("*");
    }
    printf("Your password is: %s",pass);
    return 0;

}

