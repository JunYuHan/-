#include "DXUT.h"
#include "Credit.h"

void Credit::Init()
{
	OBJ->Add(new Mouse, "Mouse");
	credit = IMG->Add("Credit");
	back = new Button(IMG->Add("player"), { CENTER.x + 650,CENTER.y + 200 }, "", 200, 70, 1, [&]()->void {SCENE->Set("title"); });
}

void Credit::Update()
{
}

void Credit::Render()
{
	credit->Render(CENTER, RT_ZERO, {1.5,1.5});
}

void Credit::Release()
{
}
