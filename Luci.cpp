






#include "Luci.h"
#include<list>




Luci::Luci()
{
	Stand = new Sprite("Resources/idle.png");
	stand_Left = new Sprite("Resources/idle_Left.png");
	MoveTo(0, 275 - Stand->Height());
	walking = false;
	walkingLeft = false;
	standing = true;
	attacking = false;
	hitFrame = false;
	enchancedAttack = false;
	parry = false;
	parryCtrlKey = false;
	parrying = false;

	hitFrameEnchanced = false;

	vida = 100;
	hurted = false;
	hurtTime = new Timer();

	FLOOR =275;
	GravityAcceleration = 8;
	GravityPushY = 0;
	IsOnFloor = true;
	MAX_GRAVITY_ACC = 100;
	jumpCtrlKey=false;
	jumpTimerCtrlKey = false;
	JumpTime = new Timer();
	jumpMinusYdirectionAcceleration = 0;
	JumpStage = false;


	walkTime = new Timer();
	attackTime = new Timer();
	enchancedAttackTime = new Timer();
	pierceAttackTime = new Timer();
	parryTime = new Timer();

	directionControl = 0;
	attackCtrlKey = false;

	pierceAttackKeyControl = false;
	pierceAttack = false;

	hitPierceAttack = false;

	{
		walk_Animation[0] = new Sprite("Resources/sprite_walk_0.png");
		walk_Animation[1] = new Sprite("Resources/sprite_walk_1.png");
		walk_Animation[2] = new Sprite("Resources/sprite_walk_2.png");
		walk_Animation[3] = new Sprite("Resources/sprite_walk_3.png");
		walk_Animation[4] = new Sprite("Resources/sprite_walk_4.png");
		walk_Animation[5] = new Sprite("Resources/sprite_walk_5.png");
		walk_Animation[6] = new Sprite("Resources/sprite_walk_6.png");
		walk_Animation[7] = new Sprite("Resources/sprite_walk_7.png");

		walk_Animation_Left[0] = new Sprite("Resources/sprite_walk_left0.png");
		walk_Animation_Left[1] = new Sprite("Resources/sprite_walk_left1.png");
		walk_Animation_Left[2] = new Sprite("Resources/sprite_walk_left2.png");
		walk_Animation_Left[3] = new Sprite("Resources/sprite_walk_left3.png");
		walk_Animation_Left[4] = new Sprite("Resources/sprite_walk_left4.png");
		walk_Animation_Left[5] = new Sprite("Resources/sprite_walk_left5.png");
		walk_Animation_Left[6] = new Sprite("Resources/sprite_walk_left6.png");
		walk_Animation_Left[7] = new Sprite("Resources/sprite_walk_left7.png");

		basic_Attack_Animation[0] = new Sprite("Resources/sprite_attack_basic0.png");
		basic_Attack_Animation[1] = new Sprite("Resources/sprite_attack_basic1.png");
		basic_Attack_Animation[2] = new Sprite("Resources/sprite_attack_basic2.png");
		basic_Attack_Animation[3] = new Sprite("Resources/sprite_attack_basic3.png");
		basic_Attack_Animation[4] = new Sprite("Resources/sprite_attack_basic4.png");
		basic_Attack_Animation[5] = new Sprite("Resources/sprite_attack_basic5.png");

		basic_Attack_Animation_Left[0] = new Sprite("Resources/sprite_basic_attac_left0.png");
		basic_Attack_Animation_Left[1] = new Sprite("Resources/sprite_basic_attac_left1.png");
		basic_Attack_Animation_Left[2] = new Sprite("Resources/sprite_basic_attac_left2.png");
		basic_Attack_Animation_Left[3] = new Sprite("Resources/sprite_basic_attac_left3.png");
		basic_Attack_Animation_Left[4] = new Sprite("Resources/sprite_basic_attac_left4.png");
		basic_Attack_Animation_Left[5] = new Sprite("Resources/sprite_basic_attac_left5.png");

		enchanced_Attack_Animation[0] = new Sprite("Resources/sprite_Enchanced_Attack_0.png");
		enchanced_Attack_Animation[1] = new Sprite("Resources/sprite_Enchanced_Attack_1.png");
		enchanced_Attack_Animation[2] = new Sprite("Resources/sprite_Enchanced_Attack_2.png");
		enchanced_Attack_Animation[3] = new Sprite("Resources/sprite_Enchanced_Attack_3.png");

		enchanced_Attack_Animation_Left[0] = new Sprite("Resources/sprite_Enchanced_attack_left_0.png");
		enchanced_Attack_Animation_Left[1] = new Sprite("Resources/sprite_Enchanced_attack_left_1.png");
		enchanced_Attack_Animation_Left[2] = new Sprite("Resources/sprite_Enchanced_attack_left_2.png");
		enchanced_Attack_Animation_Left[3] = new Sprite("Resources/sprite_Enchanced_attack_left_3.png");

		pierce_Attack_Animation[0] = new Sprite("Resources/sprite_Pierce_Animation_0.png");
		pierce_Attack_Animation[1] = new Sprite("Resources/sprite_Pierce_Animation_1.png");
		pierce_Attack_Animation[2] = new Sprite("Resources/sprite_Pierce_Animation_2.png");
		pierce_Attack_Animation_left[0] = new Sprite("Resources/sprite_Pierce_attack_left_0.png");
		pierce_Attack_Animation_left[1] = new Sprite("Resources/sprite_Pierce_attack_left_1.png");
		pierce_Attack_Animation_left[2] = new Sprite("Resources/sprite_Pierce_attack_left_2.png");

		jump_animation_sprites[0] = new Sprite("Resources/sprite_jump_animation_00.png");
		jump_animation_sprites[1] = new Sprite("Resources/sprite_jump_animation_01.png");
		jump_animation_sprites[2] = new Sprite("Resources/sprite_jump_animation_02.png");
		jump_animation_sprites[3] = new Sprite("Resources/sprite_jump_animation_03.png");
		jump_animation_sprites[4] = new Sprite("Resources/sprite_jump_animation_04.png");
		jump_animation_sprites[5] = new Sprite("Resources/sprite_jump_animation_05.png");
		jump_animation_sprites[6] = new Sprite("Resources/sprite_jump_animation_06.png");
		jump_animation_sprites[7] = new Sprite("Resources/sprite_jump_animation_07.png");
		jump_animation_sprites[8] = new Sprite("Resources/sprite_jump_animation_08.png");
		jump_animation_sprites[9] = new Sprite("Resources/sprite_jump_animation_09.png");
		jump_animation_sprites[10] = new Sprite("Resources/sprite_jump_animation_10.png");
		jump_animation_sprites[11] = new Sprite("Resources/sprite_jump_animation_11.png");

		jump_animation_sprites_left[0] = new Sprite("Resources/sprite_jump_animation_sprites_left_00.png");
		jump_animation_sprites_left[1] = new Sprite("Resources/sprite_jump_animation_sprites_left_01.png");
		jump_animation_sprites_left[2] = new Sprite("Resources/sprite_jump_animation_sprites_left_02.png");
		jump_animation_sprites_left[3] = new Sprite("Resources/sprite_jump_animation_sprites_left_03.png");
		jump_animation_sprites_left[4] = new Sprite("Resources/sprite_jump_animation_sprites_left_04.png");
		jump_animation_sprites_left[5] = new Sprite("Resources/sprite_jump_animation_sprites_left_05.png");
		jump_animation_sprites_left[6] = new Sprite("Resources/sprite_jump_animation_sprites_left_06.png");
		jump_animation_sprites_left[7] = new Sprite("Resources/sprite_jump_animation_sprites_left_07.png");
		jump_animation_sprites_left[8] = new Sprite("Resources/sprite_jump_animation_sprites_left_08.png");
		jump_animation_sprites_left[9] = new Sprite("Resources/sprite_jump_animation_sprites_left_09.png");
		jump_animation_sprites_left[10] = new Sprite("Resources/sprite_jump_animation_sprites_left_10.png");
		jump_animation_sprites_left[11] = new Sprite("Resources/sprite_jump_animation_sprites_left_11.png");

		parry_Animation_Sprites[0] = new Sprite("Resources/sprite_parry_animation_0.png");
		parry_Animation_Sprites[1] = new Sprite("Resources/sprite_parry_animation_1.png");
		parry_Animation_Sprites_left[0] = new Sprite("Resources/sprite_parry_animation_sprites_left_0.png");
		parry_Animation_Sprites_left[1] = new Sprite("Resources/sprite_parry_animation_sprites_left_1.png");

		hurtSprites_R[0] = new Sprite("Resources/sprite_hurt_sprites_R0.png");
		hurtSprites_R[1] = new Sprite("Resources/sprite_hurt_sprites_R1.png");

		hurtSprites_L[0] = new Sprite("Resources/sprite_hurt_sprites_L0.png");
		hurtSprites_L[1] = new Sprite("Resources/sprite_hurt_sprites_L1.png");

	}//inits

}
Luci::~Luci()
{
	delete Stand;


}


