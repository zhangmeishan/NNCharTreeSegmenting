/*
 * CAction.h
 *
 *  Created on: Oct 6, 2015
 *      Author: mszhang
 */

#ifndef BASIC_CAction_H_
#define BASIC_CAction_H_

#include <sstream>
#include "Tag.h"

/*===============================================================
 *
 * scored actions
 *
 *==============================================================*/
// for segmentation, there are only threee valid operations
class CAction {
public:
	enum CODE {APP = 0, FIN = 1, IDLE = 2, ARCRIGHT = 3, ARCLEFT = 4, SEP = 5, NO_ACTION = 1000};
  unsigned long _code;

public:
	CAction() : _code(NO_ACTION){
   }

   CAction(int code) : _code(code){
   }

   CAction(const CAction &ac) : _code(ac._code){
   }

public:
	inline void clear() { _code = NO_ACTION; }

   inline void set(int code){
     _code = code;
   }

   inline bool isNone() const { return _code==NO_ACTION; }
   inline bool isSeparate() const { return _code==SEP; }
   inline bool isAppend() const { return _code==APP; }
   inline bool isFinish() const { return _code==FIN; }
   inline bool isIdle() const { return _code==IDLE; }
   inline bool isArcRight() const { return _code==ARCRIGHT; }
   inline bool isArcLeft() const { return _code==ARCLEFT; }

public:
   inline std::string str() const {
     if (isNone()) { return "NONE"; }
     if (isIdle()) { return "IDLE"; }
	 if (isSeparate()) { return "SEP"; }
     if (isAppend()) { return "APP"; }
     if (isFinish()) { return "FIN"; }
     if (isArcRight()) { return "ARCRIGHT"; }
     if (isArcLeft()) { return "ARCLEFT"; }
     return "IDLE";
   }


public:
   const unsigned long &code() const {return _code;}
   const unsigned long &hash() const {return _code;}
   bool operator == (const CAction &a1) const { return _code == a1._code; }
   bool operator != (const CAction &a1) const { return _code != a1._code; }
   bool operator < (const CAction &a1) const { return _code < a1._code; }
   bool operator > (const CAction &a1) const { return _code > a1._code; }

};


inline std::ostream & operator << (std::ostream &os, const CAction &action) {
   os << action.str();
   return os;
}


#endif /* BASIC_CAction_H_ */
