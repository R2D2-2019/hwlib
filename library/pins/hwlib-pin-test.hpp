#ifndef HWLIB_HWLIB_PIN_TEST_HPP
#define HWLIB_HWLIB_PIN_TEST_HPP

#include "hwlib-pin.hpp"

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
}

#endif //HWLIB_HWLIB_PIN_TEST_HPP