void Luci::Draw()
{
	if (standing&&!attacking&&!enchancedAttack&&!pierceAttack&&IsOnFloor&&!parrying&&!hurted)
	{
		if(directionControl==0)
		Stand->Draw(x, y, Layer::FRONT);
		if (directionControl == 1)
			stand_Left->Draw(x, y, Layer::FRONT);
	}

	if (!attacking&&!enchancedAttack&&!pierceAttack&&IsOnFloor&&!parrying&&!hurted)
	{
		if (walking || walkingLeft)
		{
			if (walking)
			{
				directionControl = 0;
			}

			if (walkingLeft)
			{
				directionControl = 1;
			}
			walkAnimation();

		}
	}

	if (attacking&&!hurted)
	{

		basicAttackAnimation();

	}
	if (enchancedAttack && !hurted) {
		enchancedAttackAnimation();
	}
	if (pierceAttack && !hurted) {
		pierceAttackAnimation();
	}

	if (!IsOnFloor && !hurted) {
		JumpAnimation();
	}
	if (parrying && !hurted) {
		ParryAnimation();
	}

	if (hurted) 
	{
		hurtAnimation();
	}

}


void Luci::Update() 
{
	checkGravity();

	




	if (window->KeyDown(VK_RIGHT) && !hurted)
	{
		Translate(50 * gameTime,0 );
		if (!walking) {
			walkTime->Start();
			
		}
		if (walkingLeft) {
			walkingLeft = false;
		}

		standing = false;
		walking = true;

		
	

	}
	if (window->KeyDown(VK_LEFT) && !hurted)
	{
		Translate(-(50 * gameTime), 0);
		if (!walkingLeft) {
			walkTime->Start();
			
		}
		if (walking) {
			walking = false;
		}

		standing = false;
		walkingLeft = true;

	}

	if (window->KeyUp(VK_RIGHT)) 
	{
		if (walking) 
		{
			walkTime->Stop();
			walkTime->Reset();
		}
		
		walking = false;
		if (!walkingLeft && !walking) {
			standing = true;
		}


	}
	if (window->KeyUp(VK_LEFT))
	{
		if (walkingLeft)
		{
			walkTime->Stop();
			walkTime->Reset();
		}

		

		walkingLeft = false;
		if (!walkingLeft && !walking) {
			standing = true;
		}

	}

	if (window->KeyDown(0x5A) && !hurted)
	{

		if (!attackCtrlKey)
		{
			attackCtrlKey = !attackCtrlKey;
			attacking = true;
			standing = false;
			pierceAttack = false;
			attackTime->Start();
		}

	}
	if (window->KeyUp(0x5A)) //z
	{
		if (attackCtrlKey) 
		{
			attackCtrlKey = !attackCtrlKey;
		}

	}

	if (window->KeyDown(0x58) && !hurted) //x
	{
		if (!pierceAttackKeyControl) 
		{
			pierceAttackKeyControl = !pierceAttackKeyControl;

			pierceAttack = true;
			//attacking = false;
			standing = false;
			pierceAttackTime->Start();


		}

	}

	if (window->KeyUp(0x58)) {
		if (pierceAttackKeyControl)
			pierceAttackKeyControl = !pierceAttackKeyControl;
	}//x

	if (window->KeyDown(0x43) && !hurted)
	{
		if (!parryCtrlKey) 
		{
			parryCtrlKey = !parryCtrlKey;
			parryTime->Start();
			parrying = true;



		}


	}//c
	if (window->KeyUp(0x43)) 
	{
		if (parryCtrlKey) 
		{
			parryCtrlKey = !parryCtrlKey;
		
		}

	}

	if (window->KeyDown(VK_SPACE) && !hurted)
	{
		if (!jumpCtrlKey)
		{


			if (!jumpTimerCtrlKey)
			{
				JumpTime->Start();
				jumpTimerCtrlKey = !jumpTimerCtrlKey;
			}

			if (JumpTime->Elapsed() < 0.5) 
			{
				Jump();
			}
			if (JumpTime->Elapsed() > 0.5) 
			{
				jumpCtrlKey = true;
				
			}


		}
		



	}

	if (window->KeyUp(VK_SPACE)) 
	{ 
		if (JumpTime->Elapsed() > 0.1) {
			if (IsOnFloor)
			{
				jumpTimerCtrlKey = false;
				jumpCtrlKey = false;
				JumpTime->Stop();
				JumpTime->Reset();
				jumpMinusYdirectionAcceleration = 0;
			}
		}

	}

}

