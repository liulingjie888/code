VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3015
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command3 
      Caption         =   "清除"
      Height          =   375
      Left            =   1920
      TabIndex        =   8
      Top             =   2160
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "结束"
      Height          =   375
      Left            =   3240
      TabIndex        =   7
      Top             =   2160
      Width           =   735
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   375
      Left            =   480
      TabIndex        =   6
      Top             =   2160
      Width           =   735
   End
   Begin VB.PictureBox Picture1 
      Height          =   615
      Left            =   240
      ScaleHeight     =   555
      ScaleWidth      =   3795
      TabIndex        =   5
      Top             =   1320
      Width           =   3855
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   3360
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   240
      Width           =   735
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1320
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   240
      Width           =   735
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "三个随机数及和的平凡根"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   840
      Width           =   3855
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "整数上界"
      Height          =   255
      Left            =   2280
      TabIndex        =   1
      Top             =   360
      Width           =   975
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "整数下界"
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim a&, b&, c&, d&, e&, f!
a = Val(Text1.Text)
b = Val(Text2.Text)

Randomize
c = a + Int(Rnd * (b - a + 1))
d = a + Int(Rnd * (b - a + 1))
e = a + Int(Rnd * (b - a + 1))
f = Round(Sqr(c + d + e), 4)
Picture1.Cls
Picture1.Print c & "     " & d & "        " & e & vbCrLf & "三个数的平方根=" & f
End Sub

Private Sub Command2_Click()
End
End Sub

Private Sub Command3_Click()
Text1.Text = ""
Text2.Text = ""
Picture1.Cls
End Sub

Private Sub Form_Load()
Text1.Text = ""
Text2.Text = ""
End Sub

Private Sub Text2_LostFocus()
Picture1.Print "上界不小于下界！"
If Val(Text2.Text) < Val(Text1.Text) Then Text2.Text = "": Text2.SetFocus
End Sub
