#include <iostream>
#include <cstdarg>

using namespace std;
#define USE_SYMBOLS

#define begin {
#define end }

int countRepeats(int numArgs, ...) begin
    va_list args;
    va_start(args, numArgs);

    int counts[10] = { 0 }; // Припустимо, що числа в діапазоні [0, 9]

    for (int i = 0; i < numArgs; ++i) begin
        int num = va_arg(args, int);
        if (num >= 0 && num < 10) {
            counts[num]++;
        end
    end

    va_end(args);

    for (int i = 0; i < 10; ++i) begin
        if (counts[i] > 0) begin
            cout << "Number " << i << " repeats " << counts[i] << " times" << endl;
        end
    end

    return 0;
end

void findSymbolPositions(int numArgs, ...) begin
    va_list args;
    va_start(args, numArgs);

    int code = va_arg(args, int); // Перший аргумент — це код символа, який шукаємо

    cout << "Positions of character with ASCII code " << code << ":" << endl;

    for (int i = 1; i < numArgs; ++i) begin // Починаємо з другого аргументу, бо перший — код
        char symbol = static_cast<char>(va_arg(args, int));
        if (symbol == code) begin
            cout << "Position " << i - 1 << ", Character: '" << symbol << "'" << endl;
        end
    end

    va_end(args);
end

int main() begin
    cout << "Counting numbers in the array:" << endl;
    countRepeats(8, 1, 3, 4, 4, 3, 2, 1, 4);

    cout << "\nFinding symbol positions by ASCII code:" << endl;
    findSymbolPositions(7, 65, 'A', 'B', 'C', 'A', 'D', 'A');
    return 0;
end
