#include "Renderer.h"
#include "windows.h"
#include "iostream"

using namespace std;

void URenderer::PrintOnScreen(IRenderInterface* InRenderInterface) const
{
    COORD Pos;
    Pos.X = InRenderInterface->GetLocation().X;
    Pos.Y = InRenderInterface->GetLocation().Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    cout << InRenderInterface->GetScreenString();
}

void URenderer::PrintAllOnScrean() const
{
    for (int i = 0; i < RenderTargets.GetSize(); i++)
    {
        PrintOnScreen(RenderTargets.GetByIndex(i));
    }
}
