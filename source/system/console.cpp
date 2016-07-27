/*!
    \file console.cpp
    \brief Console management implementation
    \author Ivan Shynkarenka
    \date 27.07.2016
    \copyright MIT License
*/

#include "system/console.h"

#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

namespace CppCommon {

std::ostream& operator<<(std::ostream& stream, Color color)
{
    Console::SetColor(color);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::pair<Color, Color> colors)
{
    Console::SetColor(colors.first, colors.second);
    return stream;
}

void Console::SetColor(Color color, Color background)
{
#if defined(_WIN32) || defined(_WIN64)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (((WORD)color) & 0x0F) + ((((WORD)background) & 0x0F) << 4));
#elif defined(unix) || defined(__unix) || defined(__unix__)
    const char* colors[] =
    {
        "\033[22;30m",  // Black color
        "\033[22;34m",  // Blue color
        "\033[22;32m",  // Green color
        "\033[22;36m",  // Cyan color
        "\033[22;31m",  // Red color
        "\033[22;35m",  // Magenta color
        "\033[22;33m",  // Brown color
        "\033[22;37m",  // Grey color
        "\033[01;30m",  // Dark grey color
        "\033[01;34m",  // Light blue color
        "\033[01;32m",  // Light green color
        "\033[01;36m",  // Light cyan color
        "\033[01;31m",  // Light red color
        "\033[01;35m",  // Light magenta color
        "\033[01;33m",  // Yellow color
        "\033[01;37m"   // White color
    };
    const char* backgrounds[] =
    {
        "\033[22;40m",  // Black color
        "\033[22;44m",  // Blue color
        "\033[22;42m",  // Green color
        "\033[22;46m",  // Cyan color
        "\033[22;41m",  // Red color
        "\033[22;45m",  // Magenta color
        "\033[22;43m",  // Brown color
        "\033[22;47m",  // Grey color
        "\033[01;40m",  // Dark grey color
        "\033[01;44m",  // Light blue color
        "\033[01;42m",  // Light green color
        "\033[01;46m",  // Light cyan color
        "\033[01;41m",  // Light red color
        "\033[01;45m",  // Light magenta color
        "\033[01;43m",  // Yellow color
        "\033[01;47m"   // White color
    };
    std::cout << colors[color - Color::BLACK] << backgrounds[background - Color::BLACK];
#endif
}

} // namespace CppCommon
