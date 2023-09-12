#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Mehmet Emin Yavuz 210229051

struct personnelInfo
{
	char namePersonnel[30];
	char surnamePersonnel[30];
	char personelLesson[30];
	char registryPersonnel[16];
	char passwordPersonnel[16];
	char filePersonnelName[30];
	char filePersonnelSurname[30];
	char filePersonnelRegistry[16];
	char filePersonnelPassword[16];
	char passwordConfirmationP[16];
}academic[4];

struct officerInfo
{
	char nameOfficer[30];
	char surnameOfficer[30];
	char registryOfficer[16];
	char passwordOfficer[16];
	char passwordConfirmationO[16];
}officer;

struct adminstrativeInfo
{	
	char nameAdmin[30];
	char surnameAdmin[30];
	char registryAdmin[16];
	char passwordAdmin[16];
	char passwordConfirmationA[16];
	
}admin;

struct studentInfo
{
	char nameStudent[30];
	char surnameStudent[30];
	int idStudent;
	char passwordStudent[16];
	char passwordConfirmationS[16];
	char studentDepartment[30];
	int fileStudentNo;
	char fileStudentPassword[16];
	char fileStudentName[20];
	char fileStudentSurname[20];
	char fileStudentDepartment[30];
	
	int fileStudentNoForLesson;
	char fileStudentLesson1[20];
	char fileStudentLesson2[20];
	
	int fileStudentIdForNotes1;
	int fileStudentMidtermGrade1;
	int fileStudentFinalGrade1;
	int fileStudentIdForNotes2;
	int fileStudentMidtermGrade2;
	int fileStudentFinalGrade2;
	int fileStudentIdForNotes3;
	int fileStudentMidtermGrade3;
	int fileStudentFinalGrade3;
	int fileStudentIdForNotes4;
	int fileStudentMidtermGrade4;
	int fileStudentFinalGrade4;
	
}student[100];

struct departmentInfo
{
	char department1[20];
	char department2[20];
	char department3[20];
}department;

struct lessonInfo
{
	char lesson1[20];
	char lesson2[20];
	char lesson3[20];
	char lesson4[20];
}lesson;

int mainMenu(){ //ana menü fonksiyonu
	
	int menuStatus=0; //menünün kontrolü için tanýmlanan deðiþken
	int menuDecision; //kullanýcýnýn vereceði menü kararý
	char exitDecision; //kullanýcýn programdan çýkmak istemesi durumu için tanýmlanan deðiþken
	
	while(menuStatus==0){ //menüye dönüþ için yapýlan koþullu döngü iþlemi
		
		printf("\n******MAIN MENU******\n\n");
		printf("1. ACADEMIC LOGIN\n");
		printf("2. OFFICER LOGIN\n");
		printf("3. ADMINISTRATIVE LOGIN\n");
		printf("4. STUDENT LOGIN\n");
		printf("5. EXIT\n");
		
		printf("Please choose a valid login method![1-4]: ");
		scanf("%d",&menuDecision);	
		
		switch(menuDecision){ //switch case yöntemiyle menü kurulumu, fonksiyon çaðýrma iþlemleri ve menüden çýkýþ kontrolü
		
			case 1:
				academicMenu();
				menuStatus=1;
				break;		
			case 2: 
				officerMenu();
				menuStatus=1;
				break;
				
			case 3:
				adminstrativeMenu();
				menuStatus=1;	
				break;
				
			case 4:
				studentMenu();
				menuStatus=1;
				break;
				
			case 5:
				printf("Do you want to exit the program?[Y/y:Yes--N/n:No]: ");
				scanf("%s",&exitDecision);	
					
				if(exitDecision=='Y' || exitDecision=='y'){
					exit(0); 
					break;
				}
				
				else if(exitDecision=='N' || exitDecision=='n'){
					break;
				}
				else{
					printf("Please Enter a Valid Character!");
					break;
				}	
				
			default: 
				printf("Please Enter a Valid Character!\n\n"); //olabilecek 10 durumdan daha farklý bir durum seçilmesi istenmesi halinde verilecek hata cevabý.
				break;		
		}	
	}
}

int academicMenu(){	

	int menuStatus=0; //menünün kontrolü için tanýmlanan deðiþken
	int menuDecision; //kullanýcýnýn vereceði menü kararý
	
	while(menuStatus==0){ //menüye dönüþ için yapýlan koþullu döngü iþlemi
		
		printf("\n******ACADEMIC MENU******\n\n");
		printf("1. LOG IN\n");
		printf("2. MAIN MENU\n");
		
		printf("Please choose a valid login method!: [1-2]: ");
		scanf("%d",&menuDecision);	
		
		switch(menuDecision){ //switch case yöntemiyle menü kurulumu, fonksiyon çaðýrma iþlemleri ve menüden çýkýþ kontrolü
		
			case 1:
				academicLogin();
				menuStatus=1;
				break;		
		
			case 2:
				mainMenu();
				break;
			
			default: 
				printf("Please Enter a Valid Character!\n\n"); //olabilecek 10 durumdan daha farklý bir durum seçilmesi istenmesi halinde verilecek hata cevabý.
				break;		
	
		}
	}
}

