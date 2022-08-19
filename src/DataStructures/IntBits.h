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
    int value;

    IntBits();
    IntBits(int val);
    int getBitAt(int i);
    int clearBitAt(int i);
    int setBitAt(int i);
    int updateBitAt(int i, int &newBit);
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
    return value & (1 << i) > 0 ? 1 : 0;
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
}

#endif