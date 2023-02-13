//
//File: PersonSort.h
//A partial file that will sort Persons 

//How to use this class
//First, #include "PersonSort.h" in the file where the sort is needed.
//Next, declare a PersonSort object and call the ShellSort method.

//NOTE: this assumes that your Person has the < and > overloaded to alphabetize names

#ifndef _PERSON_SORT_H
#define _PERSON_SORT_H

#include "GrycnerP2/Person.h"

class PersonSort
{
public:
	PersonSort() = default;
	void ShellSort(Person arr[], int size);
};

void PersonSort::ShellSort(Person arr[], int size)
{
	int h = 1;
        /* 
         * find the largest h value possible 
         */
    while ((h * 3 + 1) < size) 
	{
		h = 3 * h + 1;
	}

    /* 
     * while h remains larger than 0 
     */
    while( h > 0 ) 
	{
        /* 
			* for each set of elements (there are h sets)
		*/
        for (int i = h - 1; i < size; i++) 
		{
            /* 
				* pick the last element in the set
			*/
            Person B = arr[i];
            int j = i;
     /*
             * compare the element at B to the one before it in the set
             * if they are out of order continue this loop, moving
             * elements "back" to make room for B to be inserted.
             */
			 
	
            for( j = i; (j >= h) && (arr[j-h] > B); j -= h) 
			{
                arr[j] = arr[j-h];
            }
            /*
				*  insert B into the correct place
			*/
            arr[j] = B;
        }
        /* 
			* all sets h-sorted, now decrease set size
		*/
        h = h / 3;
    }
}

#endif
