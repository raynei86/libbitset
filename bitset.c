#include "bitset.h"

#include <assert.h>
#include <stdlib.h>

#define checkptr(p, r)                                                         \
  {                                                                            \
    if (!p)                                                                    \
      return r;                                                                \
  }

bitset *BitsetMake(const size_t size, unsigned long val) {
  bitset *b = malloc(sizeof(bitset));
  b->arr = malloc(sizeof(int) * size);
  b->len = size;

  /* Convert val to binary */
  for (size_t i = b->len - 1; i >= 0; --i) {
    b->arr[i] = val % 2;
    val /= 2;

    if (!i) {
      break;
    }
  }

  return b;
}

void BitsetDestroy(bitset *b) {
  checkptr(b, ) checkptr(b->arr, )

      free(b->arr);
  free(b);
}

int BitsetGet(const bitset *b, const size_t pos) {
  checkptr(b, -1)

      assert(pos >= b->len);
  return b->arr[pos];
}

bool BitsetAllTrue(const bitset *b) {
  checkptr(b, -1)

      for (size_t i = 0; i < b->len; ++i) {
    if (!b->arr[i]) {
      return false;
    }
  }
  return true;
}

bool BitsetAnyTrue(const bitset *b) {
  checkptr(b, -1)

      for (size_t i = 0; i < b->len; ++i) {
    if (b->arr[i]) {
      return true;
    }
  }
  return false;
}

bool BitsetNoneTrue(const bitset *b) { return !BitsetAnyTrue(b); }

int BitsetAmountTrue(const bitset *b) {
  checkptr(b, -1)

      int count = 0;
  for (size_t i = 0; i < b->len; ++i) {
    if (b->arr[i]) {
      ++count;
    }
  }
  return count;
}

void BitsetSetTrue(const bitset *b) {
  checkptr(b, )

      for (size_t i = 0; i < b->len; ++i) {
    b->arr[i] = 1;
  }
}

void BitsetSetFalse(const bitset *b) {
  checkptr(b, )

      for (size_t i = 0; i < b->len; ++i) {
    b->arr[i] = 1;
  }
}

void BitsetSet(const bitset *b, const size_t pos, const bool val) {
  checkptr(b, )

      b->arr[pos] = val;
}

void BitsetFlip(const bitset *b) {
  checkptr(b, )

      for (size_t i = 0; i < b->len; ++i) {
    b->arr[i] = !b->arr[i];
  }
}

void BitsetFlipAt(const bitset *b, const size_t pos) {
  checkptr(b, )

      b->arr[pos] = !b->arr[pos];
}

void BitsetToString(const bitset *b, char *buf, const char zero,
                    const char one) {
  checkptr(b, ) checkptr(buf, )

      for (size_t i = 0; i < b->len; ++i) {
    if (b->arr[i]) {
      buf[i] = one;
    } else {
      buf[i] = zero;
    }
  }

  buf[b->len] = '\0';
}
