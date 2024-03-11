/*
std::string成员函数
    size() 或 length(): 返回字符串的长度。
    empty(): 如果字符串为空返回true，否则返回false。
    append(str): 将str添加到字符串的末尾。
    substr(pos, len): 返回从pos开始、长度为len的子字符串。
    find(str): 返回str在字符串中首次出现的位置。如果找不到，返回std::string::npos。
        std::string::npos是std::string::size_type最大可能值，一个无符号整数类型，通常与size_t相同。
    erase(pos, len): 删除从pos开始、长度为len的子字符串。
    replace(pos, len, str): 用str替换从pos开始、长度为len的子字符串。
    c_str(): 返回一个指向字符串的C风格版本的指针。
        std::string的c_str函数返回一个常量字符指针（const char*），这个指针指向一个以'\0'结尾的字符数组。这个字符数组包含了std::string的内容。
        std::string str = "Hello, world!";
        const char* cstr = str.c_str();
        在这个例子中，cstr是一个指向字符数组的指针，这个字符数组包含了"Hello, world!"和一个'\0'。C++风格则无'\0'。
    operator[]: 用于访问字符串中的单个字符。


*/