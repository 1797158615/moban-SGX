/*
 * File automatically generated by
 * gengen 1.4.2 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef ENCLAVE_LDS_GEN_CLASS_H
#define ENCLAVE_LDS_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class enclave_lds_gen_class
{
 protected:

 public:
  enclave_lds_gen_class()
  {
  }
  

  void generate_enclave_lds(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "enclave.so";
    stream << "\n";
    stream << indent_str;
    stream << "{";
    stream << "\n";
    stream << indent_str;
    stream << "    global:";
    stream << "\n";
    stream << indent_str;
    stream << "        g_global_data_sim;";
    stream << "\n";
    stream << indent_str;
    stream << "        g_global_data;";
    stream << "\n";
    stream << indent_str;
    stream << "        enclave_entry;";
    stream << "\n";
    stream << indent_str;
    stream << "        g_peak_heap_used;";
    stream << "\n";
    stream << indent_str;
    stream << "    local:";
    stream << "\n";
    stream << indent_str;
    stream << "        *;";
    stream << "\n";
    stream << indent_str;
    stream << "};";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
  }
};

#endif // ENCLAVE_LDS_GEN_CLASS_H
