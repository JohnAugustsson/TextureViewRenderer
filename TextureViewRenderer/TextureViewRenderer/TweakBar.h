#include "pch.h"
#include "AntTweakBar.h"
namespace UI
{
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	class TweakBar
	{
	public:
		~TweakBar();
		static std::shared_ptr<UI::TweakBar> GetInstance();
		int Initialize(ID3D11Device* gDevice, float windowWidth, float windowHeight);
		void Render();
	private:
		bool m_rotate = false;
		TweakBar();
		TwBar *m_barHandle;
	public: // callback functions
		static void TW_CALL RotationCall(void* data);
	};

}
