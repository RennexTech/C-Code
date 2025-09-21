/*

Write a currency program, that tells you how many number of 100, 50, 20, 10, 5, 2 
and 1 Rs notes will be needed for a given amount of money. 
For example if the total amount is Rs 545 then five 100 Ksh notes, 
two 20 Ksh note and one 5 Ksh note will be needed. 
This sort of program can be used in ATM machines,

*/
#include <stdio.h>

int main()
{
	int amount = 0;

	int one_thousand_notes = 0;
	int five_hundred_notes = 0;
	int two_hundred_notes = 0;
	int one_hundred_notes = 0;
	int fifty_notes = 0;
	int twenty_coins = 0;
	int ten_coins = 0;
	int five_coins = 0;
	int one_coins = 0;

	int modulus_of_thousand_notes = 0;
	int modulus_of_500_notes = 0;
	int modulus_of_200_notes = 0;
	int modulus_of_100_notes = 0;
	int modulus_of_50_notes = 0;
	int modulus_of_20_coins = 0;
	int modulus_of_10_coins = 0;
	int modulus_of_5_coins = 0;
	int modulus_of_1_coins = 0;

	printf("Enter the amount you want to withdraw: ");
	scanf_s("%d", &amount);

	printf("===========================================\n");
	if (amount >= 1000)
	{
		one_thousand_notes = amount / 1000;
		modulus_of_thousand_notes = (amount % 1000);
		printf("The number of thousand notes you will receive are: %d\n", one_thousand_notes);
		printf("The remaining notes will be of lower value eg 500, 200, 100, 50, 20, 10, 5\n");
		printf("The remaining money is: %d\n", modulus_of_thousand_notes);
		if (modulus_of_thousand_notes == 0)
		{
			printf("That's all go get your money! Bye!");
		}
		printf("===========================================\n");

		else if (modulus_of_thousand_notes >= 500 && modulus_of_thousand_notes < 1000)
		{
			five_hundred_notes = modulus_of_thousand_notes / 500;
			modulus_of_500_notes = (modulus_of_thousand_notes % 500);
			printf("You will receive %d five hundred notes.\n", five_hundred_notes);
			printf("Your remaining money is %d\n", modulus_of_500_notes);
			if (modulus_of_500_notes == 0)
			{
				printf("That's all the notes you'll receive. Bye!\n");
			}
			printf("===========================================\n");

			else if (modulus_of_500_notes >= 200 && modulus_of_500_notes < 500)
			{
				two_hundred_notes = modulus_of_500_notes / 200;
				modulus_of_200_notes = modulus_of_500_notes % 200;
				printf("You will receive %d two hundred notes.\n", two_hundred_notes);
				printf("Your remaining money is %d\n", modulus_of_200_notes);
				if (modulus_of_200_notes == 0)
				{
					printf("That's all the money you'll receive.Bye!\n");
				}
				else if (modulus_of_200_notes >= 100 && modulus_of_500_notes < 200)
				{
					one_hundred_notes = modulus_of_200_notes / 100;
					modulus_of_200_notes = modulus_of_500_notes % 200;
					printf("You will receive %d one hundred notes.\n", one_hundred_notes);
					printf("Your remaining money is %d\n", modulus_of_100_notes);
					if (modulus_of_100_notes == 0)
					{
						printf("That's all the money you'll receive.Bye!\n");
					}

					printf("===========================================\n");


					else if (modulus_of_100_notes >= 50 && modulus_of_100_notes < 100)
					{
						fifty_notes = modulus_of_100_notes / 50;
						modulus_of_50_notes = modulus_of_100_notes % 50;
						printf("You will receive %d fifty shilling notes.\n", fifty_notes);
						printf("Your remaining money is %d\n", modulus_of_50_notes);
						if (modulus_of_50_notes == 0)
						{
							printf("That's all the money you'll receive.Bye!\n");
						}
						printf("===========================================\n");


						if (modulus_of_50_notes >= 20 && modulus_of_50_notes < 50)
						{
							twenty_coins = modulus_of_50_notes / 20;
							modulus_of_20_coins = modulus_of_50_notes % 20;
							printf("You will receive %d twenty shilling coins.\n", twenty_coins);
							printf("Your remaining money is %d\n", modulus_of_20_coins);
							if (modulus_of_20_coins == 0)
							{
								printf("That's all the money you'll receive.Bye!\n");
							}
							printf("===========================================\n");



							if (modulus_of_20_coins >= 10 && modulus_of_20_coins < 20)
							{
								ten_coins = modulus_of_20_coins / 10;
								modulus_of_10_coins = modulus_of_20_coins % 10;
								printf("You will receive %d ten shilling coins.\n", ten_coins);
								printf("Your remaining money is %d\n", modulus_of_10_coins);
								if (modulus_of_10_coins == 0)
								{
									printf("That's all the money you'll receive.Bye!\n");
								}
								printf("===========================================\n");


								if (modulus_of_10_coins >= 5 && modulus_of_10_coins < 10)
								{
									five_coins = modulus_of_10_coins / 5;
									modulus_of_5_coins = modulus_of_10_coins % 5;
									printf("You will receive %d five shilling coins.\n", five_coins);
									printf("Your remaining money is %d\n", modulus_of_5_coins);
									if (modulus_of_5_coins == 0)
									{
										printf("That's all the money you'll receive.Bye!\n");
									}
									
									printf("===========================================\n");

									if (modulus_of_5_coins >= 1 && modulus_of_10_coins < 5)
									{
										one_coins = modulus_of_5_coins / 1;
										modulus_of_1_coins = modulus_of_5_coins % 1;
										printf("You will receive %d one shilling coins.\n", one_coins);
										printf("Your remaining money is %d\n", modulus_of_1_coins);
										if (modulus_of_1_coins == 0)
										{
											printf("That's all the money you'll receive.Bye!\n");
										}
									}

									printf("===========================================\n");

								}
							}
						}
					}
				}
			}

			printf("===========================================\n");
		}	

	}

	return 0;
	

}

