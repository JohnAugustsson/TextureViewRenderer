
#include "pch.h"
#include "TweakBar.h"
using namespace UI;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	if (TwEventWin(hWnd, message, wParam, lParam)) // send event message to AntTweakBar
		return 0; // event has been handled by AntTweakBar
	return 0;
}
TweakBar::TweakBar()
{
}

void TW_CALL TweakBar::RotationCall(void * data)
{
	if (TweakBar::GetInstance()->m_rotate)
	{
		TweakBar::GetInstance()->m_rotate = false;
	}
	else {
		TweakBar::GetInstance()->m_rotate = true;
	}
}

TweakBar::~TweakBar()
{
	TwTerminate();
}

std::shared_ptr<UI::TweakBar> UI::TweakBar::GetInstance()
{
	static TweakBar instance = TweakBar();
	return std::shared_ptr<UI::TweakBar>(&instance);
}

int UI::TweakBar::Initialize(ID3D11Device * gDevice, float windowWidth, float windowHeight)
{
	int result = 0;
	result= TwInit(TwGraphAPI::TW_DIRECT3D11, gDevice);
	result= TwWindowSize(windowWidth, windowHeight);
	m_barHandle = TwNewBar("Tweak Ui");

	TwAddButton(m_barHandle, "Rotation On/Off", TweakBar::RotationCall, NULL, "group = Rotation");
	//TwAddButton(m_barHandle, "Bounce", BounceCall, NULL, "group = Rotation");
	//TwAddVarRW(m_barHandle, "Rotation", TW_TYPE_FLOAT, &animSpeed, "step = 0.001 group = Rotation");
	//TwAddVarRW(myBar, "Rotation Speed", TW_TYPE_FLOAT, &speed, "group = Rotation step = 0.000001 min =0");
	//TwAddVarRW(myBar, "Background Color", TW_TYPE_COLOR4F, &clearColor, "");
	//TwAddVarRW(myBar, "Light Position", TW_TYPE_DIR3F, &lightPos, "group = Light");
	//TwAddVarRW(myBar, "Light Color", TW_TYPE_COLOR4F, &lightColor, "group = Light");
	//TwAddVarRW(myBar, "Light Intensity", TW_TYPE_FLOAT, &lightInt, "group = Light min= 0.0 max = 1.0 step = 0.05");
	return result;
}


void TweakBar::Render()
{
	TwDraw();
}
