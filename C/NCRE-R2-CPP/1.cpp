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

    strcpy-s: 复制字符串
    strcat-s: 连接字符串
    strlen-s: 返回字符串长度
    strcmp-s: 比较字符串
    strchr-s: 查找字符
    strstr-s: 查找字符串
    strtok-s: 分割字符串

    auto
    case
    default
    do
    enum
    extern
    static
    union
    volatile
    catch
    const_cast
    delete
    dynamic_cast
    explicit
    friend
    inline
    mutable
    new
    operator
    reinterpret_cast
    static_cast
    template
    this
    throw
    try
    typeid
    typename
    typedef
    using
    virtual
    wchar_t

    定义与声明

    \a      7       响铃
    \b      8       退格
    \f      12      换页
    \n      10      换行
    \r      13      回车
    \t      9       水平制表符
    \v      11      垂直制表符
    \\      92      反斜杠
    \'      39      单引号
    \"      34      双引号
    \?      63      问号
    \0      0       空字符
    \ddd            1到3位八进制数所代表的任意字符
    \xhh            1到2位十六进制数所代表的任意字符
    \uhhhh          4位十六进制数所代表的Unicode字符
    \Uhhhhhhhh      8位十六进制数所代表的Unicode字符

    引用和迭代
    引用传参

    
*/