


#ifndef ENEMY_MOVE
#define ENEMY_MOVE

#include "Object.h"
#include<vector>
#include"Sprite.h"
#include"Timer.h"
#include "Luci.h";
#include <cstdlib>



class Enemy_Move : public Object 
{
protected:
	
	
	Sprite* stand;
	Sprite* standRight;


	std::vector<Sprite*> walk_animation_R;
	std::vector<Sprite*> walk_animation_L;

	std::vector<Sprite*> first_attack_animation_sprites_R;
	std::vector<Sprite*> first_attack_animation_sprites_L;

	std::vector<Sprite*> second_attack_animation_sprites_R;
	std::vector<Sprite*> second_attack_animation_sprites_L;

	std::vector<Sprite*> third_attack_animation_sprites_R;
	std::vector<Sprite*> third_attack_animation_sprites_L;

	std::vector<Sprite*> hurt_sprites_L;
	std::vector<Sprite*> hurt_sprites_R;

	std::vector<Sprite*>dead_sprites_L;
	std::vector<Sprite*>dead_sprites_R;

	struct HitsRange
	{
		int x_Min, y_Min;
		int x_Max, y_Max;
	};
	HitsRange FirstAttackRangeR, SecondAttackRangeR, ThirdAttackRangeR;
	HitsRange FirstAttackRangeL, SecondAttackRangeL, ThirdAttackRangeL;

	
private:
	int vida;
	Timer * walkTime;
	Timer* attackTime;
	Timer* hurtTime;
	Timer* geraltime;
	Luci* jogador;
	Timer* deadtime;
	Timer* layTime;

	bool walking,walktimecontrol,HitStart,standing;
	bool geral;
	int direcTionPlayerControl,walkFrameC,walkFrameCR,HitCase,hurtFrame;
	int AttackFrame;
	bool unlockReset;

	float timeAccumulatorWalkL, timeAccumulatorWalkR,timeAccAttack;
	float timeAccHurt;
	int firstAttackHitFrame,secondAttackHitFrame,thirdAttackHitFrame;
	bool isHitting,hurted,islifezero;
	float timeaccdead;
	int deadframe;
	size_t maxFramesWalkL;
	bool deadtimercontrol;
	

	enum directions { right, left, up, down };

	struct HitBox_
	{
		int x1, y1;
		int x2, y2;

	};

	void walkControl();

	int WhereIsPlayer();
	void walkAnimationRight();
	void walkAnimationLeft();
	//funções para verificar se o jogador foi hitado com base em structs de pontos
	//cada animação diferente vai ter uma struct diferente para ser definida
	//com base em dois pontos da imagem
	bool isOnHitRange();
	

	void firstAttackAnimationL();
	void firstAttackAnimationR();

	void secondAttackAnimationL();
	void secondAttackAnimationR();

	void thirdAttaclAnimationL();
	void thirdAttackAnimationR();

	void isHittingPlayer();

	void isHittingMe();

	void hurtAnimation();

	void die();

	

public:
	

	void Update();

	void Draw();

	void Giveplayer(Luci* player_);

	Enemy_Move();

	


	

	


	




};





#endif // !ENEMY_MOVE