int academicLogin(){
	
	int i;
	int loginStatusAcademic=0;
	int academicOperationsDecision;
	char registrationAcademicLogin[20];
	char passwordAcademicLogin[16];
	
	int studentNoGrade;
	int studentMidterm;
	int studentFinal;
	
	
	
	char fileLesson1Academic[20];
	char fileLesson2Academic[20];
	char fileLesson3Academic[20];
	char fileLesson4Academic[20];
	
	
	FILE *fileAcademicIncludedLessons;
	fileAcademicIncludedLessons = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\academicIncludedLessons.txt","r");
	
	FILE *fileLesson1;
	fileLesson1 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson1.txt","r");
	
	FILE *fileLesson2;
	fileLesson2 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson2.txt","r");
	
	FILE *fileLesson3;
	fileLesson3 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson3.txt","r");
	
	FILE *fileLesson4;
	fileLesson4 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson4.txt","r");
	
	FILE *fileLesson1IncludeNotes;
	fileLesson1IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson1IncludeNotes.txt","a");
	
	FILE *fileLesson2IncludeNotes;
	fileLesson2IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson2IncludeNotes.txt","a");
	
	FILE *fileLesson3IncludeNotes;
	fileLesson3IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson3IncludeNotes.txt","a");
	
	FILE *fileLesson4IncludeNotes;
	fileLesson4IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson4IncludeNotes.txt","a");
	
	
	fscanf(fileLesson1,"%s",&fileLesson1Academic);	
	fscanf(fileLesson2,"%s",&fileLesson2Academic);
	fscanf(fileLesson3,"%s",&fileLesson3Academic);
	fscanf(fileLesson4,"%s",&fileLesson4Academic);
	
	printf("Registration No: ");
	scanf("%s",&registrationAcademicLogin);
	
	
	for(i=0;i<4;i++){
		
		fscanf(fileAcademicIncludedLessons,"%s %s %s %s %s",&academic[i].filePersonnelRegistry,&academic[i].filePersonnelPassword,&academic[i].filePersonnelName,&academic[i].filePersonnelSurname,&academic[i].personelLesson);
	
		if(strcmp(registrationAcademicLogin,academic[i].filePersonnelRegistry)==0){
			printf("Password: ");
			scanf("%s",&passwordAcademicLogin);
			
			if(strcmp(passwordAcademicLogin,academic[i].filePersonnelPassword)==0){
				printf("\n******Welcome %s %s!******\n",academic[i].filePersonnelName,academic[i].filePersonnelSurname);
				printf("%s!\n\n",academic[i].personelLesson);
				printf("1-STUDENT'S EXAM GRADE ENTRY\n");
				printf("2-ACADEMIC MENU\n");
				printf("Please enter the process you want to do![1-2]: ");
				scanf("%d",&academicOperationsDecision);
				
				if(academicOperationsDecision == 1){
					if(strcmp(academic[i].personelLesson,fileLesson1Academic)==0){
						printf("Please enter the number of the student whose grade you will enter!: ");
						scanf("%d",&studentNoGrade);
						
						printf("Please enter the student's midterm exam grade!: ");
						scanf("%d",&studentMidterm);
						
						printf("Please enter the student's final exam grade!: ");
						scanf("%d",&studentFinal);
						
						fprintf(fileLesson1IncludeNotes,"%d %d %d ",studentNoGrade,studentMidterm,studentFinal);
						
					}
					else if(strcmp(academic[i].personelLesson,fileLesson2Academic)==0){
						printf("Please enter the number of the student whose grade you will enter!: ");
						scanf("%d",&studentNoGrade);
						
						printf("Please enter the student's midterm exam grade!: ");
						scanf("%d",&studentMidterm);
						
						printf("Please enter the student's final exam grade!: ");
						scanf("%d",&studentFinal);
						
						fprintf(fileLesson2IncludeNotes,"%d %d %d ",studentNoGrade,studentMidterm,studentFinal);
						
					}
					else if(strcmp(academic[i].personelLesson,fileLesson3Academic)==0){
						printf("Please enter the number of the student whose grade you will enter!: ");
						scanf("%d",&studentNoGrade);
						
						printf("Please enter the student's midterm exam grade!: ");
						scanf("%d",&studentMidterm);
						
						printf("Please enter the student's final exam grade!: ");
						scanf("%d",&studentFinal);
						
						fprintf(fileLesson3IncludeNotes,"%d %d %d ",studentNoGrade,studentMidterm,studentFinal);
						
					}
					else if(strcmp(academic[i].personelLesson,fileLesson4Academic)==0){
						printf("Please enter the number of the student whose grade you will enter!: ");
						scanf("%d",&studentNoGrade);
						
						printf("Please enter the student's midterm exam grade!: ");
						scanf("%d",&studentMidterm);
						
						printf("Please enter the student's final exam grade!: ");
						scanf("%d",&studentFinal);
						
						fprintf(fileLesson4IncludeNotes,"%d %d %d ",studentNoGrade,studentMidterm,studentFinal);
						
					}
				}
				else if(academicOperationsDecision == 2){
					academicMenu();
				}
				
				
				
				break;
			}
			
		}
		else{
			printf("Your Registration No is Wrong!\n\n");
			academicLogin();
		}
	}					
}