void Luci::walkAnimation()
{
	float caso = walkTime->Elapsed();

	if (directionControl == 0)
	{
		if (caso > 0 && caso <= 0.125f)
		{
			walk_Animation[0]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.125f && caso <= 0.250f)
		{
			walk_Animation[1]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.250f && caso <= 0.375f)
		{
			walk_Animation[2]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.375f && caso <= 0.5f)
		{
			walk_Animation[3]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.5f && caso <= 0.625f)
		{
			walk_Animation[4]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.625f && caso <= 0.750f)
		{
			walk_Animation[5]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.750f && caso <= 0.875)
		{
			walk_Animation[6]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.875f) {
			walk_Animation[7]->Draw(x, y, Layer::FRONT);
			walkTime->Reset();
		}
	}
	if (directionControl == 1)
	{
		if (caso > 0 && caso <= 0.125f)
		{
			walk_Animation_Left[0]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.125f && caso <= 0.250f)
		{
			walk_Animation_Left[1]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.250f && caso <= 0.375f)
		{
			walk_Animation_Left[2]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.375f && caso <= 0.5f)
		{
			walk_Animation_Left[3]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.5f && caso <= 0.625f)
		{
			walk_Animation_Left[4]->Draw(x, y, Layer::FRONT);
			
		}
		if (caso > 0.625f && caso <= 0.750f)
		{
			walk_Animation_Left[5]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.750f && caso <= 0.875)
		{
			walk_Animation_Left[6]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.875f) {
			walk_Animation_Left[7]->Draw(x, y, Layer::FRONT);
			walkTime->Reset();
		}




	}


}


