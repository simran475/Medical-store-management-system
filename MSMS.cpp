#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void add_medicine();
void display_medicine();
void search_medicine();
void purchase_sales_medicine();
void delete_medicine();
void update_medicine();
void exit();
main()
{

      char pass[30];
      int ch,i;
       system("cls");
     ABC:
       	 printf(" \n");
       	 printf("\t\t****************************************************\n");
         printf("\t\t ****welcome to medical store management system****\n");
         printf("\t\t****************************************************\n\n");
      printf("\n\n\t==================================\n");
         printf("\t||     ENTER YOUR PASSWORD:     ||\n");
          printf("\t==================================\n");
           i = 0;
    while ((pass[i] = getch()) != '\r') {
        printf("*");
        i++;
    }
         pass[i] = '\0';
         if(strcmp(pass,"123")==0)
{
	system("cls");
	printf("\n\n\n");
	printf("\t\t-==========================-\n ");
	printf("\t\t|......Password Match......|\n");
	printf("\t\t-==========================-");
	getch();
	XYZ:
	system("cls");	
	printf("\n\n\n");
	printf("\t\t ________________________________________\n");
	printf("\t\t|   |================================|   |\n");
	printf("\t\t|   |MEDICAL STORE MANAGEMENT  SYSTEM|   |\n");
	printf("\t\t|   |================================|   |\n");
	printf("\t\t|------------======MENU======------------|\n");
	printf("\t\t| 1. Add new medicine                    |\n");
	printf("\t\t| 2. Display all medicine                |\n");
	printf("\t\t| 3. Search medicine                     |\n");
	printf("\t\t| 4. Purchase/sales medicine             |\n");
	printf("\t\t| 5. Delete medicine record              |\n");
	printf("\t\t| 6. Update medicine                     |\n");	
	printf("\t\t| 7. Exit program                        |\n");	
	printf("\t\t|________________________________________|\n");
	printf("*ENTER YOUR CHOICE:  ");
	scanf("%d",&ch);
	system("cls");
	switch(ch)
	{
		case 1:
		{
			add_medicine();
			getch();
			goto XYZ;
			break;
		}
		case 2:
		{
			display_medicine();
			getch();
			goto XYZ;
			break;
		}
		case 3:
			{
				search_medicine();
		    	getch();
				goto XYZ;	
				break;
			}
			case 4:
				{
				purchase_sales_medicine();
				getch();
				goto XYZ;
				break;
				}
				case 5:
					{
						delete_medicine();
						getch();
						goto XYZ;
						break;
					}
					case 6:
						{
							update_medicine();
							getch();
							goto XYZ;
							break;
						}
						case 7:
							{
								exit();
								break;
							}
		default:
		                            	printf("\n\n\n");
    						        	printf("\t\t=========================================\n");
                                        printf("\t\t||              INVALID CHOICE!        ||\n");
                                        printf("\t\t||    Please select a valid option.    ||\n");
                                        printf("\t\t=========================================");
                                        printf("\n\t\tPress Enter to try again...");
                                        getch();
			goto XYZ;
	} 
	}
	
else
{
	system("cls");
	    printf("\n\n");
    printf("\t\t    ?????? WRONG PASSWORD ??????\n");
    printf("\t\t=====================================\n");
    printf("\t\t|                                   |\n");
    printf("\t\t|        ACCESS DENIED !!!          |\n");
    printf("\t\t|     TRY AGAIN TO ENTER SYSTEM     |\n");
    printf("\t\t=====================================\n");
    	getch();
	system("cls");
	goto ABC;	
}
}
void add_medicine()
{
	char name[30];
	int id, quantity,rack,check_id;
	float price;
	medicine_id:
	FILE*ptr;
	ptr=fopen("medi.txt","a+");
	system("cls");
	printf ("Enter id:");
	scanf("%d",&check_id);
while(fscanf(ptr,"%d%s%f%d%d",&id,name,&price,&quantity,&rack)!=EOF)
{
if (check_id==id)
{
	printf("\n\n");
	printf("\t>>>><><><><><><><><<<<\n");
	printf("\t >>Id already exist<<\n");
	printf("\t>>>><><><><><><><><<<<");
	getch();
	goto medicine_id;
}
}
id=check_id;
printf("Enter medicine name:");
scanf("%s",name);
printf("Enter price:");
scanf("%f",&price);
printf("Enter quantity:");
scanf("%d",&quantity);
printf("Enter rack number:");
scanf("%d",&rack);
fprintf(ptr,"\t%d\t%s\t%f\t%d\t%d\n",id,name,price,quantity,rack);
printf("\n\n");
printf("\t***********************************\n");
printf("\t *!!medicine added sucessfullly!!*\n");
printf("\t***********************************");
fclose(ptr);
getch();
}
void display_medicine()
{
	char name[30];
	int id,quantity,rack;
	float price;
	FILE *ptr;
	ptr=fopen("medi.txt","r");
	if (ptr==NULL)
	{
	printf("\t **file doesnot exist**\n");	  
	getch();
	return;
	}
	system("cls");
	printf("\t\t\t\t  __________________\n");
	printf("\t\t\t\t |AVILABLE MEDICINES|\n");
	printf("\t\t\t\t |==================|\n");
	printf(" _______________________________________________________________________________\n");
	printf("|Id      |Medicine name          |Price             |Quantity     |Rack         |\n");
	printf("|========|=======================|==================|=============|=============|\n");
	while(fscanf(ptr,"%d%s%f%d%d",&id,name,&price,&quantity,&rack)!=EOF)
	{
		printf("| %-6d | %-21s | %-16.2f | %-11d | %-11d |\n",id,name,price,quantity,rack);
	}
	printf("|________|_______________________|__________________|_____________|_____________|");
	fclose(ptr);
	getch();
 }
 
 void search_medicine()
 {
    int id,check_id,quantity,rack,test = 0;
    char name[30];
    float price;
    FILE*ptr;
    ptr = fopen("medi.txt","r");
    if(ptr==NULL)
	{
		printf("Medicine file doesnot exit\n");
		getch();
		return;
	}
    printf("\n Enter ID to search for medicine: ");
    scanf("%d", &check_id);
    while (fscanf(ptr,"%d%s%f%d%d",&id,name,&price,&quantity,&rack)!=EOF) 
	{
        if (check_id==id)
		 {
            system("cls");
            test=1;
            printf("\t\t ____________________________________________\n");
            printf("\t\t|              Medicine Details              |\n");
            printf("\t\t|============================================|\n");
            printf("\t\t|Name:%-20s                   |\n",name);
            printf("\t\t|Price:%-8.2f                              |\n",price);
            printf("\t\t|Quantity:%-6d                             |\n",quantity);
            printf("\t\t|Rack number:%-6d                          |\n",rack);
            printf("\t\t|============================================|");
        } 
    }
        fclose(ptr);

    if (test == 0)
	 {
        system("cls");
        printf("\t\t\t!!Medicine ID %d Does not exist!!\n",check_id);
    }
    getch();
 }
 
