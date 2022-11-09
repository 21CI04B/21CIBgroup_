//-----------------------------------------------------------------------------
//�L�����N�^�ėp�X�[�p�[�N���X
//-----------------------------------------------------------------------------
#include "BChara.h"
#include  "MyPG.h"
#include "sound.h"


//-----------------------------------------------------------------------------
//���[�V�������X�V�i�ύX�Ȃ��̏ꍇ	false)
bool  BChara::UpdateMotion(Motion  nm_)
{
	if (nm_ == this->motion) {
		return  false;
	}
	else {
		this->motion = nm_;		//���[�V�����ύX
		this->moveCnt = 0;		//�s���J�E���^�N���A
		this->animCnt = 0;		//�A�j���[�V�����J�E���^�̃N���A
		return  true;
	}
}
//-----------------------------------------------------------------------------
//�ڐG���̉�������(���ꎩ�̂̓_�~�[�̂悤�Ȃ���)
void BChara::Received(BChara* from_, AttackInfo at_)
{
	ML::MsgBox("Received ��������Ă��܂���");
}
//-----------------------------------------------------------------------------
//�ڐG����
bool BChara::CheckHit(const ML::Box2D& hit_)
{
	ML::Box2D me = this->hitBase.OffsetCopy(this->pos);
	return me.Hit(hit_);
}
//-----------------------------------------------------------------------------
//���Ԃ̉�]�p
void BChara::Rotate(int speed_)
{
	float mx = cos(atan2(1, 0)) * (6);
	float my = sin(atan2(1, 0)) * (6);
	this->pos.x += mx;
	this->pos.y += my;

	this->angle += ML::ToRadian(speed_);
}


