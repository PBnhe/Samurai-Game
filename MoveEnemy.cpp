


#include"MoveEnemy.h"


Enemy_Move::Enemy_Move()
{
	/*HitBox_ HitBox;
	HitBox.x1 = x;
	HitBox.y1 = y;

	HitBox.x2 = x + stand->Width();
	HitBox.y2 = y + stand->Height();*/

	

	
	
	walkTime = new Timer();
	attackTime = new Timer();
	walking = false;
	walktimecontrol = false;
	HitStart = false;
	standing = true;

	direcTionPlayerControl = left;
	AttackFrame = 0;
	timeAccumulatorWalkL = 0.0f;
	timeAccumulatorWalkR = 0.0f;
	hurtFrame = 0;
	walkFrameC = 0;
	walkFrameCR = 0;
	timeAccAttack = 0;
	HitCase = 0;
	maxFramesWalkL = 0;
	deadframe = 0;
	timeaccdead = 0;

	isHitting = false;

	hurted = false;
	hurtTime = new Timer();
	geraltime = new Timer();
	deadtime = new Timer();
	layTime = new Timer();

	jogador = nullptr;

	stand = nullptr;
	geral = false;
	islifezero = false;
	deadtimercontrol = false;
	unlockReset = false;

	



	vida = 100;




}






void Enemy_Move::Draw()
{
	if (!HitStart&&!hurted&&walking&&!islifezero)
	{
		walkControl();
	}
	


	if (HitStart&&!islifezero)
	{
		switch (HitCase)
		{
		case 0:
			if (direcTionPlayerControl == left)
			{
				firstAttackAnimationL();
				isHittingPlayer();
			}
			if (direcTionPlayerControl == right)
			{
				firstAttackAnimationR();
				isHittingPlayer();
			}
			break;

		case 1:
			if (direcTionPlayerControl == left)
			{
				secondAttackAnimationL();
				isHittingPlayer();
			}
			if (direcTionPlayerControl == right)
			{
				secondAttackAnimationR();
				isHittingPlayer();
			}

			break;

		case 2:
			if (direcTionPlayerControl == left)
			{
				thirdAttaclAnimationL();
				isHittingPlayer();
			}

			if (direcTionPlayerControl == right)
			{
				thirdAttackAnimationR();
				isHittingPlayer();
			}

			break;


		}
	}

	if (hurted && !islifezero)
	{
		hurtAnimation();

	}

	if (standing && !islifezero)
	{
		switch (direcTionPlayerControl) 
		{
		case left:
			stand->Draw(x, y, Layer::FRONT);
			break;
		case right:
			standRight->Draw(x, y, Layer::FRONT);
			break;

		}
	}

	if (islifezero) 
	{
		die();
	}


}





void Enemy_Move::Update()
{
	if (!hurted)
	{
		direcTionPlayerControl = WhereIsPlayer();
	}

	if (isOnHitRange() && !HitStart&&!hurted&&!islifezero)
	{
		HitStart = true;
		HitCase = rand() % 3;
		attackTime->Start();
		AttackFrame = 0;
		timeAccAttack = 0;
		walking = false;


	}
	
	if (!geral) 
	{
		geraltime->Start();
		geral = !geral;
	}
	if (geraltime->Elapsed() > 1) {
		standing = false;
		walking = true;
		geraltime->Stop();
	}

	

	isHittingMe();

	if (!islifezero)
	{
		if (vida <= 0)
		{
			islifezero = true;
			
			deadframe = 0;
				
				deadtime->Start();

			

		}
	}



}

void Enemy_Move::Giveplayer(Luci* player_)
{
	jogador = player_;
}



void Enemy_Move::walkAnimationRight()
{
	maxFramesWalkL = walk_animation_R.size();
	timeAccumulatorWalkR += walkTime->Elapsed();
	if (timeAccumulatorWalkR >= 0.125f)
	{
		walkFrameCR++;
		timeAccumulatorWalkR = 0.0f;
		walkTime->Reset();

	}
	walk_animation_R[walkFrameCR]->Draw(x, y, Layer::FRONT);
	if (walkFrameCR + 1 >= maxFramesWalkL)
	{
		walkFrameCR = 0;
		walkTime->Reset();
		walktimecontrol = false;
		walkTime->Stop();
	}
	

}