int officerMenu(){

	int menuStatus=0; //menünün kontrolü için tanýmlanan deðiþken
	int menuDecision; //kullanýcýnýn vereceði menü kararý
	
	while(menuStatus==0){ //menüye dönüþ için yapýlan koþullu döngü iþlemi

		printf("\n******OFFICER MENU******\n\n");
		printf("1. LOG IN\n");
		printf("2. MAIN MENU\n");
		
		printf("Please choose a valid login method!: [1-2]: ");
		scanf("%d",&menuDecision);	
		
		switch(menuDecision){ //switch case yöntemiyle menü kurulumu, fonksiyon çaðýrma iþlemleri ve menüden çýkýþ kontrolü
		
			case 1:
				officerLogin();
				menuStatus=1;
				break;		
		
			case 2:
				mainMenu();
				break;
			
			default: 
				printf("Please Enter a Valid Character!\n\n"); //olabilecek 10 durumdan daha farklý bir durum seçilmesi istenmesi halinde verilecek hata cevabý.
				break;		
		}
	}
}

int officerLogin(){
	
	int i,j;
	int loginStatusOfficer=0;
	int officerMenuDecision;
	int backtoOfficerStatus=0;
	int studentDepartmentDecision;
	char backtoOfficerDecision;
	int studentRegistrationStatus=0;
	char studentRegisterDecision;
	
	char fileNameAcademic[20];
	char fileSurnameAcademic[20];
	char personnelLesson[20];
	int assignPersonnelDecision;
	int assignLessonDecision;
	
	char fileRegistry[16]; //dosyadan çekilen kullanýcý adý
	char filePassword[16]; //dosyadan çekilen þifre
	char fileName[20]; //dosyadan cekilen isim 
	char fileSurname[20]; //dosyadan cekilen soyisim
	char registryLogin[16]; //kullanici girisi kullanici adý
	char passwordLogin[16]; //kullanýcý girisi sifre
	
	FILE *fileOfficer;
	fileOfficer = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\officer.txt","r");
	
	FILE *fileLesson1;
	fileLesson1 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson1.txt","a+");
	
	FILE *fileLesson2;
	fileLesson2 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson2.txt","a+");
	
	FILE *fileLesson3;
	fileLesson3 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson3.txt","a+");
	
	FILE *fileLesson4;
	fileLesson4 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson4.txt","a+");
	
	FILE *fileStudent;
	fileStudent = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\student.txt","a");
	
	FILE *fileDepartment;
	fileDepartment = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\department.txt","r");
	
	FILE *fileAcademic;
	fileAcademic = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\academic.txt","r");
	
	FILE *fileAcademicIncludedLessons;
	fileAcademicIncludedLessons = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\academicIncludedLessons.txt","a");
	
	
	fscanf(fileOfficer,"%s %s %s %s",&fileRegistry,&filePassword,&fileName,&fileSurname);
	
		
	while(loginStatusOfficer==0){
		
		printf("Registry No: ");
		scanf("%s",&registryLogin);
		
		if(strcmp(registryLogin,fileRegistry)==0){
			printf("Password: ");
			scanf("%s",&passwordLogin);
			
			if(strcmp(passwordLogin,filePassword)==0){
				loginStatusOfficer=1;
				printf("\n\n******Welcome %s %s!******\n\n",fileName,fileSurname);
				printf("1-Lesson Opening Operations\n");
				printf("2-Student Registration\n");
				printf("3-Lesson Assignment Operations\n\n");
				printf("Please enter the process you want to do![1-3]: ");
				scanf("%d",&officerMenuDecision);
				
				if(officerMenuDecision == 1){
					
					printf("Please enter the LESSON's you will open!: \n");
					
					printf("1- :");
					scanf("%s",&lesson.lesson1);
					fprintf(fileLesson1,"%s",lesson.lesson1);
					fprintf(fileLesson1," ");
					
						
					printf("2-: ");
					scanf("%s",&lesson.lesson2);
					fprintf(fileLesson2,"%s",lesson.lesson2);
					fprintf(fileLesson2," ");
					
					printf("3-: ");
					scanf("%s",&lesson.lesson3);
					fprintf(fileLesson3,"%s",lesson.lesson3);
					fprintf(fileLesson3," ");
					
					printf("4-: ");
					scanf("%s",&lesson.lesson4);
					fprintf(fileLesson4,"%s",lesson.lesson4);
					fprintf(fileLesson4," ");
					
								
				}
				
				else if(officerMenuDecision == 2){
					
						
					for(i=0;i<100;i++){
						
						printf("Name: ");
						scanf("%s",&student[i].nameStudent);
							
						printf("Surname: ");
						scanf("%s",&student[i].surnameStudent);
						
						department: printf("Student's Department: \n");
						
						fscanf(fileDepartment,"%s %s %s",&department.department1,&department.department2,&department.department3);
						
						printf("%s\n",department.department1);
						printf("%s\n",department.department2);
						printf("%s\n",department.department3);
						
						printf("Please Choose Student's Department![1-3]: ");
						scanf("%d",&studentDepartmentDecision);
						
						if(studentDepartmentDecision==1){
							fprintf(fileStudent,"%s ",department.department1);
						}
						else if(studentDepartmentDecision==2){
							fprintf(fileStudent,"%s ",department.department2);
						}
						else if(studentDepartmentDecision==3){
							fprintf(fileStudent,"%s ",department.department3);
						}
						else{
							printf("Please Enter a Valid Character!");
							goto department;
						}
							
						printf("No: ");
						scanf("%d",&student[i].idStudent);
						
						printf("Password: ");
						scanf("%s",&student[i].passwordStudent);
							
						printf("Password Confirmation: ");
						scanf("%s",&student[i].passwordConfirmationS);
						
						if(strcmp(student[i].passwordStudent,student[i].passwordConfirmationS)==0){
							
							fprintf(fileStudent,"%d",student[i].idStudent);
							fprintf(fileStudent," ");
							fprintf(fileStudent,"%s",student[i].passwordStudent);
							fprintf(fileStudent," ");
							fprintf(fileStudent,"%s",student[i].nameStudent);
							fprintf(fileStudent," ");
							fprintf(fileStudent,"%s",student[i].surnameStudent);
							fprintf(fileStudent," ");
							fprintf(fileStudent,"%s",student[i].studentDepartment);
							
							
							printf("Your registration has been successfully received!\n");
							table: printf("Would you like to register another student?[Y/y:Yes - N/n:No]: ");
							scanf("%s",&studentRegisterDecision);
							
							if(studentRegisterDecision=='Y' || studentRegisterDecision=='y'){
							
								
							}
							
							else if(studentRegisterDecision=='N' || studentRegisterDecision=='n'){
								exit(0);
							}
							else{
								printf("Please Enter Valid Character!\n");
								goto table;
							}
		
						}
							
						else{
							printf("The password you entered do not match!\n");
						}
						
					}
						
				}
				else if(officerMenuDecision == 3){
					for(j=0;j<4;j++){
						
						fscanf(fileAcademic,"%s %s %s %s",&academic[j].filePersonnelRegistry,&academic[j].filePersonnelPassword,&academic[j].filePersonnelName,&academic[j].filePersonnelSurname);
						printf("%d- %s %s\n",j+1,academic[j].filePersonnelName,academic[j].filePersonnelSurname);
								
					}
					printf("Please select the Personnel you want to assign a lesson to![1-4]:");
					scanf("%d",&assignPersonnelDecision);
					
					fscanf(fileLesson1,"%s",&lesson.lesson1);
					fscanf(fileLesson2,"%s",&lesson.lesson2);
					fscanf(fileLesson3,"%s",&lesson.lesson3);
					fscanf(fileLesson4,"%s",&lesson.lesson4);
					
					
					if(assignPersonnelDecision == 1){
					
						
						printf("1-%s\n2-%s\n3-%s\n4-%s\n",lesson.lesson1,lesson.lesson2,lesson.lesson3,lesson.lesson4);
						printf("Please select the lesson you want to assign a personnel to![1-4]:");
						scanf("%d",&assignLessonDecision);
						if(assignLessonDecision == 1){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[0].filePersonnelRegistry,academic[0].filePersonnelPassword,academic[0].filePersonnelName,academic[0].filePersonnelSurname,lesson.lesson1);
							printf("Lesson assignment completed successfully!");
						
						}
						else if(assignLessonDecision == 2){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[0].filePersonnelRegistry,academic[0].filePersonnelPassword,academic[0].filePersonnelName,academic[0].filePersonnelSurname,lesson.lesson2);							
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 3){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[0].filePersonnelRegistry,academic[0].filePersonnelPassword,academic[0].filePersonnelName,academic[0].filePersonnelSurname,lesson.lesson3);							
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 4){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[0].filePersonnelRegistry,academic[0].filePersonnelPassword,academic[0].filePersonnelName,academic[0].filePersonnelSurname,lesson.lesson4);							
							printf("Lesson assignment completed successfully!");
						}
					
					}
					
					if(assignPersonnelDecision == 2){
					
						
						printf("1-%s\n2-%s\n3-%s\n4-%s\n",lesson.lesson1,lesson.lesson2,lesson.lesson3,lesson.lesson4);
						printf("Please select the lesson you want to assign a personnel to![1-4]:");
						scanf("%d",&assignLessonDecision);
						if(assignLessonDecision == 1){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[1].filePersonnelRegistry,academic[1].filePersonnelPassword,academic[1].filePersonnelName,academic[1].filePersonnelSurname,lesson.lesson1);
							printf("Lesson assignment completed successfully!");
						
						}
						else if(assignLessonDecision == 2){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[1].filePersonnelRegistry,academic[1].filePersonnelPassword,academic[1].filePersonnelName,academic[1].filePersonnelSurname,lesson.lesson2);							
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 3){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[1].filePersonnelRegistry,academic[1].filePersonnelPassword,academic[1].filePersonnelName,academic[1].filePersonnelSurname,lesson.lesson3);							
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 4){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[1].filePersonnelRegistry,academic[1].filePersonnelPassword,academic[1].filePersonnelName,academic[1].filePersonnelSurname,lesson.lesson4);							
							printf("Lesson assignment completed successfully!");
						}
					
					}
					
					if(assignPersonnelDecision == 3){
					
						
						printf("1-%s\n2-%s\n3-%s\n4-%s\n",lesson.lesson1,lesson.lesson2,lesson.lesson3,lesson.lesson4);
						printf("Please select the lesson you want to assign a personnel to![1-4]:");
						scanf("%d",&assignLessonDecision);
						if(assignLessonDecision == 1){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[2].filePersonnelRegistry,academic[2].filePersonnelPassword,academic[2].filePersonnelName,academic[2].filePersonnelSurname,lesson.lesson1);
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 2){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[2].filePersonnelRegistry,academic[2].filePersonnelPassword,academic[2].filePersonnelName,academic[2].filePersonnelSurname,lesson.lesson2);	
							printf("Lesson assignment completed successfully!");					
						}
						else if(assignLessonDecision == 3){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[2].filePersonnelRegistry,academic[2].filePersonnelPassword,academic[2].filePersonnelName,academic[2].filePersonnelSurname,lesson.lesson3);							
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 4){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[2].filePersonnelRegistry,academic[2].filePersonnelPassword,academic[2].filePersonnelName,academic[2].filePersonnelSurname,lesson.lesson4);						
							printf("Lesson assignment completed successfully!");
						}
					}
					
					if(assignPersonnelDecision == 4){
					
						
						printf("1-%s\n2-%s\n3-%s\n4-%s\n",lesson.lesson1,lesson.lesson2,lesson.lesson3,lesson.lesson4);
						printf("Please select the lesson you want to assign a personnel to![1-4]:");
						scanf("%d",&assignLessonDecision);
						if(assignLessonDecision == 1){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[3].filePersonnelRegistry,academic[3].filePersonnelPassword,academic[3].filePersonnelName,academic[3].filePersonnelSurname,lesson.lesson1);
							printf("Lesson assignment completed successfully!");
						
						}
						else if(assignLessonDecision == 2){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[3].filePersonnelRegistry,academic[3].filePersonnelPassword,academic[3].filePersonnelName,academic[3].filePersonnelSurname,lesson.lesson2);							
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 3){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[3].filePersonnelRegistry,academic[3].filePersonnelPassword,academic[3].filePersonnelName,academic[3].filePersonnelSurname,lesson.lesson3);							
							printf("Lesson assignment completed successfully!");
						}
						else if(assignLessonDecision == 4){
							fprintf(fileAcademicIncludedLessons,"%s %s %s %s %s ",academic[3].filePersonnelRegistry,academic[3].filePersonnelPassword,academic[3].filePersonnelName,academic[3].filePersonnelSurname,lesson.lesson4);							
							printf("Lesson assignment completed successfully!");
						}
					
					}
					
				}
					
			}
			
			else{
				printf("Your Password Is Wrong!\n\n");
				loginStatusOfficer=0;
			}
			
		}
		else{
			printf("Your Registration No is Wrong!\n\n");
			loginStatusOfficer=0;
		}
		
	}
		
}

