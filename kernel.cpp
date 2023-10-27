#include <stdio.h>

//Function response
#define FAIL 0;  //Global variable to returns Error on application
#define SUCCESS 1; //Gloal variable to returns Success on application
#define REPEAT 2; //Global variable to indecate to Repeat the proccess
//---------

//Buffer CONSTANTS
#define MAX_BUFFER = 5
int start = 0, tail = 0;
//----

typedef char (*executeBuffer)(void);  
// In this line we will define a type of "interface" of functions, to be assigned to the processes

typedef struct Buffer{
    char *nameProcess;
    executeBuffer execute;
} Buffer;

Buffer buffer[MAX_BUFFER]; // define the buffer global variable to use on Kernel

int main(){
    printf("Under construction")
    return 0;
}