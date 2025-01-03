





#ifndef _LUCI_H_
#define _LUCI_H_


#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include"Timer.h"


class Luci :public Object
{
private:
	int vida;

	Sprite* Stand;
	Sprite* stand_Left;

	Sprite* walk_Animation[8];
	Sprite* walk_Animation_Left[8];


	Sprite* basic_Attack_Animation[6];
	Sprite* basic_Attack_Animation_Left[6];


	Sprite* enchanced_Attack_Animation[4];
	Sprite* enchanced_Attack_Animation_Left[4];

	Sprite* pierce_Attack_Animation[3];
	Sprite* pierce_Attack_Animation_left[3];

	Sprite* jump_animation_sprites[12];
	Sprite* jump_animation_sprites_left[12];

	Sprite* parry_Animation_Sprites[2];
	Sprite* parry_Animation_Sprites_left[2];
	Sprite* hurtSprites_R[2];
	Sprite* hurtSprites_L[2];


	int FLOOR;
	float GravityPushY;
	float GravityAcceleration;
	bool IsOnFloor ;
	int MAX_GRAVITY_ACC;
	bool jumpCtrlKey;
	bool jumpTimerCtrlKey;
	Timer* JumpTime;
	float jumpMinusYdirectionAcceleration;

	Timer* walkTime;
	Timer* attackTime;
	Timer* enchancedAttackTime;
	Timer* pierceAttackTime;
	Timer* parryTime;
	Timer* hurtTime;



	bool walking,walkingLeft;

	bool attacking,attackCtrlKey,enchancedAttack,pierceAttackKeyControl,pierceAttack,parryCtrlKey,parrying;

	bool standing;

	float directionControl;

	bool JumpStage;

	void walkAnimation();

	void basicAttackAnimation();

	void enchancedAttackAnimation();

	void pierceAttackAnimation();

	void checkGravity();

	void Jump();

	void JumpAnimation();

	void ParryAnimation();

	void hurtAnimation();

	inline float ReturnDistanceToFloor();


	bool hitFrame, hitFrameEnchanced,hitPierceAttack,parry;
	bool hurted;

	
public:

	Luci();
	~Luci();

	void Update();
	void Draw();

	inline int ReturnX();
	inline int ReturnY();
	inline bool ReturnHit();
	inline int ReturnDiection();
	inline bool ReturnEnchancedHit();
	inline bool ReturnPierceHit();
	inline int ReturnStandWidht();
	inline int ReturnStandHeight();
	void hitPlayer(int vidaPerdida);



	bool IsOnPlayerRange(int xHit);
	

	

};

int Luci::ReturnX()
{
	return x;
}

int Luci::ReturnY()
{
	return y;
}

bool Luci::ReturnHit()
{
	return hitFrame;
}
int Luci::ReturnDiection() {
	return directionControl;
}
bool Luci::ReturnEnchancedHit() {
	return hitFrameEnchanced;
}
bool Luci::ReturnPierceHit(){

	return hitPierceAttack;
	
}
float Luci::ReturnDistanceToFloor() 
{
	return (FLOOR - (y+Stand->Height()));
}
int Luci::ReturnStandWidht() 
{
	return(Stand->Width());
}
int Luci::ReturnStandHeight() 
{
	return(Stand->Height());
}

#endif // !1
