
#define NOMINMAX
#include "windows.h"

#include "Renderer.h"
#include "iostream"

URenderer::URenderer()
{

}

URenderer::~URenderer()
{
    ;
}

void URenderer::Render(IRenderInterface* InRenderInterface) const
{
    if (!InRenderInterface)
    {
        return;
    }
    ILocationInterface* LocationInterface = dynamic_cast<ILocationInterface*>(InRenderInterface);

    if (!LocationInterface)
    {
        return;
    }

    FVector2D loc = LocationInterface->GetWorldLocation();

    COORD Pos;
    Pos.X = loc.X;
    Pos.Y = loc.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    std::cout << InRenderInterface->GetRenderString() << std::flush;
}

void URenderer::RenderAll() const
{
    for (int i = 0; i < RenderTargets.Num(); i++)
    {
        IRenderInterface* RenderTarget = RenderTargets[i];
        if (RenderTarget)
        {
            Render(RenderTarget);
        }
    }
}