void Enemy_Move::walkAnimationLeft()
{
	maxFramesWalkL = walk_animation_L.size();

	timeAccumulatorWalkL += walkTime->Elapsed();
	if (timeAccumulatorWalkL >= 0.125f)
	{
		walkFrameC++;
		timeAccumulatorWalkL = 0.0f;
		walkTime->Reset();

	}
	
	walk_animation_L[walkFrameC]->Draw(x, y, Layer::FRONT);
	if (static_cast<size_t>(walkFrameC) + 1 >= maxFramesWalkL)
	{
		walkFrameC = 0;
		walkTime->Reset();
		walktimecontrol = false;
		walkTime->Stop();
	}
	

}

int  Enemy_Move::WhereIsPlayer()
{
	return (jogador->ReturnX() >= x) ? right : left;
}

void Enemy_Move::walkControl()
{
	if (walking)
	{
		if (!walktimecontrol)
		{
			walktimecontrol = true;
			walkTime->Start();
			walkFrameC = 0;
			walkFrameCR = 0;
			timeAccumulatorWalkR = 0;
			timeAccumulatorWalkL = 0;

		}
		if (direcTionPlayerControl == right)
		{
			walkAnimationRight();
			Translate(30 * gameTime, 0, Layer::FRONT);

		}
		if (direcTionPlayerControl == left)
		{
			walkAnimationLeft();
			Translate(-30 * gameTime, 0, Layer::FRONT);

		}


	}

}


bool Enemy_Move::isOnHitRange()
{
	if (jogador == nullptr)
	{
		return false;
	}

	if (direcTionPlayerControl == right)
	{
		return (
			(jogador->IsOnPlayerRange((FirstAttackRangeR.x_Min + FirstAttackRangeR.x_Max) / 2))
			||
			(jogador->IsOnPlayerRange((SecondAttackRangeR.x_Min + SecondAttackRangeR.x_Max) / 2))
			||
			(jogador->IsOnPlayerRange((ThirdAttackRangeR.x_Min + ThirdAttackRangeR.x_Max) / 2))
			);


	}
	if (direcTionPlayerControl == left)
	{
		return (
			(jogador->IsOnPlayerRange((FirstAttackRangeL.x_Min + FirstAttackRangeL.x_Max) / 2))
			||
			(jogador->IsOnPlayerRange((SecondAttackRangeL.x_Min + SecondAttackRangeL.x_Max) / 2))
			||
			(jogador->IsOnPlayerRange((ThirdAttackRangeL.x_Min + ThirdAttackRangeL.x_Max) / 2))
			);



	}



}


void Enemy_Move::firstAttackAnimationL()
{
	maxFramesWalkL = first_attack_animation_sprites_L.size();
	timeAccAttack += attackTime->Elapsed();

	if (timeAccAttack >= 0.1f)
	{
		AttackFrame++;
		timeAccAttack -= 0.1f;
	}

	if (AttackFrame != firstAttackHitFrame)
	{
		isHitting = false;
	}
	else
	{
		isHitting = true;
	}

	if (AttackFrame < maxFramesWalkL)
	{
		first_attack_animation_sprites_L[AttackFrame]->Draw(x, y, Layer::FRONT);

	}
	if (AttackFrame + 1 >= maxFramesWalkL)
	{

		HitStart = false;
		attackTime->Stop();
		attackTime->Reset();
		timeAccAttack = 0;
		walking = true;
	}





}

