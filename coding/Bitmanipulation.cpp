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
    //bit manipulatio method look from textbook; find non-trailing those methods
}

int conversion(int A, int B) { //the number of bits need to convert
    //input 29, 11101 , 15, 01111
    //output 2
    //brutal force. check one by one?, if not differ than count ++
    //1001011
    //0000111
    //output: 3
    //O(b) time;
    //int count = 0;
    //int bigger,smaller;
    //if (A > B) {
    //     bigger = A;
    //     smaller = B;
    //}
    //else {
    //     bigger = B;
    //     smaller = A;
    //}
    //while (bigger != 0) {
    //    if ((1 & bigger) != (1 & smaller)){
    //        count++;
    //    }
    //    bigger = bigger >> 1;
    //    smaller = smaller >> 1;
    //} 
    //return count;
    //Think about what an XOR indicates. If you do a XOR b, where does the result have 1 s?
    //Where does it have Os ?
    //11101
    //01111
    //doing xor, will give 10010, then find out how many zeros have
    //int count = 0;
    //for (int c = A^B; c != 0; c = c >> 1) {
    //    count += c & 1;
    //}
    //return count;

    int count = 0;
    for (int c = A ^ B; c != 0; c = c & (c - 1)) {  //count how long it taks c to reach 0
    // 10000 -> 01111
    // 10100 -> 10011
    // The operation c = c & ( c - 1) will clear the least significant bit in c. 
        count++;
    }
    return count;

}

int pairwiseSwap(int num) {
    //swap odd and even bits in an integer
    // 101010
    // 010101
    //bit 0 and bit 1 are swapped
    //operate two bits at a time, temp to record then

    // 11 = 3, extract least significant two bits
    // 10
    // 01
    //int swap = 0;
    //int odd = 1;
    //int even = 0;
    //while (num != 0) {
    //    int temp = 1 & num; //record the first digit
    //    swap = swap | (temp << odd);
    //    num = num >> 1;
    //    swap = swap | ((num & 1) << even);
    //    num = num >> 1;
    //    // 1010 -> 
    //    //swap = 01;
    //    odd = odd + 2;
    //    even = even + 2;
    //}
    //return swap;
    
    //also another way is to think about maasking with a binary, operate on the odds bits first then even bits
    // >>> arithmatic shift, not changing the sign, the sign(msb) will still be the same when replaced
    // >> logical shift, will replace the sign bit with zero
    // We can mask all odd bits with 10101010 in binary (which is 0xAA), then shift them right by 1 to put them in the even spots.
    // For the even bits, we do an equivalent operation. Finally, we merge these two values.
    return (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1));
}

int drawline() {
    return 0;
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
    // another method is using c & (c-1)
    int count = 0;
    while (num != 0) {
        if ((num & 1) > 0) {
            count++;
        }
        num = num >> 1;
    }
    return count;
    //
    //int count = 0;
    //for (int c = A ^ B; c != 0; c = c & (c - 1)) {  //count how long it taks c to reach 0
    //    // 10000 -> 01111
    //    // 10100 -> 10011
    //    // The operation c = c & ( c - 1) will clear the least significant bit in c. 
    //    count++;
    //}
    //return count;
} 