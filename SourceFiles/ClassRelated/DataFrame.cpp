// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Ver. 1.6

// Project includes
#include "DataFrame.h"

#include<memory.h>

namespace imt {
namespace base {
namespace lib {
namespace remoting {
   
// int DataFrame::DATA_FRAME_SIZE = 100;

DataFrame::DataFrame(void) :
    m_size(0U),
    m_capacity(100)
{
    memset(m_data, 0, static_cast<size_t>(100));
}

DataFrame::~DataFrame(void) {
}

void DataFrame::init(const DataFrame& source) {
    setData(source.getData(), source.getSize());
}

void DataFrame::clear(void) {
    m_size = 0U;
}

const uint8_t* DataFrame::getData(void) const {
    return m_data;
} //lint !e1763

void DataFrame::append(const uint8_t ch) {
    ensureIsNotFull();
    m_data[m_size] = ch;
    m_size++;
}

void DataFrame::setData(const uint8_t* const pData, const uint32_t dataSize) {
  //  m_size = 0U;
    ensureTargetCapacity(dataSize);
    for (unsigned int i = 0; i < dataSize; ++i) {
        m_data[i] = *(pData + i);
    }
    //memcpy(m_data, pData, dataSize);
    m_size = dataSize;
}

bool DataFrame::removeCharacter(uint8_t& ch) {
    if (m_size == 0U) {
        return false;
    }
    m_size--;
    ch = m_data[m_size];
    return true;
}

void DataFrame::appendCRC16(const uint16_t initialCrcValue) {
 //   const uint16_t crc = Crc::crc16(m_data, m_size, initialCrcValue, 0U, false);
  //  append(ByteWordUtil::highByte(crc));
  //  append(ByteWordUtil::lowByte(crc));
}

void DataFrame::appendCid(unsigned short cid) {
    appendWord(cid);
}

bool DataFrame::removeCid(unsigned short& cid) {
    unsigned char lowByte;
    unsigned char highByte;
    if (!remove(lowByte) || !remove(highByte)) {
        return false;
    }
     cid = makeWord(lowByte, highByte);
    return true;
}

bool DataFrame::remove(unsigned char& ch) {
    if (m_size == 0) {
        return false;
    }
    --m_size;
    ch = m_pData[m_size];
    return true;
}

bool DataFrame::checkCRC16(const uint16_t initialCrcValue) const {
#if 0
    if (m_size < 2U) {
        return false;
    }
  //  const uint16_t dataCrc = Crc::crc16(m_data, m_size - 2U, initialCrcValue, 0U, false);
    uint16_t appendedCrc;
  //  ByteWordUtil::read((m_data + m_size) - 2, appendedCrc); //lint !e1960 Pointer arithmetic reviewed
    if (dataCrc == appendedCrc) {
        return true;
    }
#endif
    return false;
}

bool DataFrame::removeCRC16(void) {
    if (m_size < 2U) {
        return false;
    }
    m_size -= 2U;
    return true;
}

void DataFrame::ensureIsNotFull(void) const {
    if (m_size < m_capacity) {
        // frame is not full, so we have nothing to do
        return;
    }
   // ASSERT_DEBUG1(false, ("buffer is full"));
}

void DataFrame::ensureTargetCapacity(const uint32_t targetCapacity) const {
    if (m_capacity >= targetCapacity) {
        // frame is bigger than the requested target capacity, so
        // we have nothing to do
        return;
    }
   // ASSERT_DEBUG1(false, ("buffer has not enough space left"));
}

void DataFrame::appendWord(unsigned short word) {
    ensureIsNotFull();
    m_pData[m_size + 0] = highByte(word);
    m_pData[m_size + 1] = lowByte(word);
    m_size += 2;
}

uint8_t DataFrame::highByte(const uint16_t word) {
    return static_cast<uint8_t>(word >> 8U);
}

uint8_t DataFrame::lowByte(const uint16_t word) {
    return static_cast<uint8_t>(word);
}

uint16_t DataFrame::makeWord(const uint8_t lowerByte, const uint8_t upperByte) {
    return static_cast<uint16_t>(static_cast<uint32_t>(lowerByte) | (static_cast<uint32_t>(upperByte) << 8U));
}

} // namespace remoting
} // namespace lib
} // namespace base
} // namespace imt
