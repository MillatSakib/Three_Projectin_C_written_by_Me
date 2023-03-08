#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int student_count=0;

struct student_info{
    char first_name[50];
    char last_name[50];
    int roll;
    float cgpa;
    int course_id[5];
};
struct student_info student[500];


void add_student(){
    printf("Please enter Student's first Name: ");
    fflush(stdin);
    gets(student[student_count].first_name);
    printf("Please enter Student's Last Name: ");
    fflush(stdin);
    gets(student[student_count].last_name);
    printf("Please enter your id: ");
    scanf("%d",&student[student_count].roll);
    printf("Please enter student's CGPA: ");
    scanf("%f",&student[student_count].cgpa);
    printf("Please enter your course id: ");
    for(int i=0;i<5;i++){
        scanf("%d",&student[student_count].course_id[i]);
    }

    printf("Student's info added Successfully.....\n");
    student_count++;

}


void find_student_RN(){
    int temp_id;
    int i;
    printf("Please enter student id: ");
    scanf("%d",&temp_id);
    printf("\n\n");
    for(i=0;i<student_count;i++){
        if(student[i].roll==temp_id){
            printf("Student's first Name: ");
    puts(student[i].first_name);
    printf("Student's Last Name: ");
    puts(student[i].last_name);
    printf("Your id: ");
    printf("%d",student[i].roll);
    printf("\nStudent's CGPA: ");
    printf("%f",student[i].cgpa);
    printf("\nYour course id: ");
    for(int j=0;j<5;j++){
        printf("%d  ",student[i].course_id[j]);
    }
    printf("\n");
    break;
        }


    }
    if(i==student_count){
        printf("Sorry!!!!%d Roll NO. Not found.\n",temp_id);
    }
    printf("Press a key for operate again...");
    getch();

}
 void find_student_FN(){
        char ch[50];
    int i,k=0;
    printf("Please enter student's First Name: ");
    fflush(stdin);
    gets(ch);
    printf("\n\n");
    for(i=0;i<student_count;i++){
        if(!(strcmp(student[i].first_name,ch))){
            printf("Student's first Name: ");
    puts(student[i].first_name);
    printf("Student's Last Name: ");
    puts(student[i].last_name);
    printf("Your id: ");
    printf("%d",student[i].roll);
    printf("Student's CGPA: ");
    printf("%f",student[i].cgpa);
    printf("Please your course id: ");
    for(int j=0;j<5;j++){
        printf("%d  ",student[i].course_id[j]);
    }
    printf("\n");
    k++;
        }


    }
    if(k==0){
        printf("Sorry!!!!'%s' name not found.\n",ch);
    }
    printf("Press a key for operate again...");
    getch();
 }
 void  find_course_id(){
        int cid;
        printf("Please enter course id: ");
        scanf("%d",&cid);
        printf("The course enrolled:\n");
        for(int i=0;i<student_count;i++){
            for(int j=0;j<5;j++){
                if(student[i].course_id[j]==cid){
                printf("%s %s\n",student[i].first_name,student[i].last_name);
            }
            }


        }

  }
  void find_total_num(){
        printf("In Your instutution there has %d student/s.\n",student_count);
  }
  void delete_info(){
        int sid,index;
        printf("Please enter student's ID for Delete from Databese:");
        scanf("%d",&sid);
        for(int i=0;i<student_count;i++){
            if(student[i].roll==sid){
                index=i;
                break;
            }
        }
        printf("%d\n",index);
        for(int i=index;i<student_count-1;i++){
            student[i]=student[i+1];
        }
        student_count--;
        printf("Deleting.");
        for(int i=0;i<4;i++){
            Sleep(300);
            printf(".");
        }
        printf("\n");
        printf("Student Deleted from database Successfully.\n");
  }
  void update_info(){
          int  choose,temp_roll,index;
      printf("Please enter your Roll: ");
      scanf("%d",&temp_roll);
      for(int i=0;i<student_count;i++){
        if(temp_roll==student[i].roll){
            index=i;
        }
}
    printf("Update List:\n");
    printf("1.Update Student First Name.\n");
    printf("2.Update Student Last Name.\n");
    printf("3.Update Student ID.\n");
    printf("4.Update CGPA.\n");
    printf("5.Update Course ID.\n\n");
    printf("Please enter what want to update: ");
    scanf("%d",&choose);
    switch(choose){
case 1:
    printf("Please enter Student's First Name for update: ");
    fflush(stdin);
    gets(student[index].first_name);
    break;
case 2:
    printf("Please enter Student's  Last Name for update: ");
    fflush(stdin);
    gets(student[index].last_name);
    break;
case 3:
    printf("Please enter Student's Id update: ");
    scanf(student[index].roll);
    break;
case 4:
    printf("Please enter Student's CGPA update: ");
    scanf("%d",student[index].cgpa);
    break;
case 5:
    printf("Please enter your course id: ");
    for(int i=0;i<5;i++){
        scanf("%d",&student[index].course_id[i]);
    }


    break;
    }
    printf("Updating.");
    for(int i=0;i<4;i++){
            Sleep(300);
        printf(".");
    }
    printf("\n");
    printf("Student's info Updated Successfully.....\n");
  }

void all_student(){
    if(student_count>0){
for(int i=0;i<student_count;i++){
    printf("Student %d Info:\n\n",i+1);
    printf("Student's first Name: ");
    puts(student[i].first_name);
    printf("Student's Last Name: ");
    puts(student[i].last_name);
    printf("Your id: ");
    printf("%d",student[i].roll);
    printf("\nStudent's CGPA: ");
    printf("%f",student[i].cgpa);
    printf("\nYour course id: ");
    for(int j=0;j<5;j++){
        printf("%d  ",student[i].course_id[j]);
    }
    printf("\n\n");
}
    }
    else{
        printf("In your Instutute there has no student.\n\n");
    }
printf("Please press a key for goto main page.");
getch();
}
int main(){
    int choose;
    loop:
    printf("\nThe task you can perform; \n");
    printf("1.Add student Detail.\n");
    printf("2.Find the student detais by Roll Number.\n");
    printf("3.fin the Student detail by First Name.\n");
    printf("4.Find the student detail by Course Id.\n");
    printf("5.Find the total Number of Students.\n");
    printf("6.Delete the student detail by Roll Number.\n");
    printf("7.Update the student Detail by Roll Number.\n");
    printf("8.All Students.\n");
    printf("9.To Exit.\n");
    printf("Please enter your choise: ");
    scanf("%d",&choose);
    switch(choose){
    case 1:
        add_student();
        break;
    case 2:
        find_student_RN();
        break;
    case 3:
        find_student_FN();
        break;
    case 4:
        find_course_id();
        break;
    case 5:
        find_total_num();
        break;
    case 6:
        delete_info();
        break;
    case 7:
        update_info();
        break;
    case 8:
        all_student();
        break;
    case 9:
        printf("\nYour program will exit now");
        for(int i=0;i<4;i++){
            Sleep(300);
            printf(".");
        }
        printf("\n");
         exit(0);

    }
goto loop;
return 0;

}
