#include <iostream>
#include <string>
#include <fstream>  // 添加文件流的头文件
#include "enclave_lds.h"
#include "app_h_gen.h"
#include "enclave_h.h"
#include "makefile.h"
#include "enclave_config.h"


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
    path += "/App/App.h";

    // 创建 a_Android_gen_class 对象
    app_h_gen_class app_h;
    
    // 使用 ofstream 进行文件操作
    ofstream ofs(path);  // 打开文件
    if (!ofs) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    
    // 调用生成函数，修改为接受 ofstream
    app_h.generate_app_h(ofs);  // 需要确保该函数接受 ofstream 类型
    ofs.close();  // 关闭文件流
    
    //生成CMakeLists.txt
    path = "./";
    path += argv[1];
    path += "/Enclave/Enclave.h";
    
    enclave_h_gen_class enclave_h;
    ofstream enlcaveh(path);
    if (!enlcaveh) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    enclave_h.generate_enclave_h(enlcaveh);
    enlcaveh.close();
    
    //生成Makefile
    path = "./";
    path += argv[1];
    path += "/Enclave/Enclave.lds";
    
    enclave_lds_gen_class enclave_lds;
    ofstream enclavel(path);
    if (!enclavel) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    enclave_lds.generate_enclave_lds(enclavel);
    enclavel.close();
    
    //生成ta下的Android.mk
    path = "./";
    path += argv[1];
    path += "/Enclave/Enclave.config.xml";
    
    enclave_config_gen_class enclave_c;
    ofstream enclavec(path);
    if (!enclavec) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    enclave_c.generate_enclave_config(enclavec);
    enclavec.close();
    
    
    //生成ta下的Makefile
    path = "./";
    path += argv[1];
    path += "/Makefile";
    
    makefile_gen_class  makefile;
    ofstream mf(path);
    if (!mf) {  // 检查文件是否成功打开
        cerr << "无法打开文件: " << path << endl;
        return 1;
    }
    makefile.generate_makefile(mf);
    mf.close();
    
    
    return 0;
}