void Enemy_Move::firstAttackAnimationR()
{
	maxFramesWalkL = first_attack_animation_sprites_R.size();
	timeAccAttack += attackTime->Elapsed();

	if (timeAccAttack >= 0.1f)
	{
		AttackFrame++;
		timeAccAttack -= 0.1f;
	}

	if (AttackFrame != firstAttackHitFrame)
	{
		isHitting = false;
	}
	else
	{
		isHitting = true;
	}

	if (AttackFrame < maxFramesWalkL)
	{
		first_attack_animation_sprites_R[AttackFrame]->Draw(x, y, Layer::FRONT);

	}
	if (AttackFrame + 1 >= maxFramesWalkL)
	{

		HitStart = false;
		attackTime->Stop();
		attackTime->Reset();
		timeAccAttack = 0;
		walking = true;

	}






}

void Enemy_Move::secondAttackAnimationL()
{
	maxFramesWalkL = second_attack_animation_sprites_L.size();
	timeAccAttack += attackTime->Elapsed();

	if (timeAccAttack >= 0.1f)
	{
		AttackFrame++;
		timeAccAttack -= 0.1f;
	}

	if (AttackFrame != secondAttackHitFrame)
	{
		isHitting = false;
	}
	else
	{
		isHitting = true;
	}

	if (AttackFrame < maxFramesWalkL)
	{
		second_attack_animation_sprites_L[AttackFrame]->Draw(x, y, Layer::FRONT);

	}
	if (AttackFrame + 1 >= maxFramesWalkL)
	{

		HitStart = false;
		attackTime->Stop();
		attackTime->Reset();
		timeAccAttack = 0;
		walking = true;

	}


}

void Enemy_Move::secondAttackAnimationR()
{
	maxFramesWalkL = second_attack_animation_sprites_R.size();
	timeAccAttack += attackTime->Elapsed();

	if (timeAccAttack >= 0.1f)
	{
		AttackFrame++;
		timeAccAttack -= 0.1f;
	}

	if (AttackFrame != secondAttackHitFrame)
	{
		isHitting = false;
	}
	else
	{
		isHitting = true;
	}

	if (AttackFrame < maxFramesWalkL)
	{
		second_attack_animation_sprites_R[AttackFrame]->Draw(x, y, Layer::FRONT);

	}
	if (AttackFrame + 1 >= maxFramesWalkL)
	{

		HitStart = false;
		attackTime->Stop();
		attackTime->Reset();
		timeAccAttack = 0;
		walking = true;

	}


}

void Enemy_Move::thirdAttaclAnimationL()
{
	maxFramesWalkL = third_attack_animation_sprites_L.size();
	timeAccAttack += attackTime->Elapsed();

	if (timeAccAttack >= 0.1f)
	{
		AttackFrame++;
		timeAccAttack -= 0.1f;
	}

	if (AttackFrame != thirdAttackHitFrame)
	{
		isHitting = false;
	}
	else
	{
		isHitting = true;
	}

	if (AttackFrame < maxFramesWalkL)
	{
		third_attack_animation_sprites_L[AttackFrame]->Draw(x, y, Layer::FRONT);

	}
	if (AttackFrame + 1 >= maxFramesWalkL)
	{

		HitStart = false;
		attackTime->Stop();
		attackTime->Reset();
		timeAccAttack = 0;
		walking = true;

	}

}

void Enemy_Move::thirdAttackAnimationR()
{
	maxFramesWalkL = third_attack_animation_sprites_R.size();
	timeAccAttack += attackTime->Elapsed();

	if (timeAccAttack >= 0.1f)
	{
		AttackFrame++;
		timeAccAttack -= 0.1f;
	}

	if (AttackFrame != thirdAttackHitFrame)
	{
		isHitting = false;
	}
	else
	{
		isHitting = true;
	}

	if (AttackFrame < maxFramesWalkL)
	{
		third_attack_animation_sprites_R[AttackFrame]->Draw(x, y, Layer::FRONT);

	}
	if (AttackFrame + 1 >= maxFramesWalkL)
	{

		HitStart = false;
		attackTime->Stop();
		attackTime->Reset();
		timeAccAttack = 0;
		walking = true;

	}



}