int adminstrativeMenu(){
	
	int menuStatus=0; //menünün kontrolü için tanýmlanan deðiþken
	int menuDecision; //kullanýcýnýn vereceði menü kararý
	
	while(menuStatus==0){ //menüye dönüþ için yapýlan koþullu döngü iþlemi
	
	
		printf("\n******ADMINSTRATIVE MENU******\n\n");
		printf("1. LOG IN\n");
		printf("2. SIGN UP\n");
		printf("3. MAIN MENU\n");
		
		printf("Please choose a valid login method!: [1-3]: ");
		scanf("%d",&menuDecision);	
		
		switch(menuDecision){ //switch case yöntemiyle menü kurulumu, fonksiyon çaðýrma iþlemleri ve menüden çýkýþ kontrolü
		
			case 1:
				adminstrativeLogin();
				menuStatus=1;
				break;		
		
			case 2:
				adminstrativeSign();
				menuStatus=1;	
				break;
				
			case 3:
				mainMenu();
				break;
			
			default: 
				printf("Please Enter a Valid Character!\n\n"); //olabilecek 10 durumdan daha farklý bir durum seçilmesi istenmesi halinde verilecek hata cevabý.
				break;		
	
		}
	}
	
}

int adminstrativeSign(){
	
	int signStatus=0;
	int backtomenuStatus=0;
	int backtomenuDecision;
	
	FILE *fileAdmin;
	fileAdmin = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\admin.txt","a");
	
	while(signStatus==0){
		
		printf("\nName: ");
		scanf("%s",admin.nameAdmin);
	
		printf("Surname: ");
		scanf("%s",admin.surnameAdmin);
		
		printf("Registration No:  ");
		scanf("%s",&admin.registryAdmin);
		
		printf("Password: ");
		scanf("%s",&admin.passwordAdmin);
		
		printf("Password Confirmation: ");
		scanf("%s",&admin.passwordConfirmationA);
	
		if(strcmp(admin.passwordAdmin,admin.passwordConfirmationA)==0){
			
			fprintf(fileAdmin,"%s",admin.registryAdmin);
			fprintf(fileAdmin," ");
			fprintf(fileAdmin,"%s",admin.passwordAdmin);
			fprintf(fileAdmin," ");
			fprintf(fileAdmin,"%s",admin.nameAdmin);
			fprintf(fileAdmin," ");
			fprintf(fileAdmin,"%s",admin.surnameAdmin);
			fclose(fileAdmin);
			signStatus=1;
			
			printf("Your registration has been successfully received!\n");
			
			while(backtomenuStatus==0){
				
		
				printf("Would you like to return to the menu?[Y/y:Yes - N/n:No]");
				scanf("%s",&backtomenuDecision);
				
				if(backtomenuDecision=='Y' || backtomenuDecision=='y'){
					adminstrativeMenu();
					backtomenuStatus=1;
				}
				else if(backtomenuDecision=='N' || backtomenuDecision=='n'){
					exit(0);
				}
				
				else{
					printf("Please Enter a Valid Character!\n\n");
					backtomenuStatus=0;
				}
				
			}
			
		}
	
		else{
			printf("The passwords you entered do not match!");
		} 			
	}		
}

