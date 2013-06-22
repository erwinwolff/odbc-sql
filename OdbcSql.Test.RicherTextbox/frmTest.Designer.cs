namespace OdbcSql.Test.RicherTextbox
{
    partial class frmTest
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.richerTextBox = new OdbcSql.RicherTextBox.RicherTextBox();
            this.SuspendLayout();
            // 
            // richerTextBox
            // 
            this.richerTextBox.Location = new System.Drawing.Point(12, 42);
            this.richerTextBox.Name = "richerTextBox";
            this.richerTextBox.Size = new System.Drawing.Size(642, 459);
            this.richerTextBox.TabIndex = 0;
            this.richerTextBox.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(666, 513);
            this.Controls.Add(this.richerTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private RicherTextBox.RicherTextBox richerTextBox;
    }
}

