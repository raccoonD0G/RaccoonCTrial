
#define NOMINMAX
#include "windows.h"

#include "Renderer.h"
#include "iostream"
#include "Components/PrimitiveComponent.h"

URenderer::URenderer()
{

}

URenderer::~URenderer()
{
    ;
}


void URenderer::RenderAll() const
{
    for (int i = 0; i < VisiblePrimitiveComponents.Num(); i++)
    {
        UPrimitiveComponent* VisiblePrimitiveComponent = VisiblePrimitiveComponents[i];
        if (VisiblePrimitiveComponent)
        {
            Render(VisiblePrimitiveComponent);
        }
    }
}

void URenderer::Render(UPrimitiveComponent* InPrimitiveComponent) const
{
    if (!InPrimitiveComponent)
    {
        return;
    }

    FVector2D loc = InPrimitiveComponent->GetWorldLocation();

    COORD Pos;
    Pos.X = loc.X;
    Pos.Y = loc.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    std::cout << InPrimitiveComponent->GetRenderString() << std::flush;
}
