/* 
 * CS:APP Data Lab 
 * 
 * <John Hooper nisse038 3644736>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /* De Morgans rule. basic logic opeator*/
	return ~x & ~y;
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
/*since we can only use variable of 8 bits I created one thats 7 bits 
 *then shift over 9 and add another base. this way they are padded by 2  *zeros so the pattern may repeat*/
	int base = 73;
 	return (base<<27)+(base<<18)+(base<<9)+base;
/*0b1001001001001001001001001001001;*/
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
/* the hardest part of this problem was dealing with all the cases
 * where negative one would return one.. anyway we start by making 
 * the max number  negative by adding one. then we have to deal 
 * with negative one. so we break it out of keeping up with the max
 * by adding 1 to zero (super_negative+!super_negative). then since
 * the max plus one is esentially the inverse of itself we xor it 
 * so that the max number is now represented as all 1's. then we
 * just have to flip it to all zeros and bang it to reset all the 
 * other numbers
 */
	int super_negative = (x+1);
	int all_ones_if_max;
	int all_zeros_if_max;
		
	super_negative = super_negative+!(super_negative);
	all_ones_if_max = x ^ super_negative;
	 all_zeros_if_max = ~all_ones_if_max;
	return !all_zeros_if_max;
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
/*This one was quite a pain for me. I tried probably 5 different
 * ways before realizing the obvious solution. You shift it right
 * 15 so all that is left is the leading 17 bits. you then have to 
 * xor x with the shifted value so if it is negative it will flip 
 * to positive and mostly zeros if it can fit in a short. I was 
 * having problems with the min before thinking this. you then 
 * shift this number right 15 resulting in only zeros if its able
 * to fit in a short
*/
	int rid_right = x>>15;//should return all 1's or 0's
	int flip_x = rid_right^x;
	int check_zero = flip_x>>15;
	

	return !check_zero;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
/*
 * Here I am building up a number where every even bit is a 1. 
 * I then negate that getting the desired number then I and it
 * with x. this way if there is any number where the odd bit is 
 * one it will remain one, otherwise everything else will be zero.
 * the remaining ones are all only odd. so I bang it making it zero 
 * (and at the same time making everything without an odd 1 bit 1, 
 * then bang it again to reverse it to the desired outocme.
 */
	return !(!(x & ~((85<<8)+ (85<<16) +(85<<24)+85)));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
/* really simple solution. we talked about it in class even 
 */	
  return ~x+1;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */ 
int byteSwap(int x, int n, int m) { 
/* I think this is the longest code I wrote... anyway what you do
 * is you set up a base mask of all zeros except for the last byte.
 * you then do n and m left shift 3 to get the amount you will have
 * to shift the mask later. Next we line up the ones on our mask with
 * the byte to be swapped. then you and x with the two masks creating
 * two binary string with only the swappable bits. then you move those
 * bytes all the way over to the right again before shifting them back
 * only this time the distance of the byte you want it to be swapped with
 * next you empty out x where the bytes used to be, then you simply and 
 * the two words together and get x onlly missing both bytes. I then 
 * placed each byte individually in their place then or'd them to get 
 * the result
*/
    int mask_base = 255;

	int n_shift = n<<3;
	int m_shift = m<<3;

	int mask_n_slot = mask_base<<n_shift;//line up the ones with n
	int mask_m_slot = mask_base<<m_shift;//line up the ones with m

	int mask_n = x & mask_n_slot;//zero out all but n
	int mask_m = x & mask_m_slot;//zero out all but m

	int right_n = mask_base & (mask_n >> n_shift);//n sitting on the right
	int right_m = mask_base & (mask_m >> m_shift);//m sitting on the right

	int place_n = right_n<<m_shift;//put it in the m slot
	int place_m = right_m<<n_shift;//put it in the n slot
	
	int zero_x_n = x & ~mask_n_slot;//clear the n slot for m
	int zero_x_m = x & ~mask_m_slot;//clear the m slot for n

	int new_x = zero_x_n & zero_x_m;//combine the two
	
	int x_n = new_x | place_n;
	int x_m = new_x | place_m;

	return x_n | x_m;
}


/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
/* first we have to figure out how far to shift our mask 
 * using the same logic as above.n<<3. then we move c into 
 * position by shifting the right amount. next create our 
 * byte mask. Then we flip the sign on the mask and and it 
 * with x to zero out that sweet spot. finally we or the 
 * now properly placed c with out emptied out x
*/
	int shift_amnt = n<<3; /*0->0, 1->8 2->16 3->24*/
	int move_c = c<<shift_amnt;//move c into the right position
	int kill_n = 255<<shift_amnt;//all zeros except where n is.
	int emptied_out = ~kill_n & x;//kill the propper section (n)
	
	return move_c|emptied_out;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
