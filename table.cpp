#include "table.hpp"


//row method definitions

row::row(table& t,int i):
    t_ref(t),
    index(i),
    name(std::to_string(i)),
    row_size(t.c_n)
    {}

row::row(table& t,int i,const std::string& row_name):
    t_ref(t),
    index(i),
    name(row_name),
    row_size(t.c_n)
    {}

row::row(const row& r):t_ref(r.t_ref),index(r.index),name(r.name),row_size(r.row_size){}

entry& row::operator[](const std::string& collumn){
    return t_ref[collumn][index];
}

const entry& row::operator[](const std::string& collumn) const{
    return t_ref[collumn][index];
}

row& row::operator=(const entry& rhs){
    for(const auto& col:t_ref.cols)
        (*this)[col.first]=rhs;
    return *this;
}

row& row::operator=(const row& rhs){
    index=rhs.index;
    name=rhs.name;
    return *this;
}

row& row::operator=(const std::vector<std::pair<std::string,entry>> rhs){
    for(const auto& it:rhs)
        if(t_ref.cols.find(it.first)!=t_ref.cols.end())
            t_ref.cols[it.first][index]=it.second;
    return *this;
}

row row::operator+(const entry& rhs){
    row result=*this;
    for(const auto& col:t_ref.cols)
        result[col.first]+=rhs;
    return result;
}
row row::operator-(const entry& rhs){
    row result{*this};
    for(const auto& col:t_ref.cols)
        result[col.first]-=rhs;
    return result;
}
row row::operator*(const entry& rhs){
    row result{*this};
    for(const auto& col:t_ref.cols)
        result[col.first]*=rhs;
    return result;
}
row row::operator/(const entry& rhs){
    row result{*this};
    for(const auto& col:t_ref.cols)
        result[col.first]/=rhs;
    return result;
}

row& row::operator+=(const entry& rhs){
    for(auto it=begin();it!=end();++it)
        *it+=rhs;
    return *this;
}
row& row::operator-=(const entry& rhs){
    for(auto it=begin();it!=end();++it)
        *it-=rhs;
    return *this;
}
row& row::operator*=(const entry& rhs){
    for(auto it=begin();it!=end();++it)
        *it*=rhs;
    return *this;
}
row& row::operator/=(const entry& rhs){
    for(auto it=begin();it!=end();++it)
        *it/=rhs;
    return *this;
}


///getters and iterators row

std::vector<std::pair<std::string,entry>> row::get_row() const{
    std::vector<std::pair<std::string,entry>> result;
    for(auto& it:t_ref.cols)
        result.push_back(std::make_pair(it.first,it.second[index]));
    return result;
}


row::row_iterator row::begin(){
    std::vector<std::string> names;
    for(const auto& x:t_ref.cols){
        names.push_back(x.first);
        
    }
    return row_iterator(0,index,names,t_ref.cols);
}

row::row_iterator row::end(){
    std::vector<std::string> names;
    row_size=t_ref.c_n;
    for(const auto& x:t_ref.cols)
        names.push_back(x.first);
    return row_iterator(row_size,index,names,t_ref.cols);
}

const row::row_iterator row::begin() const {
    std::vector<std::string> names;
    for(const auto& x:t_ref.cols){
        names.push_back(x.first);

    }
    return row_iterator(0,index,names,t_ref.cols);
}

const row::row_iterator row::end() const {
    std::vector<std::string> names;
    for(const auto& x:t_ref.cols)
        names.push_back(x.first);
    return row_iterator(t_ref.c_n,index,names,t_ref.cols);
}

const row::row_iterator row::cbegin() const {
        std::vector<std::string> names;
        for(const auto& x:t_ref.cols){
            names.push_back(x.first);
        
        }
        return row_iterator(0,index,names,t_ref.cols); 
}

const row::row_iterator row::cend() const {
        std::vector<std::string> names;
        for(const auto& x:t_ref.cols)
            names.push_back(x.first);
        return row_iterator(t_ref.c_n,index,names,t_ref.cols);
}

//getters and setters row
int row::size() const {
    return row_size;
}

std::string row::r_name() const {
    return name;
}

//setters
void row::set_name(const std::string& n_name) {
    name = n_name;
}


//collumn method definitions

collumn::collumn():name(""){}

collumn::collumn(const std::string& col_name):name(col_name){
}

collumn::collumn(const collumn& r):name(r.name),entries(r.entries){}

entry& collumn::operator[](int index){
    return entries[index];
}

const entry& collumn::operator[](int index) const {
    return entries[index];
}

//     collumn =  ...

