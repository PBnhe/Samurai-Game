


#include"MoveEnemyTest.h"
#include<sstream>

shinobi::shinobi() 
{
	stand = new Sprite("Resources/sprite_stand_0.png");
	standRight = new Sprite("Resources/sprite_stand_1.png");

	for (int i = 0; i < 8; i++) 
	{
		std::stringstream ss,ss2;
		ss << "Resources/sprite_walk_left_" << i << ".png";
		ss2<< "Resources/sprite_walk_right_" << i << ".png";
		walk_animation_L.push_back(new Sprite(ss2.str().c_str()));
		walk_animation_R.push_back(new Sprite(ss.str().c_str()));
		

	}

	for (int i = 0; i < 5; i++)
	{
		std::stringstream ss, ss2;
		ss << "Resources/sprite_first_attack_left_" << i << ".png";
		ss2 << "Resources/sprite_first_attack_right_" << i << ".png";
		first_attack_animation_sprites_L.push_back(new Sprite(ss2.str().c_str()));
		first_attack_animation_sprites_R.push_back(new Sprite(ss.str().c_str()));
	}
	for (int i = 0; i < 3; i++) 
	{
		std::stringstream ss, ss2;
		ss << "Resources/sprite_second_attack_right_" << i << ".png";
		ss2 << "Resources/sprite_second_attack_left_" << i << ".png";
		second_attack_animation_sprites_L.push_back(new Sprite(ss2.str().c_str()));
		second_attack_animation_sprites_R.push_back(new Sprite(ss.str().c_str()));
	}
	for (int i = 0; i < 4; i++) 
	{
		std::stringstream ss, ss2;
		ss << "Resources/sprite_third_attack_left_" << i << ".png";
		ss2 << "Resources/sprite_third_attack_right_" << i << ".png";
		third_attack_animation_sprites_L.push_back(new Sprite(ss.str().c_str()));
		third_attack_animation_sprites_R.push_back(new Sprite(ss2.str().c_str()));
	}

	for (int i = 0; i < 2; i++) 
	{
		std::stringstream ss,ss2;
		ss << "Resources/sprite_Hurt_L" << i << ".png";
		ss2 << "Resources/sprite_hurt_R" << i << ".png";
		hurt_sprites_L.push_back(new Sprite(ss.str().c_str()));
		hurt_sprites_R.push_back(new Sprite(ss2.str().c_str()));
	}
	for (int i = 0; i < 4; i++) 
	{
		std::stringstream ss, ss2;
		ss << "Resources/sprite_dead_L_" <<i << ".png";
		ss2 << "Resources/sprite_dead_R_" <<i << ".png";
		dead_sprites_L.push_back(new Sprite(ss2.str().c_str()));
		dead_sprites_R.push_back(new Sprite(ss.str().c_str()));



	}



	FirstAttackRangeL.x_Max = 1; FirstAttackRangeL.x_Min = 1;
	FirstAttackRangeL.y_Max = 1; FirstAttackRangeL.y_Min = 1;

	SecondAttackRangeL.x_Max = 1; SecondAttackRangeL.x_Min = 1;

	ThirdAttackRangeL.x_Max = 1; ThirdAttackRangeL.x_Min = 1;

		

	




}