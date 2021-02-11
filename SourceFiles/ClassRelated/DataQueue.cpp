#include "DataQueue.h"
#include<memory.h>
#include<iostream>

using namespace std;

int DataQueue::testStaticVar = 9;

DataQueue::DataQueue():
	m_buffSize(0),
	m_InPos(0),
	m_OutPos(0)
{
	//ctor
}

DataQueue::~DataQueue()
{
	//dtor
}

void DataQueue::queueEnqueue(const uint8_t* pData, unsigned int noOfBytes) {

	m_dataFrames[m_InPos].setData(pData, noOfBytes);
	//memcpy(m_dataBuff, pData, noOfBytes);
	m_InPos = (m_InPos + 1) % BUFF_SIZE; 
	//m_buffSize = m_buffSize + noOfBytes;
	cout << "EnqueEnded" << endl;
}

unsigned int DataQueue::getUsedSize() {
	unsigned int retVal = m_InPos >= m_OutPos ? (m_InPos - m_OutPos) : (BUFF_SIZE - (m_OutPos - m_InPos));
	return retVal;
}

uint32_t DataQueue::dequeue(uint8_t* const pData, unsigned int buffSize) {

	uint32_t dataToCopy{};
	cout << "deQueue started" << endl;
	 if(getUsedSize() > 0U) {
		dataToCopy = (buffSize <= m_dataFrames[m_OutPos].getSize()) ? buffSize : m_dataFrames[m_OutPos].getSize();
		memcpy(pData, m_dataFrames[m_OutPos].getData(), dataToCopy);
		m_OutPos = (m_OutPos + 1U) % BUFF_SIZE;
	}
	// m_buffSize = m_buffSize - buffSize;
	 cout << "deQueue ended" << endl;
	return dataToCopy;
}

void DataQueue::sendFrame(DataFrame* const pFrame) {

}
void DataQueue::sendData(uint8_t* pData, unsigned short bytes) {

	uint8_t tmp[10]; 
	for (int i = 0; i < 10; ++i) {
		tmp[i] = *(pData + i);
	}
}

int DataQueue::testStaticMethod(int a, int b, int c)
{
	cout << "+++TestStaticVar =" << testStaticVar << endl;
	testStaticVar = testStaticVar + 99;
	cout << "***TestStaticVar =" << testStaticVar<<endl;
	return (a+b+c);
}

int DataQueue::testFunOverLoad(int a, int b) {
	return (a + b);
}
int DataQueue::testFunOverLoad(float f1, float f2, float f3) {
	return (f1 + f2 + f3);
}