int adminstrativeLogin(){
	
	int i,j;
	
	int loginStatus=0;
	int adminMenuDecision;
	int backtoMenuDecision;
	
	char fileRegistryLogin[16]; //dosyadan çekilen kullanýcý adý
	char filePasswordminLogin[16]; //dosyadan çekilen þifre
	char fileNameLogin[30]; //dosyadan cekilen isim 
	char fileSurnameLogin[30]; //dosyadan cekilen soyisim
	char registryLogin[16]; //kullanici girisi kullanici adý
	char passwordLogin[16]; //kullanýcý girisi sifre
	
	char registerAcademicDecision;
	
	int officerRegistrationStatus=0;
	int backtoOfficerMenuStatus=0;
	char backtoOfficerMenuDecision;
	
	int studentRegistrationStatus=0;
	char studentRegisterDecision;
	
	
	FILE *fileAdmin;
	fileAdmin = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\admin.txt","r");
	
	FILE *fileOfficer;
	fileOfficer = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\officer.txt","a");
	
	FILE *fileDepartment;
	fileDepartment = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\department.txt","a");
	
	FILE *fileAcademic;
	fileAcademic = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\academic.txt","a");
		
	
	fscanf(fileAdmin,"%s %s %s %s",&fileRegistryLogin,&filePasswordminLogin,&fileNameLogin,&fileSurnameLogin);
	fclose(fileAdmin);
	
		
	while(loginStatus==0){

		printf("Registration No: ");
		scanf("%s",&registryLogin);
		
		if(strcmp(fileRegistryLogin,registryLogin)==0){
			
			printf("Password: ");
			scanf("%s",&passwordLogin);
			
			if(strcmp(filePasswordminLogin,passwordLogin)==0){
				
				loginStatus=1;
					
				printf("\n\n******Welcome %s %s!******\n\n",fileNameLogin,fileSurnameLogin);
				
				printf("1-Department Opening Operations\n");
				printf("2-Academic Personnel Registration\n");
				printf("3-Officer Registration\n");
			
				printf("Please enter the process you want to do!: ");
				scanf("%d",&adminMenuDecision);
				
				if(adminMenuDecision == 1){
					
					printf("Please enter the DEPARTMENT's you will open!: \n");
					
					
					printf("1- :");
					scanf("%s",&department.department1);	
					printf("2-: ");
					scanf("%s",&department.department2);
					printf("3-: ");
					scanf("%s",&department.department3);
					
					
					fprintf(fileDepartment,"%s",department.department1);
					fprintf(fileDepartment," ");
					fprintf(fileDepartment,"%s",department.department2);
					fprintf(fileDepartment," ");
					fprintf(fileDepartment,"%s",department.department3);
				
					fclose(fileDepartment);			
				}
				
				else if(adminMenuDecision == 2){
					
					for(j=0;j<4;j++){
					
						printf("Name: ");
						scanf("%s",&academic[j].namePersonnel);
						
						printf("Surname: ");
						scanf("%s",&academic[j].surnamePersonnel);
						
						printf("Registration No: ");
						scanf("%s",&academic[j].registryPersonnel);
						
						printf("Password: ");
						scanf("%s",&academic[j].passwordPersonnel);
						
						printf("Password Confirmation: ");
						scanf("%s",&academic[j].passwordConfirmationP);
						
						if(strcmp(academic[j].passwordPersonnel,academic[j].passwordConfirmationP)==0){
			
							fprintf(fileAcademic,"%s",academic[j].registryPersonnel);
							fprintf(fileAcademic," ");
							fprintf(fileAcademic,"%s",academic[j].passwordPersonnel);
							fprintf(fileAcademic," ");
							fprintf(fileAcademic,"%s",academic[j].namePersonnel);
							fprintf(fileAcademic," ");
							fprintf(fileAcademic,"%s",academic[j].surnamePersonnel);
							fprintf(fileAcademic," ");
						
							
							printf("Your registration has been successfully received!\n");
							registeracademic: printf("Would You Like to Register Another Personnel![Y/y:Yes - N/n:No]: ");
							scanf("%s",&registerAcademicDecision);
							
							if(registerAcademicDecision=='Y' || registerAcademicDecision=='y'){
								
							}
							else if(registerAcademicDecision=='N' || registerAcademicDecision=='n'){
								break;
							}
							else{
								printf("Please Enter a Valid Character!\n");
								goto registeracademic;
							}
								
						}
						
					}
	
				}
				
				else if(adminMenuDecision == 3){
					
						while(officerRegistrationStatus==0){
		
							printf("\nName: ");
							scanf("%s",&officer.nameOfficer);
	
							printf("Surname: ");
							scanf("%s",&officer.surnameOfficer);
		
							printf("Registration No:  ");
							scanf("%s",&officer.registryOfficer);
		
							printf("Password: ");
							scanf("%s",&officer.passwordOfficer);
		
							printf("Password Confirmation: ");
							scanf("%s",&officer.passwordConfirmationO);
						
							if(strcmp(officer.passwordOfficer,officer.passwordConfirmationO)==0){
								
								fprintf(fileOfficer,"%s",officer.registryOfficer);
								fprintf(fileOfficer," ");
								fprintf(fileOfficer,"%s",officer.passwordOfficer);
								fprintf(fileOfficer," ");
								fprintf(fileOfficer,"%s",officer.nameOfficer);
								fprintf(fileOfficer," ");
								fprintf(fileOfficer,"%s",officer.surnameOfficer);
								fclose(fileOfficer);
								officerRegistrationStatus=1;
								
								printf("Your registration has been successfully received!\n");
								
								while(backtoOfficerMenuStatus==0){
									
							
									printf("Would you like to return to the menu?[Y/y:Yes - N/n:No]");
									scanf("%s",&backtoOfficerMenuDecision);
									
									if(backtoOfficerMenuDecision=='Y' || backtoOfficerMenuDecision=='y'){
										officerMenu();
										backtoOfficerMenuStatus=1;
									}
									else if(backtoOfficerMenuDecision=='N' || backtoOfficerMenuDecision=='n'){
										exit(0);
									}
									
									else{
										printf("Please Enter a Valid Character!\n\n");
										backtoOfficerMenuStatus=0;
									}
									
								}
								
							}
						
							else{
								printf("The passwords you entered do not match!");
							} 	
					}		
					
				}
				
				else printf("Please enter a valid character!");	
				
						
			}
			else{
				printf("Your Password Is Wrong!\n\n");
				loginStatus=0;
			}
		}
		else{
			printf("Your Registration No Is Wrong!\n\n");
			loginStatus=0;
		}	
	}		
}

