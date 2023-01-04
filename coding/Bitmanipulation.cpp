#include "bitmanipulation.h"

uint32_t insertion(uint32_t N, uint32_t M, int i, int j) {
    //clear the bits within the range from i to j
    //shift the inserted value  by the correct pos
    //or the shift value and the N
    uint32_t temp = 0;
    M = M << i;
    for (i; i <= j; i++) {
        temp |= 1 << i;
    }
    temp = ~(temp);
    return (N & temp) | M;
}

std::string binarytostring(double num) {
    char a[100] = "0.";
    int i = 2;
    //a[i] = '2';
    // while((num*2) != 1.0){
    //     if(num*2 < 1){
    //         a[i] = '0';
    //         num = num*2;
    //     }else{
    //         a[i] = '1';
    //         num = num * 2 - 1;
    //     }
    //     i++;
    // }

    //using for loop more fast
    for (i; i <= 32; i++) {
        if (num * 2 == 1.0) {
            a[i] = '1';
            return a;
        }
        else if (num * 2 < 1) {
            a[i] = '0';
            num = num * 2;
        }
        else {
            a[i] = '1';
            num = num * 2 - 1;
        }
    }
    return "error";
    // a[i] = '1';
    // if(strlen(a)>32){
    //     return "error";
    // }
    // //cout<<strlen(a);
    // return a;
}

int flipbits_findlongest_seq(int num) {
    // 0b11011101111 -> 0b11011111111 , 8
    // 0b10011010011 -> 0b10011110011 , 4
    // 0b10011001110 -> 4,
    // find the first largest one group, then second, check  if they can conncet to each other;
    //increment by one then compare those, set the flip
    //similar method could be set the previouscurrent and nextcurrent, and record their maximum when it reaches the breakpoint
    int largestcount = 0;
    int count = 0;
    int flip = 1;
    while (num != 0) {
        if ((1 & num) > 0) {
            count++;
            num = num >> 1;
        }
        else if ((count != 0) && (flip == 1)) {
            count++;
            flip = 0;
            num = num >> 1;
            if ((1 & num) == 0) {
                if (count > largestcount) {
                    largestcount = count;
                }
                count = 0;
                flip = 1;
            }
        }
        else {
            if (flip == 0) {
                if (count > largestcount) {
                    largestcount = count;
                }
                count = 0;
                flip = 1;
            }
            num = num >> 1;
        }
    }
    return largestcount;
}

void nextnumber(unsigned int num) { 
    //0100011 -> 0100110 
    //0100011 -> 
    int wanted = count1s(num);
    int temp = num;
    //brutal force: increment each intger by one then compare if they have the same 1s;
    //find the next largest:
    decimaltobinary(num);
    while (wanted != count1s(++num));
    decimaltobinary(num);
    while (wanted != count1s(--temp));
    decimaltobinary(temp);
    


}
//helping method
//used to print the binary form
void decimaltobinary(unsigned int num) { //print
    char binary[32];
    int i = 0;
    while (num != 0) {
        //ez way to do
        //if (num % 2 == 0) {   
        //    binary[i] = '0';
        //}
        //else {
        //    binary[i] = '1';
        //}
        //num = num / 2;
        //i++;
        binary[i] = (num % 2)+'0'; // notice that without adding zero will result wrong ASCII format which is zero or 1, typecasting is not ideal, it will convert to the exact ASCII cooresponding number for zero it startws with decimal number 48, so we can simply add it to zero
        num = num / 2;
        i++;
    }
    binary[i] = '\0'; //important
    printf("The string is %s\n", _strrev(binary));  //_strrev, used to reverse a string
    //std::cout << strlen(binary);
}

//count appearance of 1s for the binary forms
int count1s(unsigned int num) {
    //
    int count = 0;
    while (num != 0) {
        if ((num & 1) > 0) {
            count++;
        }
        num = num >> 1;
    }
    return count;
} 