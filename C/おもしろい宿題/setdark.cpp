#include <windows.h>
#include <iostream>

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam);
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

int main()
{
    // 开始枚举所有顶级窗口
    EnumWindows(EnumWindowsProc, NULL);
    return 0;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    char windowTitle[256];
    // 获取窗口标题
    if (GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle)) > 0)
    {
        // 检查窗口标题是否包含特定文本，例如 "微信"
        if (strstr(windowTitle, "微信") != NULL)
        {
            // 找到目标窗口，开始枚举子窗口
            EnumChildWindows(hwnd, EnumChildProc, NULL);
            return FALSE; // 停止枚举顶级窗口
        }
    }
    return TRUE; // 继续枚举顶级窗口
}

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam)
{
    // 这里可以对每个子窗口进行操作
    // 例如，获取窗口文本、类名等，进一步判断是否需要进行颜色反转操作
    char className[256];
    GetClassNameA(hwnd, className, sizeof(className));
    std::cout << "Class Name: " << className << std::endl;

    // 注意：实际的反色操作需要根据窗口的具体类型和内容进行定制
    // 这可能涉及到复杂的图形处理技术

    return TRUE; // 继续枚举子窗口
}