void Luci::basicAttackAnimation() 
{
int	tempx = x;
int tempy = y;




	float caso = attackTime->Elapsed();

	if (directionControl == 0) 
	{
		x -= 20;
		y += 10;
		if (caso > 0 && caso <= 0.1f)
		{
			basic_Attack_Animation[0]->Draw(x, y, Layer::FRONT);
			hitFrame = false;
			enchancedAttack = false;
			hitFrameEnchanced = false;
			hitPierceAttack = false;

		}

		if (caso > 0.1 && caso <= 0.2f)
		{
			basic_Attack_Animation[1]->Draw(x, y, Layer::FRONT);
		}

		if (caso > 0.2 && caso <= 0.3f)
		{
			basic_Attack_Animation[2]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.3 && caso <= 0.4f)
		{
			basic_Attack_Animation[3]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.4 && caso <= 0.5f)
		{
			basic_Attack_Animation[4]->Draw(x, y, Layer::FRONT);
			hitFrame = true;
			
			

		}
		if (caso > 0.5 && caso <= 0.6f)
		{
			basic_Attack_Animation[5]->Draw(x, y, Layer::FRONT);
			hitFrame = false;

			if (window->KeyDown(0X5A))
			{
				attackTime->Stop();
				attackTime->Reset();
				standing = true;
				attacking = false;
				enchancedAttack = true;
				enchancedAttackTime->Start();

			}

		}
		if (caso > 0.6 && caso <= 0.7f)
		{
			basic_Attack_Animation[3]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.7 && caso <= 0.8f)
		{
			basic_Attack_Animation[2]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.8 && caso <= 0.9f)
		{
			basic_Attack_Animation[1]->Draw(x, y, Layer::FRONT);
			attackTime->Stop();
			attackTime->Reset();
			standing = true;
			attacking = false;
			hitFrameEnchanced = false;

		}
	}




	if (directionControl == 1) 
	{
		x -= 20;
		y += 10;
		if (caso > 0 && caso <= 0.1f)
		{
			basic_Attack_Animation_Left[0]->Draw(x, y, Layer::FRONT);
			hitFrame = false;
			enchancedAttack = false;
			hitPierceAttack = false;
		}

		if (caso > 0.1 && caso <= 0.2f)
		{
			basic_Attack_Animation_Left[1]->Draw(x, y, Layer::FRONT);
		}

		if (caso > 0.2 && caso <= 0.3f)
		{
			basic_Attack_Animation_Left[2]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.3 && caso <= 0.4f)
		{
			basic_Attack_Animation_Left[3]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.4 && caso <= 0.5f)
		{
			basic_Attack_Animation_Left[4]->Draw(x, y, Layer::FRONT);
			hitFrame = true;
		}
		if (caso > 0.5 && caso <= 0.6f)
		{
			basic_Attack_Animation_Left[5]->Draw(x, y, Layer::FRONT);
			hitFrame = false;
			if (window->KeyDown(0X5A))
			{
				attackTime->Stop();
				attackTime->Reset();
				standing = true;
				attacking = false;
				enchancedAttack = true;
				enchancedAttackTime->Start();

			}

		}
		if (caso > 0.6 && caso <= 0.7f)
		{
			basic_Attack_Animation_Left[3]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.7 && caso <= 0.8f)
		{
			basic_Attack_Animation_Left[2]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.8 && caso <= 0.9f)
		{
			basic_Attack_Animation_Left[1]->Draw(x, y, Layer::FRONT);
			attackTime->Stop();
			attackTime->Reset();
			standing = true;
			attacking = false;
			enchancedAttack = false;

		}

	}










	x = tempx;
	y = tempy;

}


