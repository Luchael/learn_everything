#include <iostream>
/*; helloworld.asm
;
; Author: Lukael
; Date: 22-Apr-2021*/


int main(){
    __asm{
        CHARO 0x0007, d
        CHARO 0x0008, d
        STOP
        .ASCII "Hello, World!"
        .END
    }
}