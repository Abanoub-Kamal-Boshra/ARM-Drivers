/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	22 JAN 2021											*/
/************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* Registers */
// base address of NVIC = 0xE000E100
// base address of SCB  = 0xE000ED00
#define NVIC_ISER0 					*((volatile u32*) 0xE000E100 )  // Eable Exteranal interrupts from 0 to 31
#define NVIC_ISER1 					*((volatile u32*) 0xE000E104 )  // Eable Exteranal interrupts from 32 to 63

#define NVIC_ICER0 					*((volatile u32*) 0xE000E180 )	// Disable Exteranal interrupts from 0 to 31
#define NVIC_ICER1 					*((volatile u32*) 0xE000E184 )  // Disable Exteranal interrupts from 32 to 63

#define NVIC_ISPR0 					*((volatile u32*) 0xE000E200 )	// Set pending Flag for Exteranal interrupts from 0 to 31
#define NVIC_ISPR1 					*((volatile u32*) 0xE000E204 )  // Set pending Flag for Exteranal interrupts from 32 to 63

#define NVIC_ICPR0 					*((volatile u32*) 0xE000E280 )	// Clear pending Flag for Exteranal interrupts from 0 to 31
#define NVIC_ICPR1 					*((volatile u32*) 0xE000E284 )  // Clear pending Flag for Exteranal interrupts from 32 to 63

#define NVIC_IABR0 					*((volatile u32*) 0xE000E300 )	// Check on the active flag for Exteranal interrupts from 0 to 31
#define NVIC_IABR1 					*((volatile u32*) 0xE000E304 )  // Check on the active flag for Exteranal interrupts from 32 to 63
/*					without Dereference								*/
#define NVIC_IPR 					 ((volatile u8* ) 0xE000E400 )


#define NVIC_STIR 					*((volatile u32*) 0xE000EF00 )


/* in (SCB => AIRCR) 4 bits for group and 0 for sub => 4bits in (IPR) to determine group number	*/
#define NVIC_4BITS_GROUP_0BIT_SUB			0x05FA0300

/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define NVIC_3BITS_GROUP_1BIT_SUB			0x05FA0400

/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define NVIC_2BITS_GROUP_2BITS_SUB			0x05FA0500

/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define NVIC_1BIT_GROUP_3BITS_SUB			0x05FA0600

/* in (SCB => AIRCR) 0 group for 4 bits for sub												*/
#define NVIC_0BIT_GROUP_4BITS_SUB			0x05FA0700


#endif
