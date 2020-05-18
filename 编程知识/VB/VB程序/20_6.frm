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
      Caption         =   "还原"
      Height          =   375
      Left            =   3360
      TabIndex        =   4
      Top             =   1920
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "缩小"
      Height          =   375
      Left            =   3360
      TabIndex        =   3
      Top             =   1320
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "放大"
      Height          =   375
      Left            =   3360
      TabIndex        =   2
      Top             =   720
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   1575
      Left            =   480
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   1
      Text            =   "20_6.frx":0000
      Top             =   720
      Width           =   2655
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "输入文本内容"
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   2895
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Randomize
Text1.FontSize = Text1.FontSize * Int(Rnd() * 3 + 2)
Command1.Enabled = False
Command2.Enabled = True
Command3.Enabled = True
End Sub

Private Sub Command2_Click()
Randomize
Text1.FontSize = Text1.FontSize / Int(Rnd() * 3 + 1)
Command1.Enabled = True
Command2.Enabled = False
Command3.Enabled = True
End Sub

Private Sub Command3_Click()
Text1.FontSize = 9
Command1.Enabled = True
Command2.Enabled = True
Command3.Enabled = False
End Sub

Private Sub Form_Load()
Text1.Text = ""
Command3.Enabled = False
End Sub
