#include <stdio.h>
#include <stdlib.h>
//Function signatures
void print_state(int state_to_print[], int state_length);
void initialize_array(int array_to_initialize[], int state_length);
void swap_arrays(int current_state[], int next_state[], int array_length);
void search_the_state(int look_up[][2], int *new_state, int state_indice);
void calculate_next_state(int current_state[], int next_state[], int lookup_table[][2]);
//Definitions
const int MAX_STATE_COUNT = 8;
const int GENERATION_COUNT = 50;
const int ARRAY_LENGTH = 100;
#define null_char '_'
#define full_char '#'
/*Main function - We fill the array in main function as a static instantiation or you can take these values from the user. 
Take the array size as 100 (for both current & next state arrays) and generation count as 50.
*/

int main()
{
	//Getting the middle point in the array
	int middle_point = ARRAY_LENGTH / 2 - 1;
	//We need two arrays for so we don't override any of the current states
	int current_state[100], next_state[100];
	//Initialization of the lookup table for rule 30
	int rule_lookup[8][2] = { {0, 0}, {1, 1}, {10, 1}, {11, 1}, {100, 1}, {101, 0}, {110, 0}, {111, 0} };
	//Initialize the current & next arrays as full zeros
	initialize_array(current_state, ARRAY_LENGTH);
	initialize_array(next_state, ARRAY_LENGTH);
	int counter,state_length,inner_counter;
	int state_point,state_indice;
	int left,right,middle;
	current_state[middle_point]=1;
	//Outer loop that'll create 50 rows for 50 generations
	for(counter=0;counter<GENERATION_COUNT;counter++) {
		//First inner loop that'll calculate each row
		for(state_point=1;ARRAY_LENGTH>state_point;state_point++) { 
			left=current_state[state_point-1];
			middle=current_state[state_point];
			right=current_state[state_point+1];
			state_indice=(left*100)+(middle*10)+right;
			search_the_state(rule_lookup, &next_state[state_point], state_indice);
		}
		print_state(current_state,ARRAY_LENGTH);
		swap_arrays(current_state,next_state,ARRAY_LENGTH);
	}
	return(0);
}
	
	


void search_the_state(int look_up[][2], int* new_state, int state_indice)
{
	//State indice is the parameter that is being searched in the look up table
	//Ex: 101 (you can use an integer in here no need to work with binaries) is being searched
	//on the lookup table and it corresponds to 5th indice of the 2nd column (state 1)
	//will search the current neighborhood from the look up matrix and return the
	//next state value from the pointer parameter new_state
	int lookup_iterator;
	for (lookup_iterator = 0; lookup_iterator < MAX_STATE_COUNT; lookup_iterator++)
	{
		if (state_indice == look_up[lookup_iterator][0])
		{
			//That means the state that consists of the current neighborhoud
			//is found on the lookup table get the next state information for that cell
			*new_state = look_up[lookup_iterator][1];
			break;
		}
	}
}


/* ***Swap array: Takes two arrays as parameters and swap all of the elements in those arrays.*** */
void swap_arrays(int current_state[], int next_state[], int array_length)
{
	int c;
	for(c=0;c<array_length;c++) {
		current_state[c]=next_state[c];
	}
}


/* *** Initialize Array *** */
// Initializes the entire array as 0
void initialize_array(int array_to_initialize[], int state_length)
{	
	int c;
	for(c=0;c<state_length;c++) {
		array_to_initialize[c]=0;
	}
}


/* *** Print State *** */
void print_state(int state_to_print[], int state_length)
{
	int c;
	for(c=0;c<state_length;c++) {
		if(state_to_print[c]==0)
			printf("%c ",null_char);
		if(state_to_print[c]==1)
			printf("%c ",full_char);
	}
	printf("\n");
}
