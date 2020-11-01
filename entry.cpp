#include "entry.hpp" 

//constructor definitions

entry::entry(){
    type=0;
    d_v=0;
    s_v="n/a";
}

entry::entry(const entry& e){
    type=e.type;
    d_v=e.d_v;
    s_v=e.s_v;
}

entry::entry(const double d){
    type=e_double;
    d_v=d;
    s_v="";
}

entry::entry(const std::string& s){
    if(s!="n/a"){
        type=e_string;
        d_v=0;
        s_v=s;
    }
    else {
       type=e_na;
        d_v=0;
        s_v=s; 
    }
}

entry::entry(const char*s){
    if(s!="n/a"){
        type=e_string;
        d_v=0;
        s_v=s;
    }
    else {
       type=e_na;
        d_v=0;
        s_v=s; 
    }
}

//unary operators
entry& entry::operator-(){
    if(type==e_double)
        d_v=-d_v;
    return *this;
}

entry& entry::operator++(){
    if(type==e_double)
        d_v++;
    return *this;
}

entry& entry::operator--(){
    if(type==e_double)
        d_v--;
    return *this;
}

entry entry::operator++(int){
    entry curr=*this;
    if(type==e_double)
        d_v++;
    return curr;
}

entry entry::operator--(int){
    entry curr=*this;
    if(type==e_double)
        d_v--;
    return curr;
}

//assignment

entry& entry::operator=(const entry& rhs){
    type=rhs.type;
    d_v=rhs.d_v;
    s_v=rhs.s_v;
    return *this;
}

entry& entry::operator+=(const entry& rhs){
    if(type==e_string && rhs.type==e_string)
        s_v+=rhs.s_v;
    if(type==e_double && rhs.type==e_double)
        d_v+=rhs.d_v;
    return *this;
}
entry& entry::operator-=(const entry& rhs){
    if(type==e_double && rhs.type==e_double)
        d_v-=rhs.d_v;
    return *this;
}
entry& entry::operator*=(const entry& rhs){
    if(type==e_double && rhs.type==e_double)
        d_v*=rhs.d_v;
    return *this;
}
entry& entry::operator/=(const entry& rhs){
    if(type==e_double && rhs.type==e_double)
        d_v*=rhs.d_v;
    return *this;
}

//relational operators

bool entry::operator>(const entry& rhs) const{
    if(type==e_string && rhs.type==e_string)
        return s_v>rhs.s_v;
    if(type==e_double && rhs.type==e_double)
        return d_v>rhs.d_v;
    return false;
}
bool entry::operator<(const entry& rhs) const{
    if(type==e_string && rhs.type==e_string)
        return s_v<rhs.s_v;
    if(type==e_double && rhs.type==e_double)
        return d_v<rhs.d_v;
    return false;
}
bool entry::operator==(const entry& rhs) const{
    if(type==e_string && rhs.type==e_string)
        return s_v==rhs.s_v;
    if(type==e_double && rhs.type==e_double)
        return d_v==rhs.d_v;
    return false;
}
bool entry::operator!=(const entry& rhs) const{
    if(type==e_string && rhs.type==e_string)
        return s_v!=rhs.s_v;
    if(type==e_double && rhs.type==e_double)
        return d_v!=rhs.d_v;
    return false;
}
bool entry::operator>=(const entry& rhs) const{
   if(type==e_string && rhs.type==e_string)
        return s_v>=rhs.s_v;
    if(type==e_double && rhs.type==e_double)
        return d_v>=rhs.d_v;
    return false; 
}
bool entry::operator<=(const entry& rhs) const{
    if(type==e_string && rhs.type==e_string)
        return s_v<=rhs.s_v;
    if(type==e_double && rhs.type==e_double)
        return d_v<=rhs.d_v;
    return false;
}

//arithmetic operators

entry entry::operator+(const entry& rhs) const{
    entry curr=*this;
    if(curr.type!=e_string && rhs.type==e_string)
        return curr;
    if(curr.type==e_string && rhs.type!=e_string)
        return rhs;
    if(curr.type==e_string && rhs.type==e_string)
        curr.s_v+=rhs.s_v;
    if(curr.type==e_double && rhs.type==e_double)
        curr.d_v+=rhs.d_v;
    return curr;
}
entry entry::operator-(const entry& rhs) const{
    entry curr=*this;
    if(curr.type!=e_string && rhs.type==e_string)
        return curr;
    if(curr.type==e_string && rhs.type!=e_string)
        return rhs;
    if(curr.type==e_double && rhs.type==e_double)
        curr.d_v-=rhs.d_v;
    return curr;
}
entry entry::operator/(const entry& rhs) const{
    entry curr=*this;
    if(curr.type!=e_string && rhs.type==e_string)
        return curr;
    if(curr.type==e_string && rhs.type!=e_string)
        return rhs;
    if(curr.type==e_double && rhs.type==e_double)
        curr.d_v/=rhs.d_v;
    return curr;
}
entry entry::operator*(const entry& rhs) const{
    entry curr=*this;
    if(curr.type!=e_string && rhs.type==e_string)
        return curr;
    if(curr.type==e_string && rhs.type!=e_string)
        return rhs;
    if(curr.type==e_double && rhs.type==e_double)
        curr.d_v*=rhs.d_v;
    return curr;
}

//getters
bool entry::is_cast_valid(){
    if(type==e_string){
            try{
                std::string::size_type sz;
                std::stod (s_v,&sz);
                return true;
            } catch(std::invalid_argument){
                return false;
            }
    }
    if(type==e_double)
        return true;
    //for n/a
    return false;
}

double entry::get_double() const{
        if(type==e_string){
            try{
                std::string::size_type sz;
                double curr = std::stod (s_v,&sz);
                return curr;
            } catch(std::invalid_argument){
                std::cout<<"string can't be casted to double"<<std::endl;
                return 0.0;
            }
        }
        if(type==e_double)
            return d_v;
        return 0.0;
}

std::string entry::get_string() const{
        if(type==e_double){
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << d_v;
            return stream.str();
        }
        if(type==e_string || type==e_na)
            return s_v;
        return "";
}

bool entry::is_nan() const{
    if(type==e_na && s_v=="n/a")
        return true;
    return false;
}

//conversion


entry& entry::to_double(){
    d_v=get_double();
    type=e_double;
    return *this;
}

entry& entry::to_string(){
    s_v=get_string();
    type=e_string;
    return *this;
}

//ostream operator

std::ostream& entry::priv_print(std::ostream& o) const{
    if(type==e_na)
        return o<<"n/a";
    if(type==e_double)
        return o<<d_v;
    if(type==e_string)
        return o<<s_v;
    return o<<"";
}

std::ostream& operator<<(std::ostream& o,const entry& rhs){
    return rhs.priv_print(o);
}


