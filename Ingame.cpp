#include "DXUT.h"
#include "Ingame.h"

extern int score;

int Ingame::stage = 1;

Ingame::Ingame(int type)
	:type(type)
{
}

void Ingame::Init()
{
	// 마우스 추가
	OBJ->Add(new Mouse, "Mouse");

	switch (type)
	{
	case 1:
		Ingame::stage = 1;
		Player::coloring_per = 0;
		OBJ->Add(new Enemy(3), "Boss")->pos = CENTER;
		OBJ->Add(new Enemy(1), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(1), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(2), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(2), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		score = 0;
		break;
	case 2:
		Ingame::stage = 2;
		Player::coloring_per = 0;
		OBJ->Add(new Enemy(4), "Boss")->pos = CENTER;
		OBJ->Add(new Enemy(6), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(6), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(1), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(1), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		break;
	case 3:
		Ingame::stage = 3;
		Player::coloring_per = 0;
		OBJ->Add(new Enemy(5), "Boss")->pos = CENTER;
		OBJ->Add(new Enemy(6), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(6), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(7), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		OBJ->Add(new Enemy(7), "Eenmy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
		break;
	}
	OBJ->Add(new Player, "player")->pos = { CENTER.x,float(B) };
	player = OBJ->Find("player");
	// 플레이어 추가 / 플레이어 찾기

	Ui_base = IMG->Add("ui_ingame_base");
	Ui_pause = new Button(IMG->Add("ui_ingame_pause button"), { 80 , Y - 10 }, "", 60, 60, 0.2, [&]()->void {SCENE->Set("title"); }, false);
	Ui_score = IMG->Add("ui_ingame_score");
	Ui_stage1 = IMG->Add("ui_ingame_stage1");
	Ui_stage2 = IMG->Add("ui_ingame_stage2");
	Ui_stage3 = IMG->Add("ui_ingame_stage3");
	Ui_precent = IMG->Add("ui_ingame_%");
	Ui_abled_life = IMG->Add("ui_ingame_life");
	Ui_unabled_life = IMG->Add("ui_ingame_life2");
	Ui_time = IMG->Add("ui_ingame_time");
	Ui_timer_tank = IMG->Add("ui_ingame_time tank");
	Ui_timer_bar = IMG->Add("ui_ingame_time bar");
	

	OBJ->Add(new Mouse, "Mouse");

	timer = 60;
	playtime = TIME->Create(timer);
}

void Ingame::Update()
{
	// M 누르면 마우스 추가
	if (INPUT->Down('M'))
	{
		OBJ->Add(new Mouse, "Mouse");
	}
	
	
	if (Player::coloring_per >=5)
	{
		switch (type)
		{
		case 1:
			IMG->ReLoad("BG1");
			stage = 2;
			SCENE->Set("clear stage1");

			break;
		case 2:
			SCENE->Set("stage3");
			SCENE->Set("clear stage2");

			break;
		case 3:
			SCENE->Set("clear");
			break;
		}
	}
	// 플레이어가 y130자표 이상 올라가면 Ui 올라감.	Player.y < 200
	if (player->pos.y <= 130)
	{
		if (Y > -18)
		{
			Y -= 4;
			Ui_pause->pos.y -= 4;
		}
	}

	else
	{
		if (Y < 60)
		{
			Y += 4;
			Ui_pause->pos.y += 4;
		}
	}
	playtime->Start();
}

void Ingame::Render()
{
	Ui_base->Render({ WINX / 2, Y }, RT_ZERO, { 1,1 }, 0, 0.2);
	Ui_score->Render({ 200, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
	Ui_precent->Render({ WINX / 2 + 35, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
	switch (type)
	{
	case 1: 
		Ui_stage1->Render({ 570,(Y - 20) }, RT_ZERO, { 1,1 }, 0, 0.2);
		break;
	case 2:
		Ui_stage2->Render({ 550,(Y - 20) }, RT_ZERO, { 1,1 }, 0, 0.2);
		break;
	case 3:
		Ui_stage3->Render({ 550,(Y - 20) }, RT_ZERO, { 1,1 }, 0, 0.2);
		break;
	}
	switch (player->hp)
	{
	case 1:
		Ui_unabled_life->Render({ WINX / 2 + 250, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_unabled_life->Render({ WINX / 2 + 180, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_abled_life->Render({ WINX / 2 + 110, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		break;
	case 2:
		Ui_unabled_life->Render({ WINX / 2 + 250, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_abled_life->Render({ WINX / 2 + 180, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_abled_life->Render({ WINX / 2 + 110, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		break;
	case 3:
		Ui_abled_life->Render({ WINX / 2 + 250, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_abled_life->Render({ WINX / 2 + 180, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_abled_life->Render({ WINX / 2 + 110, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		break;
	default:
		Ui_abled_life->Render({ WINX / 2 + 250, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_abled_life->Render({ WINX / 2 + 180, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		Ui_abled_life->Render({ WINX / 2 + 110, (Y - 10) }, RT_ZERO, { 1,1 }, 0, 0.2);
		break;
	}
	Ui_time->Render({ WINX / 2 + 400, (Y - 20) }, RT_ZERO, { 1,1 }, 0, 0.2);
	Ui_timer_tank->Render({ WINX / 2 + 640, (Y - 5) }, RT_ZERO, { 1,1 }, 0, 0.2);
	RECT hprt =
	{
		0,
		0,
		Ui_timer_bar->info.Width / playtime->set * playtime->cur,
		Ui_timer_bar->info.Height
	};
	Ui_timer_bar->Render({ WINX / 2 + 640, (Y - 5) }, hprt, { 1,1 }, 0, 0.1);

	char str[256];
	sprintf(str, "%.0f", Player::coloring_per * 500);		//스코어
	IMG->Write(str, { 310, Y - 42 }, 50, D3DCOLOR_XRGB(0, 0, 0), false);

	sprintf(str, "%.1f", Player::coloring_per);				//점령도
	IMG->Write(str, { WINX / 2 - 25, Y - 8 }, 50, D3DCOLOR_XRGB(0, 0, 0), true);
}

void Ingame::Release()
{

}