void purchase_sales_medicine()
{
    char name[30];
    int choice, test = 0, check_id, id, quantity, newquantity, rack;
    float price;
    FILE *ptr1, *ptr2;

    ptr1 = fopen("medi.txt", "r");
    if (ptr1 == NULL)
    {
        printf("Medicine file does not exist\n");
        getch();
        return;
    }

    ptr2 = fopen("newmedi.txt", "w");
    if (ptr2 == NULL)
    {
        printf("Unable to open temporary file.\n");
        fclose(ptr1);
        getch();
        return;
    }

    printf("Enter ID to Purchase/Sell medicine: ");
    scanf("%d", &check_id);
    system("cls");
    while (fscanf(ptr1, "%d%s%f%d%d", &id, name, &price, &quantity, &rack) != EOF)
    {
        if (check_id == id)
        {
            test = 1;
            printf("\nMedicine having id %d is found\n",check_id);
            printf(" ===================================================\n");
            printf("|Name:%-16s | Current Quantity:%-9d |\n", name, quantity);
            printf(" ===================================================\n");
            printf("1. Purchase\n2. Sell\nEnter your choice: ");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter quantity to purchase: ");
                scanf("%d", &newquantity);
                quantity += newquantity;
                printf("Purchased successfully!!\n");
            }
            else if (choice == 2)
            {
                printf("Enter quantity to sell: ");
                scanf("%d", &newquantity);
                if (newquantity <= quantity)
                {
                    quantity -= newquantity;
                    printf("Sold successfully!!\n");
                }
                else
                {
                    printf(">> Not enough stock to sell<<\n");
                }
            }
            else
            {
                printf(">> Invalid choice. No change made.\n");
            }
            fprintf(ptr2, "%d\t%s\t%.2f\t%d\t%d\n", id, name, price, quantity, rack);
        }
        else
        {
            fprintf(ptr2, "%d\t%s\t%.2f\t%d\t%d\n", id, name, price, quantity, rack);
        }
    }

    fclose(ptr1);
    fclose(ptr2);
    remove("medi.txt");
    rename("newmedi.txt", "medi.txt");

    if (test == 0)
    {
        printf("!! Medicine ID %d is not found !!\n", check_id);
    }

    getch();
}