void Luci::enchancedAttackAnimation()
{
	int	tempx = x;
	int tempy = y;
	x -= 20;
	y += 10;


	float caso = enchancedAttackTime->Elapsed();
	if (directionControl == 0) {

		if (caso > 0 && caso <= 0.1f) {
			enchanced_Attack_Animation[0]->Draw(x, y, Layer::FRONT);
			hitFrameEnchanced = false;
		}
		if (caso > 0.1 && caso <= 0.2f) {
			enchanced_Attack_Animation[1]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.2 && caso <= 0.3f) {
			enchanced_Attack_Animation[2]->Draw(x, y, Layer::FRONT);
			hitFrameEnchanced = true;

		}
		if (caso > 0.3 && caso <= 0.4f) {
			enchanced_Attack_Animation[3]->Draw(x, y, Layer::FRONT);
			enchancedAttackTime->Stop();
			enchancedAttackTime->Reset();
			enchancedAttack = false;
			hitFrameEnchanced = false;
		}
	}

	if (directionControl == 1) 
	{
		if (caso > 0 && caso <= 0.1f) {
			enchanced_Attack_Animation_Left[0]->Draw(x, y, Layer::FRONT);
			hitFrameEnchanced = false;
		}
		if (caso > 0.1 && caso <= 0.2f) {
			enchanced_Attack_Animation_Left[1]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.2 && caso <= 0.3f) {
			enchanced_Attack_Animation_Left[2]->Draw(x, y, Layer::FRONT);
			hitFrameEnchanced = true;

		}
		if (caso > 0.3 && caso <= 0.4f) {
			enchanced_Attack_Animation_Left[3]->Draw(x, y, Layer::FRONT);
			enchancedAttackTime->Stop();
			enchancedAttackTime->Reset();
			enchancedAttack = false;
			hitFrameEnchanced = false;
		}







	}







	x = tempx;
	y = tempy;


}

