#include "DXUT.h"
#include "Button.h"

Button::Button(Texture* bg, V2 pos, const string& text, float w, float h, float depth, function<void()> func, bool T_B)
	:bg(bg), text(text), func(func), depth(depth), isOn(true), T_B(false)
{
	this->pos = pos;

	main_col = new Col(this, UI);

	W = w;
	H = h;
	b_pos = pos;

	title_button = T_B;


	OBJ->Add(this, "Button");
}

void Button::On()
{
	isOn = true;
	main_col->flag = true;
}

void Button::Off()
{
	isOn = false;
	main_col->flag = false;
}

void Button::Init()
{
	sword = IMG->Add("title_button_sword");
	swordX = pos.x - 1020;

	wait = TIME->Create(1);
}

void Button::Update()
{
	wait->Start();

	b_pos = this->pos;
	main_col->Set(b_pos, W, H);

	if (isClick)
	{
		if (swordX <= pos.x - 90)
		{
			swordX += 100;
		}
		else
		{
			if (wait->cur >= wait->set)
			{
				func();
				isClick = false;
			}
		}
	}
	else
	{
		swordX = pos.x - 1020;
	}
}

void Button::Render()
{
	if (isOn)
	{
		bg->Render(pos, RT_ZERO, { 1,1 }, 0, depth, D3DCOLOR_RGBA(r, g, b, 255));
		IMG->Write(text, pos);
		main_col->Draw();
		if (T_B_On)
		{
			sword->Render({ swordX,pos.y }, RT_ZERO, { 1,1.6 }, 0, 1);
		}
	}
}

void Button::Release()
{
	SAFE_DELETE(main_col);
}

void Button::Enter(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			if (title_button)
			{
				T_B_On = true;
			}
			r -= 100;
			g -= 100;
			b -= 100;
			break;
		}
}

void Button::Stay(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			if (INPUT->Down(VK_LBUTTON))
			{
				isClick = true;
			}
			break;
		}
}

void Button::Exit(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			if (title_button)
			{
				T_B_On = false;
			}
			r += 100;
			g += 100;
			b += 100;
			break;
		}
}
