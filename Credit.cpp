#include "DXUT.h"
#include "Credit.h"

void Credit::Init()
{
	OBJ->Add(new Mouse, "Mouse");
	bg = IMG->Add("Credit");
	Back = new Button(IMG->Add(""), { CENTER.x + 590,CENTER.y + 375 }, "", 250, 70, 0.9, [&]()->void { SCENE->Set("title"); }, false);
}																					

void Credit::Update()
{
}

void Credit::Render()
{
	bg->Render();
}

void Credit::Release()
{
}
