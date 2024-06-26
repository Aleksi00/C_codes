#include "stringsplit.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Splits a string into its parts, and returns a dynamically allocated  
 *        array of strings that are dynamically allocated.
 * 
 * \details For example called with "Test string split" and " ",
 *          the function returns ["Test", "string", "split", NULL].
 *          
 *          Or called with "Another - test" and " - ",
 *          returns ["Another", "test", NULL].
 * 
 * \param str The null-terminated string to split.
 * \param split The token string to split str with.
 * \return An array of strings that contains parts of str in each of 
 *         strings excluding the split.      
 */
char** split_string(const char *str, const char* split) {

    int numero = 0;
    const char *kopio = str;
    while ( (kopio = strstr(kopio,split)) ) {
        numero++;
        kopio++;
    }
 
    char** palautus = calloc((numero + 2), sizeof(char*));
 
    int i = 0;
    char *palautus_sana;
    while ( (palautus_sana = strstr(str,split)) ) {
        
        size_t vaa_tila = palautus_sana - str;
        
        palautus[i] = calloc((vaa_tila + 1) , sizeof(char));
        
        strncpy(palautus[i], str, vaa_tila);
        
        str = (str + vaa_tila) + strlen(split);
        
        i++;
    }
    
    palautus[i] = calloc((strlen(str) + 1) , sizeof(char));
    
    strcpy(palautus[i], str);

    return palautus;
}

/**
 * \brief Prints string parts that are split with split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */

 
void print_split_string(char **split_string) {

    for (int i = 0; split_string[i] != NULL; i++) {
        printf("%s\n", split_string[i]);
    }
}
/**
 * \brief Releases dynamically allocated string parts by split_string function.
* 
 * \param split_string An array of strings returned by split_string function.
 */

 
void free_split_string(char **split_string) {

    for (int i = 0; split_string[i] != NULL; i++) {
        free(split_string[i]);
    }
    
    free(split_string);
}