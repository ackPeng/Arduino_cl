#ifndef _I2CDEV_CORE_H_
#define _I2CDEV_CORE_H_

/*
    IIC硬件抽象层，用于管理硬件IIC与软件IIC，并给外部提供统一的函数指针接口，用于外部调用不同的IIC总线
*/


#include <iostream>
#include <vector>
#include <memory>
#include <string>

class IICInterface {
public:
    virtual ~IICInterface() = default;

    virtual std::string getName() const = 0;

    virtual void begin(void);
    virtual void end(void);
    virtual void beginTransmission(uint8_t address);
    virtual void beginTransmission(int address);
    virtual uint8_t endTransmission(uint8_t sendStop);
    virtual uint8_t endTransmission(void);

    virtual size_t write(uint8_t data);
    virtual size_t write(const uint8_t *data, size_t quantity);

    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop);
    virtual uint8_t requestFrom(int address, int quantity, int sendStop);
    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity);
    virtual uint8_t requestFrom(int address, int quantity);

    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);

};




#endif