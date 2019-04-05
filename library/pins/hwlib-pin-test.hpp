#ifndef HWLIB_HWLIB_PIN_TEST_HPP
#define HWLIB_HWLIB_PIN_TEST_HPP

#include "hwlib-pin.hpp"

namespace hwlib {
/// A pin_in_out for testing purposes
class pin_in_out_test : public pin_in_out {
protected:
    bool value = false;
    bool is_input = true;

    buffering buf = buffering::unbuffered;

public:
    void set( bool value, buffering buf = buffering::unbuffered ) override {
        this->value = value;
        this->buf = buf;
    }

    bool get( buffering buf = buffering::unbuffered ) override {
        this->buf = buf;

        return value;
    }

    void direction_set_input() override {
        is_input = true;
    }

    void direction_set_output() override {
        is_input = false;
    }

    bool in_input_direction() const {
        return is_input;
    }

    bool in_output_direction() const {
        return ! in_input_direction();
    }

    buffering buffered_with() const {
        return buf;
    }
};

/// A pin_in for testing purposes
class pin_in_test : public pin_in {
protected:
    bool value = false;

    buffering buf = buffering::unbuffered;

public:
    bool get( buffering buf = buffering::unbuffered ) override {
        this->buf = buf;

        return value;
    }

    void set_value(bool value) {
        this->value = value;
    }

    buffering buffered_with() const {
        return buf;
    }
};

/// A pin_out for testing purposes
class pin_out_test : public pin_out {
protected:
    bool value = false;

    buffering buf = buffering::unbuffered;

public:
    void set( bool value, buffering buf = buffering::unbuffered ) override {
        this->value = value;
        this->buf = buf;
    }

    bool get_value() const {
        return value;
    }

    buffering buffered_with() const {
        return buf;
    }
};
}

#endif //HWLIB_HWLIB_PIN_TEST_HPP
