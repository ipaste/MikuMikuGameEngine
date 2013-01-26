
// MikuMikuGameEngineView.cpp : CMikuMikuGameEngineView クラスの実装
//

#include "stdafx.h"
#include "MikuMikuGameEngine.h"

#include "MikuMikuGameEngineDoc.h"
#include "MikuMikuGameEngineView.h"

#include "engine/core/graphics/Graphics.h"

#include "engine/core/graphics/XFileLoader.h"
#include "engine/core/graphics/PMDFileLoader.h"
#include "engine/core/graphics/VMDFileLoader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMikuMikuGameEngineView

IMPLEMENT_DYNCREATE(CMikuMikuGameEngineView, CView)

BEGIN_MESSAGE_MAP(CMikuMikuGameEngineView, CView)
ON_WM_RBUTTONUP()
//	ON_WM_CLOSE()
ON_WM_DESTROY()
ON_WM_SIZE()
//ON_WM_ERASEBKGND()
ON_WM_RBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_WM_MBUTTONDOWN()
ON_WM_MBUTTONUP()
ON_WM_MOUSEWHEEL()
ON_WM_CAPTURECHANGED()
END_MESSAGE_MAP()

// CMikuMikuGameEngineView コンストラクション/デストラクション

CMikuMikuGameEngineView::CMikuMikuGameEngineView()
	: m_initialized(false)
{
	// TODO: 構築コードをここに追加します。

}

CMikuMikuGameEngineView::~CMikuMikuGameEngineView()
{
}

BOOL CMikuMikuGameEngineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CMikuMikuGameEngineView 描画

