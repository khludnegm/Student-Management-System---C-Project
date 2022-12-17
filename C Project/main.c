#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Student
{
    int ID;
	int phone;
    char name[100];
    char address[100];
    int score;
	int day;
	int month;
	int year;
    struct Student *next;
    
}* head;
struct Student * current = NULL;
void swap(struct Student* a,struct Student* b);

void insert()
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    
	
	
	printf("please enter the Student Name\n");
	fflush(stdin);
    fgets(student->name, 100, stdin);
	
	
	printf("please enter the Student ID\n");
    scanf("%d",&(student->ID));
    fflush(stdin);
	
	printf("please enter the Student phone\n");
    scanf("%d",&(student->phone));
    fflush(stdin);
	
	printf("please enter the Student Address\n");
    fgets(student->address, 100, stdin);
    fflush(stdin);
	
	printf("please enter the Student Birdthdate \n");
	scanf("%d %d %d",&(student->day),&(student->month),&(student->year));
    fflush(stdin);
	
	printf("please enter the Student Score\n");
    scanf("%d",&(student->score));
	while(0>(student->score)||(student->score)>100)
	{
		printf("out of range\n");
		scanf("%d",&(student->score));
	}
    fflush(stdin);
	
	
	
    student->next = NULL;
    
    if(head==NULL){
        
        head = student;
    }
    else{
        
        student->next = head;
        head = student;
    }
    
}
void display()
{
    struct Student * temp = head;
    if(temp!=NULL)
	{
		while(temp!=NULL){
       
			printf("----------------------------------------------------\n");
			printf(" Name    : %s",temp->name);
			printf(" ID      : %d\n",temp->ID);  
			printf(" Address : %s",temp->address);
			printf(" Phone : %d\n",temp->phone);
			printf(" Birthdate : %d - %d - %d\n",temp->day,temp->month,temp->year);
			printf(" CS Score  : %d\n",temp->score);
			printf("----------------------------------------------------\n");
			temp = temp->next;
     
        }
	}
	else
	{
		printf("-------------------------------------\n");
		printf("             Empty list              \n");
		printf("-------------------------------------\n");
		
	}
}
void delete()
{
	int ID;
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    if(temp1!=NULL){
		
		while(temp1!=NULL)
		{
			printf("please enter ID of student you want to delete : ");
			scanf("%d",&ID);
			
        
			if(temp1->ID==ID){
            
				printf("Student with ID %d Found !!!\n", ID);
            
				if(temp1==temp2){
                
					head = head->next;
					free(temp1);
				}
				else{
                
                temp2->next = temp1->next;
                free(temp1); 
				}
            
				printf("Student Successfully Deleted !!!\n");
				return;

			}
			else
			{
				printf("Student with ID : %d is not found !!!\n", ID);
			}
			temp2 = temp1;
			temp1 = temp1->next;
		}
		
		
        
    }
	else if (temp1 == NULL)
	{
		printf("-------------------------------------\n");
		printf("             Empty list              \n");
		printf("-------------------------------------\n");
	}
	
    
    
}
void update()
{
    int ID;
    struct Student * temp = head;
    if(temp!=NULL){
		while(temp!=NULL)
		{
			printf("please enter ID of student you want to update : ");
			scanf("%d",&ID);
        
			if(temp->ID==ID)
			{
				printf("Student with ID : %d Found !!!\n", ID);
				printf("Enter new Name: ");
				scanf("%s", &(temp->name));
				printf("Enter new Phone number: ");
				scanf("%d", &(temp->phone));
				printf("Enter new Address: ");
				scanf("%s", &(temp->address));
				printf("Enter new Birthdate: ");
				scanf("%d %d %d",&(temp->day),&(temp->month),&(temp->year));
				printf("Enter new Score: ");
				scanf("%d",&(temp->score));
				while(0>(temp->score)||(temp->score)>100)
				{
					printf("out of range\n");
					scanf("%d",&(temp->score));
				}
				printf("Updation Successful!!!\n");
				return;
			}
			else
			{
				printf("Student with  ID : %d is not found !!!\n", ID);
			}
			temp = temp->next;
		}
		
        
    }
	else if(temp == NULL)
	{
		printf("-------------------------------------\n");
		printf("             Empty list              \n");
		printf("-------------------------------------\n");
	}
	
    
}
void update_score()
{
    int ID;
    struct Student * temp = head;
    if(temp!=NULL){
		
		while(temp!=NULL)
		{
			printf("please enter ID of student you want to update : ");
			scanf("%d",&ID);
        
			if(temp->ID==ID){
			printf("Enter new Score: ");
			scanf("%d",&(temp->score));
			
			while(0>(temp->score)||(temp->score)>100)
			{
				printf("out of range\n");
				scanf("%d",&(temp->score));
			}
            printf("Updation Successful!!!\n");
            return;
        }
		else
		{
			printf("Student with  ID : %d is not found !!!\n", ID);
		}
        temp = temp->next;
		}
		
        
    }
	else if(temp == NULL)
	{
		printf("-------------------------------------\n");
		printf("             Empty list              \n");
		printf("-------------------------------------\n");
	}
	
    
}
void rank_students()
{
	int swapped, i;
    struct Student * lptr = NULL;
	

    
    if (head == NULL)
    {
        printf("-------------------------------------\n");
		printf("             Empty list              \n");
		printf("-------------------------------------\n");
        
    }
    do {
        swapped = 0;
        current = head;
        while (current->next != lptr)
        {
            if (current->score < current->next->score)
            {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        lptr = current;
    } while (swapped);

    printf("-------------------------------------\n");
	printf("            Students Ranked          \n");
	printf("-------------------------------------\n");
	
	
}
void swap(struct Student* a,struct Student* b)
{
    struct Student* temp = (struct Student*)malloc(sizeof(struct Student));

    
    strcpy(temp->address, a->address);
    strcpy(a->address, b->address);
    strcpy(b->address, temp->address);

    
    strcpy(temp->name, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, temp->name);

    
    temp->phone, a->phone;
    a->phone, b->phone;
    b->phone, temp->phone;

    
    temp->score = a->score;
    a->score = b->score;
    b->score = temp->score;

    
    temp->day = a->day;
    a->day = b->day;
    b->day = temp->day;

    
    temp->month = a->month;
    a->month = b->month;
    b->month = temp->month;

    
    temp->year = a->year;
    a->year = b->year;
    b->year = temp->year;

    
    temp->ID = a->ID;
    a->ID = b->ID;
    b->ID = temp->ID;

    free(temp);
}
int main(void)
{
    int program=1;
    while (program ==1)
    {
        int choose;
        printf("===================================================\n");
        printf("             Welcome to ITI School\n");
        printf("               Khlud Ashraf Negm \n");
        printf("===================================================\n");
        printf("To add a new Student                      Enter '1'\n");
        printf("To view all Students                      Enter '2'\n");
        printf("To Delete a Student                       Enter '3'\n");
        printf("To Update Student data                    Enter '4'\n");
        printf("To Edit Student Score                     Enter '5'\n");
        printf("To Rank Student                           Enter '6'\n");
        printf("To Exit                                   Enter '7'\n");
        printf("===================================================\n");
		
        scanf("%d",&choose);

        switch (choose)
        {
        case 1:
            insert();
            break;
        
        case 2:
          
            display();
            break;

        case 3:
       
			
			delete();
            break;

        case 4:
       
			
			update();
            break;

        case 5:
        
			
			update_score();
            break;


        case 6:
            
			rank_students();
            break;
        case 7:
        
            program = 0;
            break;

        default:
            printf("Invalide choice\n");
            break;
        }
    }

	return 0;
}