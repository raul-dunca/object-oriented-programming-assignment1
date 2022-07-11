#include <stdio.h>

int compare(int a, int b)
{
	// input: 2 integer number a and b; output: the bigger number between a and b
	if (a > b)
		return a;
	else
		return b;
}
int interval(int x, int a, int b)
{
	// this function checks if x is in the interval [a,b] and return 1 if it is otherwise return 0
	if (x >= a && x <= b)
		return 1;
	else
		return 0;
}
void print_function(int a[101], int s, int e)
{
	// this function checks if startindex=endindex=-1 if thats the case thah means we
	//dont have any elements in that interval and otherwise it just prints the result
	if (s == -1 && e == -1)
	{
		printf("There are no elements in this interval!\n");

	}
	else
	{
		int i;
		for (i = s; i <= e; i++)
		{
			printf("%d", a[i]);
			printf(" ");
		}
		printf("\n");
	}
}
int main()
{



	int t = 1, option = 0, ok = 0, i;


	while (t == 1)
	{
		printf("1. Read sequences of positive integer numbers (reading of each sequence ends by 0, reading of all the sequences ends by -1) and determine the maximum element of each sequence and the maxim element of the global sequence.\n");
		printf("2. Given a vector of numbers, find the longest contiguous subsequence such that all elements are in a given interval.\n");
		printf("3. Exit\n");
		//Printing the menu
		scanf("%d", &option);
		if (option == 1)
		{
			int n = 1, global_max = 0, max[31], k = 1;
			// we initilise this variables whenever we choose option 1
			while (n != -1) {



				scanf("%d", &n);
				if (ok == 1 && n != -1 && n != 0)
				{ // if n was previosly 0 and the next n is not -1 and 0 we create a new "cell" in the array
					//this means a seqence was ended

					k++;
					max[k] = 0;
				}
				ok = 0;

				if (n == 0)
				{
					ok = 1;


				}




				global_max = compare(global_max, n);
				//global_max just get the bigger value from itself and n

				max[k] = compare(max[k], n);
				//the current "cell" gets the max value from itself and n



			}

			for (i = 1; i <= k; i++) //just printing the sequence nicely
			{
				printf("The max for the sequence %d is %d\n", i, max[i]);
			}

			printf("Global max = %d\n", global_max);
		}
		else
		{
			if (option == 2)
			{
				int arr[101], l = 0, start = 0, end = 0, seqlen = 0, longest = 0, indexend = -1, indexstart = -1;
				int i;
				printf("How long is the vector>\n");
				scanf("%d", &l);
				printf("Read the vector of numbers:\n");



				for (i = 0; i < l; i++)
				{
					scanf("%d", &arr[i]);
				}


				printf("Read the vinterval [a,b]:\n");
				printf("a=");
				scanf("%d", &start);
				printf("b=");
				scanf("%d", &end);


				//we read the lenght of the vector, the vector and the interval

				for (i = 0; i < l; i++)
				{
					// if and element is form the interval 
					//we increas seqlen and check if its bigger then the longest
					//if it is we keep the start and end index and otherwise we put seqlne of 0 meaning the 
					//previous seqence ended
					if (interval(arr[i], start, end) == 1)
					{
						seqlen++;
						if (seqlen > longest)
						{
							longest = seqlen;
							indexend = i;
							indexstart = i - seqlen + 1;
						}
					}
					else
						seqlen = 0;
				}

				printf("the longest contiguous subsequence such that all elements are from [%d,%d] is:\n", start, end);
				print_function(arr, indexstart, indexend);
			}

			else
				return 0;
		}
	}
	//return 0;
}