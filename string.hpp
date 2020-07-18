#ifndef COMPLETE_STRING_INCLUDED_HPP
#define COMPLETE_STRING_INCLUDED_HPP

#include <algorithm> //std::hash //std::hash
#include <istream>
#include <ostream>

namespace complete_string
{
class string
{
	char *c; //string
	size_t s;   //size
	size_t r;   //reserve

  public:
	string();
	~string();
	string(char);
	string(const char *);
	string(const string &);
	//mov
	string(string &&);
	
	void reserve(size_t);
	void resize(size_t);
	
	//assignment
	string &operator =(char);
	string &operator =(const char*);
	string &operator =(const string&);
	//mov
	string &operator =(string&&);
	
	string &operator +=(const string&);
	string &operator *=(size_t);
	
	string operator +(const string&) const;
	string operator *(size_t) const;
	
	size_t size() const;
	size_t reserved() const;
	const char* c_str() const;
	char* data(){return this->c;}
	friend std::istream &operator >>(std::istream&, string&);
	friend std::ostream &operator <<(std::ostream&, const string);
	size_t hash() const;
	char &operator [](size_t);
	
	//new
	//bool operator ==(const string&) const;
//	bool operator !=(const string&) const;
//	bool operator >=(const string&) const;
//	char &operator[](int);
//	bool operator >(const string&) const;
//	bool operator <=(const string&) const;
//	bool operator <(const string&) const;
//	string operator %(const string&) const;
//	string operator %=(const string&) const;
	//char &front();
	//char &back();
	//char *begin();
	//char *end();
	
	
	//new
	//bool contains(const string&) const;
//	string format(const string&) const;
//	//iterator
	//string capitalize() const;
	//string center(int x, char c=' ') const;
//	int count(const string&);
//	string encode(const string& encoding='utf-8', enum errors='strict') const;
//	bool endswith(const string&) const;
//	string expandtabs(int tabsize=8) const;
//	int find(const string&);
//	string format(...);
//	string format_map(...);
//	int index(string);
//	bool isalnum();
//	bool isalpha();
//	bool isascii();
//	bool isdecimal();
//	bool isdigit();
//	bool isidentifier();
//	bool islower();
//	bool isnumeric();
//	bool isprintable();
//	bool isspace();
//	bool istitle();
//	bool isupper();
//	string join(self, string iterable, int size);
//	string ljust(int width, char fillchar=' ');
//	string lower();
//	string lstrip(chars=None);
//	vector<string> partition(string);
//	string replace(string old, string _new, int count=-1);
//	int rfind(string);
//	int rindex(string);
//	string rjust(int width, char fillchar=' ');
//	string rpartition(string sep);
//	vector<string> rsplit(self, /, char sep=' ', int maxsplit=-1);
//	string rstrip(vector chars);
//	vector split(string sep=None, int maxsplit=-1);
//	vector splitlines(bool keepends=False);
//	bool startswith();
//	string strip(vector chars);
//	string swapcase();
//	string title();
//	string translate(vector table);
//	string upper();
//	string zfill(int width);
	
};
}


#include "string.cpp"

#endif