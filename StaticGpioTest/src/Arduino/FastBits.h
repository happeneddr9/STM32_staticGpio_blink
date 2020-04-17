/**
 * @Name    : FastBits.h
 * @Date    : 2019年12月23日 下午7:30:10
 * @Author  : happe
 * @brief   :
 */

#ifndef ARDUINO_FASTBITS_H_
#define ARDUINO_FASTBITS_H_

#include "main.h"

/**
 * Get the positional index of the first bit set in 'word'. The 32-bit multiply operation is
 * single-cycle on the m3 and m4 and possibly the m0.
 * @param word the word to scan
 * @return 0..31
 */
static constexpr const uint8_t MultiplyDeBruijnBitPosition[32] = { 0, 1, 28, 2, 29, 14,
		24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 31, 27, 13, 23, 21, 19, 16, 7, 26,
		12, 18, 6, 11, 5, 10, 9 };

constexpr inline uint8_t firstSetBit(uint32_t word) {
	return MultiplyDeBruijnBitPosition[((uint32_t) ((word & -word) * 0x077CB531U))
			>> 27];
}

constexpr inline uint32_t __make_mask(uint8_t width, uint8_t offset) {
	width = (width == 0) ? 1 : width;
	return (static_cast<uint32_t>(1 << width) - 1) << offset;
}


template <class T>
constexpr void ForceSetBits(T& dir, uint32_t val, const uint8_t width, const uint8_t offset) {
	dir &= ~__make_mask(width, offset);
	//__bit_mask(dir, __make_mask(width, offset));
	dir |= (val << offset);
}

template <class T>
constexpr inline void SetBit(T& dir, uint8_t offset) {
	dir |= (static_cast<T>(1) << offset);
}

template <class T>
constexpr inline void ResetBit(T& dir, uint8_t offset) {
	dir &= ~(static_cast<T>(1) << offset);
}

template <class T>
constexpr inline void XorBit(T& dir, uint8_t offset) {
	dir ^= (static_cast<T>(1) << offset);
}

template <class T>
constexpr inline void ForceSetBit(T& dir, uint8_t val, uint8_t offset) {
	uint32_t mask = 1 << offset;
	dir &= ~mask;
	//__bit_mask(dir, mask);
	if(val > 0)
		dir |= mask;
}

constexpr unsigned _Popcount_(unsigned bb) {
	const unsigned C55 = 0x55555555UL;
	const unsigned C33 = 0x33333333UL;
	const unsigned C0F = 0x0f0f0f0fUL;
	const unsigned C01 = 0x01010101UL;

	bb -= (bb >> 1) & C55;         // put count of each 2 bits into those 2 bits
	bb = (bb & C33) + ((bb >> 2) & C33); // put count of each 4 bits into those 4 bits
	bb = (bb + (bb >> 4)) & C0F;   // put count of each 8 bits into those 8 bits
	return (bb * C01) >> 24; // returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
}

#endif /* ARDUINO_FASTBITS_H_ */
