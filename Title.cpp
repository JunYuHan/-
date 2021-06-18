#include "DXUT.h"
#include "Title.h"

Title::Title(int type)
	:bg(), map(), type(type)
{
}

void Title::Init()
{
	OBJ->Add(new Mouse, "Mouse");

	/*map = new ScrollMap(IMG->Add("Bg", "Bg"));*/

	switch (type)
	{
	case 1:
		anim = vector<Texture*>
		{
			IMG->Add("intro1"),
			IMG->Add("intro2"),
			IMG->Add("intro3"),
			IMG->Add("intro4"),
			IMG->Add("intro5"),
		};

		delay = TIME->Create(1);
		delay->Start();
		break;
	case 2:
		bg = IMG->Add("HowToPlay");
		start = new Button(IMG->Add(""), { CENTER.x + 350,CENTER.y + 90 }, "",200,70, 1, [&]()->void {SCENE->Set("stage1"); });
		HowTo = new Button(IMG->Add(""), {CENTER.x + 650,CENTER.y + 200},"",200,70,1, [&]()->void {SCENE->Set("Credit"); });
		credit = new Button(IMG->Add(""), { CENTER.x + 650,CENTER.y + 140 }, "", 200, 70, 1, [&]()->void {win_credit->On(); });
		end = new Button(IMG->Add(""), { CENTER.x + 650,CENTER.y + 365 }, "", 200, 70, 1, [&]()->void {PostQuitMessage(0); });
		
		win_credit = new Window(IMG->Add("HowToPlay"), CENTER, 900, 900);
		break;
	}
}

void Title::Update()
{
	switch (type)
	{
	case 1:
		if (INPUT->Down(VK_RETURN))
			SCENE->Set("title");
		if (delay->IsStop())
		{
			index++;
			delay->Start();
			if (index == anim.size())
				SCENE->Set("title");
		}
		break;
	case 2:
		//if (map)
		//	map->Update(500);
		break;
	}
}

void Title::Render()
{
	switch (type)
	{
	case 1:
		anim[index]->Render();
		break;
	case 2:
		//if (map)
		//	map->Render();
		IMG->Add("Bg")->Render();
		break;
	}
}

void Title::Release()
{
	SAFE_DELETE(map);
}
