#ifndef IntBits_H
#define IntBits_H

namespace SimpleDSA
{
  /**
   * @brief Simple bit manipulation class for integer numbers
   *
   */
  class IntBits
  {
  public:
    unsigned int value;

    IntBits();
    IntBits(int val);
    int getBitAt(int i);
    int clearBitAt(int i);
    int setBitAt(int i);
    int updateBitAt(int i, int &newBit);
    int clearBitsAfter(int i);
    IntBits operator+(IntBits other);
  };

  IntBits::IntBits()
  {
    value = 0;
  }

  IntBits::IntBits(int val)
  {
    value = val;
  }

  int IntBits::getBitAt(int i)
  {
    int mask = 1 << i;
    int newVal = value & mask;
    return newVal > 0 ? 1 : 0;
  }

  int IntBits::clearBitAt(int i)
  {
    int mask = ~(1 << i);
    value &= mask;
    return value;
  }

  int IntBits::setBitAt(int i)
  {
    int mask = 1 << i;
    value |= mask;
    return value;
  }

  int IntBits::updateBitAt(int i, int &newBit)
  {
    clearBitAt(i);
    int mask = newBit << i;
    value |= mask;
    return value;
  }

  int IntBits::clearBitsAfter(int i)
  {
    int mask = (~0) << i;
    value &= mask;
    return value;
  } 

  IntBits IntBits::operator+(IntBits other)
  {
    unsigned int carry = value & other.value;
    int res = value ^ other.value;

    while (carry != 0)
    {
      unsigned int shifted_carry = carry << 1;
      carry = res & shifted_carry;
      res ^= shifted_carry;
    }

    return IntBits(res);
  }
}

#endif