int studentMenu(){
	
	int menuStatus=0; //menünün kontrolü için tanýmlanan deðiþken
	int menuDecision; //kullanýcýnýn vereceði menü kararý
	
	while(menuStatus==0){ //menüye dönüþ için yapýlan koþullu döngü iþlemi
	
	
		
		printf("\n******STUDENT MENU******\n\n");
		printf("1. LOGIN\n");
		printf("2. MAIN MENU\n");
		
		printf("Please choose a valid login method![1-2]: ");
		scanf("%d",&menuDecision);	
		
		switch(menuDecision){ //switch case yöntemiyle menü kurulumu
		
			case 1:
				studentLogin();
				menuStatus=1;
				break;		
				
			case 2:
				mainMenu();
				break;
			
			default: 
				printf("Please Enter a Valid Character!\n\n"); //olabilecek 10 durumdan daha farklý bir durum seçilmesi istenmesi halinde verilecek hata cevabý.
				break;		
	
		}
	}	
}

int studentLogin(){
	
	int i,j,k;
	int studentMenuDecision;
	
	int studentNoLogin;
	char studentPasswordLogin[16];
	
	int lessonSelection;
	int counterLesson=0;
	
	char studentLesson1[20];
	char studentLesson2[20];
	char studentLesson3[20];
	char studentLesson4[20];
	
	char fileStudentLesson1[20];
	char fileStudentLesson2[20];

	
	FILE *fileStudentNoIncludeLesson;
	fileStudentNoIncludeLesson = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\studentNoIncludeLesson.txt","a+");
	
	FILE *fileLesson1IncludeNotes;
	fileLesson1IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson1IncludeNotes.txt","r");
	
	FILE *fileLesson2IncludeNotes;
	fileLesson2IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson2IncludeNotes.txt","r");
	
	FILE *fileLesson3IncludeNotes;
	fileLesson3IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson3IncludeNotes.txt","r");
	
	FILE *fileLesson4IncludeNotes;
	fileLesson4IncludeNotes = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson4IncludeNotes.txt","r");
	
	FILE *fileLesson1;
	fileLesson1 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson1.txt","r");    
	
	FILE *fileLesson2;
	fileLesson2 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson2.txt","r");
	
	FILE *fileLesson3;
	fileLesson3 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson3.txt","r");
	
	FILE *fileLesson4;
	fileLesson4 = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\lesson4.txt","r");
	
	FILE *fileStudent;
	fileStudent = fopen("C:\\Users\\AHMET\\Desktop\\Proglamlama-Final\\student.txt","r");
	
	fscanf(fileLesson1,"%s",&studentLesson1);
	fscanf(fileLesson2,"%s",&studentLesson2);
	fscanf(fileLesson3,"%s",&studentLesson3);
	fscanf(fileLesson4,"%s",&studentLesson4);
	
	
	for(i=0;i<300;i++){
		fscanf(fileLesson1IncludeNotes,"%d %d %d",&student[i].fileStudentIdForNotes1,&student[i].fileStudentMidtermGrade1,&student[i].fileStudentFinalGrade1);
		fscanf(fileLesson2IncludeNotes,"%d %d %d",&student[i].fileStudentIdForNotes2,&student[i].fileStudentMidtermGrade2,&student[i].fileStudentFinalGrade2);
		fscanf(fileLesson3IncludeNotes,"%d %d %d",&student[i].fileStudentIdForNotes3,&student[i].fileStudentMidtermGrade3,&student[i].fileStudentFinalGrade3);
		fscanf(fileLesson4IncludeNotes,"%d %d %d",&student[i].fileStudentIdForNotes4,&student[i].fileStudentMidtermGrade4,&student[i].fileStudentFinalGrade4);
	}
	
	printf("Student's No: ");
	scanf("%d",&studentNoLogin);
		
	for(i=0;i<100;i++){
			
		fscanf(fileStudent,"%s %d %s %s %s",&student[i].fileStudentDepartment,&student[i].fileStudentNo,&student[i].fileStudentPassword,&student[i].fileStudentName,&student[i].fileStudentSurname);
	
			
		if(studentNoLogin==student[i].fileStudentNo){
			printf("Password: ");
			scanf("%s",&studentPasswordLogin);
				
			if(strcmp(studentPasswordLogin,student[i].fileStudentPassword)==0){
					
				printf("\n\n******Welcome %s %s %s!******\n\n",student[i].fileStudentName,student[i].fileStudentSurname,student[i].fileStudentDepartment);
				printf("1-LEARN GRADE STATUS\n");
				printf("2-LESSON SELECTION\n\n");
				printf("Please enter the process you want to do![1-2]: ");
				scanf("%d",&studentMenuDecision);
				if(studentMenuDecision == 1){
				
					for(j=0;j<300;j++){
						
						fscanf(fileStudentNoIncludeLesson,"%d %s %s",&student[j].fileStudentNoForLesson,&student[j].fileStudentLesson1,&student[j].fileStudentLesson2);
						if(studentNoLogin==student[j].fileStudentNoForLesson){
							printf("%s  %s",student[j].fileStudentLesson1,student[j].fileStudentLesson2);
							
							for(k=0;k<300;k++){
									
								if(studentNoLogin==student[k].fileStudentIdForNotes1){
									printf("%d %d\n",student[k].fileStudentMidtermGrade1,student[k].fileStudentFinalGrade1);
									if((student[k].fileStudentMidtermGrade1+student[k].fileStudentFinalGrade1)/2 >= 50)	printf("Passed!");
									else printf("Not Passed!");
								}
								
								
								if(studentNoLogin==student[k].fileStudentIdForNotes2){
									printf("%d %d\n",student[k].fileStudentMidtermGrade2,student[k].fileStudentFinalGrade2);
									if((student[k].fileStudentMidtermGrade2+student[k].fileStudentFinalGrade2)/2 >= 50)	printf("Passed!");
									else printf("Not Passed!");
								}
								if(studentNoLogin==student[k].fileStudentIdForNotes3){
									printf("%d %d\n",student[k].fileStudentMidtermGrade3,student[k].fileStudentFinalGrade3);
									if((student[k].fileStudentMidtermGrade3+student[k].fileStudentFinalGrade3)/2 >= 50)	printf("Passed!");
									else printf("Not Passed!");
								}
								if(studentNoLogin==student[k].fileStudentIdForNotes4){
									printf("%d %d\n",student[k].fileStudentMidtermGrade4,student[k].fileStudentFinalGrade4);
									if((student[k].fileStudentMidtermGrade4+student[k].fileStudentFinalGrade4)/2 >= 50)	printf("Passed!");
									else printf("Not Passed!");
								}
							}
						}
					}
				}
				
				else if(studentMenuDecision == 2){
					
					fprintf(fileStudentNoIncludeLesson,"%d ",student[i].fileStudentNo);
					
					while(counterLesson<2){
					
						printf("1-%s(5 AKTS)\n2-%s(5 AKTS)\n3-%s(5 AKTS)\n4-%s(5 AKTS)\n",studentLesson1,studentLesson2,studentLesson3,studentLesson4);
						printf("Please select the LESSON you want to take(You can take 10 AKTS of courses in total!)[1-4]: ");
						scanf("%d",&lessonSelection);
						if(lessonSelection == 1){
							
							fprintf(fileStudentNoIncludeLesson,"%s ",studentLesson1);
							counterLesson++;
						
						}
						if(lessonSelection == 2){
							
							fprintf(fileStudentNoIncludeLesson,"%s ",studentLesson2);
							counterLesson++;
						
						}
						if(lessonSelection == 3){
							
							fprintf(fileStudentNoIncludeLesson,"%s ",studentLesson3);
							counterLesson++;
						
						}
						if(lessonSelection == 4){
							
							fprintf(fileStudentNoIncludeLesson,"%s ",studentLesson4);
							counterLesson++;
						
						}
						
					}
					printf("The lessons you have taken have been successfully saved to the system!");
				
				}
				break;			
			}
			else{
				printf("Your Password Is Wrong!");
				studentMenu();
				break;
			}				
		}		
	}
}

int main() {
	
	mainMenu();
	
	return 0;
}