void Luci::pierceAttackAnimation() 
{

	int tempx = x;
	int tempy = y;

	x -= 20;
	y += 10;

	float caso = pierceAttackTime->Elapsed();
	
	if (directionControl == 0) {
		if (caso > 0 && caso <= 0.1) {
			basic_Attack_Animation[0]->Draw(x, y, Layer::FRONT);
			hitPierceAttack = false;
		}
		if (caso > 0.1 && caso <= 0.2) {
			basic_Attack_Animation[1]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.2 && caso <= 0.3) {
			basic_Attack_Animation[2]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.3 && caso <= 0.4) {
			basic_Attack_Animation[3]->Draw(x, y, Layer::FRONT);
		}

		if (caso > 0.4 && caso <= 0.5) {
			pierce_Attack_Animation[0]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.5 && caso <= 0.6) {
			pierce_Attack_Animation[1]->Draw(x, y, Layer::FRONT);//HIT
			hitPierceAttack = true;
		}
		if (caso > 0.6 && caso <= 0.7) {
			pierce_Attack_Animation[2]->Draw(x, y, Layer::FRONT);
			hitPierceAttack = false;
			pierceAttackTime->Stop();
			pierceAttackTime->Reset();
			pierceAttack = false;
		}

		

	}
	if (directionControl == 1) 
	{
		if (caso > 0 && caso <= 0.1) {
			basic_Attack_Animation_Left[0]->Draw(x, y, Layer::FRONT);
			hitPierceAttack = false;
		}
		if (caso > 0.1 && caso <= 0.2) {
			basic_Attack_Animation_Left[1]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.2 && caso <= 0.3) {
			basic_Attack_Animation_Left[2]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.3 && caso <= 0.4) {
			basic_Attack_Animation_Left[3]->Draw(x, y, Layer::FRONT);
		}

		if (caso > 0.4 && caso <= 0.5) {
			pierce_Attack_Animation_left[0]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.5 && caso <= 0.6) {
			pierce_Attack_Animation_left[1]->Draw(x, y, Layer::FRONT);//HIT
			hitPierceAttack = true;
		}
		if (caso > 0.6 && caso <= 0.7) {
			pierce_Attack_Animation_left[2]->Draw(x, y, Layer::FRONT);
			hitPierceAttack = false;
			pierceAttackTime->Stop();
			pierceAttackTime->Reset();
			pierceAttack = false;
		}

	}
	x = tempx;
	y = tempy;


}
 
void Luci::checkGravity() 
{
	if (FLOOR-Stand->Height() < FLOOR) 
	{
		
		GravityPushY += GravityAcceleration * gameTime;
		if (GravityPushY > MAX_GRAVITY_ACC) {
			GravityPushY = MAX_GRAVITY_ACC;
		}
		IsOnFloor = false;
		Translate(0, GravityPushY , Layer::FRONT);


	}

	if (y+Stand->Height() > FLOOR)
	{
		IsOnFloor = true;
		y = FLOOR - Stand->Height();
		JumpStage = false;

		GravityPushY = 0;
	}




}

void Luci::Jump() 
{
	//jumpMinusYdirectionAcceleration += 20 * gameTime; 
	//if (jumpMinusYdirectionAcceleration > 70) {
	//	jumpMinusYdirectionAcceleration = 70;
	//}
	
	
	Translate(0, -400*gameTime, Layer::FRONT);


}

