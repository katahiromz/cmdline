/*
 * wcmdline.c --- The command line checker (Unicode version)
 * Author: katahiromz
 * License: MIT
 */
#include <windows.h>
#include <stdio.h>

int wmain(int argc, wchar_t **argv)
{
    int i;
    printf("argc: %d\n", argc);
    for (i = 0; i < argc; ++i)
    {
        printf("argv[%d]: %S\n", i, argv[i]);
    }
    return 0;
}

int main(void)
{
    int argc, ret;
    LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    ret = wmain(argc, argv);
    LocalFree(argv);
    return ret;
}
