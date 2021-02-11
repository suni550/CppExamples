#ifndef DATAQUEUE_H
#define DATAQUEUE_H
#include "DataFrame.h"
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;


class DataQueue
{
public:
    DataQueue();
    virtual ~DataQueue();

    // function to insert an element at the rear of the queue
    void queueEnqueue(const uint8_t* constpData, unsigned int noOfBytes);

    // Function to remove an item from front of the queue.
    uint32_t dequeue(uint8_t* const pData, const unsigned int buffSize);
    unsigned int getUsedSize();
   
    DataFrame m_dataFrames[5];

    ///// testing array to ClassObject (DataFrame)
    void sendFrame(DataFrame* const pFrame);
    void sendData( uint8_t* pData, unsigned short bytes);

    static int testStaticMethod(int a, int b, int c);
    static int testStaticVar;

    int testFunOverLoad(int a, int b);
    int testFunOverLoad(float f1, float f2, float f3);
protected:

private:
    uint32_t m_buffSize;
   // uint32_t m_buffCapacity;
  //  uint8_t m_dataBuff[20];
    uint8_t m_InPos, m_OutPos; 
    static const uint32_t BUFF_SIZE = 5;
};

#endif // DATAQUEUE_H

