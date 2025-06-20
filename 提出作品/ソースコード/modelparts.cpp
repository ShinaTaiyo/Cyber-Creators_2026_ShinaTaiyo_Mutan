//====================================================================================
//
//７月２９日：階層構造を作る[modelparts.cpp]
//Author:ShinaTaiyo
//
//====================================================================================

//============================================
//インクルード
//============================================
#include "modelparts.h"
#include "manager.h"
#include "renderer.h"
#include "objectXInfo.h"
//====================================================================================

//============================================
//コンストラクタ
//============================================
CModelParts::CModelParts(int nPri, bool bUseintPri, CObject::TYPE type, CObject::OBJECTTYPE ObjType) : CObjectX(nPri, bUseintPri, type, ObjType),
m_nPartsIdx(0)
{

}
//====================================================================================

//============================================
//デストラクタ
//============================================
CModelParts::~CModelParts()
{

}
//====================================================================================

//============================================
//初期化処理
//============================================
HRESULT CModelParts::Init()
{
	CObjectX::Init();//オブジェクトX初期化処理
	return S_OK;
}
//====================================================================================

//============================================
//終了処理
//============================================
void CModelParts::Uninit()
{
	CObjectX::Uninit();//オブジェクトX終了処理
}
//====================================================================================

//============================================
//死亡フラグ設定処理
//============================================
void CModelParts::SetDeath()
{
	CObjectX::SetDeath();//オブジェクトX死亡フラグ設定処理
}
//====================================================================================

//============================================
//更新処理
//============================================
void CModelParts::Update()
{

}
//====================================================================================

//==========================================================================
//別枠の更新処理（このモデルパーツを持っているオブジェクトが呼びたいので）
//==========================================================================
void CModelParts::ExtraUpdate()
{
	CObjectX::Update();//オブジェクトX更新処理
}
//====================================================================================

//============================================
//描画処理
//============================================
void CModelParts::Draw()
{

}
//================================================================================================================================================

//==========================================================================
//別枠の描画処理（このモデルパーツを持っているオブジェクトが呼びたいので）
//==========================================================================
void CModelParts::ExtraDraw()
{
 	CObjectX::Draw();//オブジェクトX描画処理
}
//================================================================================================================================================

//=====================================================================================================================
//生成処理
//=====================================================================================================================
CModelParts* CModelParts::Create(string String, CObject::TYPE Type)
{
	CModelParts* pModelParts = DBG_NEW CModelParts(0,false,Type);                     //モデルパーツを生成（呼び出し元のタイプに合わせる)
	int nIdx = 0;                                                                     //モデルのインデックス
	pModelParts->Init();                                                              //初期化処理
	pModelParts->GetSizeInfo().SetScale(D3DXVECTOR3(1.0f,1.0f,1.0f));                 //拡大率を設定する
	pModelParts->SetType(CObject::TYPE::NONE); // タイプを「なし」にする
	pModelParts->SetUseDeath(false);                                                  //死亡フラグを発動するかどうかを設定する
	nIdx = CManager::GetObjectXInfo()->Regist(String);                                //モデル情報を登録し、モデル番号を取得

	//モデル情報を割り当てる
	pModelParts->CObjectX::BindObjectXInfo(CManager::GetObjectXInfo()->GetMesh(nIdx),
		CManager::GetObjectXInfo()->GetBuffMat(nIdx),
		CManager::GetObjectXInfo()->GetdwNumMat(nIdx),
		CManager::GetObjectXInfo()->GetTexture(nIdx),
		CManager::GetObjectXInfo()->GetColorValue(nIdx));
	pModelParts->GetDrawInfo().SetUseShadow(true);                                    //影を描画する
	pModelParts->SetSize();                                                           //Xオブジェクトのサイズを設定する
	return pModelParts;
}
//================================================================================================================================================