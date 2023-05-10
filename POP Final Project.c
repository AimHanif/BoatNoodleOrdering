#include<stdio.h>//usage of basic function ( printf, scanf, etc)
#include<math.h>
#include<stdbool.h>//usage of temp (boolean)
#include<ctype.h>//usage of isalnum, isalpha
#include<string.h>//uses of strcpy
#include<time.h>//uses of time_t
#include<stdlib.h>//usage of system("cls")
int validation(const char[],int,int,const char[]);//a variable that stores ("string", integers, integers, "string") and will validate the value to be exactly the range that has been set up. DETAILED EXPLANATION : the 2 integers in the validation variable is the range, for example " positive numbers ", 1, 9, "enter positive number". the first string will be just a diplay function. then we move to the range of 'psotive number which is 1 to 9. Then, the last string will be a display function and also receive input from users.'
void pay(float []);
void receipt(float, float);
void askQuantity();
void summary(int,int,int);
void ranking(int,int,int);
bool temp;
char display[6][20]={"0","Ala Carte","Set","Aroi Drinks","Thai Boat Noodles","Overall"},menu[34][50]={"0","Sweet Treats","Kra Pow Chicken Rice","Pad Thai","Kaw Pad Super","Ayam Legend",
"Thai Fried Chicken","Crunchy Popeye's' Tempura","Grilled Chicken Meatballs","Pandan Wings","Grilled Beef Meatballs","Yum Mama","The Royal Takeout 1","The Royal Takeout 2",
"Crunchy Jumbo Thai Omelette Chicken","Crunchy Jumbo Thai Omelette Prawn","The Royal Bowls A","The Royal Bowls B","Cha Yen", "Kaffe Yen", "Cha Keow Yen", "Cha Manao Yen", 
"Terer Taro", "Mango Smoothie", "Blue Butterfly", "Fresh Thai Coconut", "Hot Kaffe", "Chill Chill Water","Pathumthani (with Meat)","Pathumthani (with Chicken)",
"Ayutthaya (with Meat)","Ayutthaya (with Chicken)","Fried Chicken Skins","Fried Wanton Skins"},tempString[100];
float price[34] = {0,8.50,15.80,16.20,16.20,15.80,15.80,8.20,5.20,13.90,7.90,11.90,10.00,18.00,17.20,17.20,36.90,70.90,9.50,9.50,9.50,9.50,9.50,6.00,6.00,10.50,9.20,3.50,2.80,
2.20,2.80,2.20,2.20,2.20},sales[34]={0.0},serviceCharge,serviceTax,total,totalSales=0,balance,finalPrice[100],orderPrice[100];;
int countOrder[34]={0},ord,loopOrder,quantity[100]={0}, bill_no=1, table, pax, opt, choice=0,option=0,temporary,sale,i,ind,totalQuantity[5]={0,0,0,0,0},overallQuantity;
char * order[100];
int main()
{
	do//untuk end if xde next user
	{
    	if (opt==1)//(WILL BE USED AFTER NEXT USER = 1)
		{
			system("cls");//WIll clear the screen that contains the previous user's activity
		}
		ord=0, loopOrder=0, quantity[ord]=0,sale=0;
		float totalPrice[5] = {0,0,0,0,0};
		printf("\t\n-------------------------------------------");
		puts("\n\tWelcome to Boat Noodle");//Greetings to the customers
		printf("\t\n-------------------------------------------");
	    temporary = validation("\nPurchase Method : [1] - Dine-In [2] - Takeaway: ",1,2, "Please enter input range from 1 to 2.");//how the customer wants to be served
		if(temporary==1)
	    {
	    	table = validation("\nSelect table range from 1 to 20 : ",1,20, "Please enter table range from 1 to 20.");//Help the allocation of the customer within 20 tables
	    }
		pax = validation("\nSelect pax range from 1 to 50: ",1,50, "Please enter table range from 1 to 50.");//Determine how many diners are there
		printf("\nPlease select from the variety of our menu~");//display instruction to menu variation
		do
		{
			printf("\n[1] - %s\n[2] - %s\n[3] - %s\n[4] - %s\n",display[1],display[2],display[3],display[4]);
			opt = validation("\nSelect an option : ",1,4, "Please enter choice range from 1 to 4.");// display menu variation (alacarte, set, drinks, boat noodle)
			char addon[4][20]={"0"," + Sangkayaa Dip"," + Plain Rice"," + Fried Egg"};
			float addonPrice[4] = {0,3.90,2.20,2.20};
			do
			{
		  		puts("\n________________________________________________________________");
		  		printf("|These are the available option(s) for %-23s |",display[opt]);
		  		if(opt==1)
				{
					for(int choice = 1; choice<12; ++choice) //ni if user pilih 1 - alacarte
		  			{
		  				printf("\n|[%d]\t %-36s - RM%12.2f |", choice, menu[choice],price[choice]);//display menu for alacarte
		  			}
		  			puts("\n|______________________________________________________________|");
		  			choice = validation("\nPlease select Ala Carte from range 1 to 11: ",1,11, "Please enter choice range from 1 to 11.");//user input
				}else if(opt==2)
				{
					for(int choice = 12; choice<18; ++choice) //ni if user pilih 2 - set
					{
						printf("\n|[%d]\t %-36s - RM%12.2f |", choice, menu[choice],price[choice]);//display menu for set
					}
					puts("\n|______________________________________________________________|");
					choice = validation("\nPlease select Set from range 12 to 17: ",12,17, "Please enter choice range from 12 to 17.");//user input
				}else if(opt==3)
				{
					for(int choice = 18; choice<28; ++choice)//ni if user pilih 3 - drinks
					{
						printf("\n|[%d]\t %-36s - RM%12.2f |", choice, menu[choice],price[choice]);//display menu for drinks
					}
					puts("\n|______________________________________________________________|");
					choice = validation("\nPlease select Aroi Drinks from range 18 to 27: ",18,27, "Please enter choice range from 18 to 27.");//user input
				}else if(opt==4)
				{
					for(int choice = 28; choice<34; ++choice)//ni if user pilih 4 - boat noodle
					{
						printf("\n|[%d]\t %-36s - RM%12.2f |", choice, menu[choice],price[choice]);//display menu for boat noodle
					}
					puts("\n|______________________________________________________________|");
					choice = validation("\nPlease select Thai Boat Noodles from range 28 to 33: ",28,33, "Please enter choice range from 28 to 33.");//user input
				}
				loopOrder++;
				ord++;
				order[ord]=menu[choice];
				orderPrice[ord]=price[choice];
				if(choice==1)//only triggered if ONLY user pilih certain menu dalam ALACARTE
				{
					order[ord]=menu[choice];
					//printf("\nDo you want to have add-ons? : \n");
					option = validation("\nDo you want to have add-ons? 1 for Yes, 2 for No. Select an option: ",1,2, "Please enter choice range from 1 to 2.");
					if(option==1)//alacarte menu 1
					{
						printf("\n_____________________________________________________");
						printf("\n|[1]%-30s - RM%8.2f      |",addon[1],addonPrice[1]);
						printf("\n|____________________________________________________|\n");
						printf("\nRM%.2f + RM%.2f",price[choice],addonPrice[1]);
						price[choice]+=addonPrice[1];//sangk
					}
				}else if(choice>1 && choice<5)//alacarte menu 2 sampai 4
				{
					//printf("\nWant to have add-ons? : \n");
					option = validation("\nWant to have add-ons? 1 for Yes, 2 for No. Select an option : ",1,2, "Please enter choice range from 1 to 2.");
					if(option==1)
					{
						printf("\n_____________________________________________________");
						printf("\n|[1]%-30s - RM%8.2f      |",addon[2],addonPrice[2]);
						printf("\n|[2]%-30s - RM%8.2f      |",addon[3],addonPrice[3]);
						printf("\n|____________________________________________________|\n");
						opt = validation("\n1 for Plain Rice, 2 for Fried Egg. Select an option : ",1,2, "Please enter choice range from 1 to 2.");
						if(option==1)
						{
							printf("\nRM%.2f + RM%.2f",price[choice],addonPrice[2]);//plain rice
							price[choice]+=addonPrice[2];
						}else
						{
							printf("\nRM%.2f + RM%.2f",price[choice],addonPrice[3]);//fried egg
							price[choice]+=addonPrice[3];
						}
					}
	    		}
				askQuantity();//masuk function ask quantity
				countOrder[choice]+=quantity[ord];
				sales[choice]+=price[choice]*quantity[ord];
				printf("\nPrice for each (%s) - RM%.2f\n", order[ord],price[choice]);//display price for each food
				totalPrice[opt]+=price[choice]*quantity[ord];
				printf("\nCurrent total : RM%.2f\n",totalPrice[opt]);//display current amount that need to be paid
				printf("\nDo you want to add anymore %s\n",display[opt]);
				option = validation("\n1 for Yes, 2 for No : ",1,2, "Please enter choice range from 1 to 2.");
	    		system("cls");
			}while(option==1);
			sale++;
			//printf("\nDo you want to add anymore order?\n");
			opt = validation("\nDo you want to add anymore order? 1 for Yes, 2 for No : ",1,2, "Please enter choice range from 1 to 2.");//tanye if nak order lagi x. IF yes then akan repeat,kalau x dia keluar.
	    	system("cls");
		}while(opt==1);
		finalPrice[sale]=totalPrice[1]+totalPrice[2]+totalPrice[3]+totalPrice[4];
	    printf("\n______________________________\n");
	    printf("Total price       : RM %.2f",finalPrice[sale]);//display total price
		pay(finalPrice);//function untuk calculation and bayar
		receipt(serviceCharge, serviceTax);//function untuk print receipt
		totalSales+=total;
		opt = validation("\nNext user? 1 for Yes, 2 for No : ",1,2, "Please enter choice range from 1 to 2.");//tanye if nak next user ke x. If yes then akan tukar jadi user baru, kalau x akan keluar to end the system
	}while(opt==1);
	printf("\n**************************************************");
  	printf("\n Total Sales Of The Day: RM%-8.2f              ",totalSales);//display total sales of the day
    printf("\n**************************************************");
	summary(1,1,12);//summary for alacarte
	summary(2,12,18);//summary for set
	summary(3,18,28);//summary for drink
	summary(4,28,34);//summary for boat noodle
  	printf("\n_________________________________________________________");//display quantity sold for each category and overall
	printf("\n Quantity sold for %-30s : %-3d  |",display[1],totalQuantity[1]);
	printf("\n Quantity sold for %-30s : %-3d  |",display[2],totalQuantity[2]);
	printf("\n Quantity sold for %-30s : %-3d  |",display[3],totalQuantity[3]);
    printf("\n Quantity sold for %-30s : %-3d  |",display[4],totalQuantity[4]);
    overallQuantity=totalQuantity[1]+totalQuantity[2]+totalQuantity[3]+totalQuantity[4];
    printf("\n Quantity sold for %-30s : %-3d  |",display[5],overallQuantity);
  	printf("\n_________________________________________________________\n");
	ranking(1,1,12);//ranking function and masukkan value tu untuk ( index , minimum(least) , maximum (most)) + ranking for alacarte
	ranking(2,12,18);//ranking set
	ranking(3,18,28);//ranking drinks
	ranking(4,28,34);//ranking boat noodle
	ranking(5,1,34);//ranking overall
	return 0;
}