collumn& collumn::operator=(const collumn& rhs){
    entries=rhs.entries;
    return *this;
}

collumn& collumn::operator=(const entry& rhs){
    for(auto &e:entries)
        e=rhs;
    return *this;
}

collumn& collumn::operator+=(const entry& rhs){
    for(auto &e:entries)
        e+=rhs;
    return *this;
}
collumn& collumn::operator-=(const entry& rhs){
    for(auto &e:entries)
        e/=rhs;
    return *this;
}
collumn& collumn::operator*=(const entry& rhs){
    for(auto &e:entries)
        e/=rhs;
    return *this;
}
collumn& collumn::operator/=(const entry& rhs){
    for(auto &e:entries)
        e/=rhs;
    return *this;
}

//      collumn operators arithmetic

collumn collumn::operator+(const collumn& rhs) const{
    collumn result;
    unsigned i=0;
    while(i<entries.size() && i<rhs.entries.size()){
        result.entries.push_back(entries[i]+rhs.entries[i]);
    }
    return result;
}
collumn collumn::operator-(const collumn& rhs) const{
    collumn result{};
    unsigned i=0;
    while(i<entries.size() && i<rhs.entries.size()){
        result.entries.push_back(entries[i]-rhs.entries[i]);
    }
    return result;
}
collumn collumn::operator*(const collumn& rhs) const{
    collumn result;
    unsigned i=0;
    while(i<entries.size() && i<rhs.entries.size()){
        result.entries.push_back(entries[i]*rhs.entries[i]);
    }
    return result;
}
collumn collumn::operator/(const collumn& rhs) const{
    collumn result;
    unsigned i=0;
    while(i<entries.size() && i<rhs.entries.size()){
        result.entries.push_back(entries[i]/rhs.entries[i]);
    }
    return result;
}

//     collumn operator entry

collumn collumn::operator+(const entry& rhs) const{
    collumn result=*this;
    for(auto&e : result.entries)
        e+=rhs;
    return result;
}
collumn collumn::operator-(const entry& rhs) const{
    collumn result=*this;
    for(auto&e : result.entries)
        e-=rhs;
    return result;
}
collumn collumn::operator*(const entry& rhs) const{
    collumn result=*this;
    for(auto&e : result.entries)
        e*=rhs;
    return result;
}
collumn collumn::operator/(const entry& rhs) const{
    collumn result=*this;
    for(auto&e : result.entries)
        e/=rhs;
    return result;
}

//relational

bool collumn::operator>(const entry& rhs) const{
    for(const auto& e:entries)
        if((e>rhs) == false)
            return false;
    return true;
}
bool collumn::operator<(const entry& rhs) const{
    for(const auto& e:entries)
        if((e<rhs) == false)
            return false;
    return true;
}
bool collumn::operator==(const entry& rhs) const{
    for(const auto& e:entries)
        if((e==rhs) == false)
            return false;
    return true;
}
bool collumn::operator!=(const entry& rhs) const{
    for(const auto& e:entries)
        if((e!=rhs) == false)
            return false;
    return true;
}
bool collumn::operator>=(const entry& rhs) const{
    for(const auto& e:entries)
        if((e>=rhs) == false)
            return false;
    return true;
}
bool collumn::operator<=(const entry& rhs) const{
    for(const auto& e:entries)
        if((e<=rhs) == false)
            return false;
    return true;
}

int collumn::size() const {
    return entries.size();
}

//table definitions

table::table():c_n(0),r_n(0){}

table::table(const table& r){
    c_n=0;
    r_n=0;
    for(auto& it:r.cols)
        push(it.first);
    for(auto& it:r.rows)
        push_row(it.get_row());
}

table::table(int i,int j) {
    c_n=0;
    r_n=0;
    std::vector<std::string> attributes(j);
    std::vector<entry> cur_row;
    for(int k = 0; k<j; k++) {
        push("column_" + std::to_string(k));
        cur_row.push_back(entry());
    }
    for(int k = 0; k<i; k++) {
        push_row(cur_row);
    }
};

collumn& table::operator[](const std::string& collumn){
    return cols[collumn];
}

const collumn& table::operator[](const std::string& collumn) const {
    auto it = cols.find(collumn);
    return it->second;
}


table table::operator[](const std::vector<std::string>& collumns){
    table result;
    result.push(collumns);
    
    for(int i=0;i<r_n;i++){
        std::vector<entry> instance;
        
        for(const auto& col:collumns)
            instance.push_back(cols[col][i]);
        result.push_row(instance);
        result.rows[i].name=rows[i].name;
    }
    return result;
}

row& table::operator[](int row){
    return rows[row]; 
}

