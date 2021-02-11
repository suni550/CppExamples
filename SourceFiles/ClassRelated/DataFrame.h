// (c) IMT - Information Management Technology AG, CH-9470 Buchs, www.imt.ch.
// SW guideline: Technote Coding Guidelines Ver. 1.6

#ifndef DATAFRAME_H
#define DATAFRAME_H

// Must be very first include
//#include <Imt.Base.Core.Platform/Platform.h>
#include<stdint.h>

// Project includes
//#include "RemotingConfig.h"

namespace imt {
namespace base {
namespace lib {
namespace remoting {

/**
 * Representation of a package of data that gets transmitted e.g. over a serial connection.
 *
 * @author marxer@imt.ch
 */
class DataFrame {

public:
    /**
     * Constructor.
     */
    explicit DataFrame(void);

    /**
     * Destructor.
     */
    virtual ~DataFrame(void);
    /**
     *Initiae DataFrame with another DataFrame
     * @param source The DataFrame to initiate this
     */
    void init(const DataFrame& source);

    /**
     * Returns the current size of the data frame.
     * @return current size of the data frame
     */
    uint32_t getSize(void) const {
        return m_size;
    }

    /**
     * Returns the maximum capacity of this data frame.
     * @return maximum capacity of this data frame
     */
    uint32_t getCapacity(void) const {
        return m_capacity;
    }

    /**
     * Clears the content of this DataFrame.
     */
    void clear(void);

    /**
     * Returns a pointer to the first character of the frame.
     * @return pointer to the first character of the frame
     */
    const uint8_t* getData(void) const;

    /**
     * Appends a character at the end of this data frame.
     * @param ch The character to add
     */
    void append(uint8_t ch);

    void appendCid(unsigned short cid);
    //@{
// Removes the cid from this data frame.
//@}
    bool removeCid(unsigned short& cid);

    //@{
// Removes a character from the end of this data frame.
// @return false if buffer was empty.
//@}
    bool remove(unsigned char& ch);

    /**
     * Sets data.
     * @param pData Pointer to the data buffer to be set
     * @param dataSize Size of the data buffer
     */
    void setData(const uint8_t* const pData, uint32_t dataSize);

    /**
     * Removes a character from the end of this data frame.
     * @param ch The character to remove
     * @return false if buffer was empty.
     */
    bool removeCharacter(uint8_t& ch); //lint !e1960 Method name

    /**
     * Calculates and appends a 2 byte crc.
     * @param initialCrcValue seed value for the CRC16 calculation
     */
    void appendCRC16(const uint16_t initialCrcValue = 0xffffU);

    /**
     * Checks if the crc 16 is valid.
     * @param initialCrcValue seed value for the CRC16 calculation
     * @return bool True if the check succeeded, false otherwise
     */
    bool checkCRC16(const uint16_t initialCrcValue = 0xffffU) const;

    /**
     * Checks and removes a 2 byte crc.
     * @return False if size of data frame is too small
     */
    bool removeCRC16(void);
    uint8_t highByte(const uint16_t word);
    uint8_t lowByte(const uint16_t word);
    uint16_t makeWord(const uint8_t lowerByte, const uint8_t upperByte);


    /**
     * Provide the private copy constructor so the compiler does not generate the default one.
     */
    DataFrame(const DataFrame&);

    /**
     * Provide the private assignment operator so the compiler does not generate the default one.
     */
    DataFrame& operator=(const DataFrame&);
//private:
    //// Helpers
    void ensureIsNotFull(void) const;
    void ensureTargetCapacity(const uint32_t targetCapacity) const;
    void appendWord(unsigned short word);

    uint32_t m_size;
    uint32_t m_capacity;
    unsigned char m_data[100];
    unsigned char* m_pData;

    static int DATA_FRAME_SIZE; 
};

} // namespace remoting
} // namespace lib
} // namespace base
} // namespace imt
using imt::base::lib::remoting::DataFrame;

#endif // #ifndef DATAFRAME_H
