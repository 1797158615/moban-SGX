/*
 * File automatically generated by
 * gengen 1.4.2 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef MAKEFILE_GEN_CLASS_H
#define MAKEFILE_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class makefile_gen_class
{
 protected:

 public:
  makefile_gen_class()
  {
  }
  

  void generate_makefile(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "######## SGX SDK Settings ########";
    stream << "\n";
    stream << indent_str;
    stream << "# 设置 SGX SDK 的路径、模式、架构和调试选项";
    stream << "\n";
    stream << indent_str;
    stream << "# SGX SDK 安装路径";
    stream << "\n";
    stream << indent_str;
    stream << "SGX_SDK ?= /opt/intel/sgxsdk";
    stream << "\n";
    stream << indent_str;
    stream << "# SGX 模式：硬件模式(HW)";
    stream << "\n";
    stream << indent_str;
    stream << "SGX_MODE ?= HW";
    stream << "\n";
    stream << indent_str;
    stream << "# SGX 架构：64 位(x64)";
    stream << "\n";
    stream << indent_str;
    stream << "SGX_ARCH ?= x64";
    stream << "\n";
    stream << indent_str;
    stream << "# SGX 调试模式：启用(1)";
    stream << "\n";
    stream << indent_str;
    stream << "SGX_DEBUG ?= 1";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 判断系统的位数，如果是 32 位，设置架构为 x86";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(shell getconf LONG_BIT), 32)";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_ARCH := x86";
    stream << "\n";
    stream << indent_str;
    stream << "# 如果编译器标志中包含 -m32，也设置架构为 x86";
    stream << "\n";
    stream << indent_str;
    stream << "else ifeq ($(findstring -m32, $(CXXFLAGS)), -m32)";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_ARCH := x86";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 根据架构选择编译器标志、库路径和工具路径";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_ARCH), x86)";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_COMMON_FLAGS := -m32                         # 设置 32 位编译标志";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_LIBRARY_PATH := $(SGX_SDK)/lib               # 32 位库路径";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_ENCLAVE_SIGNER := $(SGX_SDK)/bin/x86/sgx_sign # 使用 32 位签名工具";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_EDGER8R := $(SGX_SDK)/bin/x86/sgx_edger8r     # 使用 32 位 Edger8r 工具";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_COMMON_FLAGS := -m64                         # 设置 64 位编译标志";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_LIBRARY_PATH := $(SGX_SDK)/lib64             # 64 位库路径";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_ENCLAVE_SIGNER := $(SGX_SDK)/bin/x64/sgx_sign # 使用 64 位签名工具";
    stream << "\n";
    stream << indent_str;
    stream << "    SGX_EDGER8R := $(SGX_SDK)/bin/x64/sgx_edger8r     # 使用 64 位 Edger8r 工具";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 检查是否同时设置了调试模式和预发布模式";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_DEBUG), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_PRERELEASE), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "$(error Cannot set SGX_DEBUG and SGX_PRERELEASE at the same time!!)";
    stream << "\n";
    stream << indent_str;
    stream << "# 如果两个都设置了，报错 \"不能同时设置调试模式和预发布模式\"";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 根据是否启用调试模式设置编译标志";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_DEBUG), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "        SGX_COMMON_FLAGS += -O0 -g  # 调试模式：不进行优化，包含调试信息";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "        SGX_COMMON_FLAGS += -O2    # 生产模式：优化代码";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 设置更多的编译器警告标志，确保代码质量";
    stream << "\n";
    stream << indent_str;
    stream << "SGX_COMMON_FLAGS += -Wall -Wextra -Winit-self -Wpointer-arith -Wreturn-type \\";
    stream << "\n";
    stream << indent_str;
    stream << "                    -Waddress -Wsequence-point -Wformat-security \\";
    stream << "\n";
    stream << indent_str;
    stream << "                    -Wmissing-include-dirs -Wfloat-equal -Wundef -Wshadow \\";
    stream << "\n";
    stream << indent_str;
    stream << "                    -Wcast-align -Wcast-qual -Wconversion -Wredundant-decls";
    stream << "\n";
    stream << indent_str;
    stream << "SGX_COMMON_CFLAGS := $(SGX_COMMON_FLAGS) -Wjump-misses-init -Wstrict-prototypes -Wunsuffixed-float-constants # C 编译标志";
    stream << "\n";
    stream << indent_str;
    stream << "SGX_COMMON_CXXFLAGS := $(SGX_COMMON_FLAGS) -Wnon-virtual-dtor -std=c++11  # C++ 编译标志，使用 C++11 标准";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "######## App Settings ########";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 应用程序设置";
    stream << "\n";
    stream << indent_str;
    stream << "ifneq ($(SGX_MODE), HW)";
    stream << "\n";
    stream << indent_str;
    stream << "    Urts_Library_Name := sgx_urts_sim  # 如果不是硬件模式，使用仿真库";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "    Urts_Library_Name := sgx_urts      # 如果是硬件模式，使用真实库";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 指定应用程序的源文件和包含路径";
    stream << "\n";
    stream << indent_str;
    stream << "App_C_Files := App/App.c $(wildcard App/TrustedLibrary/*.c)";
    stream << "\n";
    stream << indent_str;
    stream << "App_Include_Paths := -IApp -I$(SGX_SDK)/include";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 设置应用程序的编译标志";
    stream << "\n";
    stream << indent_str;
    stream << "App_C_Flags := -fPIC -Wno-attributes $(App_Include_Paths)";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 根据不同的配置模式，设置不同的宏定义";
    stream << "\n";
    stream << indent_str;
    stream << "# Three configuration modes - Debug, prerelease, release";
    stream << "\n";
    stream << indent_str;
    stream << "#   Debug - Macro DEBUG enabled.";
    stream << "\n";
    stream << indent_str;
    stream << "#   Prerelease - Macro NDEBUG and EDEBUG enabled.";
    stream << "\n";
    stream << indent_str;
    stream << "#   Release - Macro NDEBUG enabled.";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_DEBUG), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "        App_C_Flags += -DDEBUG -UNDEBUG -UEDEBUG";
    stream << "\n";
    stream << indent_str;
    stream << "else ifeq ($(SGX_PRERELEASE), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "        App_C_Flags += -DNDEBUG -DEDEBUG -UDEBUG";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "        App_C_Flags += -DNDEBUG -UEDEBUG -UDEBUG";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# App_Cpp_Flags := $(App_C_Flags)";
    stream << "\n";
    stream << indent_str;
    stream << "App_Link_Flags := -L$(SGX_LIBRARY_PATH) -l$(Urts_Library_Name) -lpthread";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 生成对象文件的规则";
    stream << "\n";
    stream << indent_str;
    stream << "App_C_Objects := $(App_C_Files:.c=.o)";
    stream << "\n";
    stream << indent_str;
    stream << "# 指定生成的应用程序名称";
    stream << "\n";
    stream << indent_str;
    stream << "App_Name := app";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "######## Enclave Settings ########";
    stream << "\n";
    stream << indent_str;
    stream << "# 设置信任域版本脚本文件根据调试模式与硬件模式判断";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_Version_Script := Enclave/Enclave.lds";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_MODE), HW)";
    stream << "\n";
    stream << indent_str;
    stream << "ifneq ($(SGX_DEBUG), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "ifneq ($(SGX_PRERELEASE), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "	# 硬件发布模式下使用的版本脚本文件";
    stream << "\n";
    stream << indent_str;
    stream << "	# Choose to use 'Enclave.lds' for HW release mode";
    stream << "\n";
    stream << indent_str;
    stream << "	Enclave_Version_Script = Enclave/Enclave.lds ";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 仿真模式与硬件模式下使用不同的库";
    stream << "\n";
    stream << indent_str;
    stream << "ifneq ($(SGX_MODE), HW)";
    stream << "\n";
    stream << indent_str;
    stream << "    Trts_Library_Name := sgx_trts_sim      # 仿真模式库";
    stream << "\n";
    stream << indent_str;
    stream << "    Service_Library_Name := sgx_tservice_sim # 仿真模式服务库";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "    Trts_Library_Name := sgx_trts         # 硬件模式库";
    stream << "\n";
    stream << indent_str;
    stream << "    Service_Library_Name := sgx_tservice  # 硬件模式服务库";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "Crypto_Library_Name := sgx_tcrypto        # 加密库";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 指定信任域的源文件和包含路径";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_C_Files := Enclave/Enclave.c $(wildcard Enclave/TrustedLibrary/*.c)";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_Include_Paths := -IEnclave -I$(SGX_SDK)/include -I$(SGX_SDK)/include/libcxx -I$(SGX_SDK)/include/tlibc ";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 设置信任域的编译标志";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_C_Flags := -nostdinc -fvisibility=hidden -fpie -fstack-protector -fno-builtin-printf $(Enclave_Include_Paths)";
    stream << "\n";
    stream << indent_str;
    stream << "# Enclave_Cpp_Flags := $(Enclave_C_Flags) -nostdinc++";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 启用安全链接选项";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_Security_Link_Flags := -Wl,-z,relro,-z,now,-z,noexecstack";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 生成信任域的正确链接规则";
    stream << "\n";
    stream << indent_str;
    stream << "# 按步骤链接信任库";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_Link_Flags := $(Enclave_Security_Link_Flags) \\";
    stream << "\n";
    stream << indent_str;
    stream << "    -Wl,--no-undefined -nostdlib -nodefaultlibs -nostartfiles -L$(SGX_LIBRARY_PATH) \\";
    stream << "\n";
    stream << indent_str;
    stream << "	-Wl,--whole-archive -l$(Trts_Library_Name) -Wl,--no-whole-archive \\";
    stream << "\n";
    stream << indent_str;
    stream << "	-Wl,--start-group -lsgx_tstdc -lsgx_tcxx -l$(Crypto_Library_Name) -l$(Service_Library_Name) -Wl,--end-group \\";
    stream << "\n";
    stream << indent_str;
    stream << "	-Wl,-Bstatic -Wl,-Bsymbolic -Wl,--no-undefined \\";
    stream << "\n";
    stream << indent_str;
    stream << "	-Wl,-pie,-eenclave_entry -Wl,--export-dynamic  \\";
    stream << "\n";
    stream << indent_str;
    stream << "	-Wl,--defsym,__ImageBase=0 \\";
    stream << "\n";
    stream << indent_str;
    stream << "	-Wl,--version-script=$(Enclave_Version_Script)";
    stream << "\n";
    stream << indent_str;
    stream << "# 指定信任域生成的对象文件";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_C_Objects := $(Enclave_C_Files:.c=.o)";
    stream << "\n";
    stream << indent_str;
    stream << "# 指定生成的信任域库名";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_Name := enclave.so";
    stream << "\n";
    stream << indent_str;
    stream << "Signed_Enclave_Name := enclave.signed.so";
    stream << "\n";
    stream << indent_str;
    stream << "# 配置文件和测试密钥文件";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_Config_File := Enclave/Enclave.config.xml";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave_Key := Enclave/Enclave_private.pem";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 生成不同的构建模式名称";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_MODE), HW)";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_DEBUG), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "	Build_Mode = HW_DEBUG";
    stream << "\n";
    stream << indent_str;
    stream << "else ifeq ($(SGX_PRERELEASE), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "	Build_Mode = HW_PRERELEASE";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "	Build_Mode = HW_RELEASE";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(SGX_DEBUG), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "	Build_Mode = SIM_DEBUG";
    stream << "\n";
    stream << indent_str;
    stream << "else ifeq ($(SGX_PRERELEASE), 1)";
    stream << "\n";
    stream << indent_str;
    stream << "	Build_Mode = SIM_PRERELEASE";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "	Build_Mode = SIM_RELEASE";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << ".PHONY: all run target";
    stream << "\n";
    stream << indent_str;
    stream << "all: .config_$(Build_Mode)_$(SGX_ARCH)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(MAKE) target";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(Build_Mode), HW_RELEASE)";
    stream << "\n";
    stream << indent_str;
    stream << "target: $(App_Name) $(Enclave_Name)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"The project has been built in release hardware mode.\"";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"Please sign the $(Enclave_Name) first with your signing key before you run the $(App_Name) to launch and access the enclave.\"";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"To sign the enclave use the command:\"";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"   $(SGX_ENCLAVE_SIGNER) sign -key <your key> -enclave $(Enclave_Name) -out <$(Signed_Enclave_Name)> -config $(Enclave_Config_File)\"";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"You can also sign the enclave using an external signing tool.\"";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"To build the project in simulation mode set SGX_MODE=SIM. To build the project in prerelease mode set SGX_PRERELEASE=1 and SGX_MODE=HW.\"";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "target: $(App_Name) $(Signed_Enclave_Name)";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(Build_Mode), HW_DEBUG)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"The project has been built in debug hardware mode.\"";
    stream << "\n";
    stream << indent_str;
    stream << "else ifeq ($(Build_Mode), SIM_DEBUG)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"The project has been built in debug simulation mode.\"";
    stream << "\n";
    stream << indent_str;
    stream << "else ifeq ($(Build_Mode), HW_PRERELEASE)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"The project has been built in pre-release hardware mode.\"";
    stream << "\n";
    stream << indent_str;
    stream << "else ifeq ($(Build_Mode), SIM_PRERELEASE)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"The project has been built in pre-release simulation mode.\"";
    stream << "\n";
    stream << indent_str;
    stream << "else";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"The project has been built in release simulation mode.\"";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 运行目标规则，首先构建所有目标，然后运行应用程序，除非是在硬件发布模式下。";
    stream << "\n";
    stream << indent_str;
    stream << "run: all";
    stream << "\n";
    stream << indent_str;
    stream << "ifneq ($(Build_Mode), HW_RELEASE)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(CURDIR)/$(App_Name)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"RUN  =>  $(App_Name) [$(SGX_MODE)|$(SGX_ARCH), OK]\"";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 配置文件生成规则，如果构建模式和架构改变，重新生成配置";
    stream << "\n";
    stream << indent_str;
    stream << ".config_$(Build_Mode)_$(SGX_ARCH):";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "rm -f .config_* $(App_Name) $(Enclave_Name) $(Signed_Enclave_Name) $(App_C_Objects) App/Enclave_u.* $(Enclave_C_Objects) Enclave/Enclave_t.*";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "touch .config_$(Build_Mode)_$(SGX_ARCH)";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "######## App Objects ########";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 生成 Enclave_u.h，如果 Enclave.edl 改变";
    stream << "\n";
    stream << indent_str;
    stream << "App/Enclave_u.h: $(SGX_EDGER8R) Enclave/Enclave.edl";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "cd App && $(SGX_EDGER8R) --untrusted ../Enclave/Enclave.edl --search-path ../Enclave --search-path $(SGX_SDK)/include";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"GEN  =>  $";
    stream << "@";
    stream << "\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "App/Enclave_u.c: App/Enclave_u.h";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 编译 Enclave_u.c 生成对象文件";
    stream << "\n";
    stream << indent_str;
    stream << "App/Enclave_u.o: App/Enclave_u.c";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(CC) $(SGX_COMMON_CFLAGS) $(App_C_Flags) -c $< -o $";
    stream << "@";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"CC   <=  $<\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 编译应用程序源文件生成对象文件";
    stream << "\n";
    stream << indent_str;
    stream << "App/%.o: App/%.c App/Enclave_u.h";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(CC) $(SGX_COMMON_CFLAGS) $(App_C_Flags) -c $< -o $";
    stream << "@";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"CC  <=  $<\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 链接对象文件生成应用程序可执行文件";
    stream << "\n";
    stream << indent_str;
    stream << "$(App_Name): App/Enclave_u.o $(App_C_Objects)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(CC) $^ -o $";
    stream << "@";
    stream << " $(App_Link_Flags)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"LINK =>  $";
    stream << "@";
    stream << "\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "######## Enclave Objects ########";
    stream << "\n";
    stream << indent_str;
    stream << "# 生成 Enclave_t.h，如果 Enclave.edl 改变";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave/Enclave_t.h: $(SGX_EDGER8R) Enclave/Enclave.edl";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "cd Enclave && $(SGX_EDGER8R) --trusted ../Enclave/Enclave.edl --search-path ../Enclave --search-path $(SGX_SDK)/include";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"GEN  =>  $";
    stream << "@";
    stream << "\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "Enclave/Enclave_t.c: Enclave/Enclave_t.h";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 编译 Enclave_t.c 生成对象文件";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave/Enclave_t.o: Enclave/Enclave_t.c";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(CC) $(SGX_COMMON_CFLAGS) $(Enclave_C_Flags) -c $< -o $";
    stream << "@";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"CC   <=  $<\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 编译信任域源文件生成对象文件";
    stream << "\n";
    stream << indent_str;
    stream << "Enclave/%.o: Enclave/%.c";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(CC) $(SGX_COMMON_CFLAGS) $(Enclave_C_Flags) -c $< -o $";
    stream << "@";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"CC  <=  $<\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 生成信任域对象文件";
    stream << "\n";
    stream << indent_str;
    stream << "$(Enclave_C_Objects): Enclave/Enclave_t.h";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 链接对象文件生成信任域共享库文件";
    stream << "\n";
    stream << indent_str;
    stream << "$(Enclave_Name): Enclave/Enclave_t.o $(Enclave_C_Objects)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(CC) $^ -o $";
    stream << "@";
    stream << " $(Enclave_Link_Flags)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"LINK =>  $";
    stream << "@";
    stream << "\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# 使用测试私钥签名信任域共享库文件";
    stream << "\n";
    stream << indent_str;
    stream << "$(Signed_Enclave_Name): $(Enclave_Name)";
    stream << "\n";
    stream << indent_str;
    stream << "ifeq ($(wildcard $(Enclave_Key)),)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"There is no enclave test key<Enclave_private_test.pem>.\"";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"The project will generate a key<Enclave_private_test.pem> for test.\"";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "openssl genrsa -out $(Enclave_Key) -3 3072";
    stream << "\n";
    stream << indent_str;
    stream << "endif";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "$(SGX_ENCLAVE_SIGNER) sign -key $(Enclave_Key) -enclave $(Enclave_Name) -out $";
    stream << "@";
    stream << " -config $(Enclave_Config_File)";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "echo \"SIGN =>  $";
    stream << "@";
    stream << "\"";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "# clean 目标，删除生成的文件";
    stream << "\n";
    stream << indent_str;
    stream << ".PHONY: clean";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "clean:";
    stream << "\n";
    stream << indent_str;
    stream << "	";
    stream << "@";
    stream << "rm -f .config_* $(App_Name) $(Enclave_Name) $(Signed_Enclave_Name) $(App_C_Objects) App/Enclave_u.* $(Enclave_C_Objects) Enclave/Enclave_t.*";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
  }
};

#endif // MAKEFILE_GEN_CLASS_H
