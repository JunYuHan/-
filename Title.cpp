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
		bg = IMG->Add("title_background");
		
		start = new Button(IMG->Add("title_button_start"), { CENTER.x,CENTER.y + 90 }, "", 250, 70, 0.9, [&]()->void { SCENE->Set("stage1"); IMG->ReLoad("BG1"); },true);
		howto = new Button(IMG->Add("title_button_howto"), { CENTER.x,CENTER.y + 170 }, "", 250, 70, 0.9, [&]()->void {win_credit->On(); }, true);
		credit = new Button(IMG->Add("title_button_credit"), { CENTER.x,CENTER.y + 250 }, "", 250, 70, 0.9, [&]()->void { SCENE->Set("Credit"); }, true);
		exit = new Button(IMG->Add("title_button_exit"), { CENTER.x,CENTER.y + 330 }, "", 250, 70, 0.9, [&]()->void {PostQuitMessage(0); }, true);
		win_credit = new Window(IMG->Add("HowToPlay"), CENTER, 615, 770);
		break;
	}
}

void Title::Update()
{
	if (INPUT->Down('M'))
	{
		OBJ->Add(new Mouse, "Mouse");
	}
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
		if (win_credit->isOn)
		{
			start->Off();
			howto->Off();
			credit->Off();
			exit->Off();
		}
		else
		{
			start->On();
			howto->On();
			credit->On();
			exit->On();
		}
		break;
	}
	
}

void Title::Render()
{
	bg->Render();
}

void Title::Release()
{
	SAFE_DELETE(map);
}
