//-----------------------------------------------------------------------------
//キャラクタ汎用スーパークラス
//-----------------------------------------------------------------------------
#include "BChara.h"
#include  "MyPG.h"
#include "sound.h"


//-----------------------------------------------------------------------------
//モーションを更新（変更なしの場合	false)
bool  BChara::UpdateMotion(Motion  nm_)
{
	if (nm_ == this->motion) {
		return  false;
	}
	else {
		this->motion = nm_;		//モーション変更
		this->moveCnt = 0;		//行動カウンタクリア
		this->animCnt = 0;		//アニメーションカウンタのクリア
		return  true;
	}
}
//-----------------------------------------------------------------------------
//接触時の応答処理(これ自体はダミーのようなもの)
void BChara::Received(BChara* from_, AttackInfo at_)
{
	ML::MsgBox("Received 実装されていません");
}
//-----------------------------------------------------------------------------
//接触判定
bool BChara::CheckHit(const ML::Box2D& hit_)
{
	ML::Box2D me = this->hitBase.OffsetCopy(this->pos);
	return me.Hit(hit_);
}
//-----------------------------------------------------------------------------
//歯車の回転用
void BChara::Rotate(int speed_)
{
	float mx = cos(atan2(1, 0)) * (6);
	float my = sin(atan2(1, 0)) * (6);
	this->pos.x += mx;
	this->pos.y += my;

	this->angle += ML::ToRadian(speed_);
}