void CMikuMikuGameEngineView::OnDraw(CDC* /*pDC*/)
{
	CMikuMikuGameEngineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CMikuMikuGameEngineView 診断

#ifdef _DEBUG
void CMikuMikuGameEngineView::AssertValid() const
{
	CView::AssertValid();
}

void CMikuMikuGameEngineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMikuMikuGameEngineDoc* CMikuMikuGameEngineView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMikuMikuGameEngineDoc)));
	return (CMikuMikuGameEngineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMikuMikuGameEngineView メッセージ ハンドラ

void CMikuMikuGameEngineView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ここに特定なコードを追加するか、もしくは基本クラスを呼び出してください。
	HRESULT hr = Graphics::GetInstance()->Initialize( GetSafeHwnd() );
	if( FAILED(hr) )
	{
		::MessageBox( NULL,_T("DirectXが初期化できませんでした。"),_T("error"),MB_ICONERROR );
	}

	m_initialized = true;

	m_shadowMap=RenderTexturePtr( new RenderTexture );
	m_shadowMap->Create( 2048,2048,D3DFMT_R32F );

	//{
	//	//tstring pmdFilePath = _T("project\\assets\\Model\\Lat式ミクVer2.3\\Lat式ミクVer2.3_Normal.pmd");
	//	tstring pmdFilePath = _T("project\\assets\\Model\\初音ミク.pmd");

	//	TCHAR path[MAX_PATH];
	//	_tcscpy_s( path,PathFindFileName( pmdFilePath.c_str() ) );

	//	PathRemoveExtension( path );

	//	PMDModelPtr pModel = ResourceManager::GetInstance().GetResource<PMDModel>( pmdFilePath );
	//	if( !pModel )
	//	{
	//		PMDFileLoader pmdFileLoader;
	//		pModel = pmdFileLoader.Open( pmdFilePath );

	//		ResourceManager::GetInstance().AddResource( pmdFilePath,pModel );
	//	}

	//	if( pModel )
	//	{
	//		GameObject* gameObject = new GameObject;

	//		gameObject->SetName( path );

	//		PMDModelRenderer* pmdModelRenderer = new PMDModelRenderer;
	//		pmdModelRenderer->SetGameObject( gameObject );
	//		pmdModelRenderer->SetModel( pModel );

	//		gameObject->SetPMDModelRenderer( pmdModelRenderer );

	//		GetDocument()->AddGameObject( gameObject,GetDocument()->GetRootGameObject(),true );

	//		//tstring vmdFilePath = _T("project\\assets\\love_and_joy.vmd");

	//		//VMDAnimationClipPtr pAnimationClip = ResourceManager::GetInstance().GetResource<VMDAnimationClip>( vmdFilePath );
	//		//if( !pAnimationClip )
	//		//{
	//		//	VMDFileLoader vmdFileLoader;
	//		//	pAnimationClip = vmdFileLoader.Open( vmdFilePath );

	//		//	ResourceManager::GetInstance().AddResource( vmdFilePath,pAnimationClip );
	//		//}

	//		//if( pAnimationClip )
	//		//{
	//		//	gameObject->SetVMDAnimationClip( pAnimationClip );
	//		//}
	//	}
	//}

	//{
	//	tstring pmdFilePath = _T("project\\assets\\ShadowTest.pmd");

	//	TCHAR path[MAX_PATH];
	//	_tcscpy_s( path,PathFindFileName( pmdFilePath.c_str() ) );

	//	PathRemoveExtension( path );

	//	PMDModelPtr pModel = ResourceManager::GetInstance().GetResource<PMDModel>( pmdFilePath );
	//	if( !pModel )
	//	{
	//		PMDFileLoader pmdFileLoader;
	//		pModel = pmdFileLoader.Open( pmdFilePath );

	//		ResourceManager::GetInstance().AddResource( pmdFilePath,pModel );
	//	}

	//	if( pModel )
	//	{
	//		GameObject* gameObject = new GameObject;

	//		gameObject->SetName( path );

	//		PMDModelRenderer* pmdModelRenderer = new PMDModelRenderer;
	//		pmdModelRenderer->SetGameObject( gameObject );
	//		pmdModelRenderer->SetModel( pModel );

	//		gameObject->SetPMDModelRenderer( pmdModelRenderer );

	//		GetDocument()->AddGameObject( gameObject,GetDocument()->GetRootGameObject(),true );
	//	}
	//}

	//{
	//	tstring pmdFilePath = _T("project\\assets\\Model\\つむじ風\\つむじ風.pmd");

	//	TCHAR path[MAX_PATH];
	//	_tcscpy_s( path,PathFindFileName( pmdFilePath.c_str() ) );

	//	PathRemoveExtension( path );

	//	PMDModelPtr pModel = ResourceManager::GetInstance().GetResource<PMDModel>( pmdFilePath );
	//	if( !pModel )
	//	{
	//		PMDFileLoader pmdFileLoader;
	//		pModel = pmdFileLoader.Open( pmdFilePath );

	//		ResourceManager::GetInstance().AddResource( pmdFilePath,pModel );
	//	}

	//	if( pModel )
	//	{
	//		GameObject* gameObject = new GameObject;

	//		gameObject->SetName( path );

	//		PMDModelRenderer* pmdModelRenderer = new PMDModelRenderer;
	//		pmdModelRenderer->SetGameObject( gameObject );
	//		pmdModelRenderer->SetModel( pModel );

	//		gameObject->SetPMDModelRenderer( pmdModelRenderer );

	//		gameObject->SetLocalPosition( D3DXVECTOR3(10.0f,0.0f,0.0f) );

	//		GetDocument()->AddGameObject( gameObject,GetDocument()->GetRootGameObject(),true );

	//		tstring vmdFilePath = _T("project\\assets\\つむじ風.vmd");

	//		VMDAnimationClipPtr pAnimationClip = ResourceManager::GetInstance().GetResource<VMDAnimationClip>( vmdFilePath );
	//		if( !pAnimationClip )
	//		{
	//			VMDFileLoader vmdFileLoader;
	//			pAnimationClip = vmdFileLoader.Open( vmdFilePath );

	//			ResourceManager::GetInstance().AddResource( vmdFilePath,pAnimationClip );
	//		}

	//		if( pAnimationClip )
	//		{
	//			gameObject->SetVMDAnimationClip( pAnimationClip );
	//		}
	//	}
	//}

	//{
	//	tstring pmdFilePath = _T("project\\assets\\Model\\ＭＭＤのエンジンをＭＭＤエンジンで\\MMDのエンジンをMMDエンジンで.pmd");

	//	TCHAR path[MAX_PATH];
	//	_tcscpy_s( path,PathFindFileName( pmdFilePath.c_str() ) );

	//	PathRemoveExtension( path );

	//	PMDModelPtr pModel = ResourceManager::GetInstance().GetResource<PMDModel>( pmdFilePath );
	//	if( !pModel )
	//	{
	//		PMDFileLoader pmdFileLoader;
	//		pModel = pmdFileLoader.Open( pmdFilePath );

	//		ResourceManager::GetInstance().AddResource( pmdFilePath,pModel );
	//	}

	//	if( pModel )
	//	{
	//		GameObject* gameObject = new GameObject;

	//		gameObject->SetName( path );

	//		PMDModelRenderer* pmdModelRenderer = new PMDModelRenderer;
	//		pmdModelRenderer->SetGameObject( gameObject );
	//		pmdModelRenderer->SetModel( pModel );

	//		gameObject->SetPMDModelRenderer( pmdModelRenderer );

	//		gameObject->SetLocalPosition( D3DXVECTOR3(-10.0f,0.0f,0.0f) );

	//		GetDocument()->AddGameObject( gameObject,GetDocument()->GetRootGameObject(),true );

	//		tstring vmdFilePath = _T("project\\assets\\MMDエンジンのエンジン.vmd");

	//		VMDAnimationClipPtr pAnimationClip = ResourceManager::GetInstance().GetResource<VMDAnimationClip>( vmdFilePath );
	//		if( !pAnimationClip )
	//		{
	//			VMDFileLoader vmdFileLoader;
	//			pAnimationClip = vmdFileLoader.Open( vmdFilePath );

	//			ResourceManager::GetInstance().AddResource( vmdFilePath,pAnimationClip );
	//		}

	//		if( pAnimationClip )
	//		{
	//			gameObject->SetVMDAnimationClip( pAnimationClip );
	//		}
	//	}
	//}

	//{
	//	tstring pmdFilePath = _T("project\\assets\\Model\\MMDエンジン原理可視モデル\\MMDエンジンかしもでる.pmd");

	//	TCHAR path[MAX_PATH];
	//	_tcscpy_s( path,PathFindFileName( pmdFilePath.c_str() ) );

	//	PathRemoveExtension( path );

	//	PMDModelPtr pModel = ResourceManager::GetInstance().GetResource<PMDModel>( pmdFilePath );
	//	if( !pModel )
	//	{
	//		PMDFileLoader pmdFileLoader;
	//		pModel = pmdFileLoader.Open( pmdFilePath );

	//		ResourceManager::GetInstance().AddResource( pmdFilePath,pModel );
	//	}

	//	if( pModel )
	//	{
	//		GameObject* gameObject = new GameObject;

	//		gameObject->SetName( path );

	//		PMDModelRenderer* pmdModelRenderer = new PMDModelRenderer;
	//		pmdModelRenderer->SetGameObject( gameObject );
	//		pmdModelRenderer->SetModel( pModel );

	//		gameObject->SetPMDModelRenderer( pmdModelRenderer );

	//		gameObject->SetLocalPosition( D3DXVECTOR3(-20.0f,0.0f,0.0f) );

	//		GetDocument()->AddGameObject( gameObject,GetDocument()->GetRootGameObject(),true );

	//		tstring vmdFilePath = _T("project\\assets\\MMDエンジン原理可視モデルでのテストぐるぐる.vmd");

	//		VMDAnimationClipPtr pAnimationClip = ResourceManager::GetInstance().GetResource<VMDAnimationClip>( vmdFilePath );
	//		if( !pAnimationClip )
	//		{
	//			VMDFileLoader vmdFileLoader;
	//			pAnimationClip = vmdFileLoader.Open( vmdFilePath );

	//			ResourceManager::GetInstance().AddResource( vmdFilePath,pAnimationClip );
	//		}

	//		if( pAnimationClip )
	//		{
	//			gameObject->SetVMDAnimationClip( pAnimationClip );
	//		}
	//	}
	//}

	m_cameraPosition = D3DXVECTOR3( 0.0f,10.0f,0.0f );

	D3DXQuaternionIdentity( &m_cameraRotation );
	m_cameraRadius = 35.0f;
	m_cameraState = 0;

	m_coordinateAxis = new CoordinateAxis;

	m_nowTime = timeGetTime();
}

