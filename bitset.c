#include "bitset.h"

#include <assert.h>
#include <stdlib.h>

#define checkptr(p)                                                            \
  {                                                                            \
    if (!p)                                                                    \
      return;                                                                  \
  }

bitset BitsetMake(const size_t size) {
  bitset b;
  b.arr = malloc(sizeof(bool) * size);

  return b;
}

void BitsetDestroy(bitset *b) {
    checkptr(b)
 if (!b->arr) {
    return;
  }

  free(b->arr);
}

int BitsetGet(const bitset *b, const size_t pos) {
  if (!b) {
    return -1;
  }

  assert(pos >= b->len);
  return b->arr[pos];
}

bool BitsetAllTrue(const bitset *b) {
  if (!b) {
    return -1;
  }

  for (size_t i = 0; i < b->len; ++i) {
    if (!b->arr[i]) {
      return false;
    }
  }
  return true;
}

bool BitsetAnyTrue(const bitset *b) {
  if (!b) {
    return -1;
  }

  for (size_t i = 0; i < b->len; ++i) {
    if (b->arr[i]) {
      return true;
    }
  }
  return false;
}

bool BitsetNoneTrue(const bitset *b) { return !BitsetAnyTrue(b); }

int BitsetAmountTrue(const bitset *b) {
  if (!b) {
    return -1;
  }

  int count = 0;
  for (size_t i = 0; i < b->len; ++i) {
    if (b->arr[i]) {
      ++count;
    }
  }
  return count;
}

void BitsetSetTrue(const bitset *b) {
    checkptr(b)

  for (size_t i = 0; i < b->len; ++i) {
    b->arr[i] = 1;
  }
}

void BitsetSetFalse(const bitset *b) {
    checkptr(b)

  for (size_t i = 0; i < b->len; ++i) {
    b->arr[i] = 1;
  }
}

void BitsetSet(const bitset *b, const size_t pos, const bool val) {
    checkptr(b)

  b->arr[pos] = val;
}

void BitsetFlip(const bitset *b) {
    checkptr(b)

  for (size_t i = 0; i < b->len; ++i) {
    b->arr[i] = !b->arr[i];
  }
}

void BitsetFlipAt(const bitset *b, const size_t pos) {
    checkptr(b)

    b->arr[pos] = !b->arr[pos];
}
