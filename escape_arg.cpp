#include <string>
#include <windows.h>

std::wstring escape_arg(const std::wstring& arg)
{
    std::wstring result = L"\"";
    int backslashes = 0;

    for (wchar_t c : arg)
    {
        if (c == L'\\')
        {
            ++backslashes;
        }
        else if (c == L'"')
        {
            result.append(backslashes * 2, L'\\');
            result += L"\\\"";
            backslashes = 0;
        }
        else
        {
            result.append(backslashes, L'\\');
            backslashes = 0;
            result += c;
        }
    }

    result.append(backslashes * 2, L'\\');
    result += L'"';
    return result;
}