#include "engine/core/math/BoundingFrustum.h"
#include "engine/core/math/BoundingBox.h"
#include "engine/core/math/BoundingCone.h"
#include "engine/core/math/Ray.h"

//D3DXMATRIX CalcShadowMatrix( sRenderInfo& renderInfo )
//{
//	//表示行列設定
//	D3DXVECTOR3 lightDir = renderInfo.lightDir;
//	D3DXVECTOR3 viewDir = renderInfo.camera.GetLookDir();
//
//	const D3DXMATRIX& matView = renderInfo.camera.GetViewMatrix();
//
//	const D3DXMATRIX& matProj = renderInfo.camera.GetViewMatrix();
//
//	D3DXVECTOR3 vUp;
//	D3DXVec3Cross( &vUp,&viewDir,&(-lightDir) );
//	if( D3DXVec3LengthSq( &vUp ) < FLT_EPSILON )
//	{
//		// 
//		// 通常のシャドウマップ
//		// MMDだと影が消える？
//
//		return matView * matProj;
//	}
//
//	float d = (1.0f-D3DXVec3Dot( &viewDir,&lightDir ))*0.5f;
//
//	D3DXVec3Normalize( &vUp,&vUp );
//	D3DXVec3Cross( &vUp,&vUp,&viewDir );
//	D3DXVec3Normalize( &vUp,&vUp );
//
//	float shadowDistance = 8875*0.01f;
//
//	// シャドウ距離の位置がファークリップ面

