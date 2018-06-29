#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define NUM_CARDS 5

bool straight, flush, four, three, royalFlush;
int pairs;

void read_cards(char[][2]);
void analyze_hand(char[][2]);
void print_result(void);
int selection_sort(char[][2], int);

int main(void)
{
	char hand[NUM_CARDS][2] = {0};
	
	for (;;)
	{
		read_cards(hand);
		analyze_hand(hand);
		print_result();
	}
}

void read_cards(char hand[][2])
{
	char ch;
	bool bad_card, duplicate_card;
	short i, x;
	
/*	for (rank = 0; rank < NUM_RANKS; rank++)
	{
		num_in_rank[rank] = 0;
		for (suit = 0; suit < NUM_SUITS; suit++)
		{
			card_exists[rank][suit] = false;
		}
	}											//Don't think I need this section anymore. It zero's out the num_in_rank, card_exists, & num_in_suit arrays
	
	for (suit = 0; suit < NUM_SUITS; suit++)
		num_in_suit[suit] = 0;*/
	
	for (i = 0;i < NUM_CARDS;)
	{
		bad_card = false;
		
		printf("Enter a card: ");
		
		hand[i][0] = getchar();
		
		switch (hand[i][0])
		{
			case '0': exit(EXIT_SUCCESS);
			case '2': hand[i][0] = 1; break;
			case '3': hand[i][0] = 2; break;
			case '4': hand[i][0] = 3; break;
			case '5': hand[i][0] = 4; break;
			case '6': hand[i][0] = 5; break;
			case '7': hand[i][0] = 6; break;
			case '8': hand[i][0] = 7; break;
			case '9': hand[i][0] = 8; break;
			case 't': case 'T': hand[i][0] = 9; break;
			case 'j': case 'J': hand[i][0] = 10; break;
			case 'q': case 'Q': hand[i][0] = 11; break;
			case 'k': case 'K': hand[i][0] = 12; break;
			case 'a': case 'A': hand[i][0] = 13; break;
			default: bad_card = true;
		}
	
		hand[i][1] = getchar();
		switch (hand[i][1])
		{
			case 'c': case 'C': hand[i][1] = 0; break;
			case 'd': case 'D': hand[i][1] = 1; break;
			case 'h': case 'H': hand[i][1] = 2; break;
			case 's': case 'S': hand[i][1] = 3; break;
			default: bad_card = true;
		}
		
		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_card = true;
		
		for(x = 0; x < i; x++)
		{
			if(hand[x][0] == hand[i][0] && hand[x][1] == hand[i][1])
			{
				duplicate_card = true;
			}
		}
		
		if (bad_card)
		{
			printf("Bad card; ignored.\n");
		}
		else if(duplicate_card)
		{
			printf("Duplicate card; ignored.\n");
		}
		else
		{
			i++;
		}
	}
}

void analyze_hand(char hand[][2])
{
	short i, same;
	char temp = 0;
	royalFlush = false; 
	straight = false;
	flush = true;
	four = false;
	three = false;
	pairs = 0;
	
	selection_sort(hand, NUM_CARDS);
	
	for(i = 1; i < NUM_CARDS; i++)				//flush
	{
		if(hand[i-1][1] != hand[i][1])
		{
			flush = false;
			break;
		}
	}
	
	i = 0;
	while(i < (NUM_CARDS * 2))				//straight
	{
		same = 0;
		do
		{
			same++;
			i++;
		} while (((hand[(i-1) % NUM_CARDS][0] + 1) % 13) == ((hand[i % NUM_CARDS][0]) % 13));
			
		if(same == NUM_CARDS)
		{
			straight = true;
			break;
		}
	}
	
	if(flush && straight && (hand[0][0] == 9))		//royal flush
	{
		royalFlush = true;
	}
	
	i = 0;
	while (i < NUM_CARDS)						//pairs, three of a kind, four of a kind
	{
		temp = hand[i][0];
		same = 0;
		do 
		{
			same++;
			i++;
		} while (i < NUM_CARDS && hand[i][0] == temp);
		
		switch (same)
		{
			case 2: pairs++; break;
			case 3: three = true; break;
			case 4: four = true; break;
		}
	}
}

int selection_sort(char hand[][2], int n)
{
	char temp_rank = 0, temp_suit = 0;
	short i = 0;
	
	if(n <= 0)
	{
		return(0);										//ends the recursion
	}
	else
	{
		for(i = 0;i < n - 1;i++)						//searches the array and sets the largest number as x[n]
		{
			if(hand[i][0] > hand[i+1][0])
			{
				temp_rank = hand[i+1][0];				//Swaps i+1 with i if i is larger than i+1
				temp_suit = hand[i+1][1];
				hand[i+1][0] = hand[i][0];
				hand[i+1][1] = hand[i][1];
				hand[i][0] = temp_rank;
				hand[i][1] = temp_suit;
			}
		}
		selection_sort(hand,n - 1);						//calls the array again to continue sorting
	}
}

void print_result(void)
{
	if (royalFlush) printf("Royal Flush");
	else if (straight && flush) printf("Straight flush");
	else if (four) printf("Four of a kind");
	else if (three && pairs == 1) printf("Full house");
	else if (flush) printf("Flush");
	else if (straight) printf("Straight");
	else if (three) printf("Three of a kind");
	else if (pairs == 2) printf("Two pairs");
	else if (pairs == 1) printf("Pair");
	else printf("High card");
	
	printf("\n\n");
}
