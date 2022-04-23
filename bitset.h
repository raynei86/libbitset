#ifndef BITSET_H
#define BITSET_H

#include <stdbool.h>
#include <stddef.h>

typedef struct bitset {
	int *arr;
	size_t len;
} bitset;

/* Return a bitset of size and value based on val */
bitset *BitsetMake(const size_t size, unsigned long val);
/* Free bitset */
void BitsetDestroy(bitset *b);

/* Get bit at particular position */
int BitsetGet(const bitset *b, const size_t pos);

/* See if bits are:
 * All are true
 * Any being true
 * None are true */
bool BitsetAllTrue(const bitset *b);
bool BitsetAnyTrue(const bitset *b);
bool BitsetNoneTrue(const bitset *b);

/* Return the amount of true or false */
int BitsetAmountTrue(const bitset *b);
int BitsetAmountFalse(const bitset *b);

/* Set all to be true/false */
void BitsetSetTrue(const bitset *b);
void BitsetSetFalse(const bitset *b);
/* Set a certain bit at pos to val */
void BitsetSet(const bitset *b, const size_t pos, const bool val);
/* Flip all bits or flip at pos */
void BitsetFlip(const bitset *b);
void BitsetFlipAt(const bitset *b, const size_t pos);

/* Converts the bitset into string and write into buf */
void BitsetToString(const bitset *b, char *buf, const char zero,
    const char one);

/* Converts the bitset into unsigned long */
unsigned long BitsetToULong(const bitset *b);

/* bitwise operations */
void BitsetAND(bitset *b, const bitset *other);
void BitsetOR(bitset *b, const bitset *other);
void BitsetXOR(bitset *b, const bitset *other);
void BitsetLeftShift(bitset *b, const size_t pos);
void BitsetRightShift(bitset *b, const size_t pos);

#endif
