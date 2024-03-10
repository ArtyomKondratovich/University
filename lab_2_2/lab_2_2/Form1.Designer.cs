using OxyPlot.WindowsForms;

namespace lab_2_2
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
            functionLabel = new Label();
            button1 = new Button();
            plotView1 = new PlotView();
            plotView2 = new PlotView();
            label1 = new Label();
            SuspendLayout();
            // 
            // functionLabel
            // 
            functionLabel.AutoSize = true;
            functionLabel.Location = new Point(36, 498);
            functionLabel.Name = "functionLabel";
            functionLabel.Size = new Size(146, 15);
            functionLabel.TabIndex = 0;
            functionLabel.Text = "f(x) = sin(x)cos(x), xϵ[-3,3]";
            // 
            // button1
            // 
            button1.Location = new Point(36, 516);
            button1.Name = "button1";
            button1.Size = new Size(146, 23);
            button1.TabIndex = 1;
            button1.Text = "calculate";
            button1.UseVisualStyleBackColor = true;
            button1.Click += Button1_Click;
            // 
            // plotView1
            // 
            plotView1.Location = new Point(12, 26);
            plotView1.Name = "plotView1";
            plotView1.PanCursor = Cursors.Hand;
            plotView1.Size = new Size(542, 442);
            plotView1.TabIndex = 2;
            plotView1.Text = "plotView1";
            plotView1.ZoomHorizontalCursor = Cursors.SizeWE;
            plotView1.ZoomRectangleCursor = Cursors.SizeNWSE;
            plotView1.ZoomVerticalCursor = Cursors.SizeNS;
            // 
            // plotView2
            // 
            plotView2.Location = new Point(579, 26);
            plotView2.Name = "plotView2";
            plotView2.PanCursor = Cursors.Hand;
            plotView2.Size = new Size(542, 442);
            plotView2.TabIndex = 3;
            plotView2.Text = "plotView2";
            plotView2.ZoomHorizontalCursor = Cursors.SizeWE;
            plotView2.ZoomRectangleCursor = Cursors.SizeNWSE;
            plotView2.ZoomVerticalCursor = Cursors.SizeNS;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(200, 498);
            label1.Name = "label1";
            label1.Size = new Size(119, 15);
            label1.TabIndex = 4;
            label1.Text = "max|f(x)-s(x)| = none";
            label1.Click += label1_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1203, 563);
            Controls.Add(label1);
            Controls.Add(plotView2);
            Controls.Add(plotView1);
            Controls.Add(button1);
            Controls.Add(functionLabel);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label functionLabel;
        private Button button1;
        private PlotView plotView1;
        private PlotView plotView2;
        private Label label1;
    }
}