//	float nearClip = 10.0f + shadowDistance;
//
//	const D3DXVECTOR3& camPos = renderInfo.camera.GetPosition() + viewDir * d * 50.0f;
//	D3DXVECTOR3 lightPos = camPos - lightDir * nearClip;
//
//	D3DXMATRIX matLightView;
//	D3DXMatrixLookAtLH( &matLightView,&lightPos,&(lightPos + lightDir),&vUp );
//
//	D3DXMATRIX matLightProj;
//	D3DXMatrixPerspectiveFovLH( &matLightProj,D3DXToRadian(10.0f),1.0f,nearClip,nearClip+1500.0f );
//
//	return matLightView * matLightProj;
//}

D3DXMATRIX CalcShadowMatrix( sRenderInfo& renderInfo )
{
	//表示行列設定
	D3DXVECTOR3 lightDir = renderInfo.lightDir;

	const D3DXMATRIX& matView = renderInfo.camera.GetViewMatrix();
	const D3DXMATRIX& matProj = renderInfo.camera.GetViewMatrix();

	//光の方向に回転する回転行列を生成
	D3DXMATRIX lightRotation;
	D3DXMatrixLookAtLH( &lightRotation,&D3DXVECTOR3(0.0f,0.0f,0.0f),&lightDir,&D3DXVECTOR3(0.0f,1.0f,0.0f) );
	//視錐台から錐台のコーナー情報取得

	D3DXVECTOR3 frustumCorners[ BoundingFrustum::CornerCount ];
	renderInfo.camera.GetFrustumCorners( 100.0f, frustumCorners);
	//光の方向に回転
	for(int index = 0; index < BoundingFrustum::CornerCount; index++ )
	{
		D3DXVec3TransformCoord( &frustumCorners[index],&frustumCorners[index], &lightRotation );
	}

	//錐台を含む最小の箱型空間を生成
	BoundingBox lightBox = BoundingBox::CreateFromPoints(frustumCorners,BoundingFrustum::CornerCount);
	//箱型空間のサイズ取得
	D3DXVECTOR3 boxSize = lightBox.GetMax() - lightBox.GetMin();
	D3DXVECTOR3 halfBoxSize = boxSize * 0.5f;

	//ライトの位置計算
	//平行光源におけるライトの位置は箱型空間のバックパネル中央。
	D3DXVECTOR3 lightPosition = lightBox.GetMin() + halfBoxSize;
	lightPosition.z = lightBox.GetMin().z;

	//ライトの位置を元の座標系に戻す
	D3DXMatrixInverse(&lightRotation,NULL,&lightRotation);
	D3DXVec3TransformCoord( &lightPosition,&lightPosition, &lightRotation );

	D3DXMATRIX matLightView;
	D3DXMATRIX matLightProj;

	D3DXVECTOR3 vLook = renderInfo.camera.GetLookDir();
	D3DXVECTOR3 vUp;
	D3DXVec3Cross( &vUp,&vLook,&(-lightDir) );
	D3DXVec3Normalize( &vUp,&vUp );
	D3DXVec3Cross( &vUp,&vUp,&vLook );
	D3DXVec3Normalize( &vUp,&vUp );

	//ライトの位置を元にしたビューマトリックス生成
	//ライトのプロジェクションマトリックスを使う
	//パースペクティブシャドウマップの場合は視錐台のプロジェクションを使う。これによりパースペクティブシャドウマップになる
	
	D3DXMatrixLookAtLH( &matLightView,&lightPosition,&(lightPosition + lightDir),&vUp );
	//D3DXMatrixPerspectiveFovLH( &matLightProj,D3DXToRadian( 45.0f ) , 1.0f , 1.0f, 1000.0f );
	D3DXMatrixOrthoLH( &matLightProj,boxSize.x, boxSize.y, -boxSize.z, boxSize.z );

	return matLightView * matLightProj;
}

