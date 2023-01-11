#pragma once
#include <iostream>

using namespace System;
using namespace std;

namespace CSC4900GraphicsEngine {
	public ref class Mesh
	{
		// TODO: Add your methods for this class here.
	public:

		//[DllImport("user32.dll", EntryPoint = "CharLower", CharSet = CharSet::Ansi)]
		//static String^ CharLower([In, Out] String^);

		void WriteLine(String^ text) {
			Console::WriteLine(text);
		}
	};
}
