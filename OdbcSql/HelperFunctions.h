#pragma once

#include "stdafx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace OdbcSql {

	/// <summary>
	/// Summary for HelperFunctions
	/// </summary>
	public ref class HelperFunctions :  public System::ComponentModel::Component
	{
	public:
		HelperFunctions(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		HelperFunctions(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HelperFunctions()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			components = gcnew System::ComponentModel::Container();
		}
#pragma endregion

	public: static System::String ^ cleanString(System::String ^ entry)
			{
				System::String ^ result = System::String::Empty;

				result = entry->Replace("\n", "");
				result = result->Replace("\r", "");
				result = result->Replace("  ", " ");

				return result;
			}

	};
}
