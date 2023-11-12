#include <stdio.h>

//Function response
#define FAIL 0;  //Global variable to returns Error on application
#define SUCCESS 1; //Gloal variable to returns Success on application
#define REPEAT 2; //Global variable to indecate to Repeat the proccess
#define POOL_SIZE 10;

//---------

//Buffer CONSTANTS
#define MAX_BUFFER = 5
int start = 0, tail = 0;
//----

typedef char (*executeBuffer)(void);  
// In this line we will define a type of "interface" of functions, to be assigned to the processes

typedef char(*ptrFunc)(void);
typedef struct {
    ptrFunc function;
} Process;

typedef struct Buffer{
    char *nameProcess;
    executeBuffer execute;
} Buffer;

Process* pool[POOL_SIZE];
Buffer buffer[MAX_BUFFER]; // define the buffer global variable to use on Kernel


//----------------------------------------//

// Kernel initialization by setting values ​​in variables
char kernelInit(void){ 
    start = 0;
    tail = 0;
    return SUCCESS;
}

//add a new process on pool process
char kernelAddProc(Process* nProcess){
    if(((tail + 1) % POOL_SIZE) != start){// with the rest of the division, check whether you have already reached the end of the line and whether you should return to the beginning
        pool[tail] = nProcess; //Assign the current process in the village for execution
        tail = (tail + 1) % POOL_SIZE; //realocate the tail
        print("Start: %d, End: %d\n", start, tail);
        return SUCCESS;
    }
    return FAIL;
}

void kernelLoop(void){
    while(1){
        if(start != tail){ //check if you are already at the end of the queue
            if(pool[start] => function() === REPEAT){
                kernelAddProc(pool[start]);
            }

            start = (start + 1) % POOL_SIZE;
        }
    }
}

//----------------------------------------//

int main(){
    printf("Under construction")
    return 0;
}