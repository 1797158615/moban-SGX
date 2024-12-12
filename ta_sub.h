/*
 * File automatically generated by
 * gengen 1.4.2 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef TA_SUB_GEN_CLASS_H
#define TA_SUB_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class ta_sub_gen_class
{
 protected:
  string srcname;

 public:
  ta_sub_gen_class()
  {
  }
  
  ta_sub_gen_class(const string &_srcname) :
    srcname (_srcname)
  {
  }

  void set_srcname(const string &_srcname)
  {
    srcname = _srcname;
  }

  void generate_ta_sub(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "global-incdirs-y += include";
    stream << "\n";
    stream << indent_str;
    stream << "srcs-y += ";
    stream << srcname;
    stream << ".c";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# To remove a certain compiler flag, add a line like this";
    stream << "\n";
    stream << indent_str;
    stream << "#cflags-template_ta.c-y += -Wno-strict-prototypes";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
  }
};

#endif // TA_SUB_GEN_CLASS_H
