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
	case 1: //¸ðµç ½ºÅ×ÀÌÁö¸¦ ³¡³ÂÀ» ¶§
		bg = IMG->Add("Success");restart = new Button(IMG->Add("return"), { CENTER.x - 550,CENTER.y + 300 }, "", 400, 150, 1, [&]()->void { SCENE->Set("stage1"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		title = new Button(IMG->Add("menu"), { CENTER.x +550 ,CENTER.y + 300 }, "", 400, 170, 1, [&]()->void { SCENE->Set("title"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		break;
	case 2: //Á×¾úÀ» ¶§
		bg = IMG->Add("Failure");
		restart = new Button(IMG->Add("return"), { CENTER.x - 300,CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("stage1"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		title = new Button(IMG->Add("menu"), { CENTER.x + 300,CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("title"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		break;
	case 3: //1stage ²¢À» ¶§
		bg = IMG->Add("Success"); restart = new Button(IMG->Add("return"), { CENTER.x - 550,CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("stage1"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		title = new Button(IMG->Add("menu"), { CENTER.x + 0,CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("title"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		next = new Button(IMG->Add("next"), { CENTER.x + 550,CENTER.y + 300 }, "", 440, 180, 1, [&]()->void { SCENE->Set("stage2"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		break;
	case 4: //2stage ²¢À» ¶§
		bg = IMG->Add("Success"); restart = new Button(IMG->Add("return"), { CENTER.x - 550,CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("stage1"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		title = new Button(IMG->Add("menu"), { CENTER.x + 0,CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("title"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		next = new Button(IMG->Add("next"), { CENTER.x + 550,CENTER.y + 300 }, "", 440, 180, 1, [&]()->void { SCENE->Set("stage3"); IMG->ReLoad("BG1"); IMG->ReLoad("BG3"); }, false);
		break;
	}
	OBJ->Add(new Mouse, "Mouse");

	//map = new ScrollMap(IMG->Add("Bg"));
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
	/*switch (type)
	{
	case 1:
		IMG->Write("Clear!", V2{ CENTER.x,CENTER.y + 50 }, 80, D3DCOLOR_RGBA(100, 100, 255, 255));
		break;
	case 2:
		IMG->Write("I wish you success next time...");
		break;
	} */
}

void End::Release()
{
	SAFE_DELETE(map);
}