void CMikuMikuGameEngineView::OnIdle()
{
	if( !m_initialized )
	{
		return;
	}

	DWORD time=timeGetTime();
	float elapsedTime=(time-m_nowTime)/1000.0f;
	m_nowTime=time;

	GetDocument()->GetRootGameObject()->UpdateAnimation( elapsedTime );

	{
		Graphics* graphics = Graphics::GetInstance();
		IDirect3DDevice9Ptr pD3DDevice = graphics->GetDirect3DDevice();

		//Locker lock( graphics->GetCriticalSection() );

		sRenderInfo renderInfo;

		renderInfo.lightDir = D3DXVECTOR3(-0.5f,-1.0f,0.5f);
		D3DXVec3Normalize( &renderInfo.lightDir,&renderInfo.lightDir );
		renderInfo.lightColor = D3DXCOLOR( 0xFF9A9A9A );

		float nearClip = 1.0f;
		float farClip = 1000000.0f;

		renderInfo.camera.UpdateView( m_cameraPosition,m_cameraRotation,m_cameraRadius );
		renderInfo.camera.UpdateProj( D3DXToRadian(45.0f), (float)graphics->GetBackBufferWidth()/(float)graphics->GetBackBufferHeight(), nearClip, farClip);
		
		renderInfo.shadowMap = true;

		if( renderInfo.shadowMap )
		{
			renderInfo.shadowMapTexture = m_shadowMap;

			float shadowDistance = 12000.0f;

			renderInfo.matShadow = CalcShadowMatrix( renderInfo );
		}

		HRESULT hr = graphics->BeginScene();
		if( SUCCEEDED(hr) )
		{
			// TODO: ここにコードを挿入してください。
			// 描画開始

			GetDocument()->GetRootGameObject()->UpdateMesh( renderInfo );

			if( renderInfo.shadowMap )
			{
				IDirect3DSurface9Ptr pOldBackBuffer;
				IDirect3DSurface9Ptr pOldDepthBuffer;
				D3DVIEWPORT9 oldViewport;
				pD3DDevice->GetRenderTarget( 0,&pOldBackBuffer );
				pD3DDevice->GetDepthStencilSurface( &pOldDepthBuffer );
				pD3DDevice->GetViewport( &oldViewport );

				m_shadowMap->SetRenderTarget();

				graphics->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xFFFFFFFF, 1.0f, 0 );

				GetDocument()->GetRootGameObject()->RenderZPlot( renderInfo );

				pD3DDevice->SetRenderTarget( 0,pOldBackBuffer );
				pD3DDevice->SetDepthStencilSurface( pOldDepthBuffer );
				pD3DDevice->SetViewport( &oldViewport );				
			}

			graphics->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB( 255, 255, 255 ), 1.0f, 0 );

			{
				m_coordinateAxis->Render( renderInfo.camera.GetViewMatrix(),renderInfo.camera.GetProjMatrix() );
			}

			graphics->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
			graphics->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
			graphics->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );

			graphics->SetRenderState( D3DRS_SEPARATEALPHABLENDENABLE,TRUE );
			graphics->SetRenderState( D3DRS_SRCBLENDALPHA,D3DBLEND_ONE );
			graphics->SetRenderState( D3DRS_DESTBLENDALPHA,D3DBLEND_ONE );
			graphics->SetRenderState( D3DRS_BLENDOPALPHA,D3DBLENDOP_ADD );

			GetDocument()->GetRootGameObject()->Render( renderInfo );

			graphics->SetRenderState( D3DRS_SEPARATEALPHABLENDENABLE,FALSE );
			graphics->SetRenderState( D3DRS_ALPHABLENDENABLE, FALSE );

			GameObject* selectObject = GetDocument()->GetSelectGameObject();
			if( selectObject )
			{
				// TODO:Draw Select Object
			}

			//// Debug Shadow Map
			//ShaderPtr pDefaultShader = graphics->GetDefaultShader();
			//if( pDefaultShader )
			//{
			//	ID3DXEffectPtr pEffect = pDefaultShader->GetEffect();

			//	graphics->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );

			//	{
			//		graphics->SetFVF( D3DFVF_XYZ );

			//		pEffect->SetTechnique( "TechEdge" );
			//		
			//		UINT passes;
			//		pEffect->Begin( &passes,0 );

			//		BoundingFrustum frustum( renderInfo.matShadow );

			//		DWORD indices[] =
			//		{
			//			0,1, // top,near,
			//			0,2, // left,near,
			//			1,3, // right,near,
			//			2,3, // botom,near,

			//			0,4, // left,top
			//			1,5, // right,top
			//			2,6, // left,bottom
			//			3,7, // right,bottom

			//			4,5, // top,near,
			//			4,6, // left,near,
			//			5,7, // right,near,
			//			6,7, // botom,near,
			//		};
			//		
			//		D3DXVECTOR4 color( 0.0f,0.0f,0.0f,1.0f );
			//		pEffect->SetVector( "g_edgeColor" , &color );
			//		pEffect->SetTexture( "g_Texture",m_shadowMap->GetTexture() );

			//		for( UINT cpass = 0; cpass<passes; cpass++ )
			//		{
			//			pEffect->BeginPass( cpass );

			//			graphics->DrawIndexedPrimitiveUP( D3DPT_LINELIST,0,BoundingFrustum::CornerCount,12,indices,D3DFMT_INDEX32,frustum.GetCorners(),sizeof(D3DXVECTOR3) );

			//			pEffect->EndPass();
			//		}

			//		pEffect->End();
			//	}

			//	{
			//		graphics->SetFVF( D3DFVF_XYZRHW|D3DFVF_TEX1 );

			//		pEffect->SetTechnique( "TechScreenDiffuseTexture" );
			//		
			//		UINT passes;
			//		pEffect->Begin( &passes,0 );
			//		
			//		struct sVertex
			//		{
			//			float x;
			//			float y;
			//			float z;
			//			float rhw;
			//			float u;
			//			float v;
			//		};

			//		float right = (float)graphics->GetBackBufferWidth();
			//		float left = right-400.0f;
			//		float top = 0.0f;
			//		float bottom = top+400.0f;

			//		sVertex v[4]={
			//			{  left,   top,0.0f,1.0f,0.0f,0.0f},
			//			{ right,   top,0.0f,1.0f,1.0f,0.0f},
			//			{  left,bottom,0.0f,1.0f,0.0f,1.0f},
			//			{ right,bottom,0.0f,1.0f,1.0f,1.0f},
			//		};

			//		D3DXVECTOR4 color( 1.0f,1.0f,1.0f,1.0f );
			//		pEffect->SetVector( "g_materialDiffuse" , &color );
			//		pEffect->SetTexture( "g_Texture",m_shadowMap->GetTexture() );

			//		for( UINT cpass = 0; cpass<passes; cpass++ )
			//		{
			//			pEffect->BeginPass( cpass );

			//			graphics->DrawPrimitiveUP( D3DPT_TRIANGLESTRIP,2,v,sizeof(sVertex) );

			//			pEffect->EndPass();
			//		}

			//		pEffect->End();
			//	}

			//	graphics->SetRenderState( D3DRS_ALPHABLENDENABLE, FALSE );
			//}

			graphics->EndScene();
		}
	}

}