int validation(const char quest[],int min, int max, const char warn[])
{
	do
	{
	    printf("%s",quest);
	    temp = scanf("%d",&option);
	    fflush(stdin);
	    if(temp != 1 || option<min || option>max)
	    {
	    	if(temp != 1)
	      	{
	        	printf("Sorry, your choice is non-number. %s\n",warn);
	      	}
	      	else if (option<min || option>max)
	      	{
	        	printf("Sorry, your choice is invalid. %s\n",warn);
	      	}
	    }
	}while(temp !=1|| option<min || option>max);
	return option;
}

void pay(float finalPrice[sale])
{
	float amount, balance;
	do
	{ 
	    serviceCharge=finalPrice[sale]*0.1;
	    serviceTax=finalPrice[sale]*0.06;
	    total=finalPrice[sale]+serviceCharge+serviceTax;
    	printf("\n______________________________\n");
    	printf("\nService Charges   : RM %.2f",serviceCharge);
    	printf("\nService Taxes     : RM %.2f",serviceTax);
		printf("\nYou have to pay   : RM %.2f",total);
		printf("\nEnter your amount : RM ");
		temp = scanf("%f",&amount);
		fflush(stdin);
		if(temp!=1 || amount<total || amount<0)
		{
		    if(temp!=1)
		    {
		        printf("\nNon-number amount. Please enter RM%.2f or more.\n",total);
		    }
	      	else if (amount<total)
	      	{
	        	printf("\nInsufficient amount. Please enter RM%.2f or more.\n",total);
	      	}
	      	else if (amount<0)
	      	{
	      		printf("\nNegative amount. Please enter RM%.2f or more.\n",total);
			}
		}
	}while(temp != 1 || amount<total || amount<0);
	if(amount>=total)
    {
       balance=amount-total;
        printf("\n______________________________");
        printf("\nThe balance is    : RM %.2f",balance);
        printf("\n______________________________");
    }
}
void askQuantity()
{
	do
  	{	
		printf("\nEnter quantity(Food + Addons): ");
	  	temp = scanf("%d",&quantity[ord]);
	  	fflush(stdin);
	  	if(temp != 1 || quantity[ord]<0)
	  	{
	    	if(temp != 1)
	    	{
	      		puts("\nSorry, your quantity is non-number. Please re-enter.");
	    	}else if(quantity[ord]<0)
	    	{
	    		puts("\nSorry, your quantity is negative. Please re-enter.");
			}
		}
	}while(temp != 1 || quantity[ord]<0);
}

