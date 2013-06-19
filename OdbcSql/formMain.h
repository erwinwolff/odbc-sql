#pragma once

#include "stdafx.h"
#include "HelperFunctions.h"

namespace OdbcSql {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for formMain
	/// </summary>
	public ref class formMain : public System::Windows::Forms::Form
	{



	public:
		formMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~formMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox1;

	private: System::Windows::Forms::TextBox^  textBoxQuery;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  toolStripConnect;
	private: System::Windows::Forms::RichTextBox^  textBoxResult;
	private: System::Windows::Forms::SplitContainer^  splitContainer;
	private: System::Windows::Forms::ToolStripMenuItem^  odbcToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  odbcDriversToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  odbcDSNsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  toolStripClose;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  windowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  outputToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tableStyleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  jSONToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  xMLToolStripMenuItem;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(formMain::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->windowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->odbcToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->odbcDriversToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->odbcDSNsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->outputToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableStyleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->jSONToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xMLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->toolStripConnect = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripClose = (gcnew System::Windows::Forms::ToolStripButton());
			this->textBoxQuery = (gcnew System::Windows::Forms::TextBox());
			this->textBoxResult = (gcnew System::Windows::Forms::RichTextBox());
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->odbcToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1030, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->newToolStripMenuItem, 
				this->clearToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->windowToolStripMenuItem});
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->newToolStripMenuItem->Text = L"New";
			// 
			// windowToolStripMenuItem
			// 
			this->windowToolStripMenuItem->Name = L"windowToolStripMenuItem";
			this->windowToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->windowToolStripMenuItem->Text = L"Window";
			this->windowToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::windowToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::clearToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::exitToolStripMenuItem_Click);
			// 
			// odbcToolStripMenuItem
			// 
			this->odbcToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->showToolStripMenuItem, 
				this->outputToolStripMenuItem});
			this->odbcToolStripMenuItem->Name = L"odbcToolStripMenuItem";
			this->odbcToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->odbcToolStripMenuItem->Text = L"Odbc";
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->odbcDriversToolStripMenuItem, 
				this->odbcDSNsToolStripMenuItem});
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->showToolStripMenuItem->Text = L"Show";
			// 
			// odbcDriversToolStripMenuItem
			// 
			this->odbcDriversToolStripMenuItem->Name = L"odbcDriversToolStripMenuItem";
			this->odbcDriversToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->odbcDriversToolStripMenuItem->Text = L"Odbc Drivers";
			this->odbcDriversToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::odbcDriversToolStripMenuItem_Click);
			// 
			// odbcDSNsToolStripMenuItem
			// 
			this->odbcDSNsToolStripMenuItem->Name = L"odbcDSNsToolStripMenuItem";
			this->odbcDSNsToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->odbcDSNsToolStripMenuItem->Text = L"Odbc DSN\'s";
			this->odbcDSNsToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::odbcDSNsToolStripMenuItem_Click);
			// 
			// outputToolStripMenuItem
			// 
			this->outputToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->tableStyleToolStripMenuItem, 
				this->jSONToolStripMenuItem, this->xMLToolStripMenuItem});
			this->outputToolStripMenuItem->Name = L"outputToolStripMenuItem";
			this->outputToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->outputToolStripMenuItem->Text = L"Output";
			// 
			// tableStyleToolStripMenuItem
			// 
			this->tableStyleToolStripMenuItem->Checked = true;
			this->tableStyleToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->tableStyleToolStripMenuItem->Name = L"tableStyleToolStripMenuItem";
			this->tableStyleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->tableStyleToolStripMenuItem->Text = L"Old table style";
			this->tableStyleToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::tableStyleToolStripMenuItem_Click);
			// 
			// jSONToolStripMenuItem
			// 
			this->jSONToolStripMenuItem->Name = L"jSONToolStripMenuItem";
			this->jSONToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->jSONToolStripMenuItem->Text = L"JSON";
			this->jSONToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::jSONToolStripMenuItem_Click);
			// 
			// xMLToolStripMenuItem
			// 
			this->xMLToolStripMenuItem->Name = L"xMLToolStripMenuItem";
			this->xMLToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->xMLToolStripMenuItem->Text = L"XML";
			this->xMLToolStripMenuItem->Click += gcnew System::EventHandler(this, &formMain::xMLToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripLabel1, 
				this->toolStripComboBox1, this->toolStripConnect, this->toolStripClose});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1030, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(101, 22);
			this->toolStripLabel1->Text = L"Odbc Connection";
			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->toolStripComboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(300, 25);
			// 
			// toolStripConnect
			// 
			this->toolStripConnect->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripConnect->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripConnect.Image")));
			this->toolStripConnect->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripConnect->Name = L"toolStripConnect";
			this->toolStripConnect->Size = System::Drawing::Size(23, 22);
			this->toolStripConnect->Text = L"Connect";
			this->toolStripConnect->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->toolStripConnect->ToolTipText = L"Connect!";
			// 
			// toolStripClose
			// 
			this->toolStripClose->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripClose->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripClose.Image")));
			this->toolStripClose->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripClose->Name = L"toolStripClose";
			this->toolStripClose->Size = System::Drawing::Size(23, 22);
			this->toolStripClose->Text = L"Close";
			// 
			// textBoxQuery
			// 
			this->textBoxQuery->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxQuery->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxQuery->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold));
			this->textBoxQuery->Location = System::Drawing::Point(0, 0);
			this->textBoxQuery->Multiline = true;
			this->textBoxQuery->Name = L"textBoxQuery";
			this->textBoxQuery->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxQuery->Size = System::Drawing::Size(1030, 174);
			this->textBoxQuery->TabIndex = 3;
			this->textBoxQuery->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &formMain::textBoxQuery_KeyUp);
			// 
			// textBoxResult
			// 
			this->textBoxResult->BackColor = System::Drawing::Color::White;
			this->textBoxResult->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxResult->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxResult->Location = System::Drawing::Point(0, 0);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->textBoxResult->Size = System::Drawing::Size(1030, 448);
			this->textBoxResult->TabIndex = 4;
			this->textBoxResult->Text = L"";
			// 
			// splitContainer
			// 
			this->splitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer->Location = System::Drawing::Point(0, 49);
			this->splitContainer->Name = L"splitContainer";
			this->splitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->textBoxResult);
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->textBoxQuery);
			this->splitContainer->Size = System::Drawing::Size(1030, 626);
			this->splitContainer->SplitterDistance = 448;
			this->splitContainer->TabIndex = 5;
			// 
			// formMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1030, 675);
			this->Controls->Add(this->splitContainer);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"formMain";
			this->Text = L"Odbc Sql Command Prompt";
			this->Load += gcnew System::EventHandler(this, &formMain::formMain_Load);
			this->Resize += gcnew System::EventHandler(this, &formMain::formMain_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->splitContainer->Panel1->ResumeLayout(false);
			this->splitContainer->Panel2->ResumeLayout(false);
			this->splitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer))->EndInit();
			this->splitContainer->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Windows::Forms::MessageBox ^ box;
	private : OdbcActions * odbcActions;
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->Close();
			 }
	private: System::Void textBoxQuery_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 }


	private: System::Void clearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBoxResult->Text = System::String::Empty;
				 this->textBoxQuery->Text = System::String::Empty;
			 }

	private: System::Void formMain_Resize(System::Object^  sender, System::EventArgs^  e) {
				 resizeScreen();
			 }

	private: System::Void resizeScreen()
			 {
				 //textBoxResult->Height = (this->Height - textBoxQuery->Height);
			 }

	private: System::Void fillDSNList()
			 {

				 OdbcSystemQueries * OdbcSystemQueries = new OdbcSql::OdbcSystemQueries();
				 this->toolStripComboBox1->Items->Clear();
				 for each (String ^ var in OdbcSystemQueries->GetDSNList())
				 {				
					 this->toolStripComboBox1->Items->Add(var);	 
				 }

				 delete OdbcSystemQueries;
			 }


	private : System::Void executeQuery(System::String ^ query)
			  {
				  textBoxResult->Text += "\nODBC >> " + query + "\n";

				  if(HelperFunctions::cleanString(query) == "@@drivers") 
				  {
					  OdbcSystemQueries * OdbcSystemQueries = new OdbcSql::OdbcSystemQueries();

					  textBoxResult->Text += OdbcSystemQueries->GetDrivers();

					  delete OdbcSystemQueries;
				  }

				  if(HelperFunctions::cleanString(query) == "@@dsn") 
				  {
					  OdbcSystemQueries * OdbcSystemQueries = new OdbcSql::OdbcSystemQueries();

					  textBoxResult->Text += OdbcSystemQueries->GetDSN();

					  delete OdbcSystemQueries;
				  }


				  textBoxResult->Select(textBoxResult->Text->Length - 1, 0);
				  textBoxResult->ScrollToCaret();

			  }

	private: System::Void formMain_Load(System::Object^  sender, System::EventArgs^  e) {
				 resizeScreen();
				 fillDSNList();

				 this->odbcActions = new OdbcActions();
			 }

	private: System::Void textBoxQuery_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 System::String ^ query = textBoxQuery->Text;

				 if(e->KeyCode == Keys::Enter)
				 {
					 this->executeQuery(query);

					 this->textBoxQuery->Text = System::String::Empty;
					 this->textBoxQuery->Lines = gcnew array<String ^>(0);
					 textBoxQuery->Select(0,0);

					 textBoxQuery->Text = textBoxQuery->Text->Replace("\n", "");
					 textBoxQuery->Text = textBoxQuery->Text->Replace("\r", "");

					 // e->Handled = true;
				 }


				 // e->Handled = true;

			 }

	private: System::Void odbcDriversToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->executeQuery("@@drivers");
			 }

	private: System::Void odbcDSNsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->executeQuery("@@dsn");
			 }
	private: System::Void windowToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 formMain ^ newFormMain = gcnew formMain();

				 newFormMain->Show();
			 }

	private: System::Void tableStyleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void jSONToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void xMLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }


	};
}