//void CMikuMikuGameEngineView::OnClose()
//{
//	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。
//
//	Graphics::GetInstance()->Cleanup();
//
//	CView::OnClose();
//}

void CMikuMikuGameEngineView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ここにメッセージ ハンドラ コードを追加します。

	delete m_coordinateAxis;

	m_shadowMap.reset();

	Graphics::GetInstance()->Cleanup();
}

BOOL CMikuMikuGameEngineView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ここに特定なコードを追加するか、もしくは基本クラスを呼び出してください。

	switch( pMsg->message )
	{
	case WM_USER_RESETDEVICE:
		{
			Graphics::GetInstance()->ResetDevice();
		}
		return TRUE;
	case WM_USER_LOSTDEVICE:
		{
			Graphics::GetInstance()->LostDevice();
		}
		return TRUE;
	case WM_SIZING:
		{
			::OutputDebugString( _T("WM_SIZING\n") );

			RECT rc = *(RECT*)pMsg->lParam;

			RECT clientRect;
			::GetClientRect( pMsg->hwnd,&clientRect );

			POINT ptLeftTop={clientRect.left,clientRect.top};
			::ClientToScreen( pMsg->hwnd,&ptLeftTop );

			POINT ptRightBottom={clientRect.right,clientRect.bottom};
			::ClientToScreen( pMsg->hwnd,&ptRightBottom );

			clientRect.left = ptLeftTop.x;
			clientRect.top = ptLeftTop.y;
			clientRect.right = ptRightBottom.x;
			clientRect.bottom = ptRightBottom.y;

			RECT windowRect;
			::GetWindowRect( pMsg->hwnd,&windowRect );

			rc.left += clientRect.left-windowRect.left;
			rc.top += clientRect.top-windowRect.top;
			rc.right -= windowRect.right-clientRect.right;
			rc.bottom -= windowRect.bottom-clientRect.bottom;

			SIZE size;

			size.cx = rc.right-rc.left;
			size.cy = rc.bottom-rc.top;

			Locker lock( Graphics::GetInstance()->GetCriticalSection() );

			Graphics::GetInstance()->EnableRender(false);

			// TODO:デバイスロスト発生処理

			Graphics::GetInstance()->Resize( size.cx, size.cy );

			// TODO:デバイス復帰処理

			Graphics::GetInstance()->EnableRender(true);
		}
		break;
	}

	return CView::PreTranslateMessage(pMsg);
}