const row& table::operator[](int row) const {
    return rows[row];
}

table table::operator[](const std::vector<int>& rows_indexes){
    table result;
    for(const auto& col:cols)
        result.push(col.first);
    int i=0;
    for(auto row:rows_indexes){
        std::vector<entry> instance;
        for(const auto& col:result.cols)
            instance.push_back(cols[col.first][row]);
        result.push_row(instance);
        result.rows[i++].name=rows[row].name;
    }
    return result; 
}

//   table assignment operators

table& table::operator=(const table& rhs){
    cols=rhs.cols;
    rows=rhs.rows;
    c_n=rhs.c_n;
    r_n=rhs.r_n;
    return *this;
}

table& table::operator=(const entry& rhs){
    for(auto& col:cols)
        col.second=rhs;
    return *this;
}

table& table::operator+=(const entry& rhs){
    for(auto& col:cols)
        col.second+=rhs;
    return *this;
}
table& table::operator-=(const entry& rhs){
    for(auto& col:cols)
        col.second-=rhs;
    return *this;
}
table& table::operator*=(const entry& rhs){
    for(auto& col:cols)
        col.second*=rhs;
    return *this;
}
table& table::operator/=(const entry& rhs){
    for(auto& col:cols)
        col.second/=rhs;
    return *this;
}

//    table arithmetic operators

table table::operator+(const entry& rhs) const{
    table result=*this;
    return result+=rhs;
}
table table::operator-(const entry& rhs) const{
    table result=*this;
    return result-=rhs;
}
table table::operator*(const entry& rhs) const{
    table result=*this;
    return result*=rhs;
}
table table::operator/(const entry& rhs) const{
    table result=*this;
    return result/=rhs;
}

//    table relational methods

bool table::operator>(const entry& rhs) const{
    for(const auto& col:cols)
        if((col.second>rhs) == false)
            return false;
    return true;
}
bool table::operator<(const entry& rhs) const{
    for(const auto& col:cols)
        if((col.second<rhs) == false)
            return false;
    return true;
}
bool table::operator==(const entry& rhs) const{
    for(const auto& col:cols)
        if( (col.second==rhs) == false)
            return false;
    return true;
}
bool table::operator!=(const entry& rhs) const{
    for(const auto& col:cols)
        if( (col.second!=rhs) == false)
            return false;
    return true;
}
bool table::operator>=(const entry& rhs) const{
    for(const auto& col:cols)
        if( (col.second>=rhs) == false)
            return false;
    return true;
}
bool table::operator<=(const entry& rhs) const{
    for(const auto& col:cols)
        if( (col.second<=rhs) == false)
            return false;
    return true;
}

//    table push methods

void table::push(const std::string& name){
    cols[name]=collumn(name);
    cols[name].name=name;
    if(r_n > 0) {
        cols[name].entries.resize(r_n, entry("n/a"));
    }
    for(auto& x:rows)
        x.t_ref=*this;
    c_n++;
}


void table::push(const std::vector<std::string>& names){
    for(auto it=names.rbegin();it!=names.rend();it++)
        push(*it);
}

void table::push_row(){
    rows.push_back(row(*this,r_n));
    for(auto& col:cols)
        col.second.entries.push_back(entry());
    r_n++;
}

void table::push_row(const std::vector<entry>& new_row){
     unsigned i=0;
     rows.push_back(row(*this,r_n));
     for(auto& col:cols){
        if(i<new_row.size())
            col.second.entries.push_back(new_row[i++]);
        else
            col.second.entries.push_back(entry());
     }
     r_n++;
}

void table::push_row(const std::vector<std::pair<std::string,entry>>& new_row){
    push_row();
    for(const auto& pair:new_row)
        cols[pair.first][r_n-1]=pair.second;
}

//    table pop methods

void table::pop(const std::string& collumn){
    cols.erase(collumn);
    c_n--;
    if(c_n<=0){
        c_n=0;
        r_n=0;
    }
    for(auto &it : rows) 
        it.t_ref = *this;
}
void table::pop(const std::vector<std::string>& collumns){
    for(auto& c:collumns)
        cols.erase(c);
    c_n-=collumns.size();
    if(c_n<=0){
        c_n=0;
        r_n=0;
    }
}
void table::pop_row(){
    for(auto& col:cols)
        col.second.entries.pop_back();
    rows.pop_back();
    r_n--;
}
void table::pop_row(int row){
    for(auto& col:cols)
        col.second.entries.erase(col.second.entries.begin()+row);
    rows.erase(rows.begin()+row);
    r_n--;
    for(int i=0;i<r_n;i++)
        rows[i].index=i;
}
void table::pop_rows(const std::vector<int>& rows_indexes){
    int i=0;
    for(auto ind:rows_indexes) {
        pop_row(ind-(i++));
    }
}