/* This program failed me, and I don't know how to correct it. It's just weird,
* that am writing too many C programs and failing to get them to run but 
* I still won't give up.
* 
* ChatGPT Version of this code:
* 
* 
*/

void money_counter1() {
    int amount, one_thousand_notes, five_hundred_notes, two_hundred_notes, one_hundred_notes, fifty_notes, twenty_coins, ten_coins, five_coins, one_coins;
    
    printf("Enter the amount you want to withdraw: ");
    scanf("%d", &amount);

    printf("===========================================\n");

    if (amount >= 1000) {
        one_thousand_notes = amount / 1000;
        amount %= 1000;
        printf("The number of thousand notes you will receive are: %d\n", one_thousand_notes);
    }

    if (amount >= 500) {
        five_hundred_notes = amount / 500;
        amount %= 500;
        printf("You will receive %d five hundred notes.\n", five_hundred_notes);
    }

    if (amount >= 200) {
        two_hundred_notes = amount / 200;
        amount %= 200;
        printf("You will receive %d two hundred notes.\n", two_hundred_notes);
    }

    if (amount >= 100) {
        one_hundred_notes = amount / 100;
        amount %= 100;
        printf("You will receive %d one hundred notes.\n", one_hundred_notes);
    }

    if (amount >= 50) {
        fifty_notes = amount / 50;
        amount %= 50;
        printf("You will receive %d fifty shilling notes.\n", fifty_notes);
    }

    if (amount >= 20) {
        twenty_coins = amount / 20;
        amount %= 20;
        printf("You will receive %d twenty shilling coins.\n", twenty_coins);
    }

    if (amount >= 10) {
        ten_coins = amount / 10;
        amount %= 10;
        printf("You will receive %d ten shilling coins.\n", ten_coins);
    }

    if (amount >= 5) {
        five_coins = amount / 5;
        amount %= 5;
        printf("You will receive %d five shilling coins.\n", five_coins);
    }

    if (amount >= 1) {
        one_coins = amount;
        printf("You will receive %d one shilling coins.\n", one_coins);
    }

    printf("That's all the money you'll receive. Bye!\n");
    printf("===========================================\n");

    return 0;
}



/*

A second version of chatgpt's code:


*/



void money_counter2() {
	int amount, denominations[] = {1000, 500, 200, 100, 50, 20, 10, 5, 1};

	printf("Enter the amount you want to withdraw: ");
	scanf("%d", &amount);

	printf("===========================================\n");

	for (int i = 0; i < 9; i++) {
		if (amount >= denominations[i]) {
			int count = amount / denominations[i];
			printf("You will receive %d %d Ksh %s.\n", count, denominations[i],
				denominations[i] >= 100 ? "notes" : "coins");
			amount %= denominations[i];
		}
	}

	printf("===========================================\n");
	return 0;
}









void money_counter 3()
{
	int amount;
	printf("Enter the amount you want to withdraw: ");
	scanf_s("%d", &amount);

	int denominations[] = {1000, 500, 200, 100, 50, 20, 10, 5, 1};
	int notes_coins[9] = {0};  // To store the count of each denomination

	printf("===========================================\n");

	for (int i = 0; i < 9; i++) {
		if (amount >= denominations[i]) {
			notes_coins[i] = amount / denominations[i];
			amount %= denominations[i];
		}
	}

	for (int i = 0; i < 9; i++) {
		if (notes_coins[i] > 0) {
			if (denominations[i] >= 100) {
				printf("You will receive %d %d Ksh notes.\n", notes_coins[i], denominations[i]);
			} else {
				printf("You will receive %d %d Ksh coins.\n", notes_coins[i], denominations[i]);
			}
		}
	}

	printf("===========================================\n");

	return 0;
}






//another version

void money_counter()
{
	int n, choice, notes;
	printf("Enter the total amount in Ksh: ");
	scanf("%d", &n);
	printf("Enter the value of note from which you want to begin: ");
	scanf_s("%d", choice);

	switch (choice)
	{
	default:
		printf("Enter only a valid number.\n");
		case 100:
			notes = n / 100;
			printf("Number of 100 KSh notes = %d\n", notes);
			n = n % 100;
		case 50:
			notes = n / 50;
			printf("Number of 50 KSh notes = %d\n", notes);
			n = n % 50;
		case 20:
			notes = n / 20;
			printf("Number of 20 KSh notes = %d\n", notes);
			n = n % 20;
		case 10:
			notes = n / 10;
			printf("Number of 100 KSh notes = %d\n", notes);
			n = n % 10;
		case 5:
			notes = n / 5;
			printf("Number of 5 KSh notes = %d\n", notes);
			n = n % 5;
		case 2:
			notes = n / 2;
			printf("Number of 2 KSh notes = %d\n", notes);
			n = n % 2;
		case 1:
			notes = n / 1;
			printf("Number of 1 KSh notes = %d\n", notes);
			
			

	}
}















































