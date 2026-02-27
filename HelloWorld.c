#include <stdio.h>
#include <windows.h>  // Windows 延时函数 Sleep()，Linux/macOS 换 unistd.h + usleep

int main() {
    // 目标文本（和 Python 一致）
    char text[] = "Hello World I'm Gay";
    // 临时字符串，存储已匹配的字符（长度足够即可）
    char temp[50] = "";
    // 精简版可打印字符集（覆盖目标文本所有字符，足够实现效果）
    char printable[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!'";

    // 遍历目标文本的每个字符
    for (int i = 0; text[i] != '\0'; i++) {
        char target = text[i];  // 当前要匹配的字符
        // 枚举字符集，直到匹配目标
        for (int j = 0; printable[j] != '\0'; j++) {
            // 打印：已匹配的字符 + 当前枚举的字符
            printf("%s%c\n", temp, printable[j]);
            Sleep(10);  // 延时 10 毫秒（对应 Python 的 0.01 秒）

            // 匹配成功，把目标字符加入临时字符串，停止枚举
            if (printable[j] == target) {
                // 简易拼接：直接追加字符（利用字符串结束符定位）
                int len = 0;
                while (temp[len] != '\0') len++;  // 找临时字符串末尾
                temp[len] = target;
                temp[len + 1] = '\0';  // 补字符串结束符
                break;
            }
        }
    }

    // 无限循环打印最终文本
    while (1) {
        printf("%s\n", temp);
        Sleep(10);
    }

    return 0;
}