//   table methods definitions

void table::swap_row(int i,int j){
    
    for(auto& col:cols)
        std::swap(col.second.entries[i],col.second.entries[j]);
    std::string k=rows[i].name;
    rows[i].name=rows[j].name;
    rows[j].name=k;
    
}

table& table::sort(const std::string& name,int order){
    std::vector<int> row_numbers(r_n);
    
    int i=0;
    std::generate(row_numbers.begin(),row_numbers.end(),[&i](){return i++;});
    std::vector<bool> help(r_n,false);

    std::sort(row_numbers.begin(),row_numbers.end(),[order,this,name](auto x,auto y){
        if(order==0)
            return cols[name][x]>=cols[name][y];
        else
            return cols[name][x]<=cols[name][y];
    });
    
    for(i=0;i<r_n;i++){
     if(!help[i]){
      swap_row(i,row_numbers[i]);
      help[row_numbers[i]]=true;
     }
    }
    return *this;
}

table table::cpy_sort(const std::string& name,int order) const {
    table result=*this;
    return result.sort(name,order);
}

std::vector<int> table::where(const std::string& collumn_name,std::function<bool(entry)> predicate){
    std::vector<int> result;
    int i=0;
    std::for_each(cols[collumn_name].cbegin(),cols[collumn_name].cend(),[&i,&result,predicate](const auto& x){
            if(predicate(x))
                result.push_back(i);
            i++;
        }
    );
    return result;
}

std::vector<int> table::where(std::function<bool(row)> predicate) const {
     std::vector<int> result;
     int i=0;
     std::for_each(rows.cbegin(),rows.cend(),[&i,&result,predicate](const auto& x){
        if(predicate(x))
                result.push_back(i);
            i++;
        }
    );
    return result;
}


//    table helper methods

int table::col_n() const{
   return c_n; 
}
int table::row_n() const{
    return r_n;
}

std::vector<std::string> table::col_names() const{
    std::vector<std::string> result;
    for(const auto& col:cols)
        result.push_back(col.first);
    return result;
}

int table::row_by_name(const std::string& name) const{
    for(int i=0;i<r_n;i++)
        if(rows[i].name==name)
            return i;
    return -1;
}

//  table set methods

void table::set_col_name(std::string original,std::string new_name){
    cols[original].name=new_name;
    auto nh=cols.extract(original);
    nh.key()=new_name;
    cols.insert(move(nh));
}

std::ostream& table::steam_print(std::ostream& o) const{
    
    std::vector<int> max_name_sizes;
    max_name_sizes.push_back(std::to_string(r_n).size());
    
    if(rows.size()>0){
        auto it=std::max_element(rows.begin(),rows.end(),[](auto x,auto y){return x.name.size()<y.name.size();});
        max_name_sizes.push_back(it->name.size());
    }
    
    for(const auto& col:cols){
        auto it=std::max_element(col.second.entries.begin(),col.second.entries.end(),[](auto x,auto y){
            return x.get_string().size()<y.get_string().size();});
        max_name_sizes.push_back(1+std::max( col.first.size()+3,it->get_string().size() ));
    }
    
    int header_length=std::accumulate(max_name_sizes.begin(),max_name_sizes.end(),0);

    std::string h;
    h.resize(max_name_sizes[0]+max_name_sizes[1]+2,' ');
    o<<h;
    
    int j=2;
    for(const auto& col:cols){
        std::string name=col.first;
        name.resize(max_name_sizes[j++]);
        o<<"| "<<name<<" ";
    }
    
    o<<std::endl;
    for(int i=0;i<header_length+6;i++)
        o<<"-";
    o<<std::endl;
    for(int i=0;i<r_n;i++){
        std::string r_name=rows[i].name;
        std::string r_ind=std::to_string(rows[i].index);
        r_ind.resize(max_name_sizes[0],' ');
        r_name.resize(max_name_sizes[1],' ');
        o<<r_ind<<" "<<r_name<<" |";
        int j=2;
        for(const auto& col:cols){
            std::string curr_n=col.second.entries[i].get_string();
            curr_n.resize(max_name_sizes[j++],' ');
            o<<curr_n;
        }
        o<<std::endl;
    }
    o<<std::endl;
    return o;
}

//out of class definitions

std::ostream& operator<<(std::ostream& o,const table& rhs){
    return rhs.steam_print(o);
}

#include<algorithm>
