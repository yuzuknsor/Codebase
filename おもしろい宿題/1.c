#include <stdio.h>
#include <string.h>
struct __STU
{
    char name[20];
    int age;
} stu[100];
struct __STU *pstu = stu;
int cmp(const void *a, const void *b)
{
    return ((struct __STU *)a)->age - ((struct __STU *)b)->age;
}
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", (pstu + i)->name, &(pstu + i)->age);
    }
    qsort(pstu, n, sizeof(struct __STU), cmp);
    // 比较两个string字符串是否一致
    // 1. 直接比较
    string s1 = "hello";
    string s2 = "hello";
    if (s1 == s2)
    {
        cout << "s1 == s2" << endl;
    }
    else
    {
        cout << "s1 != s2" << endl;
    }
    // 2. 使用compare函数
    string s1 = "hello";
    string s2 = "hello";
    if (s1.compare(s2) == 0) // 相等
    {
        cout << "s1 == s2" << endl;
    }
    else if (s1.compare(s2) > 0) // s1 > s2
    {
        cout << "s1 > s2" << endl;
    }
    else // s1 < s2
    {
        cout << "s1 < s2" << endl;
    }
    {
        cout << "s1 == s2" << endl;
    }
    else
    {
        cout << "s1 != s2" << endl;
    }

    // 比较两个string字符串的字典序
    string s1 = "hello";
    string s2 = "hello";
    if (s1 < s2)
    {
        cout << "s1 < s2" << endl;
    }
    else if (s1 > s2)
    {
        cout << "s1 > s2" << endl;
    }
    else
    {
        cout << "s1 == s2" << endl;
    }

    // 删除string字符串中某个特定字母
    string s = "hello";
    s.erase(remove(s.begin(), s.end(), 'l'), s.end());
    cout << s << endl; // heo

    // 删除string字符串中某个特定子串
    string s = "hello";
    string t = "ll";
    int pos = s.find(t);
    if (pos != string::npos)
    {
        s.erase(pos, t.length());
    }
    cout << s << endl; // heo
    // string 的所有成员函数
    string s;
    s.size(); // 字符串长度
    s.length(); // 字符串长度
    s.empty(); // 判断字符串是否为空
    s.clear(); // 清空字符串
    s.substr(); // 截取子串
    // s.substr() 例
    string s = "hello";
    string t = s.substr(1, 3); // ello

    s.find_first_of(); // 查找字符
    s.find(); // 查找子串
    s.rfind();
    s.replace();
    s.insert();
    s.erase();
    s.push_back();
    s.pop_back();
    s.c_str();
    s.compare();
    s.swap();
    s.at();
    s.begin();
    s.end();
    s.rbegin();
    s.rend();
    s.max_size();
    s.capacity();
    s.resize();
    s.reserve();
    s.copy();
    s.data();
    s.get_allocator();
    return 0;
}