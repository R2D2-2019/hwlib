/*
 * =====================================================================================
 *
 *       Filename:  hwlib-serial.hpp
 *
 *    Description:  uart (and usart) implementation in hwlib
 *
 *        Version:  1.0
 *        Created:  13-03-19 14:19:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

namespace hwlib {

struct uart_bus {
    pin_in  rx;
    pin_out tx;
    char port;
};

class uart_primitive {
protected:
    uart_bus &bus;
    unsigned int boud_rate;
public:
    uart_primitive(unsigned int boud_rate, uart_bus &bus):
        boud_rate(boud_rate),
        bus(bus)
    {}
    virtual void begin() = 0;
    virtual void unsigned int available() = 0;
    virtual bool send(char c) =0;
    virtual bool send(const uint8_t *data, size_t length) =0;
    virtual bool send(const hwlib::string<0> & str);
    virtual void uint8_t recieve() =0;
    virtual void is_initialized() =0;
    virtual void putc(char c) =0;
    virtual bool char_available() =0;
    virtual char getc() =0;
    ~uart_primitive();

    
    //    virtual void set_boud_rate(unsigned int new_boud_rate) =0;
//    virtual void set_bus(serial_bus &new_bus) =0;

};
/* /
class software_uart : uart_primitive {
public:
    software_uart(unsigned int boud_rate, uart_bus &bus);
    void begin() override;
    void available override

};*/ 

}