void receipt(float serviceCharge, float serviceTax)
{
  	printf("\n_____________________________________________________________\n");
	printf("\n                        Boat Noodle\n");
	printf("                    Aeon Bandaraya Melaka,\n");
	printf("                       7540 Malacca City\n");
    printf("                            Tel :\n");
    printf("                     Boat Noodle Sdn Bhd\n");
    printf("                         (1102985-D)\n");
    printf("                     W10-1808-31008809\n");
    printf("\n");
    printf("************************** Receipt **************************\n");
    printf("-------------------------------------------------------------\n");
    printf("Table: %d                                              PAX: %d\n",table,pax);
    printf("\nBill No: %d-043169\n",rand());
    time_t t;       
    time(&t);
    t = time(NULL);
    struct tm tm = *localtime(&t);
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
	printf("Date: %d/%d/%d  %02d:%02d:%02d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900,current_time->tm_hour,current_time->tm_min,current_time->tm_sec);
    printf("\n------------------------------------------------------------\n");
    // senarai makanan yang dibeli  |  quantity  |  harga
    for(ord=1;ord<=loopOrder;++ord)
		{
			printf("%-3d. %-35s %8d RM%8.2f\n",ord, order[ord],quantity[ord],orderPrice[ord]);
		} 
    printf("-------------------------------------------------------------\n");
    // tarik variable finalPrice dekat calculate price
    printf("                                       Sub Total  RM %-5.2f \n",finalPrice[sale]);
    printf("                            Service Charge (10%%)  RM %-5.2f \n",serviceCharge);
    printf("                                (6%%) Service Tax  RM %-5.2f \n",serviceTax);
    printf("                                                  ------------\n");
    total=finalPrice[sale]+serviceCharge+serviceTax;
    printf("                                           Total  RM %-5.2f \n",total);
    printf("\n");
    printf("-------------------------------------------------------------\n");
    printf("                            Thank You              \n");
    printf("                        Please Come Again          \n");	
    printf("\n_____________________________________________________________\n");
}

void summary(int ind, int min, int max)
{
	//summary for each category
  	printf("\n_________________________________________________________");
	printf("\n Summary for %-17s                           |",display[ind]);
  	printf("\n_________________________________________________________\n");
  	i=1;
	for(ord=min;ord<max;++ord)
	{
		printf(" %-2d. %-36s |%-3d RM%-8.2f|\n",i, menu[ord],countOrder[ord],sales[ord]);
		totalQuantity[ind]+=countOrder[ord];
    	i++;
	}
	printf("________________________________________________________\n");
}
void ranking(int ind,int min,int max)//ranking function and bawak value tu untuk ( index , minimum(least) , maximum (most))
{
	printf("\n Menu Ranking For %-30s",display[ind]);
	for(int outer=min;outer<max;outer++)
	{
    	for(int inner=outer+1;inner<max;inner++)
    	{
			if(countOrder[inner]>countOrder[outer])
		    {
		    	strcpy(tempString,menu[inner]);
		        strcpy(menu[inner],menu[outer]);
		        strcpy(menu[outer],tempString);
		        temporary=countOrder[inner];
		        countOrder[inner]=countOrder[outer];
		        countOrder[outer]=temporary;
		    }
	  	}
	}
 	printf("\n------------------------------------------------\n");
 	i=1;
	for(ord=min;ord<max;ord++)
	{
		printf("|%-2d. %-36s : %-3d |\n",i, menu[ord],countOrder[ord]);
		i++;
	}
  	printf("------------------------------------------------\n");
}