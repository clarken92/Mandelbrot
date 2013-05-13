namespace MiscTest
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.glControl1 = new OpenTK.GLControl();
            this.btnDraw = new System.Windows.Forms.Button();
            this.udPower = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.udIterations = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.udPointsPerAxis = new System.Windows.Forms.NumericUpDown();
            this.btnColorize = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.udPointWidth = new System.Windows.Forms.NumericUpDown();
            this.chkShowAxes = new System.Windows.Forms.CheckBox();
            this.chkShowFog = new System.Windows.Forms.CheckBox();
            this.btnAbout = new System.Windows.Forms.Button();
            this.btnZoomCube = new System.Windows.Forms.Button();
            this.btnZoomOut = new System.Windows.Forms.Button();
            this.btnZoomOriginal = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.udPower)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.udIterations)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.udPointsPerAxis)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.udPointWidth)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // glControl1
            // 
            this.glControl1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.glControl1.BackColor = System.Drawing.Color.Black;
            this.glControl1.Location = new System.Drawing.Point(12, 12);
            this.glControl1.Name = "glControl1";
            this.glControl1.Size = new System.Drawing.Size(528, 524);
            this.glControl1.TabIndex = 0;
            this.glControl1.VSync = false;
            this.glControl1.Load += new System.EventHandler(this.glControl1_Load);
            this.glControl1.Paint += new System.Windows.Forms.PaintEventHandler(this.glControl1_Paint);
            this.glControl1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.glControl1_MouseDown);
            this.glControl1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.glControl1_MouseMove);
            this.glControl1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.glControl1_MouseUp);
            this.glControl1.Resize += new System.EventHandler(this.glControl1_Resize);
            // 
            // btnDraw
            // 
            this.btnDraw.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnDraw.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDraw.Location = new System.Drawing.Point(549, 140);
            this.btnDraw.Name = "btnDraw";
            this.btnDraw.Size = new System.Drawing.Size(170, 57);
            this.btnDraw.TabIndex = 1;
            this.btnDraw.Text = "&Render";
            this.btnDraw.UseVisualStyleBackColor = true;
            this.btnDraw.Click += new System.EventHandler(this.btnDraw_Click);
            // 
            // udPower
            // 
            this.udPower.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.udPower.Location = new System.Drawing.Point(653, 203);
            this.udPower.Maximum = new decimal(new int[] {
            32,
            0,
            0,
            0});
            this.udPower.Minimum = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.udPower.Name = "udPower";
            this.udPower.Size = new System.Drawing.Size(66, 21);
            this.udPower.TabIndex = 2;
            this.udPower.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(606, 205);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Power:";
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(589, 231);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Iterations:";
            // 
            // udIterations
            // 
            this.udIterations.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.udIterations.Location = new System.Drawing.Point(653, 229);
            this.udIterations.Maximum = new decimal(new int[] {
            256,
            0,
            0,
            0});
            this.udIterations.Minimum = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.udIterations.Name = "udIterations";
            this.udIterations.Size = new System.Drawing.Size(66, 21);
            this.udIterations.TabIndex = 4;
            this.udIterations.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // label8
            // 
            this.label8.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(566, 257);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(81, 13);
            this.label8.TabIndex = 8;
            this.label8.Text = "Points per axis:";
            // 
            // udPointsPerAxis
            // 
            this.udPointsPerAxis.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.udPointsPerAxis.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.udPointsPerAxis.Location = new System.Drawing.Point(653, 255);
            this.udPointsPerAxis.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.udPointsPerAxis.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.udPointsPerAxis.Name = "udPointsPerAxis";
            this.udPointsPerAxis.Size = new System.Drawing.Size(66, 21);
            this.udPointsPerAxis.TabIndex = 7;
            this.udPointsPerAxis.Value = new decimal(new int[] {
            200,
            0,
            0,
            0});
            // 
            // btnColorize
            // 
            this.btnColorize.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnColorize.Location = new System.Drawing.Point(725, 140);
            this.btnColorize.Name = "btnColorize";
            this.btnColorize.Size = new System.Drawing.Size(62, 57);
            this.btnColorize.TabIndex = 11;
            this.btnColorize.Text = "Colorize points";
            this.btnColorize.UseVisualStyleBackColor = true;
            this.btnColorize.Click += new System.EventHandler(this.btnColorize_Click);
            // 
            // label9
            // 
            this.label9.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(583, 282);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(64, 13);
            this.label9.TabIndex = 14;
            this.label9.Text = "Point width:";
            // 
            // udPointWidth
            // 
            this.udPointWidth.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.udPointWidth.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.udPointWidth.Location = new System.Drawing.Point(653, 280);
            this.udPointWidth.Maximum = new decimal(new int[] {
            16,
            0,
            0,
            0});
            this.udPointWidth.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.udPointWidth.Name = "udPointWidth";
            this.udPointWidth.Size = new System.Drawing.Size(66, 21);
            this.udPointWidth.TabIndex = 13;
            this.udPointWidth.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.udPointWidth.ValueChanged += new System.EventHandler(this.chkShowSelectionCube_CheckedChanged);
            // 
            // chkShowAxes
            // 
            this.chkShowAxes.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.chkShowAxes.AutoSize = true;
            this.chkShowAxes.Checked = true;
            this.chkShowAxes.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkShowAxes.Location = new System.Drawing.Point(633, 364);
            this.chkShowAxes.Name = "chkShowAxes";
            this.chkShowAxes.Size = new System.Drawing.Size(78, 17);
            this.chkShowAxes.TabIndex = 15;
            this.chkShowAxes.Text = "Show axes";
            this.chkShowAxes.UseVisualStyleBackColor = true;
            this.chkShowAxes.CheckedChanged += new System.EventHandler(this.chkShowSelectionCube_CheckedChanged);
            // 
            // chkShowFog
            // 
            this.chkShowFog.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.chkShowFog.AutoSize = true;
            this.chkShowFog.Checked = true;
            this.chkShowFog.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkShowFog.Location = new System.Drawing.Point(633, 345);
            this.chkShowFog.Name = "chkShowFog";
            this.chkShowFog.Size = new System.Drawing.Size(71, 17);
            this.chkShowFog.TabIndex = 16;
            this.chkShowFog.Text = "Show fog";
            this.chkShowFog.UseVisualStyleBackColor = true;
            this.chkShowFog.CheckedChanged += new System.EventHandler(this.chkShowSelectionCube_CheckedChanged);
            // 
            // btnAbout
            // 
            this.btnAbout.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnAbout.Location = new System.Drawing.Point(549, 513);
            this.btnAbout.Name = "btnAbout";
            this.btnAbout.Size = new System.Drawing.Size(61, 23);
            this.btnAbout.TabIndex = 17;
            this.btnAbout.Text = "About...";
            this.btnAbout.UseVisualStyleBackColor = true;
            this.btnAbout.Click += new System.EventHandler(this.btnAbout_Click);
            // 
            // btnZoomCube
            // 
            this.btnZoomCube.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnZoomCube.Location = new System.Drawing.Point(68, 20);
            this.btnZoomCube.Name = "btnZoomCube";
            this.btnZoomCube.Size = new System.Drawing.Size(106, 27);
            this.btnZoomCube.TabIndex = 10;
            this.btnZoomCube.Text = "Zoom in";
            this.btnZoomCube.UseVisualStyleBackColor = true;
            this.btnZoomCube.Click += new System.EventHandler(this.btnZoomCube_Click);
            // 
            // btnZoomOut
            // 
            this.btnZoomOut.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnZoomOut.Location = new System.Drawing.Point(68, 53);
            this.btnZoomOut.Name = "btnZoomOut";
            this.btnZoomOut.Size = new System.Drawing.Size(106, 27);
            this.btnZoomOut.TabIndex = 11;
            this.btnZoomOut.Text = "Zoom out";
            this.btnZoomOut.UseVisualStyleBackColor = true;
            this.btnZoomOut.Click += new System.EventHandler(this.btnZoomOut_Click);
            // 
            // btnZoomOriginal
            // 
            this.btnZoomOriginal.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnZoomOriginal.Location = new System.Drawing.Point(68, 86);
            this.btnZoomOriginal.Name = "btnZoomOriginal";
            this.btnZoomOriginal.Size = new System.Drawing.Size(106, 27);
            this.btnZoomOriginal.TabIndex = 12;
            this.btnZoomOriginal.Text = "Original zoom";
            this.btnZoomOriginal.UseVisualStyleBackColor = true;
            this.btnZoomOriginal.Click += new System.EventHandler(this.btnZoomOriginal_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.btnZoomOriginal);
            this.groupBox1.Controls.Add(this.btnZoomOut);
            this.groupBox1.Controls.Add(this.btnZoomCube);
            this.groupBox1.Location = new System.Drawing.Point(549, 387);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(238, 119);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Control view";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.comboBox1);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Location = new System.Drawing.Point(549, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(238, 122);
            this.groupBox2.TabIndex = 18;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Method selection : ";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "Classic Method",
            "Positive z-component method",
            "Cosine method",
            "Rudy Rucker’s method",
            "Unknown method"});
            this.comboBox1.Location = new System.Drawing.Point(7, 21);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(225, 21);
            this.comboBox1.TabIndex = 1;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.ComboBox1_SelectedIndexChanged);
            this.comboBox1.SelectedIndex = 0;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 45);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(218, 52);
            this.label3.TabIndex = 0;
            this.label3.Text = "-Description :{x, y, z}^n= r^n \n{ sin(θn) cos(φn), sin(θn) sin(φn), cos(θn) }\n\rTh" +
    "is the original method that rapidly \ngrew in popularity.";
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(604, 309);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 13);
            this.label4.TabIndex = 20;
            this.label4.Text = "Bailout:";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.numericUpDown1.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.numericUpDown1.Location = new System.Drawing.Point(653, 307);
            this.numericUpDown1.Maximum = new decimal(new int[] {
            16,
            0,
            0,
            0});
            this.numericUpDown1.Minimum = new decimal(new int[] {
            4,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(66, 21);
            this.numericUpDown1.TabIndex = 19;
            this.numericUpDown1.Value = new decimal(new int[] {
            4,
            0,
            0,
            0});
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(799, 509);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.btnAbout);
            this.Controls.Add(this.chkShowFog);
            this.Controls.Add(this.chkShowAxes);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.udPointWidth);
            this.Controls.Add(this.btnColorize);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.udPointsPerAxis);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.udIterations);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.udPower);
            this.Controls.Add(this.btnDraw);
            this.Controls.Add(this.glControl1);
            this.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximumSize = new System.Drawing.Size(815, 548);
            this.MinimumSize = new System.Drawing.Size(815, 548);
            this.Name = "Form1";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.udPower)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.udIterations)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.udPointsPerAxis)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.udPointWidth)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private OpenTK.GLControl glControl1;
        private System.Windows.Forms.Button btnDraw;
        private System.Windows.Forms.NumericUpDown udPower;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown udIterations;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.NumericUpDown udPointsPerAxis;
        private System.Windows.Forms.Button btnColorize;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.NumericUpDown udPointWidth;
        private System.Windows.Forms.CheckBox chkShowAxes;
        private System.Windows.Forms.CheckBox chkShowFog;
        private System.Windows.Forms.Button btnAbout;
        private System.Windows.Forms.Button btnZoomCube;
        private System.Windows.Forms.Button btnZoomOut;
        private System.Windows.Forms.Button btnZoomOriginal;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
    }
}