#include <stdlib.h>
#include <stdio.h>
#include "source.h"
#include <string.h>

/**
 * \brief Joins 3 arrays into a new dynamically allocated array
 *
 * \param n1 The number of elements in array
 * \param a1 The array 1 composed of n1 elements
 * \param n2 The number of elements in array
 * \param a2 The array 1 composed of n1 elements
 * \param n3 The number of elements in array
 * \param a3 The array 1 composed of n1 elements
 * \return a pointer to the dynamically allocated array
 *
 * \note The caller is responsible for deallocating the allocated array
 */
int *join_arrays(unsigned int n1,
                 const int *a1,
                 unsigned int n2,
                 const int *a2,
                 unsigned int n3,
                 const int *a3)
{
  int *memory;
  unsigned int i;
  unsigned int j = 0;

  unsigned int k;
  unsigned int l = 0;

  unsigned int a;
  unsigned int b = 0;
  memory = malloc(n1*sizeof(int) + n2*sizeof(int) + n3*sizeof(int) );
  if (memory != NULL)
  {
    for(i=0 ; i<n1 ; i++)
    {
        memory[i] = a1[j++];
    }

    for(k=i ; k<n2+n1 ; k++)
    {
        memory[k] = a2[l++];
    }

    for(a=k ; a<n3+n2+n1 ; a++)
    {
        memory[a] = a3[b++];
    }




  }
  return memory;

}