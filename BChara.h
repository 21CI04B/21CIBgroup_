#pragma once
#pragma warning(disable:4996)
#pragma once
//-----------------------------------------------------------------------------
//�L�����N�^�ėp�X�[�p�[�N���X
//-----------------------------------------------------------------------------
#include "GameEngine_Ver3_83.h"

class BChara : public BTask
{
	//�ύX�s����������������������������������������������������
public:
	typedef shared_ptr<BChara>		SP;
	typedef weak_ptr<BChara>		WP;
public:
	//�ύX������������������������������������������������������
	//�L�����N�^���ʃ����o�ϐ�
	ML::Vec2    pos;		//�L�����N�^�ʒu
	ML::Box2D   hitBase;	//�����蔻��͈�
	ML::Vec2	moveVec;	//�ړ��x�N�g��
	int			moveCnt;	//�s���J�E���^
	int         moveCntMax; //�ő�s���J�E���^
	int         number;     //���ʗp�i���o�[
	int         spornX, spornY; //�o���n�_(�z��p)
	bool        meDeath;
	int			hp;
	//���E�̌����i2D�����_�Q�[����p�j
	enum class Angle_LR { Left, Right };
	Angle_LR	angle_LR;
	WP			target;

	//�L�����N�^�̍s����ԃt���O
	enum class Motion
	{
		Unnon = -1,	//	����(�g���܂���j
		Stand,		//	��~
		Walk,		//	���s
		Walkturn,	//	���s(�A��)
		Attack,		//	�U����
		Attack2,		//	�U����2
		JumpAttack,		//	�W�����v�U����
		JumpAttack2,    //	�W�����v�U����2
		Jump,		//	�W�����v
		Fall,		//	����
		Jump2,		//	�W�����v2
		Fall2,		//	����2
		TakeOff,	//	��ї��u��
		Landing,	//	���n
		Turn,       //  �^�[��
		Bound,      //�@�e����΂���Ă�
		Counterderay, //�J�E���^�[���͎�
		CounterAtk, //�J�E���^�[�U��
		Lose,       //�@���Œ�
		Defence,
		Have,
		Death,
		Havestand
	};
	Motion			motion;			//	���݂̍s���������t���O
	int				animCnt;		//�A�j���[�V�����J�E���^
	float			jumpPow;		//	�W�����v����
	float			maxFallSpeed;	//	�����ő呬�x
	float			gravity;		//	�t���[���P�ʂ̉��Z��
	float			maxSpeed;		//	���E�����ւ̈ړ��̉��Z��
	float			addSpeed;		//	���E�����ւ̈ړ��̉��Z��
	float			decSpeed;		//	���E�����ւ̈ړ��̌�����
	int             honey;             //�ő�HP
	int             unHitTime;      //���G����
	DG::Image::SP   debugimage;      //�f�o�b�O�p



	//�����o�ϐ��ɍŒ���̏��������s��
	//���������o�ϐ���ǉ�������K�����������ǉ����鎖����
	BChara()
		: pos(0, 0)
		, hitBase(0, 0, 0, 0)
		, moveVec(0, 0)
		, moveCnt(0)
		, angle_LR(Angle_LR::Right)
		, motion(Motion::Stand)
		, jumpPow(0)
		, maxFallSpeed(0)
		, gravity(0)
		, maxSpeed(0)
		, addSpeed(0)
		, decSpeed(0)
		, honey(0)
		, unHitTime(0)
		, meDeath(false)
		, hp(1)
	{
	}
	virtual  ~BChara() {}

	//�L�����N�^���ʃ��\�b�h
	//���[�V�������X�V�i�ύX�Ȃ��̏ꍇ	false)
	virtual bool  UpdateMotion(Motion  nm_);

	//	�A�j���[�V�������\����
	struct DrawInfo {
		ML::Box2D		draw, src;
		ML::Color		color;
	};

	//�U�����
	struct AttackInfo {
		int power;    //�U���̈З�
		int hit;      //�������x
		int element;  //�U������
		//���̑��K�v�ɉ�����
	};


	//�ڐG���̉�������(���ꎩ�̂̓_�~�[�̂悤�Ȃ���)
	virtual void Received(BChara* from_, AttackInfo at_);

	//�ڐG����
	virtual bool CheckHit(const ML::Box2D& hit_);
};