void Enemy_Move::isHittingPlayer() 
{
	if (isHitting) 

	{
		if (direcTionPlayerControl == left)
		{
			switch (HitCase)

			{
			case 0:
				if ((
					(x + FirstAttackRangeL.x_Min > jogador->ReturnX() && x + FirstAttackRangeL.x_Min < jogador->ReturnX() + jogador->ReturnStandWidht()) //retorna stand width
					||
					(x + FirstAttackRangeL.x_Max > jogador->ReturnX() && x + FirstAttackRangeL.x_Max < jogador->ReturnX() + jogador->ReturnStandWidht())
					)
					&&
					(y + FirstAttackRangeL.y_Min > jogador->ReturnY() && y + FirstAttackRangeL.y_Min > jogador->ReturnY() + jogador->ReturnStandHeight())
					)
				{
					jogador->hitPlayer(10);
				}
				break;
			case 1:
				if ((
					(x + SecondAttackRangeL.x_Min > jogador->ReturnX() && x + SecondAttackRangeL.x_Min < jogador->ReturnX() + jogador->ReturnStandWidht()) //retorna stand width
					||
					(x + SecondAttackRangeL.x_Max > jogador->ReturnX() && x + SecondAttackRangeL.x_Max < jogador->ReturnX() + jogador->ReturnStandWidht())
					)
					&&
					(y + SecondAttackRangeL.y_Min > jogador->ReturnY() && y + SecondAttackRangeL.y_Min > jogador->ReturnY() + jogador->ReturnStandHeight())
					)
				{
					jogador->hitPlayer(10);
				}
				break;
			case 2:

				if ((
					(x + ThirdAttackRangeL.x_Min > jogador->ReturnX() && x + ThirdAttackRangeL.x_Min < jogador->ReturnX() + jogador->ReturnStandWidht()) //retorna stand width
					||
					(x + ThirdAttackRangeL.x_Max > jogador->ReturnX() && x + ThirdAttackRangeL.x_Max < jogador->ReturnX() + jogador->ReturnStandWidht())
					)
					&&
					(y + ThirdAttackRangeL.y_Min > jogador->ReturnY() && y + ThirdAttackRangeL.y_Min > jogador->ReturnY() + jogador->ReturnStandHeight())
					)
				{
					jogador->hitPlayer(10);
				}
				break;

			}



		}



		if (direcTionPlayerControl == right)
		{
			switch (HitCase)

			{
			case 0:
				if ((
					(x + FirstAttackRangeR.x_Min > jogador->ReturnX() && x + FirstAttackRangeR.x_Min < jogador->ReturnX() + jogador->ReturnStandWidht()) //retorna stand width
					||
					(x + FirstAttackRangeR.x_Max > jogador->ReturnX() && x + FirstAttackRangeR.x_Max < jogador->ReturnX() + jogador->ReturnStandWidht())
					)
					&&
					(y + FirstAttackRangeR.y_Min > jogador->ReturnY() && y + FirstAttackRangeR.y_Min > jogador->ReturnY() + jogador->ReturnStandHeight())
					)
				{
					jogador->hitPlayer(10);
				}
				break;
			case 1:
				if ((
					(x + SecondAttackRangeR.x_Min > jogador->ReturnX() && x + SecondAttackRangeR.x_Min < jogador->ReturnX() + jogador->ReturnStandWidht()) //retorna stand width
					||
					(x + SecondAttackRangeR.x_Max > jogador->ReturnX() && x + SecondAttackRangeR.x_Max < jogador->ReturnX() + jogador->ReturnStandWidht())
					)
					&&
					(y + SecondAttackRangeR.y_Min > jogador->ReturnY() && y + SecondAttackRangeR.y_Min > jogador->ReturnY() + jogador->ReturnStandHeight())
					)
				{
					jogador->hitPlayer(10);
				}
				break;
			case 2:

				if ((
					(x + ThirdAttackRangeR.x_Min > jogador->ReturnX() && x + ThirdAttackRangeR.x_Min < jogador->ReturnX() + jogador->ReturnStandWidht()) //retorna stand width
					||
					(x + ThirdAttackRangeR.x_Max > jogador->ReturnX() && x + ThirdAttackRangeR.x_Max < jogador->ReturnX() + jogador->ReturnStandWidht())
					)
					&&
					(y + ThirdAttackRangeR.y_Min > jogador->ReturnY() && y + ThirdAttackRangeR.y_Min > jogador->ReturnY() + jogador->ReturnStandHeight())
					)
				{
					jogador->hitPlayer(10);
				}
				break;

			}



		}
	}

}

