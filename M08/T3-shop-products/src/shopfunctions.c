#include "shopfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Returns a comparison value obtained by comparing the names of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details The name field of a Product is a string.
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns 0 if a == b
 * \returns a positive number if b should be placed before a
 */
int compareAlpha(const void* a, const void* b) {
	(void)a;
	(void)b;
	return strcmp(a,b);
}

/**
 * \brief Returns a comparison value obtained by comparing in_stock of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details in_stock is an integer, and the products with higher stock should be
 *          placed before the products with lower stock. 
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns 0 if a == b
 * \returns a positive number if b should be placed before a
 */
int compareNum(const void* a, const void* b) {
	const Product *a_1 = a;
	const Product *b_1 = b;
	if (a_1->in_stock > b_1->in_stock)
	{
		return -1;
	}
	else if (a_1->in_stock < b_1->in_stock)
	{
		return 1;
	}
	else
	{
		return compareAlpha(a,b);
	}
	
}

const Product* findProduct(const Product* p_array,
						   const char* search_key,
						   int (*cmp)(const void*, const void*)) {
	(void)p_array;
	(void)search_key;
	(void)cmp;
	const Product *item;
	Product new_product;
	strcpy(new_product.name,search_key);
	int i = 0;
	while (p_array[i].name[0] != 0)
	{
		i++;
	}
	item = bsearch (&new_product, p_array, i, sizeof(Product), cmp);
	if (item != NULL)
	{
		return item;
	}
	else
	{
		return NULL;
	}
	
}
