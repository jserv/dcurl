#ifndef POW_SSE_H_
#define POW_SSE_H_

#include "trinary.h"
#include <stdint.h>

typedef struct _pwork_struct Pwork_struct;

struct _pwork_struct {
    int8_t *mid;
    int mwm;
    int8_t *nonce;
    int n;
    int index;
    int64_t ret;
};

int8_t *PowSSE(int8_t *trytes, int mwm, int index);
int pow_sse_init(int num_task);
void pow_sse_destroy();

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

#define HBITS 0xFFFFFFFFFFFFFFFFuLL
#define LBITS 0x0000000000000000uLL
#define HASH_LENGTH 243               // trits
#define NONCE_LENGTH 81               // trits
#define STATE_LENGTH 3 * HASH_LENGTH  // trits
#define TX_LENGTH 2673                // trytes
#define INCR_START HASH_LENGTH - NONCE_LENGTH + 4 + 27
#define LOW00 \
    0xDB6DB6DB6DB6DB6DuLL  // 0b1101101101101101101101101101101101101101101101101101101101101101L;
#define HIGH00 \
    0xB6DB6DB6DB6DB6DBuLL  // 0b1011011011011011011011011011011011011011011011011011011011011011L;
#define LOW10 \
    0xF1F8FC7E3F1F8FC7uLL  // 0b1111000111111000111111000111111000111111000111111000111111000111L;
#define HIGH10 \
    0x8FC7E3F1F8FC7E3FuLL  // 0b1000111111000111111000111111000111111000111111000111111000111111L;
#define LOW20 \
    0x7FFFE00FFFFC01FFuLL  // 0b0111111111111111111000000000111111111111111111000000000111111111L;
#define HIGH20 \
    0xFFC01FFFF803FFFFuLL  // 0b1111111111000000000111111111111111111000000000111111111111111111L;
#define LOW30 \
    0xFFC0000007FFFFFFuLL  // 0b1111111111000000000000000000000000000111111111111111111111111111L;
#define HIGH30 \
    0x003FFFFFFFFFFFFFuLL  // 0b0000000000111111111111111111111111111111111111111111111111111111L;
#define LOW40 \
    0xFFFFFFFFFFFFFFFFuLL  // 0b1111111111111111111111111111111111111111111111111111111111111111L;
#define HIGH40 \
    0xFFFFFFFFFFFFFFFFuLL  // 0b1111111111111111111111111111111111111111111111111111111111111111L;
#define LOW01 \
    0x6DB6DB6DB6DB6DB6uLL  // 0b0110110110110110110110110110110110110110110110110110110110110110
#define HIGH01 \
    0xDB6DB6DB6DB6DB6DuLL  // 0b1101101101101101101101101101101101101101101101101101101101101101
#define LOW11 \
    0xF8FC7E3F1F8FC7E3uLL  // 0b1111100011111100011111100011111100011111100011111100011111100011
#define HIGH11 \
    0xC7E3F1F8FC7E3F1FuLL  // 0b1100011111100011111100011111100011111100011111100011111100011111
#define LOW21 \
    0xC01FFFF803FFFF00uLL  // 0b1100000000011111111111111111100000000011111111111111111100000000
#define HIGH21 \
    0x3FFFF007FFFE00FFuLL  // 0b0011111111111111111100000000011111111111111111100000000011111111
#define LOW31 \
    0x00000FFFFFFFFFFFuLL  // 0b0000000000000000000011111111111111111111111111111111111111111111
#define HIGH31 \
    0xFFFFFFFFFFFE0000uLL  // 0b1111111111111111111111111111111111111111111111100000000000000000
#define LOW41 \
    0x000000000001FFFFuLL  // 0b0000000000000000000000000000000000000000000000011111111111111111
#define HIGH41 \
    0xFFFFFFFFFFFFFFFFuLL  // 0b1111111111111111111111111111111111111111111111111111111111111111


#endif
