//
// Created by janek on 21.05.2023.
//

#ifndef ZAD8COMMANDSPARSER_DLASTUDENTOW_COMPLEXOBJECT_H
#define ZAD8COMMANDSPARSER_DLASTUDENTOW_COMPLEXOBJECT_H
#include "object.h"
#include <complex>
#include <ostream>

class ComplexObject : public Object {
    std::complex<double> number_;
public:
    std::complex<double> number() {return number_;};
    explicit ComplexObject(std::complex<double> number): number_(number) {};

    explicit ComplexObject(std::string &valueString) {

        auto minusPos = valueString.find('-');
        size_t pos = valueString.find('+') != std::string::npos ? valueString.find('+') : minusPos;
        size_t iPos = valueString.find('i');
        int multiplier = 1;
        if (minusPos!=std::string::npos) multiplier = -1;
        if (pos != std::string::npos) {
            double realPart = std::stod(valueString.substr(0, pos));
            double imgPart = std::stod(valueString.substr(pos+1));
            number_ = std::complex(realPart, multiplier * imgPart);
        }
        else if (iPos!=std::string::npos && iPos>0) {
            number_ = std::complex(0.0, multiplier * std::stod(valueString.substr(0, valueString.length()-1)));
        }
        else if (iPos==0) {
            number_ = std::complex(0.0, 1.0);
        }
        else {
            number_ = std::complex(std::stod(valueString), 0.0);
        }
    }

    bool operator==(const Object &obj) const override {
        try {
            ComplexObject that = dynamic_cast<const ComplexObject &>(obj);
            return this->number_ == that.number_;
        }
        catch (std::bad_cast& e) {
            return false;
        }
    }
    Object* clone() const override
    {
        return new ComplexObject(*this);
    }

    void print(std::ostream &os) const override {
        os << number_.real();
        if (number_.imag()!=0.0 && number_.imag()>0) os << '+' << number_.imag() << 'i';
        else if (number_.imag()!=0.0) os << number_.imag() << 'i';
    }

    std::string numberInString() const {
        std::string result;
        result += std::to_string(int(number_.real()));
        if (number_.imag()!=0.0 && number_.imag()>0) result += '+' + std::to_string(int(number_.imag())) + 'i';
        else if (number_.imag()!=0.0) result += std::to_string(int(number_.imag())) + 'i';
        return result;
    }
    std::string getType() override {
        return "ComplexObject";
    }

    void mul(int x) override {
        number_ *= x;
    }
};


#endif //ZAD8COMMANDSPARSER_DLASTUDENTOW_COMPLEXOBJECT_H
