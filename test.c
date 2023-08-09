#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pig2_system.h"

int main(void){
    assert(judge(1) == 0);
    assert(judge(4) == 1);
    
    return (0);
}