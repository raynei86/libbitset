#ifndef BITSET_H
#define BITSET_H

#include <stdbool.h>
#include <stddef.h>

typedef struct bitset
{
  int *arr;
  size_t len;
} bitset;

bitset *BitsetMake (const size_t size, unsigned long val);
void BitsetDestroy (bitset *b);

int BitsetGet (const bitset *b, const size_t pos);

bool BitsetAllTrue (const bitset *b);
bool BitsetAnyTrue (const bitset *b);
bool BitsetNoneTrue (const bitset *b);

int BitsetAmountTrue (const bitset *b);
int BitsetAmountFalse (const bitset *b);

void BitsetSetTrue (const bitset *b);
void BitsetSetFalse (const bitset *b);
void BitsetSet (const bitset *b, const size_t pos, const bool val);
void BitsetFlip (const bitset *b);
void BitsetFlipAt (const bitset *b, const size_t pos);

/* TODO: WIP functions */
void BitsetToString (const bitset *b, char *buf, const char zero,
                     const char one);
unsigned long BitsetToULong (const bitset *b);
void BitsetAND (bitset *b, const bitset *other);
void BitsetOR (bitset *b, const bitset *other);
void BitsetXOR (bitset *b, const bitset *other);
void BitsetLeftShift (bitset *b, const size_t pos);
void BitsetRightShift (bitset *b, const size_t pos);

#endif
