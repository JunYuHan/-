#pragma once
#include "Obj.h"
class Enemy :
    public Obj
{
public:
    Enemy(int type);

    vector<Effect*> fxs;
    Texture* img;
    Timer* timer;
    Timer* during;
    V2 size;
    V2 dir;

    float cool;
    float rot;
    int type;
    int spin_force;

    vector<V2> sizes = vector<V2>
    { //적 크기
        {0.5f,0.5f}, //0
        {1,1}, //1
        {9,9}, //2
        {4,4}, //3
        {8,9}, //4
        {12,6}, //5 
        {15,14}, //6 
        {7,7}, //7 
    };

    vector<float> speeds = vector<float>
    {               //적 스피드
        0.5f, //0
        0.75f, //1
        1, //2 
        1.25f, //3 
        1.5f, //4 
        4, //5
        7, //6

    };

    void Flash();
    void Rush();
    void Shot(int shots);

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

