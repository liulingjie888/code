VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2565
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   2565
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command3 
      Caption         =   "结束"
      Height          =   375
      Left            =   3600
      TabIndex        =   9
      Top             =   1920
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "清除"
      Height          =   375
      Left            =   3600
      TabIndex        =   8
      Top             =   1320
      Width           =   735
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   375
      Left            =   3600
      TabIndex        =   7
      Top             =   720
      Width           =   735
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1080
      TabIndex        =   6
      Text            =   "Text1"
      Top             =   1920
      Width           =   2295
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1080
      TabIndex        =   5
      Text            =   "Text1"
      Top             =   1320
      Width           =   2295
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1080
      TabIndex        =   4
      Text            =   "34"
      Top             =   720
      Width           =   2295
   End
   Begin VB.Label Label4 
      Caption         =   "圆周长为"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   1320
      Width           =   855
   End
   Begin VB.Label Label3 
      Caption         =   "圆面积为"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   1920
      Width           =   855
   End
   Begin VB.Label Label2 
      Caption         =   "输入半径"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   720
      Width           =   855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "输入圆半径计算圆周长和面积"
      Height          =   255
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   3855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim radius As Single
radius = Val(Text1.Text)
Text2.Text = radius * 6.28
Text3.Text = radius ^ 2 * 3.14
End Sub

Private Sub Command2_Click()
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
End Sub

Private Sub Command3_Click()
End
End Sub

Private Sub Form_Load()
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
End Sub

Private Sub Text1_Change()
If Left(Text1.Text, 1) = "-" Then Text1.Text = Right(Text1.Text, Len(Text1.Text) - 1)

End Sub
