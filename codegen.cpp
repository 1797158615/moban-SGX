#include <iostream>
#include <string>
#include <fstream>  // 添加文件流的头文件
#include "a_Android.h"
#include "a_CMakeList.h"
#include "a_Makefile.h"
#include "ta_Android.h"
#include "ta_Makefile.h"
#include "ta_sub.h"
#include "ta_user_ta_header_defines.h"
#include "host_Makefile.h"

using namespace std;

int main(int argc, char* argv[])
{
    // 检查是否有输入参数
    if (argc < 2) {
        std::cout << "请提供至少一个参数。" << std::endl;
        return 1;
    }
    
    string path = "./";
    path += argv[1];
    path += "/Android.mk";

    // 创建 a_Android_gen_class 对象
    a_Android_gen_class a_Android(argv[1]);
    
    // 使用 ofstream 进行文件操作
    ofstream ofs(path);  // 打开文件
    if (!ofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    
    // 调用生成函数，修改为接受 ofstream
    a_Android.generate_a_Android(ofs);  // 需要确保该函数接受 ofstream 类型
    ofs.close();  // 关闭文件流
    
    //生成CMakeLists.txt
    path = "./";
    path += argv[1];
    path += "/CMakeLists.txt";
    
    a_CMakeList_gen_class a_CMakeList(argv[1]);
    ofstream a_CMofs(path);
    if (!a_CMofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    a_CMakeList.generate_a_CMakeList(a_CMofs);
    a_CMofs.close();
    
    //生成Makefile
    path = "./";
    path += argv[1];
    path += "/Makefile";
    
    a_Makefile_gen_class a_Makefile;
    ofstream a_Mofs(path);
    if (!a_Mofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    a_Makefile.generate_a_Makefile(a_Mofs);
    a_Mofs.close();
    
    //生成ta下的Android.mk
    path = "./";
    path += argv[1];
    path += "/ta/Android.mk";
    
    ta_Android_gen_class ta_Android;
    ofstream ta_aofs(path);
    if (!ta_aofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    ta_Android.generate_ta_Android(ta_aofs);
    ta_aofs.close();
    
    
    //生成ta下的Makefile
    path = "./";
    path += argv[1];
    path += "/ta/Makefile";
    
    ta_Makefile_gen_class  ta_Makefile;
    ofstream ta_mofs(path);
    if (!ta_mofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    ta_Makefile.generate_ta_Makefile(ta_mofs);
    ta_mofs.close();
    
    
    //生成ta下的Makefile
    path = "./";
    path += argv[1];
    path += "/ta/sub.mk";
    
    ta_sub_gen_class  ta_sub(argv[1]);
    ofstream ta_sofs(path);
    if (!ta_sofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    ta_sub.generate_ta_sub(ta_sofs);
    ta_sofs.close();
    
    //生成ta下的user_ta_header_defines.h
    path = "./";
    path += argv[1];
    path += "/ta/user_ta_header_defines.h";
    
    ta_user_ta_header_defines_gen_class  ta_user(argv[1]);
    ofstream ta_uofs(path);
    if (!ta_uofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    ta_user.generate_ta_user_ta_header_defines(ta_uofs);
    ta_uofs.close();
    
    //生成host下的Makefile
    path = "./";
    path += argv[1];
    path += "/host/Makefile";
    
    host_Makefile_gen_class  host_makefile(argv[1]);
    ofstream host_mofs(path);
    if (!host_mofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    host_makefile.generate_host_Makefile(host_mofs);
    host_mofs.close();
    
    return 0;
}