void Enemy_Move::isHittingMe() 
{
	if (jogador->ReturnHit() || jogador->ReturnEnchancedHit() || jogador->ReturnPierceHit()&&!hurted) 
	{
		if (jogador->ReturnDiection() == 0) 
		{
			if (((jogador->ReturnX() + 72 > x && jogador->ReturnX() + 72 < x + stand->Width())
				||
				(jogador->ReturnX() + 82 > x && jogador->ReturnX() + 82 < x + stand->Width()))

				&&
				(jogador->ReturnY() + 35 > y
					&&
					jogador->ReturnY() + 35 < y + stand->Height())) 
			{
				hurted = true;
				hurtTime->Start();
				vida -= 10;

			}




		}
		if (jogador->ReturnDiection() == 1) 
		{
			if (((jogador->ReturnX() - 16 > x && jogador->ReturnX() - 16 < x + stand->Width())
				||
				(jogador->ReturnX() - 7 > x && jogador->ReturnX() - 7 < x + stand->Width()))

				&&
				(jogador->ReturnY() + 35 > y
					&&
					jogador->ReturnY() + 35 < y + stand->Height())) 
			{

				hurted = true;
				hurtTime->Start();
				vida -= 10;
			}




		}



	}

}

void Enemy_Move::hurtAnimation() 
{
	maxFramesWalkL = hurt_sprites_L.size();

	timeAccHurt += hurtTime->Elapsed();
	if (timeAccHurt >= 0.1f) 
	{
		hurtFrame++;
		timeAccHurt -= 0.1f;

	}
	if (hurtFrame < maxFramesWalkL) 
	{
		switch (direcTionPlayerControl) 
		{
		case right:
			hurt_sprites_R[hurtFrame]->Draw(x, y, Layer::FRONT);
			Translate(-3, 0);
			break;
		case left:
			hurt_sprites_L[hurtFrame]->Draw(x, y, Layer::FRONT);
			Translate(3, 0);
			break;
		}

	}
	if (hurtFrame + 1 >= maxFramesWalkL)
	{
		hurtFrame = 0;
		hurtTime->Stop();
		hurtTime->Reset();
		hurted = false;
	}




}

void Enemy_Move::die() 
{
	maxFramesWalkL = dead_sprites_L.size();
	timeaccdead += deadtime->Elapsed();

	if (deadframe + 1 != maxFramesWalkL)
	{
		if (timeaccdead >= 1.0f)
		{
			deadframe++;
			timeaccdead = 0;
			deadtime->Reset();

		}
	}

	if (deadframe < maxFramesWalkL)
	{
		switch (direcTionPlayerControl)
		{
		case right:
			dead_sprites_L[deadframe]->Draw(x, y, Layer::FRONT);
			break;
		case left:
			dead_sprites_R[deadframe]->Draw(x, y, Layer::FRONT);
			break;

		}
		if (deadframe + 1 == maxFramesWalkL) 
		{
			if (!unlockReset) 
			{
				layTime->Start();
			}

			unlockReset = true;
			
		}

	}
	if (unlockReset)
	{
		if (layTime->Elapsed() >= 2.0f)
		{
			
			
				vida = 100;
				MoveTo(200, 200);
				islifezero = false;
				deadtime->Stop();
				deadtime->Reset();
				deadtimercontrol = false;
				unlockReset = false;
				layTime->Reset();
				layTime->Stop();

			
		}
	}


}