#ifndef HWLIB_HWLIB_PIN_TEST_HPP
#define HWLIB_HWLIB_PIN_TEST_HPP

namespace hwlib {
/// A pin_in_out for testing purposes
    class pin_in_out_test : public pin_in_out {
    protected:
        bool value = false;
        bool is_input = true;

    public:
        void direction_set_input() override {
            is_input = true;
        }

        bool read() override {
            return value;
        }

        void refresh() override {}

        void direction_set_output() override {
            is_input = false;
        }

        void direction_flush() override {}

        void write( bool value ) override {
            this->value = value;
        }

        void flush() override {}

        bool in_input_direction() const {
            return is_input;
        }

        bool in_output_direction() const {
            return ! in_input_direction();
        }
    };

/// A pin_in for testing purposes
    class pin_in_test : public pin_in {
    protected:
        bool value = false;

    public:
        bool read() override {
            return value;
        }

        void set_value(bool value) {
            this->value = value;
        }
    };

/// A pin_out for testing purposes
    class pin_out_test : public pin_out {
    protected:
        bool value = false;

    public:
        void write( bool value ) override {
            this->value = value;
        }

        void flush() override {}

        bool get_value() const {
            return value;
        }
    };
    
 /// A pin_adc for testing purposes
 /// pin value starts default at 0 value can be set using the set_pin_value function
    class pin_adc_test : public adc {
    protected:
        adc_value_type pin_value = 0;
        
    public:
        pin_adc_test(): adc(12) {}
        
        adc_value_type read(){
            return pin_value;
        }
            
        void set_pin_value(adc_value_type new_value){
            // check max value since arduino due has an 12 bit adc max value is 4096
            if(new_value > 4096){
                new_value = 4096;
            }
            pin_value = new_value;
        }
        
        void refresh(){};//needs to be implemented because pure virtual base      
    };
    
};// namespace hwlib

#endif //HWLIB_HWLIB_PIN_TEST_HPP
