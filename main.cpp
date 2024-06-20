#include <Novice.h>
#define _USE_MATH_DEFINES
#include<cmath>

#include"ImGuiManager.h"
const char kWindowTitle[] = "LC1C_04_ウエノ_ユウキ_タイトル";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	struct Vector2 {
		float x, y;
	};
	struct Vector2Int
	{
		int x, y;
	};
	Vector2 pos = { 640,360 };
	
	//float Ripple[20] = {};

	Vector2Int mousePos = {0,0};
	
	int isRipple = false;
	float speed = 2.0f;
	float radius = 4;

	int color = 0xFFFFFFFF;
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Novice::GetMousePosition(&mousePos.x, &mousePos.y);

		if (Novice::IsTriggerMouse(0)) {
			isRipple = true;
			color = 0xFFFFFFFF;
			radius = 4;

			pos.x = static_cast<float>(mousePos.x);
			pos.y = static_cast<float>(mousePos.y);

		}
		
		if (isRipple) {
				radius += speed;
				color -= 2;
		}
		if (color<=0xFFFFFF00) {
			radius = 4;
			isRipple = false;
		}
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		if (isRipple) {
			Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int> (pos.y), static_cast<int>(radius), static_cast<int>(radius), 0.0f, color, kFillModeWireFrame);

		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