void delete_medicine()
{
	int id,quantity,rack,check_id,test=0;
	char name[30];
	float price;
	FILE*ptr1,*ptr2;
	ptr1 = fopen("medi.txt","r");
	if(ptr1==NULL)
	{
		printf("Medicine file does not exit\n");
		getch();
		return;
	}
	ptr2 = fopen("newmedi.txt","w");
	printf("Enter id to delete medicine:");
	scanf("%d",&check_id);
	while(fscanf(ptr1,"%d%s%f%d%d",&id,name,&price,&quantity,&rack)!=EOF)
	{
		if(check_id!=id)
		{
			fprintf(ptr2,"%d\t%s\t%f\t%d\t%d\n",id,name,price,quantity,rack);
		}
		else
		{
			printf(">>Medicine deleted succesfully<<\n");
			test++;
			getch();
		}
	}
	fclose(ptr1);
	fclose(ptr2);
	remove("medi.txt");
	rename("newmedi.txt","medi.txt");
	if(test==0)
	{
		printf("medicine id %d is not  found",check_id);
	}
	getch();
}

void update_medicine()
{
    int id, quantity, edit_id, found = 0,rack;
    char name[30];
    float price;

    FILE *ptr1, *ptr2;
    ptr1 = fopen("medi.txt", "r");
    if (ptr1 == NULL)
    {
        printf("Medicine file does not exist.\n");
        getch();
        return;
    }

    ptr2 = fopen("newmedi.txt", "w");
    if (ptr2 == NULL)
    {
        printf("Unable to open temporary file.\n");
        fclose(ptr2);
        getch();
        return;
    }

    printf("Enter Medicine ID to edit: ");
    scanf("%d", &edit_id);

    while (fscanf(ptr1, "%d%s%f%d%d", &id, name, &price, &quantity, &rack) != EOF)
    {
        if (id == edit_id)
        {
            found = 1;
            printf("Record found. Enter new details for id %d\n\n",edit_id);
            printf("Enter new Medicine name: ");
            scanf("%s", name);
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            printf("Enter new price: ");
            scanf("%f", &price);
            printf("Enter new rack number:");
            scanf("%d", &rack);
            printf(">>Medicine record updated successfully<<\n");
        }
        fprintf(ptr2, "%d\t%s\t%f\t%d\t%d\n", id, name, price, quantity, rack);
    }

    fclose(ptr1);
    fclose(ptr2);
    
   	remove("medi.txt");
	rename("newmedi.txt","medi.txt");


    if (!found)
    {
        printf(">>Medicine ID not found<<\n");
    }
    getch();
}
   void exit()
   {
 printf("............................ !!!Program is Terminating!!!.......................");
    getch();
	}