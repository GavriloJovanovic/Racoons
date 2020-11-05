#ifndef entry_hpp
#define entry_hpp

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#define e_na 0
#define e_double 1
#define e_string 2


class entry{
public:
    //constructors
    entry();
    entry(const entry& e);
    entry(const double d);
    entry(const std::string& s);
    explicit entry(const char*s);
    //unary operators
    entry& operator-();
    
    entry& operator++();
    entry& operator--();
    entry operator++(int);
    entry operator--(int);
    
    //getters
    double get_double() const;
    std::string get_string() const;
    
    //assignment operators
    entry& operator=(const entry& rhs);    
    entry& operator+=(const entry& rhs);
    entry& operator-=(const entry& rhs);
    entry& operator*=(const entry& rhs);
    entry& operator/=(const entry& rhs);
    
    //relational operators
    bool operator>(const entry& rhs) const;
    bool operator<(const entry& rhs) const;
    bool operator==(const entry& rhs) const;
    bool operator!=(const entry& rhs) const;
    bool operator>=(const entry& rhs) const;
    bool operator<=(const entry& rhs) const;
    
    //arithmetic operators
    entry operator+(const entry& rhs) const;
    entry operator-(const entry& rhs) const;
    entry operator/(const entry& rhs) const;
    entry operator*(const entry& rhs) const;
                
    //conversion
    entry& to_double();
    entry& to_string();
    
    //is conversion to double from string valid
    bool is_cast_valid();
    
    operator double() const{
        return get_double();
    }
    
    bool is_nan() const;
        
    friend std::ostream& operator<<(std::ostream& o,const entry& rhs);
            
private:
    
    std::string s_v;
    double d_v;
    int type;
    
    std::ostream& priv_print(std::ostream& o) const;
    
};

std::ostream& operator<<(std::ostream& o,const entry& rhs);


#endif
