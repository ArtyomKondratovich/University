namespace lab_1_
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            plotView1 = new OxyPlot.WindowsForms.PlotView();
            label1 = new Label();
            textBox1 = new TextBox();
            label4 = new Label();
            button1 = new Button();
            f1 = new CheckBox();
            f2 = new CheckBox();
            SuspendLayout();
            // 
            // plotView1
            // 
            plotView1.Location = new Point(12, 12);
            plotView1.Name = "plotView1";
            plotView1.PanCursor = Cursors.Hand;
            plotView1.Size = new Size(746, 476);
            plotView1.TabIndex = 0;
            plotView1.Text = "plotView1";
            plotView1.ZoomHorizontalCursor = Cursors.SizeWE;
            plotView1.ZoomRectangleCursor = Cursors.SizeNWSE;
            plotView1.ZoomVerticalCursor = Cursors.SizeNS;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(801, 26);
            label1.Name = "label1";
            label1.Size = new Size(74, 15);
            label1.TabIndex = 1;
            label1.Text = "Range: [-3,3]";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(801, 118);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(100, 23);
            textBox1.TabIndex = 4;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(801, 100);
            label4.Name = "label4";
            label4.Size = new Size(14, 15);
            label4.TabIndex = 5;
            label4.Text = "n";
            // 
            // button1
            // 
            button1.Location = new Point(801, 147);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 6;
            button1.Text = "calculate";
            button1.UseVisualStyleBackColor = true;
            button1.Click += Button1_Click;
            // 
            // f1
            // 
            f1.AutoSize = true;
            f1.Location = new Point(801, 53);
            f1.Name = "f1";
            f1.Size = new Size(122, 19);
            f1.TabIndex = 7;
            f1.Text = "f1 = sin(x) * cos(x)";
            f1.UseVisualStyleBackColor = true;
            // 
            // f2
            // 
            f2.AutoSize = true;
            f2.Location = new Point(801, 78);
            f2.Name = "f2";
            f2.Size = new Size(132, 19);
            f2.TabIndex = 8;
            f2.Text = "f2 = 1 / (1 + 12*x^4)";
            f2.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1046, 677);
            Controls.Add(f2);
            Controls.Add(f1);
            Controls.Add(button1);
            Controls.Add(label4);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Controls.Add(plotView1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private OxyPlot.WindowsForms.PlotView plotView1;
        private Label label1;
        private TextBox textBox1;
        private Label label4;
        private Button button1;
        private CheckBox f1;
        private CheckBox f2;
    }
}
