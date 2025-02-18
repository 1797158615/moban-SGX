/*
 * File automatically generated by
 * gengen 1.4.2 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef ENCLAVE_CONFIG_GEN_CLASS_H
#define ENCLAVE_CONFIG_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class enclave_config_gen_class
{
 protected:

 public:
  enclave_config_gen_class()
  {
  }
  

  void generate_enclave_config(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "<EnclaveConfiguration>";
    stream << "\n";
    stream << indent_str;
    stream << "  <ProdID>0</ProdID>";
    stream << "\n";
    stream << indent_str;
    stream << "  <ISVSVN>0</ISVSVN>";
    stream << "\n";
    stream << indent_str;
    stream << "  <StackMaxSize>0x40000</StackMaxSize>";
    stream << "\n";
    stream << indent_str;
    stream << "  <HeapMaxSize>0x100000</HeapMaxSize>";
    stream << "\n";
    stream << indent_str;
    stream << "  <TCSNum>10</TCSNum>";
    stream << "\n";
    stream << indent_str;
    stream << "  <TCSPolicy>1</TCSPolicy>";
    stream << "\n";
    stream << indent_str;
    stream << "  <!-- Recommend changing 'DisableDebug' to 1 to make the enclave undebuggable for enclave release -->";
    stream << "\n";
    stream << indent_str;
    stream << "  <DisableDebug>0</DisableDebug>";
    stream << "\n";
    stream << indent_str;
    stream << "  <MiscSelect>0</MiscSelect>";
    stream << "\n";
    stream << indent_str;
    stream << "  <MiscMask>0xFFFFFFFF</MiscMask>";
    stream << "\n";
    stream << indent_str;
    stream << "</EnclaveConfiguration>";
    stream << "\n";
    stream << indent_str;
  }
};

#endif // ENCLAVE_CONFIG_GEN_CLASS_H
