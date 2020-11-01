#ifndef table_hpp
#define table_hpp

#include "entry.hpp"

#include<unordered_map>
#include<vector>

#include<algorithm>
#include<numeric>

#include <functional>

class table;


class collumn{
public:
    //constructors
    collumn();
    collumn(const collumn& r);
    explicit collumn(const std::string& col_name);
    
    //operators
    entry& operator[](int index);
    const entry& operator[](int index) const;

    collumn& operator=(const collumn& rhs);
    collumn& operator=(const entry& rhs);
    
    collumn& operator+=(const entry& rhs);
    collumn& operator-=(const entry& rhs);
    collumn& operator*=(const entry& rhs);
    collumn& operator/=(const entry& rhs);
    
    
    //arithmetic
    collumn operator+(const entry& rhs) const;
    collumn operator-(const entry& rhs) const;
    collumn operator*(const entry& rhs) const;
    collumn operator/(const entry& rhs) const;
    
    
    collumn operator+(const collumn& rhs) const;
    collumn operator-(const collumn& rhs) const;
    collumn operator*(const collumn& rhs) const;
    collumn operator/(const collumn& rhs) const;
    
    //relational
    bool operator>(const entry& rhs) const;
    bool operator<(const entry& rhs) const;
    bool operator==(const entry& rhs) const;
    bool operator!=(const entry& rhs) const;
    bool operator>=(const entry& rhs) const;
    bool operator<=(const entry& rhs) const;
    
    //iterators
    std::vector<entry>::iterator begin() { return entries.begin(); }
    std::vector<entry>::iterator end()   { return entries.end();   }
    
    std::vector<entry>::const_iterator begin() const { return entries.begin(); }
    std::vector<entry>::const_iterator end()  const { return entries.end();   }
    
    std::vector<entry>::const_iterator cbegin() const { return entries.cbegin(); }
    std::vector<entry>::const_iterator cend()  const { return entries.cend();   }

    //getters
    int size() const;
    
private:
    //list of all entries in collumn
    std::string name;
    std::vector<entry> entries;
    friend class table;
};

class row{
public:
    entry& operator[](const std::string& collumn);
    const entry& operator[](const std::string& collumn) const;
    row(const  row& r);

    row& operator=(const entry& rhs);
    row& operator=(const row& rhs);
    row& operator=(const std::vector<std::pair<std::string,entry>> rhs);
        
    row operator+(const entry& rhs);
    row operator-(const entry& rhs);
    row operator*(const entry& rhs);
    row operator/(const entry& rhs);

    row& operator+=(const entry& rhs);
    row& operator-=(const entry& rhs);
    row& operator*=(const entry& rhs);
    row& operator/=(const entry& rhs);
    
    std::vector<std::pair<std::string,entry>> get_row() const;
    
    //sluzi da bi se omogucilo iteriranje kroz red
    class row_iterator{
    public:
        row_iterator(int j,int ind,const std::vector<std::string>& c_names,std::unordered_map<std::string,collumn>& r):
            i(j),index(ind),col_names(c_names),ref_col(r)
            {}
        
        row_iterator& operator++(){
            i++;
            return *this;
        }
        
        bool operator!=(const row_iterator& rhs) const{
            return i!=rhs.i && index==rhs.index;
        }
        
        entry& operator*(){
            return ref_col[col_names[i]][index];
        }

        const entry& operator*() const {
            return ref_col[col_names[i]][index];
        }
        
        int i=0;
        int index;
        std::vector<std::string> col_names;
        std::unordered_map<std::string,collumn>& ref_col;
    };
    
    row_iterator begin();
    
    row_iterator end();
    const row_iterator begin() const;

    const row_iterator end() const;
    const row_iterator cbegin() const;
    
    const row_iterator cend() const;
    //getters

    int size() const;

    std::string r_name() const;

    //setters
    void set_name(const std::string& n_name);
    
private:
    row(table& t,int i);
    row(table& t,int i,const std::string& row_name);
    
    table& t_ref;
    int index;
    std::string name;
    int row_size;
    
    friend class table;
};

class table{
public:
    //constructors
    table();
    table(const table& r);
    table(int i,int j);

    table& operator=(const table& rhs);
    
    //indexing operators for collumns [strings]
    collumn& operator[](const std::string& collumn);
    table operator[](const std::vector<std::string>& collumns);
    const collumn& operator[](const std::string& collumn) const;
    
    //indexing operators for collumns [ints]
    row& operator[](int row);
    table operator[](const std::vector<int>& rows_indexes);
    const row& operator[](int row) const;
    
    //assignment operators
    table& operator=(const entry& rhs);
    
    table& operator+=(const entry& rhs);
    table& operator-=(const entry& rhs);
    table& operator*=(const entry& rhs);
    table& operator/=(const entry& rhs);
    
    //arithmetic operators
    
    table operator+(const entry& rhs) const;
    table operator-(const entry& rhs) const;
    table operator*(const entry& rhs) const;
    table operator/(const entry& rhs) const;
    
    //relational operators
    bool operator>(const entry& rhs) const;
    bool operator<(const entry& rhs) const;
    bool operator==(const entry& rhs) const;
    bool operator!=(const entry& rhs) const;
    bool operator>=(const entry& rhs) const;
    bool operator<=(const entry& rhs) const;
    
    
    //pushing methods
    void push(const std::string& name);
    void push(const std::vector<std::string>& names);
    void push_row();
    void push_row(const std::vector<entry>& new_row);
    void push_row(const std::vector<std::pair<std::string,entry>>& new_row);

    //poping methods
    void pop(const std::string& collumn);
    void pop(const std::vector<std::string>& collumns);
    void pop_row();
    void pop_row(int row);
    void pop_rows(const std::vector<int>& rows_indexes);

    //table methods
    void swap_row(int i,int j);
    //sorts rows by collumn on given order : 0 ascending , 1 descending
    table& sort(const std::string& name,int order);
    table cpy_sort(const std::string& name,int order) const;
    //returns row indexes that satisfies passed predicate for given collumn name
    std::vector<int> where(std::function<bool(row)> predicate) const;
    std::vector<int> where(const std::string& collumn_name,std::function<bool(entry)> predicate);
    
    //getters
    int col_n() const;
    int row_n() const;
    std::vector<std::string> col_names() const;

    int row_by_name(const std::string& name) const;
    
    void set_col_name(std::string original,std::string new_name);
    
    std::ostream& steam_print(std::ostream& o) const;
    
private:
    int c_n;
    int r_n;
    //maps collumn name to one collumn
    std::unordered_map<std::string,collumn> cols;
    //vector of helper class row
    std::vector<row> rows;
    
    friend class row;
};

std::ostream& operator<<(std::ostream& o,const table& rhs);

#endif
