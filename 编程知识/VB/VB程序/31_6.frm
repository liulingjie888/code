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
   Begin VB.CommandButton Command2 
      Caption         =   "清除"
      Height          =   375
      Left            =   2760
      TabIndex        =   6
      Top             =   2040
      Width           =   735
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   375
      Left            =   840
      TabIndex        =   5
      Top             =   2040
      Width           =   735
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2520
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   840
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   600
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label3 
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Label3"
      Height          =   375
      Left            =   600
      TabIndex        =   4
      Top             =   1440
      Width           =   3135
   End
   Begin VB.Label Label2 
      Caption         =   "输入总脚数F（F为偶数)"
      Height          =   375
      Left            =   2640
      TabIndex        =   1
      Top             =   240
      Width           =   1095
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "输入总头数H"
      Height          =   255
      Left            =   360
      TabIndex        =   0
      Top             =   360
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim H%, F%, X%, Y%
Dim flag As Boolean
flag = True

H = Val(Text1.Text)
F = Val(Text2.Text)

For Y = 1 To F \ 4
If Y * 4 + (H - Y) * 2 = F Then
X = H - Y
Label3.Caption = "鸡数量" & X & "      " & "兔数量" & Y
flag = False
Exit For
End If
Next Y

If flag Then Label3.Caption = " 不存在该情况！"

End Sub

Private Sub Form_Load()
Text1.Text = ""
Text2.Text = ""
Label3.Caption = ""
End Sub

Private Sub Text2_LostFocus()
If Val(Text2.Text) Mod 2 <> 0 Then Text2.Text = "": Text2.SetFocus: Label3.Caption = "F应为偶数！"
End Sub
