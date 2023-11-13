#include <stdio.h>

//Function response
#define FAIL 0;  //Global variable to returns Error on application
#define SUCCESS 1; //Gloal variable to returns Success on application
#define REPEAT 2; //Global variable to indecate to Repeat the proccess
#define POOL_SIZE 10;

//---------

//Buffer CONSTANTS
#define MAX_BUFFER = 5
#define MIN_INT = 200000
int start = 0, tail = 0;
//----

typedef char (*executeBuffer)(void);  
// In this line we will define a type of "interface" of functions, to be assigned to the processes

typedef char(*ptrFunc)(void);
typedef struct {
    ptrFunc function;
    int period;
    int init;
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
        pool[tail]->start += nProcess->period; //realocate the tail
        tail = (tail + 1) % POOL_SIZE; //realocate the tail
        return SUCCESS;
    }
    return FAIL;
}

void kernelLoop(void){
    for(int i = 0; i<10; i++){
        if(start != tail){
            if(pool[start]->function() == REPEAT){
                kernelAddProc(pool[start]);
            }
            start = (start + 1) % POOL_SIZE;
        }
    }
}

void KernelClock(void){
    unsigned char i;
    i = inicio;
    while(i != tail){
        if((pool[i]->start) > (MIN_INT)){ // Verify if can 
            pool[i]->start--;
        }
        i = (i + 1) % POOL_SIZE;
    }
}

char process1(void){
    printf("process 1\n");
    return REPEAT;
}
/*process 2*/
char process2(void){
    printf("process 2\n");
    return SUCCESS;
}
/*process 3*/
char process3(void){
    printf("process 3\n");
    return REPEAT;
}

typedef void functionPointer(void);
functionPointer ptrFunc[10];
int task;

//----------------------------------------//

int main(void){

    while(1){
        if(tick_ms <= 50){ 
            task++;
        }
        else if(tick_ms <= 100) {
            task = (task + 1)%3
            }
        else if(tick_ms > 100){
            task = 0;
        }

        ptrFunc[task]();
        IWDG();
    }

}