#ifndef USERIN_H_INCLUDED
#define USERIN_H_INCLUDED
/*#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
//*/
class userInHandler{
    friend class sorting;
	public:
		userInHandler() {this->errname = "Invalid input.";}//output generated when Math realted exception occurs
		string getName() const {return this->errname;}
		void setName(string name) {this->errname = name;}
	//private:
		string errname;
};

class outOfRange : public userInHandler
{
    public:
        outOfRange() {this->errname = "Out of range.";}
};
#endif // USERIN_H_INCLUDED
