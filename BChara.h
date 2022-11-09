#pragma once
#pragma warning(disable:4996)
#pragma once
//-----------------------------------------------------------------------------
//キャラクタ汎用スーパークラス
//-----------------------------------------------------------------------------
#include "GameEngine_Ver3_83.h"

class BChara : public BTask
{
	//変更不可◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆
public:
	typedef shared_ptr<BChara>		SP;
	typedef weak_ptr<BChara>		WP;
public:
	//変更可◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
	//キャラクタ共通メンバ変数
	ML::Vec2    pos;		//キャラクタ位置
	ML::Box2D   hitBase;	//あたり判定範囲
	ML::Vec2	moveVec;	//移動ベクトル
	int			moveCnt;	//行動カウンタ
	int         moveCntMax; //最大行動カウンタ
	int         number;     //識別用ナンバー
	int         spornX, spornY; //出現地点(配列用)
	bool        meDeath;
	int			hp;
	//左右の向き（2D横視点ゲーム専用）
	enum class Angle_LR { Left, Right };
	Angle_LR	angle_LR;
	WP			target;

	//キャラクタの行動状態フラグ
	enum class Motion
	{
		Unnon = -1,	//	無効(使えません）
		Stand,		//	停止
		Walk,		//	歩行
		Walkturn,	//	歩行(帰り)
		Attack,		//	攻撃中
		Attack2,		//	攻撃中2
		JumpAttack,		//	ジャンプ攻撃中
		JumpAttack2,    //	ジャンプ攻撃中2
		Jump,		//	ジャンプ
		Fall,		//	落下
		Jump2,		//	ジャンプ2
		Fall2,		//	落下2
		TakeOff,	//	飛び立つ瞬間
		Landing,	//	着地
		Turn,       //  ターン
		Bound,      //　弾き飛ばされてる
		Counterderay, //カウンター入力時
		CounterAtk, //カウンター攻撃
		Lose,       //　消滅中
		Defence,
		Have,
		Death,
		Havestand
	};
	Motion			motion;			//	現在の行動を示すフラグ
	int				animCnt;		//アニメーションカウンタ
	float			jumpPow;		//	ジャンプ初速
	float			maxFallSpeed;	//	落下最大速度
	float			gravity;		//	フレーム単位の加算量
	float			maxSpeed;		//	左右方向への移動の加算量
	float			addSpeed;		//	左右方向への移動の加算量
	float			decSpeed;		//	左右方向への移動の減衰量
	int             honey;             //最大HP
	int             unHitTime;      //無敵時間
	DG::Image::SP   debugimage;      //デバッグ用



	//メンバ変数に最低限の初期化を行う
	//★★メンバ変数を追加したら必ず初期化も追加する事★★
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

	//キャラクタ共通メソッド
	//モーションを更新（変更なしの場合	false)
	virtual bool  UpdateMotion(Motion  nm_);

	//	アニメーション情報構造体
	struct DrawInfo {
		ML::Box2D		draw, src;
		ML::Color		color;
	};

	//攻撃情報
	struct AttackInfo {
		int power;    //攻撃の威力
		int hit;      //命中精度
		int element;  //攻撃属性
		//その他必要に応じて
	};


	//接触時の応答処理(これ自体はダミーのようなもの)
	virtual void Received(BChara* from_, AttackInfo at_);

	//接触判定
	virtual bool CheckHit(const ML::Box2D& hit_);
};