/* first things first. lets figure out if the first thing
 * should evaluate to true or not by banging x. then we 
 * have to negate that result so we get -1 or 0.
 * next we take y and or it with negate so that y will remain 
 * intact if we passed in a number not zero. then we and negate
 * with z so that if we passed in zero, it is now -1 and -1&z 
 * is equal to z. finally we xor those two values and then the 
 * resultant with negate
*/
	int one_or_zero = !x; // !0 = 1   |||  !anything else = 0
	int negate = ~one_or_zero+1;//1 = -1 |||  ~0=0
	int or = y | negate;// y | -1 =-1 |||  0 | y = y
	int and = negate & z;// -1 & z =z |||  0 & z = 0	
  	return  (and^or)^negate ;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
/* start off easy enough by pushing the number to the right. 
 * next we create a negative n to perform a "subtraction" 
 * from 32, effectively pushing what was first pushed off 
 * the right all the way over to the left. then I had to make
 * a negative one because driver didnt like it :P 
 * next we have to mask x so that we can slot in the right part
 * that rolled over. finally we or the two to get our answer
*/
	int shifted = x>>n;//the right part of the number
	int neg_n = ~n+1;//for easy subtraction
	int roll_over = x<<(32+neg_n);//move the carried part to the end
	int neg_one = (1<<31)>>32;
	int mask_x = shifted & ~(neg_one<<(32+neg_n));
	
  return roll_over|mask_x;

}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
/* first you have to get the sign obviously. right shift 31.
 * then you xor x with the sign. if its was positiv then you 
 * are doing x ^0 which will remain as x. only the negatives 
 * will flip bits. now you want to check the sign of your 
 * flipped number, make sure its the one you want by left 
 * shifting it 31 (zero out everything but the sign. then you 
 * have to or the your wanted sign with the flipped one from 
 * before and add the negation of your sign (to account for
 * gaining one earlier. dont worry it was positive then you 
 * are just adding positive.
*/
	int sign = x>>31;
	int flip = x^sign;//negative will flip
	int check_sign = (flip>>31)|sign;
	int correct_sign = check_sign<<31;
	
	
	return (correct_sign | flip)+(~sign+1);
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
/* first thing you have to do is kill the signed bit, by pushing 1 all the 
 * way to the left and negating it. Then I chose to set up my variable for
 * checking if I was going to have issues with NAN. I then killed the signed
 * bit by anding the bit mask with uf. then you just have to check it your
 * new uf is less than the NAN value. if its not that means you will have a 
 * problem, in which case you just return the number given.
*/
  unsigned kill_sign_bit = ~(1<<31);//get ready to kill the sign
  unsigned bad_touch_NAN = (255<<23)+1; //NAN in unsigned form
  
  unsigned abs_uf = kill_sign_bit & uf; //kill the bit!
  
  if (abs_uf < bad_touch_NAN){
    return abs_uf;
  }
  else{
    return uf;
  }
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
/* This one took a whilel to figure out because i was thinkign about
 * it like I was adding uf to itself instead of just increasing the 
 * exp by 1 essentially doubling it for most cases. Start off by
 * segregating your signed bit, mantissa, and exp then shift your 
 * exp over to the right for easy manipulation. check for all the bad 
 * cases first so we can bail out if need be. then start if elseing the
 * edge cases. if there is an overflow in the mantissa subtract one and 
 * add it to the exp. if it is only mantissa and no exponent then you
 * just double the mantissa by left shifting one. at the end reshift 
 * your exp to the right location and or all your masked pieces to 
 * reassemble your number. 
*/  
  unsigned mantissa = uf & 8388607;//save the mantissa
  unsigned exp_mask = 2139095040;
  unsigned exp= uf & exp_mask; //save the exp
  unsigned sign = uf & (-2147483648); // save the sign
  unsigned right_exp= (exp>>23);//gonna have to add one eventually
  
  
  if (right_exp==255||(right_exp==0 &&mantissa==0)){
//return uf if exp is all ones = infinity or NAN or -0 or 0

    return uf;
 
  }
  else if(right_exp!=0){
    right_exp+=1;
  }
  else if(mantissa==8388607){//mantissa is all ones
  
    right_exp+=1;//overlow  
    mantissa -=1;//overflow
   
  }
  else if(mantissa!=0){
    mantissa= mantissa<<1;
  } 
  


  right_exp=right_exp<<23;
 return sign|right_exp|mantissa;
}
