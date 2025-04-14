#include "ScreenPrinter.h"
#include "windows.h"
#include "iostream"

using namespace std;

void ScreenPrinter::PrintOnScreen(IScreenPrintInterface* InScreenPrintInterface) const
{
    COORD Pos;
    Pos.X = InScreenPrintInterface->GetLocation().X;
    Pos.Y = InScreenPrintInterface->GetLocation().Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    cout << InScreenPrintInterface->GetScreenString();
}

void ScreenPrinter::PrintAllOnScrean() const
{
    for (int i = 0; i < ScreenPrints.GetSize(); i++)
    {
        PrintOnScreen(ScreenPrints.GetByIndex(i));
    }
}
