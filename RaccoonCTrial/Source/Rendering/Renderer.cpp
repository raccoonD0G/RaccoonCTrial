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
    cout << InRenderInterface->GetScreenString() << flush;

}

void URenderer::PrintAllOnScreen() const
{
    for (int i = 0; i < RenderTargets.Num(); i++)
    {
        PrintOnScreen(RenderTargets.GetByIndex(i));
    }
}
