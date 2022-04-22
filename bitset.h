#ifndef BITSET_H
#define BITSET_H

#include <stdbool.h>
#include <stddef.h>

typedef struct bitset {
  bool *arr;
  const size_t len;
} bitset;

bitset BitsetMake(const size_t size);
void BitsetDestroy(bitset *b);

int BitsetGet(const bitset *b, const size_t pos);

bool BitsetAllTrue(const bitset *b);
bool BitsetAnyTrue(const bitset *b);
bool BitsetNoneTrue(const bitset *b);

int BitsetAmountTrue(const bitset *b);
int BitsetAmountFalse(const bitset *b);

void BitsetSetTrue(const bitset *b);
void BitsetSetFalse(const bitset *b);
void BitsetSet(const bitset *b, const size_t pos, const bool val);
void BitsetFlip(const bitset *b);
void BitsetFlipAt(const bitset *b, const size_t pos);

#endif