void CMikuMikuGameEngineView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ここにメッセージ ハンドラ コードを追加します。

	if( m_initialized )
	{
		Locker lock( Graphics::GetInstance()->GetCriticalSection() );

		Graphics::GetInstance()->EnableRender(false);

		// TODO:デバイスロスト発生処理

		Graphics::GetInstance()->Resize( cx, cy );

		// TODO:デバイス復帰処理

		Graphics::GetInstance()->EnableRender(true);
	}
}

//BOOL CMikuMikuGameEngineView::OnEraseBkgnd(CDC* pDC)
//{
//	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。
//
//	return TRUE;
//	//return CView::OnEraseBkgnd(pDC);
//}

void CMikuMikuGameEngineView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。

	if( m_cameraState == 0 )
	{
		POINT pt;
		pt.x = point.x;
		pt.y = point.y;

		m_ptCursorDown = pt;
		m_cameraState = 1;

		SetCapture();
	}

	CView::OnRButtonDown(nFlags, point);
}

void CMikuMikuGameEngineView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。

	if( m_cameraState == 1 )
	{
		POINT pt;
		pt.x = point.x;
		pt.y = point.y;

		m_cameraState = 0;

		ReleaseCapture();
	}

	CView::OnRButtonUp(nFlags, point);
}

void CMikuMikuGameEngineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。

	POINT pt;
	pt.x = point.x;
	pt.y = point.y;

	int x = pt.x-m_ptCursorDown.x;
	int y = pt.y-m_ptCursorDown.y;

	switch( m_cameraState )
	{
	case 1:
		{
			m_ptCursorDown = pt;

			if( x!=0 )
			{
				D3DXQUATERNION q;
				D3DXQuaternionRotationAxis( &q,&D3DXVECTOR3(0.0f,1.0f,0.0f),D3DXToRadian( x*0.573f ) );

				m_cameraRotation = m_cameraRotation * q;
			}

			if( y!=0 )
			{
				D3DXQUATERNION q;
				D3DXQuaternionRotationAxis( &q,&D3DXVECTOR3(1.0f,0.0f,0.0f),D3DXToRadian( y*0.573f ) );

				m_cameraRotation = q * m_cameraRotation;
			}
		}
		break;
	case 2:
		{
			m_ptCursorDown = pt;

			D3DXVECTOR3 move((float)-x,(float)y,0.0f);
			move *= 0.05f;

			D3DXMATRIX matCameraRotate;
			D3DXMatrixRotationQuaternion( &matCameraRotate,&m_cameraRotation );

			D3DXVec3TransformNormal( &move,&move,&matCameraRotate );

			m_cameraPosition += move;
		}
		break;
	}
	CView::OnMouseMove(nFlags, point);
}

void CMikuMikuGameEngineView::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。

	if( m_cameraState == 0 )
	{
		POINT pt;
		pt.x = point.x;
		pt.y = point.y;

		m_ptCursorDown = pt;
		m_cameraState = 2;

		SetCapture();
	}

	CView::OnMButtonDown(nFlags, point);
}

void CMikuMikuGameEngineView::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。

	if( m_cameraState == 2 )
	{
		POINT pt;
		pt.x = point.x;
		pt.y = point.y;

		m_cameraState = 0;

		ReleaseCapture();
	}

	CView::OnMButtonUp(nFlags, point);
}

BOOL CMikuMikuGameEngineView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。

	m_cameraRadius -= ((float)zDelta/120.0f)*6.0f;
	
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CMikuMikuGameEngineView::OnCaptureChanged(CWnd *pWnd)
{
	// TODO: ここにメッセージ ハンドラ コードを追加します。

	if( m_cameraState != 0 )
	{
		m_cameraState = 0;
	}

	CView::OnCaptureChanged(pWnd);
}
