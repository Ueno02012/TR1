#include <Novice.h>
#include<cmath>
#include"ImGuiManager.h"
const char kWindowTitle[] = "LC1C_04_ウエノ_ユウキ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	const float kAmp = 200.0f;

	const float kHz = 1.0f;

	float inputFloat2[2] = { 0,0,};

	float currentTime[20] = { 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f };
	int currentFrame[20] = { 0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190 };
	int offsetY = 360;



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
		for (int i = 0; i < 20; i++) {
			currentFrame[i]++;
			currentTime[i] = static_cast<float>(currentFrame[i]) / 60.0f;

		}
		ImGui::Begin("Debug1");
		ImGui::InputFloat2("currenyFrame", inputFloat2);
		ImGui::End();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Novice::DrawLine(0,offsetY, 1280,offsetY, WHITE);
		for (int i = 0; i < 20; i++) {
			Novice::DrawEllipse(i*50+200, static_cast<int>(kAmp * sinf(kHz * currentTime[i])) + offsetY, 16, 16, 0.0f, 0xFFFFFFFF, kFillModeSolid);

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
