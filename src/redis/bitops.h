#include <stdint.h>

void setUnsignedBitfield(unsigned char* p, uint64_t offset, uint64_t bits, uint64_t value);
void setSignedBitfield(unsigned char* p, uint64_t offset, uint64_t bits, int64_t value);
uint64_t getUnsignedBitfield(unsigned char* p, uint64_t offset, uint64_t bits);
int64_t getSignedBitfield(unsigned char* p, uint64_t offset, uint64_t bits);

/* The following two functions detect overflow of a value in the context
 * of storing it as an unsigned or signed integer with the specified
 * number of bits. The functions both take the value and a possible increment.
 * If no overflow could happen and the value+increment fit inside the limits,
 * then zero is returned, otherwise in case of overflow, 1 is returned,
 * otherwise in case of underflow, -1 is returned.
 *
 * When non-zero is returned (overflow or underflow), if not NULL, *limit is
 * set to the value the operation should result when an overflow happens,
 * depending on the specified overflow semantics:
 *
 * For BFOVERFLOW_SAT if 1 is returned, *limit it is set maximum value that
 * you can store in that integer. when -1 is returned, *limit is set to the
 * minimum value that an integer of that size can represent.
 *
 * For BFOVERFLOW_WRAP *limit is set by performing the operation in order to
 * "wrap" around towards zero for unsigned integers, or towards the most
 * negative number that is possible to represent for signed integers. */

#define BFOVERFLOW_WRAP 0
#define BFOVERFLOW_SAT 1
#define BFOVERFLOW_FAIL 2

int checkUnsignedBitfieldOverflow(uint64_t value, int64_t incr, uint64_t bits, int owtype,
                                  uint64_t* limit);
int checkSignedBitfieldOverflow(int64_t value, int64_t incr, uint64_t bits, int owtype,
                                int64_t* limit);
