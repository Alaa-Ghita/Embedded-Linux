/*
 * Bit_Math.h
 *
 * Created: 11/29/2023 3:18:28 PM
 *  Author: Alaa
 */ 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SIZE_OF_REG 8

// Set bit BIT in REG
#define SET_BIT(REG,BIT) REG |=(1<<BIT)
// Clear bit BIT in REG       
#define CLR_BIT(REG,BIT) REG &=(~(1<<BIT))
// Toggle bit BIT in REG           
#define TGL_BIT(REG,BIT) REG ^=(1<<BIT)
// Get bit BIT in REG           
#define GET_BIT(REG,BIT) (1&(REG>>BIT))
          
// Set high nibble in REG
#define SET_HIGH_NIB(REG) ((REG) |= (0xf0))
// Clear high nibble in REG          
#define CLR_HIGH_NIB(REG) ((REG) &= (0x0f))
// Get high nibble in REG          
#define GET_HIGH_NIB(REG) ((REG) >> (SIZE_OF_REG/2))
// Toggle high nibble in REG       
#define TGL_HIGH_NIB(REG) ((REG) ^= (0xf0))
// Set low nibble in REG         
#define SET_LOW_NIB(REG) ((REG) |= (0x0f))
// Clear low nibble in REG           
#define CLR_LOW_NIB(REG) ((REG) &= (0xf0))
// Get low nibble in REG            
#define GET_LOW_NIB(REG) ((REG) & (0x0f))
// Toggle low nibble in REG            
#define TGL_LOW_NIB(REG) ((REG) ^= (0x0f))

// Assign VALUE to REG
#define ASSIGN_REG(REG,VALUE) REG=VALUE
// Assign VALUE to high nibble REG
#define ASSIGN_HIGH_NIB(REG,VALUE) REG=(VALUE<<(SIZE_OF_REG/2))|(CLR_HIGH_NIB(REG))
// Assign VALUE to low nibble REG 
#define ASSIGN_LOW_NIB(REG,VALUE) REG=(CLR_LOW_NIB(REG))|(CLR_HIGH_NIB(VALUE))
// Right shift by NO in REG
#define RSHFT_REG(REG, NO) REG=REG>>NO
// Left shift by NO in REG
#define LSHFT_REG(REG, NO) REG=REG<<NO     
// Circular right shift by NO in REG
#define CRSHFT_REG(REG, NO) REG=(REG>>NO)|(REG<<SIZE_OF_REG-NO)
// Circular left shift by NO in REG
#define CLSHFT_REG(REG,NO) REG=(REG<<NO)|(REG>>SIZE_OF_REG-NO)      


#endif /* BIT_MATH_H_ */