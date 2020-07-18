#ifndef COMPLETE_STRING_INCLUDED_CPP
#define COMPLETE_STRING_INCLUDED_CPP

namespace complete_string
{
string::string(){
	this->c = new char[1];
	this->s = 0;
	this->r = 1;
}
string::~string(){
	delete[] this->c;
}
string::string(char c){
	this->c = new char[1];
	this->s = 1;
	this->r = 1;
	this->c[0] = c;
}
string::string(const char* cc){
	size_t index=0;
	while(cc[index++]){
	}
	this->c = new char[--index];
	this->r = index;
	this->s = index;
	for(size_t i=0; i<index; i++){
		this->c[i] = cc[i];
	}
}
string::string(const string& str){
	this->c = new char[str.s];
	this->s = str.s;
	this->r = str.s;
	for(size_t i=0; i<str.s; i++){
		this->c[i] = str.c[i];
	}
}
string::string(string&& str):c(nullptr), s(0), r(0){
	this->c = str.c;
	this->s = str.s;
	this->r = str.r;
	
	str.c = nullptr;
	str.s = 0;
	str.r = 0;
}
void string::reserve(size_t new_size){
	char *str_temp = this->c;
	this->c = new char[new_size];
	this->r = new_size;
	if(this->s <= new_size){
		for(size_t i=0; i<this->s; i++){
			this->c[i] = str_temp[i];
		}
	}else{
		for(size_t i=0; i<new_size; i++){
			this->c[i] = str_temp[i];
		}
		this->s = new_size;
	}
}
void string::resize(size_t new_size){
	if(new_size>this->r){
		this->reserve(new_size);
	}
	if(new_size<=this->s){
		this->s = new_size;
	}else{
		for(size_t i=this->s; i<new_size; i++){
			this->c = 0;
		}
		this->s = new_size;
	}
}
string &string::operator =(char c){
	return *this = string(c);
}
string &string::operator =(const char* cc){
	return *this = string(cc);
}
string &string::operator =(const string& str){
	if(this->r<str.s){
		this->reserve(str.s);
	}
	for(size_t i=0; i<str.s; i++){
		this->c[i] = str.c[i];
	}
	this->s = str.s;
	return *this;
}
string &string::operator =(string &&str){
	if(this!=&str){
		this->c = str.c;
		this->s = str.s;
		this->r = str.r;
		
		str.c = nullptr;
		str.r = 0;
		str.s = 0;
	}
	return *this;
}
string &string::operator +=(const string &str){
	size_t tmax = this->s+str.s;
	if(tmax>this->r){
		this->reserve(tmax);
	}
	for(size_t i=this->s; i<tmax; i++){
		this->c[i] = str.c[i];
	}
	this->s = tmax;
	return *this;
}
string &string::operator *=(size_t x){
	size_t tmax = this->s*x;
	if(this->r<(tmax)){
		this->reserve(tmax);
	}
	for(size_t i=this->s; i<tmax; i++){
		this->c[i] = this->c[i%this->s];
	}
	this->s = tmax;
	return *this;
}
string string::operator +(const string& str) const{
	string s(*this);
	return s += str;
}
string string::operator *(size_t x) const{
	string s(*this);
	return s *= x;
}
size_t string::size() const{
	return this->s;
}
size_t string::reserved()const{
	return this->r;
}
const char* string::c_str() const{
	char* cstr = new char[this->s+1];
	cstr[this->s] = 0;
	for(size_t i=0; i<this->s; i++){
		cstr[i] = this->c[i];
	}
	return cstr;
}
std::istream &operator >>(std::istream &is, string &str){
	const size_t SIZE = 1024*1024*16;
	char* a = new char[SIZE];
	is.get(a, SIZE);
	str = a;
	delete[] a;
	return is;
}
std::ostream &operator <<(std::ostream &os, const string str){
	for(size_t i=0; i<str.s; i++){
		os << str.c[i];
	}
	return os;
}
size_t string::hash() const{
	return std::hash<const char*>()(this->c_str());
}
char &string::operator [](size_t index){
	return this->c[index];
}
}

#endif