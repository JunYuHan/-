#include "DXUT.h"
#include "End.h"

End::End(int type)
	:bg(), map(), type(type)
{
}

void End::Init()
{
	switch (type)
	{
	case 1:
		
		bg = IMG->Add("Success");
		break;
	case 2:
		bg = IMG->Add("Failure");
		break;
	}
	OBJ->Add(new Mouse, "Mouse");

	//map = new ScrollMap(IMG->Add("Bg"));

	

	restart = new Button(IMG->Add("BigBlue"), { CENTER.x - 300,CENTER.y + 300 }, "RESTART", 440, 200, 1, [&]()->void { SCENE->Set("stage1"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
	title = new Button(IMG->Add("BigBlue"), { CENTER.x + 300,CENTER.y + 300 }, "TITLE", 440, 200, 1, [&]()->void { SCENE->Set("title"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
}

void End::Update()
{
	if (INPUT->Down('M'))
	{
		OBJ->Add(new Mouse, "Mouse");
	}
}

void End::Render()
{
	//if (map)
	//	map->Render();
	bg->Render();
	switch (type)
	{
	case 1:
		IMG->Write("Clear!", V2{ CENTER.x,CENTER.y + 50 }, 80, D3DCOLOR_RGBA(100, 100, 255, 255));
		break;
	case 2:
		IMG->Write("I wish you success next time...");
		break;
	}
}

void End::Release()
{
	SAFE_DELETE(map);
}
