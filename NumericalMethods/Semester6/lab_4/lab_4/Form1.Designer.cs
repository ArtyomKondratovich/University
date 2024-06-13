namespace lab_4
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
            mainPlot = new ScottPlot.WinForms.FormsPlot();
            button = new Button();
            SuspendLayout();
            // 
            // mainPlot
            // 
            mainPlot.DisplayScale = 1F;
            mainPlot.Location = new Point(12, 12);
            mainPlot.Name = "mainPlot";
            mainPlot.Size = new Size(648, 459);
            mainPlot.TabIndex = 0;
            // 
            // button
            // 
            button.Location = new Point(12, 480);
            button.Name = "button";
            button.Size = new Size(75, 23);
            button.TabIndex = 2;
            button.Text = "calculate";
            button.UseVisualStyleBackColor = true;
            button.Click += Button_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 16F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(681, 515);
            Controls.Add(button);
            Controls.Add(mainPlot);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
        }

        #endregion

        private ScottPlot.WinForms.FormsPlot mainPlot;
        private Button button;
    }
}
