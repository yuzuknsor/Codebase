#include <stdio.h>
#include <string.h>
struct __STU
{
    char name[20];
    int age;
} stu[100];
struct __STU *pstu = stu;
int cmp(const struct __STU *a, const struct __STU *b)
{
    return b->age - a->age;
}
void quicksort(int number[25], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
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
    s.size();   // 字符串长度
    s.length(); // 字符串长度
    s.empty();  // 判断字符串是否为空
    s.clear();  // 清空字符串
    s.substr(); // 截取子串
    // s.substr() 例
    string s = "hello";
    string t = s.substr(1, 3); // ello

    s.find_first_of(); // 查找字符
    s.find();          // 查找子串
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

    // 冒泡排序
    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    // 插入排序
    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int i, j, temp;
    for (i = 1; i < 10; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }

    // 快速排序
    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    int i, count, number[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);

    quicksort(number, 0, count - 1);

    printf("Order of Sorted elements: ");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);

    return 0;
}