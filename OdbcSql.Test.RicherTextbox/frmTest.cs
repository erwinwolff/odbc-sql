using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OdbcSql.Test.RicherTextbox
{
    public partial class frmTest : Form
    {
        public frmTest()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.richerTextBox.AppendRtf(this.richerTextBox.HighlightSQL(("SELECT * FROM TABLE\r\n")));
        }

        private void frmTest_Load(object sender, EventArgs e)
        {
            this.richerTextBox.initRicherTextbox();
            this.richerTextBox.AppendRtf(this.richerTextBox.HighlightSQL(("SELECT * FROM TABLE\r\n")));
            //this.richerTextBox.AppendRtf(this.richerTextBox.HighlightSystemKeywords(("@@dsn")));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //this.richerTextBox.AppendRtf(this.richerTextBox.HighlightSystemKeywords(("@@dsn")));
        }
    }
}