void Luci::JumpAnimation() 
{
	float caso = JumpTime->Elapsed();

	if (directionControl == 0) 
	{
		if (caso > 0 && caso <= 0.02)
		{
			jump_animation_sprites[0]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.02 && caso <= 0.04)
		{
			jump_animation_sprites[1]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.04 && caso <= 0.06)
		{
			jump_animation_sprites[2]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.06 && caso <= 0.08)
		{
			jump_animation_sprites[3]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.1 && caso <= 0.12)
		{
			jump_animation_sprites[4]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.12 && caso <= 0.14) {
			jump_animation_sprites[5]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.14 && ReturnDistanceToFloor() <= 100 && !JumpStage) {
			jump_animation_sprites[6]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.14 && ReturnDistanceToFloor() > 100) {
			jump_animation_sprites[7]->Draw(x, y, Layer::FRONT);
			JumpStage = true;
		}
		if (caso > 0.14 && ReturnDistanceToFloor() <= 100 && JumpStage && ReturnDistanceToFloor() > 60)
		{
			jump_animation_sprites[8]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.14 && ReturnDistanceToFloor() < 60 && JumpStage)
		{
			jump_animation_sprites[9]->Draw(x, y, Layer::FRONT);
		}
	}
	if (directionControl == 1)
	{
		if (caso > 0 && caso <= 0.02)
		{
			jump_animation_sprites_left[0]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.02 && caso <= 0.04)
		{
			jump_animation_sprites_left[1]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.04 && caso <= 0.06)
		{
			jump_animation_sprites_left[2]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.06 && caso <= 0.08)
		{
			jump_animation_sprites_left[3]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.1 && caso <= 0.12)
		{
			jump_animation_sprites_left[4]->Draw(x, y, Layer::FRONT);

		}
		if (caso > 0.12 && caso <= 0.14) {
			jump_animation_sprites_left[5]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.14 && ReturnDistanceToFloor() <= 100 && !JumpStage) {
			jump_animation_sprites_left[6]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.14 && ReturnDistanceToFloor() > 100) {
			jump_animation_sprites_left[7]->Draw(x, y, Layer::FRONT);
			JumpStage = true;
		}
		if (caso > 0.14 && ReturnDistanceToFloor() <= 100 && JumpStage && ReturnDistanceToFloor() > 60)
		{
			jump_animation_sprites_left[8]->Draw(x, y, Layer::FRONT);
		}
		if (caso > 0.14 && ReturnDistanceToFloor() < 60 && JumpStage)
		{
			jump_animation_sprites_left[9]->Draw(x, y, Layer::FRONT);
		}

	}





}

void Luci::ParryAnimation() 
{
	float caso = parryTime->Elapsed();

	if (directionControl == 0) {
		if (caso > 0 && caso <= 0.1) {
			parry_Animation_Sprites[0]->Draw(x, y, Layer::FRONT);
			parry = false;

		}
		if (caso > 0.1 && caso <= 0.15) {
			parry_Animation_Sprites[1]->Draw(x, y, Layer::FRONT);
			parry = true;
		}
		if (caso > 0.15 && caso <= 0.2) {
			parry_Animation_Sprites[0]->Draw(x, y, Layer::FRONT);
			parry = false;
			parryTime->Stop();
			parryTime->Reset();
			parrying = false;

		}
	}

	if (directionControl == 1) 
	{
		if (caso > 0 && caso <= 0.1) {
			parry_Animation_Sprites_left[0]->Draw(x, y, Layer::FRONT);
			parry = false;

		}
		if (caso > 0.1 && caso <= 0.15) {
			parry_Animation_Sprites_left[1]->Draw(x, y, Layer::FRONT);
			parry = true;
		}
		if (caso > 0.15 && caso <= 0.2) {
			parry_Animation_Sprites_left[0]->Draw(x, y, Layer::FRONT);
			parry = false;
			parryTime->Stop();
			parryTime->Reset();
			parrying = false;

		}

	}

}

bool Luci::IsOnPlayerRange(int xHit) 
{
	return (xHit > x && xHit < x + Stand->Width());
		


}

void Luci::hitPlayer(int vidaPerdida) 
{
	hurted = true;
	vida -= vidaPerdida;
	hurtTime->Start();
}

void Luci::hurtAnimation() 
{
	float caso = hurtTime->Elapsed();
	if (directionControl == 0) 
	{
		if (caso > 0 && caso <= 0.1)
		{
			hurtSprites_R[0]->Draw(x, y, Layer::FRONT);
			Translate(-5, -5);
		}
		if (caso > 0.1) {
			hurtSprites_R[1]->Draw(x, y, Layer::FRONT);
			Translate(-5, 0);
			hurted = false;
			hurtTime->Stop();
			hurtTime->Reset();
		}
	}
	if (directionControl == 1)
	{
		if (caso > 0 && caso <= 0.1)
		{
			hurtSprites_L[0]->Draw(x, y, Layer::FRONT);
			Translate(5, -5);
		}
		if (caso > 0.1) {
			hurtSprites_L[1]->Draw(x, y, Layer::FRONT);
			Translate(5, 0);
			hurted = false;
			hurtTime->Stop();
			hurtTime->Reset();
		}
	}


}